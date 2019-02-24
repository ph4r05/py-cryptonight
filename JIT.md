## JIT implementation and troubleshooting

JIT optimization feature for CNv4 `cn_slow_hash()`.
JIT can boost the performance significantly.

JIT feature is experimental and was not properly tested on multiple platforms.

I tested on:
 - OSX LLVM
 - Ubuntu 18.10 GCC


## Static JIT

By default, the static JIT is used.
It is pre-computed instruction table in bytes for x86_64 architecture.

For other architectures the dynamic JIT has to be used, i.e., ASM to bytes extraction.

To disable static JIT define `MONERO_STATIC_JIT=0`.

## Dynamic JIT

### Problem

Python distutils cannot compile `.S` file so a
[CryptonightR_template.c](src/cryptonight/CryptonightR_template.c) file
was generated with [tools/convert_s_to_c.py](tools/convert_s_to_c.py) script.

The function bodies are inlined assembly generated instructions which are
later assembled to a function in [CryptonightR_JIT.c](src/cryptonight/CryptonightR_JIT.c), in the function:

```
int v4_generate_JIT_code(const struct V4_Instruction* code, v4_random_math_JIT_func buf, const size_t buf_size)
```

In order to JIT work correctly, the `APPEND_CODE` has to append the exact instruction bytes (function body),
without function prologue / epilogues.

Traditionally, the function is compiled as:

```asm
pycryptonight`CryptonightR_instruction120:
    0x10fb91080 <+0>: pushq  %rbp
    0x10fb91081 <+1>: movq   %rsp, %rbp
    0x10fb91084 <+4>: imull  %ebp, %ebp
    0x10fb91087 <+7>: popq   %rbp
    0x10fb91088 <+8>: retq
    0x10fb91089 <+9>: nopl   (%rax)
```

### Solution

In order to remove a function prologue, we could use `__attribute__ ((naked))`.
However, `naked` attribute is not supported by GCC.

The problem also is we don't know where the function ends.

```asm
pycryptonight`CryptonightR_instruction0:
    0x108879650 <+0>: 0f af db                          imull  %ebx, %ebx
    0x108879653 <+3>: 0f 0b                             ud2
    0x108879655 <+5>: 66 66 2e 0f 1f 84 00 00 00 00 00  nopw   %cs:(%rax,%rax)

pycryptonight`CryptonightR_instruction1:
    0x108879660 <+0>:  0f af db                          imull  %ebx, %ebx
    0x108879663 <+3>:  0f 0b                             ud2
    0x108879665 <+5>:  66 66 2e 0f 1f 84 00 00 00 00 00  nopw   %cs:(%rax,%rax)
```

The idea is to add a known trailing sequence to mark end of the function, such as

```c
#define ASM_E ".byte 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90\n\t");
```

This is NOP trail of 8 bytes. LLVM also generates another trailing, example:

```asm
pycryptonight`CryptonightR_instruction2:
    0x100d9d470 <+0>:  0f af db                                imull  %ebx, %ebx
    0x100d9d473 <+3>:  90                                      nop
    0x100d9d474 <+4>:  90                                      nop
    0x100d9d475 <+5>:  90                                      nop
    0x100d9d476 <+6>:  90                                      nop
    0x100d9d477 <+7>:  90                                      nop
    0x100d9d478 <+8>:  90                                      nop
    0x100d9d479 <+9>:  90                                      nop
    0x100d9d47a <+10>: 90                                      nop
    0x100d9d47b <+11>: 0f 0b                                   ud2    ;<--- THIS
    0x100d9d47d <+13>: 0f 1f 00                                nopl   (%rax)
```

but it is unknown whether other compilers do the same thing so we cannot check for this trailing.

Solution:
 - when initializing the sequence, check for introducing and trailing NOPs for each function.
 - mark down each instruction size to an array.

Example of a generated function:

```asm
pycryptonight`CryptonightR_instruction2:
    0x10e0471d5 <+0>:  90        nop
    0x10e0471d6 <+1>:  90        nop
    0x10e0471d7 <+2>:  90        nop
    0x10e0471d8 <+3>:  90        nop
    0x10e0471d9 <+4>:  90        nop
    0x10e0471da <+5>:  90        nop
    0x10e0471db <+6>:  90        nop
    0x10e0471dc <+7>:  90        nop
    0x10e0471dd <+8>:  0f af db  imull  %ebx, %ebx
    0x10e0471e0 <+11>: 90        nop
    0x10e0471e1 <+12>: 90        nop
    0x10e0471e2 <+13>: 90        nop
    0x10e0471e3 <+14>: 90        nop
    0x10e0471e4 <+15>: 90        nop
    0x10e0471e5 <+16>: 90        nop
    0x10e0471e6 <+17>: 90        nop
    0x10e0471e7 <+18>: 90        nop
```

Note: Debugging mode messes up instruction codes when read from LLDB vs read by code.
I.e., LLDB memory view displays correctly `0f af db` bytes, so comparison should
match the known instruction and determine the length of the function prefix.
However, the real execution prints `cc af db` instead (?!).

Code for detecting the beginning and end of our instruction sequences.

```c
static unsigned inst_lengths[257];
static uint8_t * inst_offsets[257];
static unsigned inst_mov_lengths[257];
static uint8_t * inst_mov_offsets[257];

static const unsigned nop_len = 8;
static const uint8_t nop_trail[] = {
    0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90
};

#define COMP_INS_ADDR(instructions, inst_offsets, inst_lengths) do {                      \
  for(unsigned ii = 0; ii < 257; ++ii){                       \
    const uint8_t * p1 = (const uint8_t*) (instructions)[ii]; \
    const uint8_t * p2 = (const uint8_t*) (ii < 256 ? (instructions)[ii + 1] : p1 + 0x30); \
    unsigned nstate = 0;                                      \
    (inst_lengths)[ii] = 0;                                   \
    for(const uint8_t* px = p1; px <= p2 && nstate < 2; ++px){\
      if (memcmp(px, &nop_trail, nop_len) == 0){              \
        if (nstate == 0)                                      \
            (inst_offsets)[ii] = ((uint8_t *)px + 8);         \
        else                                                  \
            (inst_lengths)[ii] = (px - (inst_offsets)[ii]);   \
        nstate += 1;                                          \
        px += nop_len - 1;                                    \
      }                                                       \
    }                                                         \
  }                                                           \
} while (0)
```

Then in the JIT build code:

```c
    // INITIALIZATION OF THE INSTRUCTION LENGTH ARRAY
	static bool fnc_computed = false;
	if (!fnc_computed){
		fnc_computed = true;
        COMP_INS_SIZE(instructions, inst_lengths);
        COMP_INS_SIZE(instructions_mov, inst_mov_lengths);
	}
```

#### Dynamic JIT

This worked on OSX and LLVM however the compilation under Ubuntu 18.10 and GCC
fails to add NOPs to the functions so the bodies cannot be detected.

Due to this, dynamic JIT compilation requires to use top-level ASM so
the defined functions are exactly as we want them

```c
ASM_FNC(CryptonightR_instruction42,
        IMUL(R(esi), R(esi))
)
```

Generates

```c
__asm__ ("_CryptonightR_instruction42:\n\t"
        "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t"
        "imull %esi, %esi\n\t"
        "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t" "nop\n\t"
        ".global _CryptonightR_instruction42\n");
```

While on Win it generates:

```c
__declspec(naked) void CryptonightR_instruction42(void){
    __asm { nop; nop; nop; nop; nop; nop; nop; nop; imul esi, esi; nop; nop; nop; nop; nop; nop; nop; nop;
    }
}
```


#### Static table

The static instruction table is generated if `-DDUMP_JIT=1` is defined.
The instruction table was generated to [CryptonightR_JIT_x86_64.c](src/cryptonight/CryptonightR_JIT_x86_64.c)

The static table is used if `-DSTATIC_JIT=1` is defined.


### Alternative 1

Use JIT library to generate ASM code:

https://github.com/asmjit/asmjit


### Alternative 2
Note: *Not working*

Using GCC feature of label addresses and `&&` operator.

```c
void * CryptonightR_instruction_X(int ins){
  void* goto_table[] = {
      &&ins_cryptonightr_instruction0_s,
      &&ins_cryptonightr_instruction1_s,
      &&ins_cryptonightr_instruction2_s,
      &&ins_cryptonightr_instruction3_s
  }

  return goto_table[ins];

ins_cryptonightr_instruction0_s:
    ASM_B
    IMUL(R(ebx), R(ebx))
    ASM_E
ins_cryptonightr_instruction1_s:
    ASM_B
    IMUL(R(ebx), R(ebx))
    ASM_E
ins_cryptonightr_instruction2_s:
    ASM_B
    IMUL(R(ebx), R(ebx))
    ASM_E
ins_cryptonightr_instruction3_s:
    ASM_B
    ADD(R(ebx), R(r9d))
    ADD(R(ebx), C(2147483647))
    ASM_E
}
```

This and similar variations do not work from some reason.
LLDB cannot dereference the label address, even `printf` in release
mode does not show correct instruction address.


## LLDB
LLDB tutorials, useful for JIT debugging:

- http://nickdesaulniers.github.io/blog/2016/01/20/debugging-x86-64-assembly-with-lldb-and-dtrace/
- https://lldb.llvm.org/tutorial.html
- https://www.nesono.com/sites/default/files/lldb%20cheat%20sheet.pdf
- https://developer.apple.com/library/archive/documentation/IDEs/Conceptual/gdb_to_lldb_transition_guide/document/lldb-command-examples.html
- https://lldb.llvm.org/lldb-gdb.html

Few LLDB tricks:

```lldb
d --pc -c 100            # disassm around PC, 100 lines
d -s 0x10fb91090 -c 100  # disassm at the address, 100 lines
d -n CryptonightR_instruction121 -c 10  # disassm the function

# Breakpoints
b 0x10fb91090            # BP to address, will last only one exection (address changes)

# Read registers
register read
re read
re read rax

# Read memory
x/32xb JIT_code

memory read `argv[0]`
memory read --size 4 --format x --count 4 0xbffff3c0
me r -s4 -fx -c4 0xbffff3c
x -s4 -fx -c4 0xbffff3c0
memory read/4xw 0xbffff3c0
x/4xb 0xbffff3c0
x/4xw 0xbffff3c0

# Variables
fr v           # all frame variables
fr v var       # particular frame var
p var          # print var

```
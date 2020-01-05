#ifndef CRYPTONIGHTR_JIT_H
#define CRYPTONIGHTR_JIT_H

#include "CryptonightR_base.h"

// Minimalistic JIT code generator for random math sequence in CryptonightR
//
// Usage:
// - Allocate writable and executable memory
// - Call v4_generate_JIT_code with "buf" pointed to memory allocated on previous step
// - Call the generated code instead of "v4_random_math(code, r)", omit the "code" parameter
#if (defined(__GNUC__) || defined(__clang__))
#define ATTR_ABI __attribute__((sysv_abi))
#else
#define ATTR_ABI
#endif

typedef void (*v4_random_math_JIT_func)(uint32_t* r)ATTR_ABI;

// Given the random math sequence, generates machine code (x86-64) for it
// Returns 0 if code was generated successfully
// Returns -1 if provided buffer was too small
int v4_generate_JIT_code(const struct V4_Instruction* code, v4_random_math_JIT_func buf, const size_t buf_size);

#endif // CRYPTONIGHTR_JIT_H

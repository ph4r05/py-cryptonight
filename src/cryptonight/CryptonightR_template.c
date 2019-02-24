// This file was generated from CryptonightR_template.S
// I don't see an easy way to compile python extension with .S file.
// gcc would do it like this: gcc -c file.S -o file.o
// However, distutils support many different compilers, some of them do not have .S option (maybe).
//
// JIT is not tested thus the default compilation setting should be -DNO_JIT=1
// https://stackoverflow.com/questions/61341/is-there-a-way-to-insert-assembly-code-into-c

#include "CryptonightR_base.h"

#if defined(NO_JIT) || defined(STATIC_JIT) || !defined(__x86_64__)

// ASM disabled - safe option
#define ASMFNC
#define ASM
#define ASM_B
#define ASM_E
#define R(x) x
#define C(x) x

#define IMUL(a, b)
#define ADD(a, b)
#define SUB(a, b)
#define ROR(a, b)
#define ROL(a, b)
#define XOR(a, b)
#define MOV(a, b)
#define NOP()
#define ASM_FNC(fnc, BODY) void fnc(void){}


#elif !defined(_MSC_VER)

// https://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html
// GCC uses AT&T/UNIX assembly syntax
//  - Op-code src dst
//  - registers prefixed with %
//  - constants prefixed with $

#define ASMFNC
#define NOP() "nop\n\t"
#define NOP8() NOP() NOP() NOP() NOP() NOP() NOP() NOP() NOP()

#define R(x) "%"#x
#define C(x) "$"#x

#define IMUL(a, b) "imull "b", "a"\n\t"
#define ADD(a, b) "addl "b", "a"\n\t"
#define SUB(a, b) "subl "b", "a"\n\t"
#define ROR(a, b) "rorl "b", "a"\n\t"
#define ROL(a, b) "roll "b", "a"\n\t"
#define XOR(a, b) "xorl "b", "a"\n\t"
#define MOV(a, b) "movl "b", "a"\n\t"

#define ASM_FNC(fnc, BODY)        \
  __asm__ ("_"#fnc":\n\t"         \
           NOP8()                 \
           BODY                   \
           NOP8()                 \
           ".global _"#fnc"\n");

#else

// https://docs.microsoft.com/en-us/cpp/assembler/inline/writing-functions-with-inline-assembly?view=vs-2017

#define ASMFNC __declspec(naked)

#define ASM __asm
#define NOP() nop;
#define NOP8() NOP() NOP() NOP() NOP() NOP() NOP() NOP() NOP()

#define ASM_B ASM { NOP8()
#define ASM_E NOP8() }
#define R(x) x
#define C(x) x

#define IMUL(a, b) imul a, b;
#define ADD(a, b) add a, b;
#define SUB(a, b) sub a, b;
#define ROR(a, b) ror a, b;
#define ROL(a, b) rol a, b;
#define XOR(a, b) xor a, b;
#define MOV(a, b) mov a, b;

#define ASM_FNC(fnc, BODY)        \
ASMFNC void fnc(void){            \
  ASM_B                           \
  BODY                            \
  ASM_E                           \
}

#endif

ASM_FNC(CryptonightR_instruction0,
        IMUL(R(ebx), R(ebx))
)
ASM_FNC(CryptonightR_instruction1,
        IMUL(R(ebx), R(ebx))
)
ASM_FNC(CryptonightR_instruction2,
        IMUL(R(ebx), R(ebx))
)
ASM_FNC(CryptonightR_instruction3,
        ADD(R(ebx), R(r9d))
        ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction4,
        SUB(R(ebx), R(r9d))
)
ASM_FNC(CryptonightR_instruction5,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction6,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction7,
        XOR(R(ebx), R(r9d))
)
ASM_FNC(CryptonightR_instruction8,
        IMUL(R(esi), R(ebx))
)
ASM_FNC(CryptonightR_instruction9,
        IMUL(R(esi), R(ebx))
)
ASM_FNC(CryptonightR_instruction10,
        IMUL(R(esi), R(ebx))
)
ASM_FNC(CryptonightR_instruction11,
        ADD(R(esi), R(ebx))
        ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction12,
        SUB(R(esi), R(ebx))
)
ASM_FNC(CryptonightR_instruction13,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction14,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction15,
        XOR(R(esi), R(ebx))
)
ASM_FNC(CryptonightR_instruction16,
        IMUL(R(edi), R(ebx))
)
ASM_FNC(CryptonightR_instruction17,
        IMUL(R(edi), R(ebx))
)
ASM_FNC(CryptonightR_instruction18,
        IMUL(R(edi), R(ebx))
)
ASM_FNC(CryptonightR_instruction19,
        ADD(R(edi), R(ebx))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction20,
        SUB(R(edi), R(ebx))
)
ASM_FNC(CryptonightR_instruction21,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction22,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction23,
        XOR(R(edi), R(ebx))
)
ASM_FNC(CryptonightR_instruction24,
        IMUL(R(ebp), R(ebx))
)
ASM_FNC(CryptonightR_instruction25,
        IMUL(R(ebp), R(ebx))
)
ASM_FNC(CryptonightR_instruction26,
        IMUL(R(ebp), R(ebx))
)
ASM_FNC(CryptonightR_instruction27,
        ADD(R(ebp), R(ebx))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction28,
        SUB(R(ebp), R(ebx))
)
ASM_FNC(CryptonightR_instruction29,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction30,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction31,
        XOR(R(ebp), R(ebx))
)
ASM_FNC(CryptonightR_instruction32,
        IMUL(R(ebx), R(esi))
)
ASM_FNC(CryptonightR_instruction33,
        IMUL(R(ebx), R(esi))
)
ASM_FNC(CryptonightR_instruction34,
        IMUL(R(ebx), R(esi))
)
ASM_FNC(CryptonightR_instruction35,
        ADD(R(ebx), R(esi))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction36,
        SUB(R(ebx), R(esi))
)
ASM_FNC(CryptonightR_instruction37,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction38,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction39,
        XOR(R(ebx), R(esi))
)
ASM_FNC(CryptonightR_instruction40,
        IMUL(R(esi), R(esi))
)
ASM_FNC(CryptonightR_instruction41,
        IMUL(R(esi), R(esi))
)
ASM_FNC(CryptonightR_instruction42,
        IMUL(R(esi), R(esi))
)
ASM_FNC(CryptonightR_instruction43,
        ADD(R(esi), R(r9d))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction44,
        SUB(R(esi), R(r9d))
)
ASM_FNC(CryptonightR_instruction45,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction46,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction47,
        XOR(R(esi), R(r9d))
)
ASM_FNC(CryptonightR_instruction48,
        IMUL(R(edi), R(esi))
)
ASM_FNC(CryptonightR_instruction49,
        IMUL(R(edi), R(esi))
)
ASM_FNC(CryptonightR_instruction50,
        IMUL(R(edi), R(esi))
)
ASM_FNC(CryptonightR_instruction51,
        ADD(R(edi), R(esi))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction52,
        SUB(R(edi), R(esi))
)
ASM_FNC(CryptonightR_instruction53,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction54,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction55,
        XOR(R(edi), R(esi))
)
ASM_FNC(CryptonightR_instruction56,
        IMUL(R(ebp), R(esi))
)
ASM_FNC(CryptonightR_instruction57,
        IMUL(R(ebp), R(esi))
)
ASM_FNC(CryptonightR_instruction58,
        IMUL(R(ebp), R(esi))
)
ASM_FNC(CryptonightR_instruction59,
        ADD(R(ebp), R(esi))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction60,
        SUB(R(ebp), R(esi))
)
ASM_FNC(CryptonightR_instruction61,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction62,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction63,
        XOR(R(ebp), R(esi))
)
ASM_FNC(CryptonightR_instruction64,
        IMUL(R(ebx), R(edi))
)
ASM_FNC(CryptonightR_instruction65,
        IMUL(R(ebx), R(edi))
)
ASM_FNC(CryptonightR_instruction66,
        IMUL(R(ebx), R(edi))
)
ASM_FNC(CryptonightR_instruction67,
        ADD(R(ebx), R(edi))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction68,
        SUB(R(ebx), R(edi))
)
ASM_FNC(CryptonightR_instruction69,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction70,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction71,
        XOR(R(ebx), R(edi))
)
ASM_FNC(CryptonightR_instruction72,
        IMUL(R(esi), R(edi))
)
ASM_FNC(CryptonightR_instruction73,
        IMUL(R(esi), R(edi))
)
ASM_FNC(CryptonightR_instruction74,
        IMUL(R(esi), R(edi))
)
ASM_FNC(CryptonightR_instruction75,
        ADD(R(esi), R(edi))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction76,
        SUB(R(esi), R(edi))
)
ASM_FNC(CryptonightR_instruction77,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction78,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction79,
        XOR(R(esi), R(edi))
)
ASM_FNC(CryptonightR_instruction80,
        IMUL(R(edi), R(edi))
)
ASM_FNC(CryptonightR_instruction81,
        IMUL(R(edi), R(edi))
)
ASM_FNC(CryptonightR_instruction82,
        IMUL(R(edi), R(edi))
)
ASM_FNC(CryptonightR_instruction83,
        ADD(R(edi), R(r9d))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction84,
        SUB(R(edi), R(r9d))
)
ASM_FNC(CryptonightR_instruction85,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction86,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction87,
        XOR(R(edi), R(r9d))
)
ASM_FNC(CryptonightR_instruction88,
        IMUL(R(ebp), R(edi))
)
ASM_FNC(CryptonightR_instruction89,
        IMUL(R(ebp), R(edi))
)
ASM_FNC(CryptonightR_instruction90,
        IMUL(R(ebp), R(edi))
)
ASM_FNC(CryptonightR_instruction91,
        ADD(R(ebp), R(edi))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction92,
        SUB(R(ebp), R(edi))
)
ASM_FNC(CryptonightR_instruction93,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction94,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction95,
        XOR(R(ebp), R(edi))
)
ASM_FNC(CryptonightR_instruction96,
        IMUL(R(ebx), R(ebp))
)
ASM_FNC(CryptonightR_instruction97,
        IMUL(R(ebx), R(ebp))
)
ASM_FNC(CryptonightR_instruction98,
        IMUL(R(ebx), R(ebp))
)
ASM_FNC(CryptonightR_instruction99,
        ADD(R(ebx), R(ebp))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction100,
        SUB(R(ebx), R(ebp))
)
ASM_FNC(CryptonightR_instruction101,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction102,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction103,
        XOR(R(ebx), R(ebp))
)
ASM_FNC(CryptonightR_instruction104,
        IMUL(R(esi), R(ebp))
)
ASM_FNC(CryptonightR_instruction105,
        IMUL(R(esi), R(ebp))
)
ASM_FNC(CryptonightR_instruction106,
        IMUL(R(esi), R(ebp))
)
ASM_FNC(CryptonightR_instruction107,
        ADD(R(esi), R(ebp))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction108,
        SUB(R(esi), R(ebp))
)
ASM_FNC(CryptonightR_instruction109,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction110,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction111,
        XOR(R(esi), R(ebp))
)
ASM_FNC(CryptonightR_instruction112,
        IMUL(R(edi), R(ebp))
)
ASM_FNC(CryptonightR_instruction113,
        IMUL(R(edi), R(ebp))
)
ASM_FNC(CryptonightR_instruction114,
        IMUL(R(edi), R(ebp))
)
ASM_FNC(CryptonightR_instruction115,
        ADD(R(edi), R(ebp))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction116,
        SUB(R(edi), R(ebp))
)
ASM_FNC(CryptonightR_instruction117,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction118,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction119,
        XOR(R(edi), R(ebp))
)
ASM_FNC(CryptonightR_instruction120,
        IMUL(R(ebp), R(ebp))
)
ASM_FNC(CryptonightR_instruction121,
        IMUL(R(ebp), R(ebp))
)
ASM_FNC(CryptonightR_instruction122,
        IMUL(R(ebp), R(ebp))
)
ASM_FNC(CryptonightR_instruction123,
        ADD(R(ebp), R(r9d))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction124,
        SUB(R(ebp), R(r9d))
)
ASM_FNC(CryptonightR_instruction125,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction126,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction127,
        XOR(R(ebp), R(r9d))
)
ASM_FNC(CryptonightR_instruction128,
        IMUL(R(ebx), R(esp))
)
ASM_FNC(CryptonightR_instruction129,
        IMUL(R(ebx), R(esp))
)
ASM_FNC(CryptonightR_instruction130,
        IMUL(R(ebx), R(esp))
)
ASM_FNC(CryptonightR_instruction131,
        ADD(R(ebx), R(esp))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction132,
        SUB(R(ebx), R(esp))
)
ASM_FNC(CryptonightR_instruction133,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction134,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction135,
        XOR(R(ebx), R(esp))
)
ASM_FNC(CryptonightR_instruction136,
        IMUL(R(esi), R(esp))
)
ASM_FNC(CryptonightR_instruction137,
        IMUL(R(esi), R(esp))
)
ASM_FNC(CryptonightR_instruction138,
        IMUL(R(esi), R(esp))
)
ASM_FNC(CryptonightR_instruction139,
        ADD(R(esi), R(esp))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction140,
        SUB(R(esi), R(esp))
)
ASM_FNC(CryptonightR_instruction141,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction142,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction143,
        XOR(R(esi), R(esp))
)
ASM_FNC(CryptonightR_instruction144,
        IMUL(R(edi), R(esp))
)
ASM_FNC(CryptonightR_instruction145,
        IMUL(R(edi), R(esp))
)
ASM_FNC(CryptonightR_instruction146,
        IMUL(R(edi), R(esp))
)
ASM_FNC(CryptonightR_instruction147,
        ADD(R(edi), R(esp))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction148,
        SUB(R(edi), R(esp))
)
ASM_FNC(CryptonightR_instruction149,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction150,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction151,
        XOR(R(edi), R(esp))
)
ASM_FNC(CryptonightR_instruction152,
        IMUL(R(ebp), R(esp))
)
ASM_FNC(CryptonightR_instruction153,
        IMUL(R(ebp), R(esp))
)
ASM_FNC(CryptonightR_instruction154,
        IMUL(R(ebp), R(esp))
)
ASM_FNC(CryptonightR_instruction155,
        ADD(R(ebp), R(esp))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction156,
        SUB(R(ebp), R(esp))
)
ASM_FNC(CryptonightR_instruction157,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction158,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction159,
        XOR(R(ebp), R(esp))
)
ASM_FNC(CryptonightR_instruction160,
        IMUL(R(ebx), R(r15d))
)
ASM_FNC(CryptonightR_instruction161,
        IMUL(R(ebx), R(r15d))
)
ASM_FNC(CryptonightR_instruction162,
        IMUL(R(ebx), R(r15d))
)
ASM_FNC(CryptonightR_instruction163,
        ADD(R(ebx), R(r15d))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction164,
        SUB(R(ebx), R(r15d))
)
ASM_FNC(CryptonightR_instruction165,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction166,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction167,
        XOR(R(ebx), R(r15d))
)
ASM_FNC(CryptonightR_instruction168,
        IMUL(R(esi), R(r15d))
)
ASM_FNC(CryptonightR_instruction169,
        IMUL(R(esi), R(r15d))
)
ASM_FNC(CryptonightR_instruction170,
        IMUL(R(esi), R(r15d))
)
ASM_FNC(CryptonightR_instruction171,
        ADD(R(esi), R(r15d))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction172,
        SUB(R(esi), R(r15d))
)
ASM_FNC(CryptonightR_instruction173,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction174,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction175,
        XOR(R(esi), R(r15d))
)
ASM_FNC(CryptonightR_instruction176,
        IMUL(R(edi), R(r15d))
)
ASM_FNC(CryptonightR_instruction177,
        IMUL(R(edi), R(r15d))
)
ASM_FNC(CryptonightR_instruction178,
        IMUL(R(edi), R(r15d))
)
ASM_FNC(CryptonightR_instruction179,
        ADD(R(edi), R(r15d))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction180,
        SUB(R(edi), R(r15d))
)
ASM_FNC(CryptonightR_instruction181,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction182,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction183,
        XOR(R(edi), R(r15d))
)
ASM_FNC(CryptonightR_instruction184,
        IMUL(R(ebp), R(r15d))
)
ASM_FNC(CryptonightR_instruction185,
        IMUL(R(ebp), R(r15d))
)
ASM_FNC(CryptonightR_instruction186,
        IMUL(R(ebp), R(r15d))
)
ASM_FNC(CryptonightR_instruction187,
        ADD(R(ebp), R(r15d))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction188,
        SUB(R(ebp), R(r15d))
)
ASM_FNC(CryptonightR_instruction189,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction190,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction191,
        XOR(R(ebp), R(r15d))
)
ASM_FNC(CryptonightR_instruction192,
        IMUL(R(ebx), R(eax))
)
ASM_FNC(CryptonightR_instruction193,
        IMUL(R(ebx), R(eax))
)
ASM_FNC(CryptonightR_instruction194,
        IMUL(R(ebx), R(eax))
)
ASM_FNC(CryptonightR_instruction195,
        ADD(R(ebx), R(eax))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction196,
        SUB(R(ebx), R(eax))
)
ASM_FNC(CryptonightR_instruction197,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction198,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction199,
        XOR(R(ebx), R(eax))
)
ASM_FNC(CryptonightR_instruction200,
        IMUL(R(esi), R(eax))
)
ASM_FNC(CryptonightR_instruction201,
        IMUL(R(esi), R(eax))
)
ASM_FNC(CryptonightR_instruction202,
        IMUL(R(esi), R(eax))
)
ASM_FNC(CryptonightR_instruction203,
        ADD(R(esi), R(eax))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction204,
        SUB(R(esi), R(eax))
)
ASM_FNC(CryptonightR_instruction205,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction206,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction207,
        XOR(R(esi), R(eax))
)
ASM_FNC(CryptonightR_instruction208,
        IMUL(R(edi), R(eax))
)
ASM_FNC(CryptonightR_instruction209,
        IMUL(R(edi), R(eax))
)
ASM_FNC(CryptonightR_instruction210,
        IMUL(R(edi), R(eax))
)
ASM_FNC(CryptonightR_instruction211,
        ADD(R(edi), R(eax))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction212,
        SUB(R(edi), R(eax))
)
ASM_FNC(CryptonightR_instruction213,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction214,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction215,
        XOR(R(edi), R(eax))
)
ASM_FNC(CryptonightR_instruction216,
        IMUL(R(ebp), R(eax))
)
ASM_FNC(CryptonightR_instruction217,
        IMUL(R(ebp), R(eax))
)
ASM_FNC(CryptonightR_instruction218,
        IMUL(R(ebp), R(eax))
)
ASM_FNC(CryptonightR_instruction219,
        ADD(R(ebp), R(eax))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction220,
        SUB(R(ebp), R(eax))
)
ASM_FNC(CryptonightR_instruction221,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction222,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction223,
        XOR(R(ebp), R(eax))
)
ASM_FNC(CryptonightR_instruction224,
        IMUL(R(ebx), R(edx))
)
ASM_FNC(CryptonightR_instruction225,
        IMUL(R(ebx), R(edx))
)
ASM_FNC(CryptonightR_instruction226,
        IMUL(R(ebx), R(edx))
)
ASM_FNC(CryptonightR_instruction227,
        ADD(R(ebx), R(edx))
            ADD(R(ebx), C(2147483647))
)
ASM_FNC(CryptonightR_instruction228,
        SUB(R(ebx), R(edx))
)
ASM_FNC(CryptonightR_instruction229,
        ROR(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction230,
        ROL(R(ebx), R(cl))
)
ASM_FNC(CryptonightR_instruction231,
        XOR(R(ebx), R(edx))
)
ASM_FNC(CryptonightR_instruction232,
        IMUL(R(esi), R(edx))
)
ASM_FNC(CryptonightR_instruction233,
        IMUL(R(esi), R(edx))
)
ASM_FNC(CryptonightR_instruction234,
        IMUL(R(esi), R(edx))
)
ASM_FNC(CryptonightR_instruction235,
        ADD(R(esi), R(edx))
            ADD(R(esi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction236,
        SUB(R(esi), R(edx))
)
ASM_FNC(CryptonightR_instruction237,
        ROR(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction238,
        ROL(R(esi), R(cl))
)
ASM_FNC(CryptonightR_instruction239,
        XOR(R(esi), R(edx))
)
ASM_FNC(CryptonightR_instruction240,
        IMUL(R(edi), R(edx))
)
ASM_FNC(CryptonightR_instruction241,
        IMUL(R(edi), R(edx))
)
ASM_FNC(CryptonightR_instruction242,
        IMUL(R(edi), R(edx))
)
ASM_FNC(CryptonightR_instruction243,
        ADD(R(edi), R(edx))
            ADD(R(edi), C(2147483647))
)
ASM_FNC(CryptonightR_instruction244,
        SUB(R(edi), R(edx))
)
ASM_FNC(CryptonightR_instruction245,
        ROR(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction246,
        ROL(R(edi), R(cl))
)
ASM_FNC(CryptonightR_instruction247,
        XOR(R(edi), R(edx))
)
ASM_FNC(CryptonightR_instruction248,
        IMUL(R(ebp), R(edx))
)
ASM_FNC(CryptonightR_instruction249,
        IMUL(R(ebp), R(edx))
)
ASM_FNC(CryptonightR_instruction250,
        IMUL(R(ebp), R(edx))
)
ASM_FNC(CryptonightR_instruction251,
        ADD(R(ebp), R(edx))
            ADD(R(ebp), C(2147483647))
)
ASM_FNC(CryptonightR_instruction252,
        SUB(R(ebp), R(edx))
)
ASM_FNC(CryptonightR_instruction253,
        ROR(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction254,
        ROL(R(ebp), R(cl))
)
ASM_FNC(CryptonightR_instruction255,
        XOR(R(ebp), R(edx))
)
ASM_FNC(CryptonightR_instruction256,
        IMUL(R(ebx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov0,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov1,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov2,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov3,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov4,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov5,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov6,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov7,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov8,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov9,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov10,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov11,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov12,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov13,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov14,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov15,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov16,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov17,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov18,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov19,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov20,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov21,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov22,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov23,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov24,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov25,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov26,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov27,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov28,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov29,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov30,
        MOV(R(ecx), R(ebx))
)
ASM_FNC(CryptonightR_instruction_mov31,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov32,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov33,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov34,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov35,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov36,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov37,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov38,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov39,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov40,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov41,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov42,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov43,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov44,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov45,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov46,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov47,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov48,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov49,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov50,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov51,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov52,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov53,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov54,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov55,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov56,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov57,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov58,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov59,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov60,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov61,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov62,
        MOV(R(ecx), R(esi))
)
ASM_FNC(CryptonightR_instruction_mov63,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov64,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov65,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov66,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov67,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov68,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov69,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov70,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov71,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov72,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov73,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov74,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov75,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov76,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov77,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov78,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov79,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov80,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov81,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov82,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov83,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov84,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov85,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov86,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov87,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov88,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov89,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov90,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov91,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov92,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov93,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov94,
        MOV(R(ecx), R(edi))
)
ASM_FNC(CryptonightR_instruction_mov95,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov96,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov97,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov98,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov99,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov100,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov101,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov102,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov103,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov104,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov105,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov106,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov107,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov108,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov109,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov110,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov111,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov112,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov113,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov114,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov115,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov116,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov117,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov118,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov119,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov120,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov121,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov122,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov123,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov124,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov125,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov126,
        MOV(R(ecx), R(ebp))
)
ASM_FNC(CryptonightR_instruction_mov127,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov128,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov129,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov130,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov131,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov132,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov133,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov134,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov135,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov136,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov137,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov138,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov139,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov140,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov141,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov142,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov143,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov144,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov145,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov146,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov147,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov148,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov149,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov150,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov151,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov152,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov153,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov154,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov155,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov156,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov157,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov158,
        MOV(R(ecx), R(esp))
)
ASM_FNC(CryptonightR_instruction_mov159,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov160,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov161,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov162,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov163,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov164,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov165,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov166,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov167,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov168,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov169,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov170,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov171,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov172,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov173,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov174,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov175,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov176,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov177,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov178,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov179,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov180,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov181,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov182,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov183,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov184,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov185,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov186,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov187,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov188,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov189,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov190,
        MOV(R(ecx), R(r15d))
)
ASM_FNC(CryptonightR_instruction_mov191,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov192,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov193,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov194,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov195,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov196,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov197,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov198,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov199,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov200,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov201,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov202,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov203,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov204,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov205,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov206,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov207,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov208,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov209,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov210,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov211,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov212,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov213,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov214,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov215,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov216,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov217,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov218,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov219,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov220,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov221,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov222,
        MOV(R(ecx), R(eax))
)
ASM_FNC(CryptonightR_instruction_mov223,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov224,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov225,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov226,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov227,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov228,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov229,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov230,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov231,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov232,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov233,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov234,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov235,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov236,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov237,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov238,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov239,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov240,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov241,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov242,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov243,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov244,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov245,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov246,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov247,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov248,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov249,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov250,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov251,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov252,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov253,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov254,
        MOV(R(ecx), R(edx))
)
ASM_FNC(CryptonightR_instruction_mov255,
        NOP()
)
ASM_FNC(CryptonightR_instruction_mov256,
        NOP()
)

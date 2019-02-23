// This file was generated from CryptonightR_template.S
// I don't see an easy way to compile python extension with .S file.
// gcc would do it like this: gcc -c file.S -o file.o
// However, distutils support many different compilers, some of them do not have .S option (maybe).
//
// JIT is not tested thus the default compilation setting should be -DNO_JIT=1
// https://stackoverflow.com/questions/61341/is-there-a-way-to-insert-assembly-code-into-c


#if defined(NO_JIT) || !defined(__x86_64__)

// ASM disabled - safe option
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

#elif defined(__INTEL_COMPILER)
#define ASM __asm__
#elif !defined(_MSC_VER)
#define ASM __asm__
#define ASM_B ASM(
#define ASM_E );

#define R(x) "%"#x
#define C(x) "$"#x

#define IMUL(a, b) "imul "b", "a"\n\t"
#define ADD(a, b) "add "b", "a"\n\t"
#define SUB(a, b) "sub "b", "a"\n\t"
#define ROR(a, b) "ror "b", "a"\n\t"
#define ROL(a, b) "rol "b", "a"\n\t"
#define XOR(a, b) "xor "b", "a"\n\t"
#define MOV(a, b) "mov "b", "a"\n\t"

#else

#define ASM __asm
#define ASM_B ASM {
#define ASM_E }
#define R(x) x
#define C(x) x

#define IMUL(a, b) imul a, b
#define ADD(a, b) add a, b
#define SUB(a, b) sub a, b
#define ROR(a, b) ror a, b
#define ROL(a, b) rol a, b
#define XOR(a, b) xor a, b
#define MOV(a, b) mov a, b

#endif

void CryptonightR_instruction0(void){
  ASM_B
  IMUL(R(ebx), R(ebx))
  ASM_E
}

void CryptonightR_instruction1(void){
  ASM_B
  IMUL(R(ebx), R(ebx))
  ASM_E
}

void CryptonightR_instruction2(void){
  ASM_B
  IMUL(R(ebx), R(ebx))
  ASM_E
}

void CryptonightR_instruction3(void){
  ASM_B
  ADD(R(ebx), R(r9d))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction4(void){
  ASM_B
  SUB(R(ebx), R(r9d))
  ASM_E
}

void CryptonightR_instruction5(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction6(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction7(void){
  ASM_B
  XOR(R(ebx), R(r9d))
  ASM_E
}

void CryptonightR_instruction8(void){
  ASM_B
  IMUL(R(esi), R(ebx))
  ASM_E
}

void CryptonightR_instruction9(void){
  ASM_B
  IMUL(R(esi), R(ebx))
  ASM_E
}

void CryptonightR_instruction10(void){
  ASM_B
  IMUL(R(esi), R(ebx))
  ASM_E
}

void CryptonightR_instruction11(void){
  ASM_B
  ADD(R(esi), R(ebx))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction12(void){
  ASM_B
  SUB(R(esi), R(ebx))
  ASM_E
}

void CryptonightR_instruction13(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction14(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction15(void){
  ASM_B
  XOR(R(esi), R(ebx))
  ASM_E
}

void CryptonightR_instruction16(void){
  ASM_B
  IMUL(R(edi), R(ebx))
  ASM_E
}

void CryptonightR_instruction17(void){
  ASM_B
  IMUL(R(edi), R(ebx))
  ASM_E
}

void CryptonightR_instruction18(void){
  ASM_B
  IMUL(R(edi), R(ebx))
  ASM_E
}

void CryptonightR_instruction19(void){
  ASM_B
  ADD(R(edi), R(ebx))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction20(void){
  ASM_B
  SUB(R(edi), R(ebx))
  ASM_E
}

void CryptonightR_instruction21(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction22(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction23(void){
  ASM_B
  XOR(R(edi), R(ebx))
  ASM_E
}

void CryptonightR_instruction24(void){
  ASM_B
  IMUL(R(ebp), R(ebx))
  ASM_E
}

void CryptonightR_instruction25(void){
  ASM_B
  IMUL(R(ebp), R(ebx))
  ASM_E
}

void CryptonightR_instruction26(void){
  ASM_B
  IMUL(R(ebp), R(ebx))
  ASM_E
}

void CryptonightR_instruction27(void){
  ASM_B
  ADD(R(ebp), R(ebx))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction28(void){
  ASM_B
  SUB(R(ebp), R(ebx))
  ASM_E
}

void CryptonightR_instruction29(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction30(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction31(void){
  ASM_B
  XOR(R(ebp), R(ebx))
  ASM_E
}

void CryptonightR_instruction32(void){
  ASM_B
  IMUL(R(ebx), R(esi))
  ASM_E
}

void CryptonightR_instruction33(void){
  ASM_B
  IMUL(R(ebx), R(esi))
  ASM_E
}

void CryptonightR_instruction34(void){
  ASM_B
  IMUL(R(ebx), R(esi))
  ASM_E
}

void CryptonightR_instruction35(void){
  ASM_B
  ADD(R(ebx), R(esi))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction36(void){
  ASM_B
  SUB(R(ebx), R(esi))
  ASM_E
}

void CryptonightR_instruction37(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction38(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction39(void){
  ASM_B
  XOR(R(ebx), R(esi))
  ASM_E
}

void CryptonightR_instruction40(void){
  ASM_B
  IMUL(R(esi), R(esi))
  ASM_E
}

void CryptonightR_instruction41(void){
  ASM_B
  IMUL(R(esi), R(esi))
  ASM_E
}

void CryptonightR_instruction42(void){
  ASM_B
  IMUL(R(esi), R(esi))
  ASM_E
}

void CryptonightR_instruction43(void){
  ASM_B
  ADD(R(esi), R(r9d))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction44(void){
  ASM_B
  SUB(R(esi), R(r9d))
  ASM_E
}

void CryptonightR_instruction45(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction46(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction47(void){
  ASM_B
  XOR(R(esi), R(r9d))
  ASM_E
}

void CryptonightR_instruction48(void){
  ASM_B
  IMUL(R(edi), R(esi))
  ASM_E
}

void CryptonightR_instruction49(void){
  ASM_B
  IMUL(R(edi), R(esi))
  ASM_E
}

void CryptonightR_instruction50(void){
  ASM_B
  IMUL(R(edi), R(esi))
  ASM_E
}

void CryptonightR_instruction51(void){
  ASM_B
  ADD(R(edi), R(esi))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction52(void){
  ASM_B
  SUB(R(edi), R(esi))
  ASM_E
}

void CryptonightR_instruction53(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction54(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction55(void){
  ASM_B
  XOR(R(edi), R(esi))
  ASM_E
}

void CryptonightR_instruction56(void){
  ASM_B
  IMUL(R(ebp), R(esi))
  ASM_E
}

void CryptonightR_instruction57(void){
  ASM_B
  IMUL(R(ebp), R(esi))
  ASM_E
}

void CryptonightR_instruction58(void){
  ASM_B
  IMUL(R(ebp), R(esi))
  ASM_E
}

void CryptonightR_instruction59(void){
  ASM_B
  ADD(R(ebp), R(esi))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction60(void){
  ASM_B
  SUB(R(ebp), R(esi))
  ASM_E
}

void CryptonightR_instruction61(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction62(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction63(void){
  ASM_B
  XOR(R(ebp), R(esi))
  ASM_E
}

void CryptonightR_instruction64(void){
  ASM_B
  IMUL(R(ebx), R(edi))
  ASM_E
}

void CryptonightR_instruction65(void){
  ASM_B
  IMUL(R(ebx), R(edi))
  ASM_E
}

void CryptonightR_instruction66(void){
  ASM_B
  IMUL(R(ebx), R(edi))
  ASM_E
}

void CryptonightR_instruction67(void){
  ASM_B
  ADD(R(ebx), R(edi))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction68(void){
  ASM_B
  SUB(R(ebx), R(edi))
  ASM_E
}

void CryptonightR_instruction69(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction70(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction71(void){
  ASM_B
  XOR(R(ebx), R(edi))
  ASM_E
}

void CryptonightR_instruction72(void){
  ASM_B
  IMUL(R(esi), R(edi))
  ASM_E
}

void CryptonightR_instruction73(void){
  ASM_B
  IMUL(R(esi), R(edi))
  ASM_E
}

void CryptonightR_instruction74(void){
  ASM_B
  IMUL(R(esi), R(edi))
  ASM_E
}

void CryptonightR_instruction75(void){
  ASM_B
  ADD(R(esi), R(edi))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction76(void){
  ASM_B
  SUB(R(esi), R(edi))
  ASM_E
}

void CryptonightR_instruction77(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction78(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction79(void){
  ASM_B
  XOR(R(esi), R(edi))
  ASM_E
}

void CryptonightR_instruction80(void){
  ASM_B
  IMUL(R(edi), R(edi))
  ASM_E
}

void CryptonightR_instruction81(void){
  ASM_B
  IMUL(R(edi), R(edi))
  ASM_E
}

void CryptonightR_instruction82(void){
  ASM_B
  IMUL(R(edi), R(edi))
  ASM_E
}

void CryptonightR_instruction83(void){
  ASM_B
  ADD(R(edi), R(r9d))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction84(void){
  ASM_B
  SUB(R(edi), R(r9d))
  ASM_E
}

void CryptonightR_instruction85(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction86(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction87(void){
  ASM_B
  XOR(R(edi), R(r9d))
  ASM_E
}

void CryptonightR_instruction88(void){
  ASM_B
  IMUL(R(ebp), R(edi))
  ASM_E
}

void CryptonightR_instruction89(void){
  ASM_B
  IMUL(R(ebp), R(edi))
  ASM_E
}

void CryptonightR_instruction90(void){
  ASM_B
  IMUL(R(ebp), R(edi))
  ASM_E
}

void CryptonightR_instruction91(void){
  ASM_B
  ADD(R(ebp), R(edi))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction92(void){
  ASM_B
  SUB(R(ebp), R(edi))
  ASM_E
}

void CryptonightR_instruction93(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction94(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction95(void){
  ASM_B
  XOR(R(ebp), R(edi))
  ASM_E
}

void CryptonightR_instruction96(void){
  ASM_B
  IMUL(R(ebx), R(ebp))
  ASM_E
}

void CryptonightR_instruction97(void){
  ASM_B
  IMUL(R(ebx), R(ebp))
  ASM_E
}

void CryptonightR_instruction98(void){
  ASM_B
  IMUL(R(ebx), R(ebp))
  ASM_E
}

void CryptonightR_instruction99(void){
  ASM_B
  ADD(R(ebx), R(ebp))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction100(void){
  ASM_B
  SUB(R(ebx), R(ebp))
  ASM_E
}

void CryptonightR_instruction101(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction102(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction103(void){
  ASM_B
  XOR(R(ebx), R(ebp))
  ASM_E
}

void CryptonightR_instruction104(void){
  ASM_B
  IMUL(R(esi), R(ebp))
  ASM_E
}

void CryptonightR_instruction105(void){
  ASM_B
  IMUL(R(esi), R(ebp))
  ASM_E
}

void CryptonightR_instruction106(void){
  ASM_B
  IMUL(R(esi), R(ebp))
  ASM_E
}

void CryptonightR_instruction107(void){
  ASM_B
  ADD(R(esi), R(ebp))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction108(void){
  ASM_B
  SUB(R(esi), R(ebp))
  ASM_E
}

void CryptonightR_instruction109(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction110(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction111(void){
  ASM_B
  XOR(R(esi), R(ebp))
  ASM_E
}

void CryptonightR_instruction112(void){
  ASM_B
  IMUL(R(edi), R(ebp))
  ASM_E
}

void CryptonightR_instruction113(void){
  ASM_B
  IMUL(R(edi), R(ebp))
  ASM_E
}

void CryptonightR_instruction114(void){
  ASM_B
  IMUL(R(edi), R(ebp))
  ASM_E
}

void CryptonightR_instruction115(void){
  ASM_B
  ADD(R(edi), R(ebp))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction116(void){
  ASM_B
  SUB(R(edi), R(ebp))
  ASM_E
}

void CryptonightR_instruction117(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction118(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction119(void){
  ASM_B
  XOR(R(edi), R(ebp))
  ASM_E
}

void CryptonightR_instruction120(void){
  ASM_B
  IMUL(R(ebp), R(ebp))
  ASM_E
}

void CryptonightR_instruction121(void){
  ASM_B
  IMUL(R(ebp), R(ebp))
  ASM_E
}

void CryptonightR_instruction122(void){
  ASM_B
  IMUL(R(ebp), R(ebp))
  ASM_E
}

void CryptonightR_instruction123(void){
  ASM_B
  ADD(R(ebp), R(r9d))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction124(void){
  ASM_B
  SUB(R(ebp), R(r9d))
  ASM_E
}

void CryptonightR_instruction125(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction126(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction127(void){
  ASM_B
  XOR(R(ebp), R(r9d))
  ASM_E
}

void CryptonightR_instruction128(void){
  ASM_B
  IMUL(R(ebx), R(esp))
  ASM_E
}

void CryptonightR_instruction129(void){
  ASM_B
  IMUL(R(ebx), R(esp))
  ASM_E
}

void CryptonightR_instruction130(void){
  ASM_B
  IMUL(R(ebx), R(esp))
  ASM_E
}

void CryptonightR_instruction131(void){
  ASM_B
  ADD(R(ebx), R(esp))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction132(void){
  ASM_B
  SUB(R(ebx), R(esp))
  ASM_E
}

void CryptonightR_instruction133(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction134(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction135(void){
  ASM_B
  XOR(R(ebx), R(esp))
  ASM_E
}

void CryptonightR_instruction136(void){
  ASM_B
  IMUL(R(esi), R(esp))
  ASM_E
}

void CryptonightR_instruction137(void){
  ASM_B
  IMUL(R(esi), R(esp))
  ASM_E
}

void CryptonightR_instruction138(void){
  ASM_B
  IMUL(R(esi), R(esp))
  ASM_E
}

void CryptonightR_instruction139(void){
  ASM_B
  ADD(R(esi), R(esp))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction140(void){
  ASM_B
  SUB(R(esi), R(esp))
  ASM_E
}

void CryptonightR_instruction141(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction142(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction143(void){
  ASM_B
  XOR(R(esi), R(esp))
  ASM_E
}

void CryptonightR_instruction144(void){
  ASM_B
  IMUL(R(edi), R(esp))
  ASM_E
}

void CryptonightR_instruction145(void){
  ASM_B
  IMUL(R(edi), R(esp))
  ASM_E
}

void CryptonightR_instruction146(void){
  ASM_B
  IMUL(R(edi), R(esp))
  ASM_E
}

void CryptonightR_instruction147(void){
  ASM_B
  ADD(R(edi), R(esp))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction148(void){
  ASM_B
  SUB(R(edi), R(esp))
  ASM_E
}

void CryptonightR_instruction149(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction150(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction151(void){
  ASM_B
  XOR(R(edi), R(esp))
  ASM_E
}

void CryptonightR_instruction152(void){
  ASM_B
  IMUL(R(ebp), R(esp))
  ASM_E
}

void CryptonightR_instruction153(void){
  ASM_B
  IMUL(R(ebp), R(esp))
  ASM_E
}

void CryptonightR_instruction154(void){
  ASM_B
  IMUL(R(ebp), R(esp))
  ASM_E
}

void CryptonightR_instruction155(void){
  ASM_B
  ADD(R(ebp), R(esp))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction156(void){
  ASM_B
  SUB(R(ebp), R(esp))
  ASM_E
}

void CryptonightR_instruction157(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction158(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction159(void){
  ASM_B
  XOR(R(ebp), R(esp))
  ASM_E
}

void CryptonightR_instruction160(void){
  ASM_B
  IMUL(R(ebx), R(r15d))
  ASM_E
}

void CryptonightR_instruction161(void){
  ASM_B
  IMUL(R(ebx), R(r15d))
  ASM_E
}

void CryptonightR_instruction162(void){
  ASM_B
  IMUL(R(ebx), R(r15d))
  ASM_E
}

void CryptonightR_instruction163(void){
  ASM_B
  ADD(R(ebx), R(r15d))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction164(void){
  ASM_B
  SUB(R(ebx), R(r15d))
  ASM_E
}

void CryptonightR_instruction165(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction166(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction167(void){
  ASM_B
  XOR(R(ebx), R(r15d))
  ASM_E
}

void CryptonightR_instruction168(void){
  ASM_B
  IMUL(R(esi), R(r15d))
  ASM_E
}

void CryptonightR_instruction169(void){
  ASM_B
  IMUL(R(esi), R(r15d))
  ASM_E
}

void CryptonightR_instruction170(void){
  ASM_B
  IMUL(R(esi), R(r15d))
  ASM_E
}

void CryptonightR_instruction171(void){
  ASM_B
  ADD(R(esi), R(r15d))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction172(void){
  ASM_B
  SUB(R(esi), R(r15d))
  ASM_E
}

void CryptonightR_instruction173(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction174(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction175(void){
  ASM_B
  XOR(R(esi), R(r15d))
  ASM_E
}

void CryptonightR_instruction176(void){
  ASM_B
  IMUL(R(edi), R(r15d))
  ASM_E
}

void CryptonightR_instruction177(void){
  ASM_B
  IMUL(R(edi), R(r15d))
  ASM_E
}

void CryptonightR_instruction178(void){
  ASM_B
  IMUL(R(edi), R(r15d))
  ASM_E
}

void CryptonightR_instruction179(void){
  ASM_B
  ADD(R(edi), R(r15d))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction180(void){
  ASM_B
  SUB(R(edi), R(r15d))
  ASM_E
}

void CryptonightR_instruction181(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction182(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction183(void){
  ASM_B
  XOR(R(edi), R(r15d))
  ASM_E
}

void CryptonightR_instruction184(void){
  ASM_B
  IMUL(R(ebp), R(r15d))
  ASM_E
}

void CryptonightR_instruction185(void){
  ASM_B
  IMUL(R(ebp), R(r15d))
  ASM_E
}

void CryptonightR_instruction186(void){
  ASM_B
  IMUL(R(ebp), R(r15d))
  ASM_E
}

void CryptonightR_instruction187(void){
  ASM_B
  ADD(R(ebp), R(r15d))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction188(void){
  ASM_B
  SUB(R(ebp), R(r15d))
  ASM_E
}

void CryptonightR_instruction189(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction190(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction191(void){
  ASM_B
  XOR(R(ebp), R(r15d))
  ASM_E
}

void CryptonightR_instruction192(void){
  ASM_B
  IMUL(R(ebx), R(eax))
  ASM_E
}

void CryptonightR_instruction193(void){
  ASM_B
  IMUL(R(ebx), R(eax))
  ASM_E
}

void CryptonightR_instruction194(void){
  ASM_B
  IMUL(R(ebx), R(eax))
  ASM_E
}

void CryptonightR_instruction195(void){
  ASM_B
  ADD(R(ebx), R(eax))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction196(void){
  ASM_B
  SUB(R(ebx), R(eax))
  ASM_E
}

void CryptonightR_instruction197(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction198(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction199(void){
  ASM_B
  XOR(R(ebx), R(eax))
  ASM_E
}

void CryptonightR_instruction200(void){
  ASM_B
  IMUL(R(esi), R(eax))
  ASM_E
}

void CryptonightR_instruction201(void){
  ASM_B
  IMUL(R(esi), R(eax))
  ASM_E
}

void CryptonightR_instruction202(void){
  ASM_B
  IMUL(R(esi), R(eax))
  ASM_E
}

void CryptonightR_instruction203(void){
  ASM_B
  ADD(R(esi), R(eax))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction204(void){
  ASM_B
  SUB(R(esi), R(eax))
  ASM_E
}

void CryptonightR_instruction205(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction206(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction207(void){
  ASM_B
  XOR(R(esi), R(eax))
  ASM_E
}

void CryptonightR_instruction208(void){
  ASM_B
  IMUL(R(edi), R(eax))
  ASM_E
}

void CryptonightR_instruction209(void){
  ASM_B
  IMUL(R(edi), R(eax))
  ASM_E
}

void CryptonightR_instruction210(void){
  ASM_B
  IMUL(R(edi), R(eax))
  ASM_E
}

void CryptonightR_instruction211(void){
  ASM_B
  ADD(R(edi), R(eax))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction212(void){
  ASM_B
  SUB(R(edi), R(eax))
  ASM_E
}

void CryptonightR_instruction213(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction214(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction215(void){
  ASM_B
  XOR(R(edi), R(eax))
  ASM_E
}

void CryptonightR_instruction216(void){
  ASM_B
  IMUL(R(ebp), R(eax))
  ASM_E
}

void CryptonightR_instruction217(void){
  ASM_B
  IMUL(R(ebp), R(eax))
  ASM_E
}

void CryptonightR_instruction218(void){
  ASM_B
  IMUL(R(ebp), R(eax))
  ASM_E
}

void CryptonightR_instruction219(void){
  ASM_B
  ADD(R(ebp), R(eax))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction220(void){
  ASM_B
  SUB(R(ebp), R(eax))
  ASM_E
}

void CryptonightR_instruction221(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction222(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction223(void){
  ASM_B
  XOR(R(ebp), R(eax))
  ASM_E
}

void CryptonightR_instruction224(void){
  ASM_B
  IMUL(R(ebx), R(edx))
  ASM_E
}

void CryptonightR_instruction225(void){
  ASM_B
  IMUL(R(ebx), R(edx))
  ASM_E
}

void CryptonightR_instruction226(void){
  ASM_B
  IMUL(R(ebx), R(edx))
  ASM_E
}

void CryptonightR_instruction227(void){
  ASM_B
  ADD(R(ebx), R(edx))
  ADD(R(ebx), C(2147483647))
  ASM_E
}

void CryptonightR_instruction228(void){
  ASM_B
  SUB(R(ebx), R(edx))
  ASM_E
}

void CryptonightR_instruction229(void){
  ASM_B
  ROR(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction230(void){
  ASM_B
  ROL(R(ebx), R(cl))
  ASM_E
}

void CryptonightR_instruction231(void){
  ASM_B
  XOR(R(ebx), R(edx))
  ASM_E
}

void CryptonightR_instruction232(void){
  ASM_B
  IMUL(R(esi), R(edx))
  ASM_E
}

void CryptonightR_instruction233(void){
  ASM_B
  IMUL(R(esi), R(edx))
  ASM_E
}

void CryptonightR_instruction234(void){
  ASM_B
  IMUL(R(esi), R(edx))
  ASM_E
}

void CryptonightR_instruction235(void){
  ASM_B
  ADD(R(esi), R(edx))
  ADD(R(esi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction236(void){
  ASM_B
  SUB(R(esi), R(edx))
  ASM_E
}

void CryptonightR_instruction237(void){
  ASM_B
  ROR(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction238(void){
  ASM_B
  ROL(R(esi), R(cl))
  ASM_E
}

void CryptonightR_instruction239(void){
  ASM_B
  XOR(R(esi), R(edx))
  ASM_E
}

void CryptonightR_instruction240(void){
  ASM_B
  IMUL(R(edi), R(edx))
  ASM_E
}

void CryptonightR_instruction241(void){
  ASM_B
  IMUL(R(edi), R(edx))
  ASM_E
}

void CryptonightR_instruction242(void){
  ASM_B
  IMUL(R(edi), R(edx))
  ASM_E
}

void CryptonightR_instruction243(void){
  ASM_B
  ADD(R(edi), R(edx))
  ADD(R(edi), C(2147483647))
  ASM_E
}

void CryptonightR_instruction244(void){
  ASM_B
  SUB(R(edi), R(edx))
  ASM_E
}

void CryptonightR_instruction245(void){
  ASM_B
  ROR(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction246(void){
  ASM_B
  ROL(R(edi), R(cl))
  ASM_E
}

void CryptonightR_instruction247(void){
  ASM_B
  XOR(R(edi), R(edx))
  ASM_E
}

void CryptonightR_instruction248(void){
  ASM_B
  IMUL(R(ebp), R(edx))
  ASM_E
}

void CryptonightR_instruction249(void){
  ASM_B
  IMUL(R(ebp), R(edx))
  ASM_E
}

void CryptonightR_instruction250(void){
  ASM_B
  IMUL(R(ebp), R(edx))
  ASM_E
}

void CryptonightR_instruction251(void){
  ASM_B
  ADD(R(ebp), R(edx))
  ADD(R(ebp), C(2147483647))
  ASM_E
}

void CryptonightR_instruction252(void){
  ASM_B
  SUB(R(ebp), R(edx))
  ASM_E
}

void CryptonightR_instruction253(void){
  ASM_B
  ROR(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction254(void){
  ASM_B
  ROL(R(ebp), R(cl))
  ASM_E
}

void CryptonightR_instruction255(void){
  ASM_B
  XOR(R(ebp), R(edx))
  ASM_E
}

void CryptonightR_instruction256(void){
  ASM_B
  IMUL(R(ebx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov0(void){
}

void CryptonightR_instruction_mov1(void){
}

void CryptonightR_instruction_mov2(void){
}

void CryptonightR_instruction_mov3(void){
}

void CryptonightR_instruction_mov4(void){
}

void CryptonightR_instruction_mov5(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov6(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov7(void){
}

void CryptonightR_instruction_mov8(void){
}

void CryptonightR_instruction_mov9(void){
}

void CryptonightR_instruction_mov10(void){
}

void CryptonightR_instruction_mov11(void){
}

void CryptonightR_instruction_mov12(void){
}

void CryptonightR_instruction_mov13(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov14(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov15(void){
}

void CryptonightR_instruction_mov16(void){
}

void CryptonightR_instruction_mov17(void){
}

void CryptonightR_instruction_mov18(void){
}

void CryptonightR_instruction_mov19(void){
}

void CryptonightR_instruction_mov20(void){
}

void CryptonightR_instruction_mov21(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov22(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov23(void){
}

void CryptonightR_instruction_mov24(void){
}

void CryptonightR_instruction_mov25(void){
}

void CryptonightR_instruction_mov26(void){
}

void CryptonightR_instruction_mov27(void){
}

void CryptonightR_instruction_mov28(void){
}

void CryptonightR_instruction_mov29(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov30(void){
  ASM_B
  MOV(R(ecx), R(ebx))
  ASM_E
}

void CryptonightR_instruction_mov31(void){
}

void CryptonightR_instruction_mov32(void){
}

void CryptonightR_instruction_mov33(void){
}

void CryptonightR_instruction_mov34(void){
}

void CryptonightR_instruction_mov35(void){
}

void CryptonightR_instruction_mov36(void){
}

void CryptonightR_instruction_mov37(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov38(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov39(void){
}

void CryptonightR_instruction_mov40(void){
}

void CryptonightR_instruction_mov41(void){
}

void CryptonightR_instruction_mov42(void){
}

void CryptonightR_instruction_mov43(void){
}

void CryptonightR_instruction_mov44(void){
}

void CryptonightR_instruction_mov45(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov46(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov47(void){
}

void CryptonightR_instruction_mov48(void){
}

void CryptonightR_instruction_mov49(void){
}

void CryptonightR_instruction_mov50(void){
}

void CryptonightR_instruction_mov51(void){
}

void CryptonightR_instruction_mov52(void){
}

void CryptonightR_instruction_mov53(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov54(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov55(void){
}

void CryptonightR_instruction_mov56(void){
}

void CryptonightR_instruction_mov57(void){
}

void CryptonightR_instruction_mov58(void){
}

void CryptonightR_instruction_mov59(void){
}

void CryptonightR_instruction_mov60(void){
}

void CryptonightR_instruction_mov61(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov62(void){
  ASM_B
  MOV(R(ecx), R(esi))
  ASM_E
}

void CryptonightR_instruction_mov63(void){
}

void CryptonightR_instruction_mov64(void){
}

void CryptonightR_instruction_mov65(void){
}

void CryptonightR_instruction_mov66(void){
}

void CryptonightR_instruction_mov67(void){
}

void CryptonightR_instruction_mov68(void){
}

void CryptonightR_instruction_mov69(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov70(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov71(void){
}

void CryptonightR_instruction_mov72(void){
}

void CryptonightR_instruction_mov73(void){
}

void CryptonightR_instruction_mov74(void){
}

void CryptonightR_instruction_mov75(void){
}

void CryptonightR_instruction_mov76(void){
}

void CryptonightR_instruction_mov77(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov78(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov79(void){
}

void CryptonightR_instruction_mov80(void){
}

void CryptonightR_instruction_mov81(void){
}

void CryptonightR_instruction_mov82(void){
}

void CryptonightR_instruction_mov83(void){
}

void CryptonightR_instruction_mov84(void){
}

void CryptonightR_instruction_mov85(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov86(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov87(void){
}

void CryptonightR_instruction_mov88(void){
}

void CryptonightR_instruction_mov89(void){
}

void CryptonightR_instruction_mov90(void){
}

void CryptonightR_instruction_mov91(void){
}

void CryptonightR_instruction_mov92(void){
}

void CryptonightR_instruction_mov93(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov94(void){
  ASM_B
  MOV(R(ecx), R(edi))
  ASM_E
}

void CryptonightR_instruction_mov95(void){
}

void CryptonightR_instruction_mov96(void){
}

void CryptonightR_instruction_mov97(void){
}

void CryptonightR_instruction_mov98(void){
}

void CryptonightR_instruction_mov99(void){
}

void CryptonightR_instruction_mov100(void){
}

void CryptonightR_instruction_mov101(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov102(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov103(void){
}

void CryptonightR_instruction_mov104(void){
}

void CryptonightR_instruction_mov105(void){
}

void CryptonightR_instruction_mov106(void){
}

void CryptonightR_instruction_mov107(void){
}

void CryptonightR_instruction_mov108(void){
}

void CryptonightR_instruction_mov109(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov110(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov111(void){
}

void CryptonightR_instruction_mov112(void){
}

void CryptonightR_instruction_mov113(void){
}

void CryptonightR_instruction_mov114(void){
}

void CryptonightR_instruction_mov115(void){
}

void CryptonightR_instruction_mov116(void){
}

void CryptonightR_instruction_mov117(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov118(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov119(void){
}

void CryptonightR_instruction_mov120(void){
}

void CryptonightR_instruction_mov121(void){
}

void CryptonightR_instruction_mov122(void){
}

void CryptonightR_instruction_mov123(void){
}

void CryptonightR_instruction_mov124(void){
}

void CryptonightR_instruction_mov125(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov126(void){
  ASM_B
  MOV(R(ecx), R(ebp))
  ASM_E
}

void CryptonightR_instruction_mov127(void){
}

void CryptonightR_instruction_mov128(void){
}

void CryptonightR_instruction_mov129(void){
}

void CryptonightR_instruction_mov130(void){
}

void CryptonightR_instruction_mov131(void){
}

void CryptonightR_instruction_mov132(void){
}

void CryptonightR_instruction_mov133(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov134(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov135(void){
}

void CryptonightR_instruction_mov136(void){
}

void CryptonightR_instruction_mov137(void){
}

void CryptonightR_instruction_mov138(void){
}

void CryptonightR_instruction_mov139(void){
}

void CryptonightR_instruction_mov140(void){
}

void CryptonightR_instruction_mov141(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov142(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov143(void){
}

void CryptonightR_instruction_mov144(void){
}

void CryptonightR_instruction_mov145(void){
}

void CryptonightR_instruction_mov146(void){
}

void CryptonightR_instruction_mov147(void){
}

void CryptonightR_instruction_mov148(void){
}

void CryptonightR_instruction_mov149(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov150(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov151(void){
}

void CryptonightR_instruction_mov152(void){
}

void CryptonightR_instruction_mov153(void){
}

void CryptonightR_instruction_mov154(void){
}

void CryptonightR_instruction_mov155(void){
}

void CryptonightR_instruction_mov156(void){
}

void CryptonightR_instruction_mov157(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov158(void){
  ASM_B
  MOV(R(ecx), R(esp))
  ASM_E
}

void CryptonightR_instruction_mov159(void){
}

void CryptonightR_instruction_mov160(void){
}

void CryptonightR_instruction_mov161(void){
}

void CryptonightR_instruction_mov162(void){
}

void CryptonightR_instruction_mov163(void){
}

void CryptonightR_instruction_mov164(void){
}

void CryptonightR_instruction_mov165(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov166(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov167(void){
}

void CryptonightR_instruction_mov168(void){
}

void CryptonightR_instruction_mov169(void){
}

void CryptonightR_instruction_mov170(void){
}

void CryptonightR_instruction_mov171(void){
}

void CryptonightR_instruction_mov172(void){
}

void CryptonightR_instruction_mov173(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov174(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov175(void){
}

void CryptonightR_instruction_mov176(void){
}

void CryptonightR_instruction_mov177(void){
}

void CryptonightR_instruction_mov178(void){
}

void CryptonightR_instruction_mov179(void){
}

void CryptonightR_instruction_mov180(void){
}

void CryptonightR_instruction_mov181(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov182(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov183(void){
}

void CryptonightR_instruction_mov184(void){
}

void CryptonightR_instruction_mov185(void){
}

void CryptonightR_instruction_mov186(void){
}

void CryptonightR_instruction_mov187(void){
}

void CryptonightR_instruction_mov188(void){
}

void CryptonightR_instruction_mov189(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov190(void){
  ASM_B
  MOV(R(ecx), R(r15d))
  ASM_E
}

void CryptonightR_instruction_mov191(void){
}

void CryptonightR_instruction_mov192(void){
}

void CryptonightR_instruction_mov193(void){
}

void CryptonightR_instruction_mov194(void){
}

void CryptonightR_instruction_mov195(void){
}

void CryptonightR_instruction_mov196(void){
}

void CryptonightR_instruction_mov197(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov198(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov199(void){
}

void CryptonightR_instruction_mov200(void){
}

void CryptonightR_instruction_mov201(void){
}

void CryptonightR_instruction_mov202(void){
}

void CryptonightR_instruction_mov203(void){
}

void CryptonightR_instruction_mov204(void){
}

void CryptonightR_instruction_mov205(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov206(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov207(void){
}

void CryptonightR_instruction_mov208(void){
}

void CryptonightR_instruction_mov209(void){
}

void CryptonightR_instruction_mov210(void){
}

void CryptonightR_instruction_mov211(void){
}

void CryptonightR_instruction_mov212(void){
}

void CryptonightR_instruction_mov213(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov214(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov215(void){
}

void CryptonightR_instruction_mov216(void){
}

void CryptonightR_instruction_mov217(void){
}

void CryptonightR_instruction_mov218(void){
}

void CryptonightR_instruction_mov219(void){
}

void CryptonightR_instruction_mov220(void){
}

void CryptonightR_instruction_mov221(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov222(void){
  ASM_B
  MOV(R(ecx), R(eax))
  ASM_E
}

void CryptonightR_instruction_mov223(void){
}

void CryptonightR_instruction_mov224(void){
}

void CryptonightR_instruction_mov225(void){
}

void CryptonightR_instruction_mov226(void){
}

void CryptonightR_instruction_mov227(void){
}

void CryptonightR_instruction_mov228(void){
}

void CryptonightR_instruction_mov229(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov230(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov231(void){
}

void CryptonightR_instruction_mov232(void){
}

void CryptonightR_instruction_mov233(void){
}

void CryptonightR_instruction_mov234(void){
}

void CryptonightR_instruction_mov235(void){
}

void CryptonightR_instruction_mov236(void){
}

void CryptonightR_instruction_mov237(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov238(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov239(void){
}

void CryptonightR_instruction_mov240(void){
}

void CryptonightR_instruction_mov241(void){
}

void CryptonightR_instruction_mov242(void){
}

void CryptonightR_instruction_mov243(void){
}

void CryptonightR_instruction_mov244(void){
}

void CryptonightR_instruction_mov245(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov246(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov247(void){
}

void CryptonightR_instruction_mov248(void){
}

void CryptonightR_instruction_mov249(void){
}

void CryptonightR_instruction_mov250(void){
}

void CryptonightR_instruction_mov251(void){
}

void CryptonightR_instruction_mov252(void){
}

void CryptonightR_instruction_mov253(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov254(void){
  ASM_B
  MOV(R(ecx), R(edx))
  ASM_E
}

void CryptonightR_instruction_mov255(void){
}

void CryptonightR_instruction_mov256(void){
}

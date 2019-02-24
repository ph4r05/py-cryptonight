"""
Converts .S file to the .C file
Used to generate CryptonightR_template.c
"""

import re

# Read the .S file here, the CryptonightR_instruction* definitions
data = """
    FN_PREFIX(CryptonightR_instruction51):
	    add	edi, esi
	    add	edi, 2147483647    
"""

is_body = False
fnc_name = None
body = []
instructions = []
lines = [x.strip() for x in data.split("\n") if x]


def try_int(x):
    try:
        return int(x)
    except:
        return x


for idx, line in enumerate(lines):
    if not line:
        continue
    m = re.match(r'^FN_PREFIX\(([\w_-]+)\):$', line)
    if m:
        is_body = False
        if fnc_name:
            instructions.append((fnc_name, body))

        fnc_name = m.group(1)
        body = []
    else:
        m2 = re.match(r'^([\w]+)\s+([\w]+)\s*,\s*([\w]+)\s*$', line.strip())
        if not m2:
            raise ValueError('Problem')
        body.append(m2.groups())
instructions.append((fnc_name, body))

def gen_functions(instructions):
    for fname, body in instructions:
        print('ASMFNC void %s(void){' % fname)
        # print('ins_%s_s:' % fname.lower())
        print('  ASM_B')
        for b in body:
            arg1 = try_int(b[1])
            arg2 = try_int(b[2])
            arg1s = ('C(%s)' % arg1) if isinstance(arg1, int) else ('R(%s)' % arg1)
            arg2s = ('C(%s)' % arg2) if isinstance(arg2, int) else ('R(%s)' % arg2)
            print('    %s(%s, %s)' % (b[0].upper(), arg1s, arg2s))
        print('    NOP()')
        print('  ASM_E')
        print('}\n')


def gen_asms(instructions):
    for fname, body in instructions:
        print('ASM_FNC(%s, ' % fname)
        for b in body:
            arg1 = try_int(b[1])
            arg2 = try_int(b[2])
            arg1s = ('C(%s)' % arg1) if isinstance(arg1, int) else ('R(%s)' % arg1)
            arg2s = ('C(%s)' % arg2) if isinstance(arg2, int) else ('R(%s)' % arg2)
            print('    %s(%s, %s)' % (b[0].upper(), arg1s, arg2s))
        if not body:
            print('    NOP()')
        print(')')


gen_asms(instructions)


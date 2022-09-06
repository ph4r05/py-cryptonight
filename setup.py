import sys
import os
import platform

from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

version = '1.0.0'

# Please update tox.ini when modifying dependency version requirements
install_requires = [
]

dev_extras = [
    'nose',
    'pep8',
    'tox',
    'aiounittest',
]

docs_extras = [
    'Sphinx>=1.0',  # autodoc_member_order = 'bysource', autodoc_default_flags
    'sphinx_rtd_theme',
    'sphinxcontrib-programoutput',
]

no_gnu = int(os.getenv('MONERO_NO_GNU', 0))
no_aes = int(os.getenv('MONERO_NO_AES', 0))
no_jit = int(os.getenv('MONERO_NO_JIT', 1))
st_jit = int(os.getenv('MONERO_STATIC_JIT', 1)) and not no_jit
du_jit = int(os.getenv('MONERO_DUMP_JIT', 0)) and not no_jit
de_jit = int(os.getenv('MONERO_DEBUG_JIT', 0)) and not no_jit
do_rndx = int(os.getenv('MONERO_RANDOMX', 0))
is_arm = int(os.getenv('MONERO_IS_ARM', platform.processor() == 'arm'))

define_macros = [
    ('NO_AES', 1) if no_aes else None,
    ('NO_JIT', 1) if no_jit else None,
    ('STATIC_JIT', 1) if st_jit else None,
    ('DUMP_JIT', 1) if du_jit else None,
    ('DEBUG_JIT', 1) if de_jit else None,
    ('NO_RANDOMX', 1) if not do_rndx else None,
    ('XMR_IS_ARM', is_arm),
]

if os.name == 'nt':
    compile_args = []  # AzeS: Maybe some cl.exe args that would be interesting?
else:
    compile_args = [
        '-std=c++11' if not no_gnu else '-std=c++11',
        '-maes' if not no_aes else None,
        '-fpermissive',
    ]

libs = []

if sys.platform == 'win32':
    libs = ['advapi32', 'user32']

include_dirs = ['.', 'src/', 'src/cryptonight', 'src/randomx']
if os.name == 'nt':
    include_dirs.insert(2, 'src/misc')

randomx_files = [
    'src/cryptonight/rx-slow-hash.cpp',

    'src/randomx/blake2/blake2b.cpp',
    'src/randomx/argon2_avx2.cpp',
    'src/randomx/argon2_core.cpp',
    'src/randomx/argon2_ref.cpp',
    'src/randomx/argon2_ssse3.cpp',
    'src/randomx/reciprocal.cpp',
    'src/randomx/virtual_memory.cpp',

    'src/randomx/aes_hash.cpp',
    'src/randomx/allocator.cpp',
    'src/randomx/assembly_generator_x86.cpp',
    'src/randomx/blake2_generator.cpp',
    'src/randomx/bytecode_machine.cpp',
    'src/randomx/cpu.cpp',
    'src/randomx/dataset.cpp',
    'src/randomx/instruction.cpp',
    'src/randomx/instructions_portable.cpp',
    ('src/randomx/jit_compiler_a64.cpp' if is_arm else 'src/randomx/jit_compiler_x86.cpp'),
    'src/randomx/randomx.cpp',
    'src/randomx/soft_aes.cpp',
    'src/randomx/superscalar.cpp',
    'src/randomx/virtual_machine.cpp',
    'src/randomx/vm_compiled.cpp',
    'src/randomx/vm_compiled_light.cpp',
    'src/randomx/vm_interpreted.cpp',
    'src/randomx/vm_interpreted_light.cpp',
]

randomx_extra = [
    'src/randomx/jit_compiler_a64_static.S' if is_arm else 'src/randomx/jit_compiler_x86_static.S'
]

extra_objects = [] \
    + (['src/cryptonight/CryptonightR_template.S'] if not is_arm else []) \
    + (randomx_extra if do_rndx else [])

hash_module = Extension('_pycryptonight',
                        sources=[
                            'src/cryptonight/aesb.cpp',
                            'src/cryptonight/blake256.cpp',
                            'src/cryptonight/CryptonightR_JIT.cpp',
                            'src/cryptonight/CryptonightR_template.cpp',
                            'src/cryptonight/groestl.cpp',
                            'src/cryptonight/hash.cpp',
                            'src/cryptonight/hash-extra-blake.cpp',
                            'src/cryptonight/hash-extra-groestl.cpp',
                            'src/cryptonight/hash-extra-jh.cpp',
                            'src/cryptonight/hash-extra-skein.cpp',
                            'src/cryptonight/jh.cpp',
                            'src/cryptonight/keccak.cpp',
                            'src/cryptonight/memwipe.cpp',
                            'src/cryptonight/oaes_lib.cpp',
                            'src/cryptonight/skein.cpp',
                            'src/cryptonight/slow-hash.cpp',

                            'src/pycryptonight.cpp',
                        ] + (randomx_files if do_rndx else []),
                        include_dirs=include_dirs,
                        define_macros=[x for x in define_macros if x],
                        extra_compile_args=[x for x in compile_args if x],
                        extra_objects=extra_objects,
                        libraries=libs,
                        # For testing only - some of these are GCC-specific
                        # '-Wall',
                        # '-Wextra',
                        # '-Wundef',
                        # '-Wshadow',
                        # '-Wcast-align',
                        # '-Wcast-qual',
                        # '-Wstrict-prototypes',
                        # '-pedantic'
                        )

try:
    import pypandoc

    long_description = pypandoc.convert_file('README.md', 'rst')
    long_description = long_description.replace("\r", '')

except(IOError, ImportError):
    import io

    with io.open('README.md', encoding='utf-8') as f:
        long_description = f.read()

setup(
    name='py_cryptonight',
    version=version,
    description='Python Cryptonight',
    long_description=long_description,
    url='https://github.com/ph4r05/py-cryptonight',
    author='Dusan Klinec',
    author_email='dusan.klinec@gmail.com',
    license='MIT',
    classifiers=[
        'Development Status :: 3 - Alpha',
        'Intended Audience :: Developers',
        'Programming Language :: Python',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Topic :: Security',
    ],

    packages=find_packages(),
    include_package_data=True,
    install_requires=install_requires,
    ext_modules=[hash_module],
    extras_require={
        'dev': dev_extras,
        'docs': docs_extras,
    },
)

import sys
import os

from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

version = '0.3.2'

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

define_macros = [
    ('NO_AES', 1) if no_aes else None,
    ('NO_JIT', 1) if no_jit else None,
    ('STATIC_JIT', 1) if st_jit else None,
    ('DUMP_JIT', 1) if du_jit else None,
    ('DEBUG_JIT', 1) if de_jit else None,
]

if os.name == 'nt':
    compile_args = []  # AzeS: Maybe some cl.exe args that would be interesting?
else:
    compile_args = [
        '-std=gnu11' if not no_gnu else '-std=c11',
        '-maes' if not no_aes else None
    ]

libs = []

if sys.platform == 'win32':
    libs = ['advapi32', 'user32']

include_dirs = ['.', 'src/', 'src/cryptonight']
if os.name == 'nt':
    include_dirs.insert(2, 'src/misc')

hash_module = Extension('_pycryptonight',
                        sources=[
                            'src/cryptonight/aesb.c',
                            'src/cryptonight/blake256.c',
                            'src/cryptonight/CryptonightR_JIT.c',
                            'src/cryptonight/CryptonightR_template.c',
                            'src/cryptonight/groestl.c',
                            'src/cryptonight/hash.c',
                            'src/cryptonight/hash-extra-blake.c',
                            'src/cryptonight/hash-extra-groestl.c',
                            'src/cryptonight/hash-extra-jh.c',
                            'src/cryptonight/hash-extra-skein.c',
                            'src/cryptonight/jh.c',
                            'src/cryptonight/keccak.c',
                            'src/cryptonight/oaes_lib.c',
                            'src/cryptonight/skein.c',
                            'src/cryptonight/slow-hash.c',
                            'src/pycryptonight.c',
                        ],
                        include_dirs=include_dirs,
                        define_macros=[x for x in define_macros if x],
                        extra_compile_args=[x for x in compile_args if x],
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

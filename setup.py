import sys

from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

version = '0.1.5'

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

hash_module = Extension('_pycryptonight',
                        sources=[
                            'src/cryptonight/aesb.c',
                            'src/cryptonight/blake256.c',
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
                        include_dirs=['.', 'src/', 'src/cryptonight'],
                        define_macros=[
                            ('NO_AES', 1)
                        ],
                        extra_compile_args=[
                                    '-std=c11',
                                    # For testing only - some of these are GCC-specific
                                    # '-Wall',
                                    # '-Wextra',
                                    # '-Wundef',
                                    # '-Wshadow',
                                    # '-Wcast-align',
                                    # '-Wcast-qual',
                                    # '-Wstrict-prototypes',
                                    # '-pedantic'
                                ],
                        )


try:
    import pypandoc
    long_description = pypandoc.convert('README.md', 'rst')
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

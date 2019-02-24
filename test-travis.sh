#!/bin/bash
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

/bin/rm -rf build/ ; MONERO_NO_AES=1 MONERO_NO_JIT=1 python setup.py develop
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

/bin/rm -rf build/ ; MONERO_NO_AES=0 MONERO_NO_JIT=1 python setup.py develop
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

/bin/rm -rf build/ ; MONERO_NO_AES=0 MONERO_NO_JIT=0 python setup.py develop
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

/bin/rm -rf build/ ; MONERO_NO_AES=0 MONERO_NO_JIT=0 MONERO_STATIC_JIT=0 python setup.py develop
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

/bin/rm -rf build/ ; MONERO_NO_AES=0 MONERO_NO_JIT=0 MONERO_STATIC_JIT=0 MONERO_DEBUG_JIT=1 MONERO_DUMP_JIT=1 python setup.py develop
MONERO_USE_CNV4_JIT=0 python -m unittest discover $*
MONERO_USE_CNV4_JIT=1 python -m unittest discover $*

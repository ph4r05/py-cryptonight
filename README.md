# Python CryptoNight implementation

[![Build Status](https://travis-ci.org/ph4r05/py-cryptonight.svg?branch=master)](https://travis-ci.org/ph4r05/py-cryptonight)

Python binding for Monero hash functions `cn_fast_hash`, `cn_slow_hash`.

- `cn_fast_hash` is used mainly for hashing to scalars / EC points.
- `cn_slow_hash` is CryptoNight hash function used for mining and encryption key derivation for encrypted wallet
files.
  - Supports CNv1, CNv2, CNv4
  - JIT tested on OSX + LLVM, experimental

Py2, Py3 compatible + tests with Monero test vectors.

```
pip install py-cryptonight
```

## Usage

```python
import binascii
import pycryptonight

pycryptonight.cn_fast_hash(b'1')
# hexcoded: b'c89efdaa54c0f20c7adf612882df0950f5a951637e0307cdcb4c672f298b8bc6

pycryptonight.cn_slow_hash(b'1')
# hexcoded: b'cbdfba46388e040422b4a9daa471726be659ae184ee86420c2795647f0b301d5

# variant 1:
pycryptonight.cn_slow_hash(binascii.unhexlify(b'38274c97c45a172cfc97679870422e3a1ab0784960c60514d816271415c306ee3a3ed1a77e31f6a885c3cb'), 1)  # variant 1
# hexcoded: b'ed082e49dbd5bbe34a3726a0d1dad981146062b39d36d62c71eb1ed8ab49459b

# variant 2:
pycryptonight.cn_slow_hash(b'1', 2)  # variant 2
# hexcoded: b'44016d2376838d89b374e99a20118c0e8916e8c0a5b910744efc7d8f426509ca

# variant 4:
pycryptonight.cn_slow_hash(b'1', 4)  # variant 4
# hexcoded: b'97db7e03629f7c17e4d78b36a2d247d226b88a8df6cf69f2e4cdae1f1b706b4a

# variant 4, height:
pycryptonight.cn_slow_hash(b'1', 4, prehashed=0, height=1)  # variant 4, height 1
# hexcoded: b'09bcf4997132dc3d7980125620724acc9c90dc393cb6694097a7d745c57b6b5b
```

## Build problems

The extension builds with AES extension by default. To disable this, rebuild with:

```bash
MONERO_NO_AES=1 python setup.py install
```

### JIT

The JIT optimization is disabled by default as the implementation was not properly tested.
If you want to experiment with JIT you need to compile with:

```bash
MONERO_NO_JIT=0 python setup.py install
MONERO_USE_CNV4_JIT=1 ./test.sh
```

To rebuild locally and test:

```bash
MONERO_NO_AES=0 MONERO_NO_JIT=0 python setup.py develop
MONERO_USE_CNV4_JIT=0 ./test.sh  # JIT disabled
MONERO_USE_CNV4_JIT=1 ./test.sh  # JIT enabled
```

For more info read [JIT.md](JIT.md)

## Donations
Thanks for your support!

`47BEukN83whUdvuXbaWmDDQLYNUpLsvFR2jioQtpP5vD8b3o74b9oFgQ3KFa3ibjbwBsaJEehogjiUCfGtugUGAuJAfbh1Z`

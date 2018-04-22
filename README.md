# Python CryptoNight implementation

[![Build Status](https://travis-ci.org/ph4r05/py-cryptonight.svg?branch=master)](https://travis-ci.org/ph4r05/py-cryptonight)

Python binding for Monero hash functions `cn_fast_hash`, `cn_slow_hash`.

- `cn_fast_hash` is used mainly for hashing to scalars / EC points.
- `cn_slow_hash` is CryptoNight hash function used for mining and encryption key derivation for encrypted wallet
files.

Py2, Py3 compatible + tests.

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
```


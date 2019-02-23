#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os
import random
import binascii
import unittest
import pkg_resources
import pycryptonight

__author__ = 'dusanklinec'


class PyCryptoNightTest(unittest.TestCase):

    def test_fast(self):
        self.tst_method('tests-fast.txt', lambda x, y: pycryptonight.cn_fast_hash(x))

    def test_slow(self):
        self.tst_method('tests-slow.txt', lambda x, y: pycryptonight.cn_slow_hash(x, 0, 0, 0))

    def test_slow1(self):
        self.tst_method('tests-slow-1.txt', lambda x, y: pycryptonight.cn_slow_hash(x, 1, 0, 0))

    def test_slow2(self):
        self.tst_method('tests-slow-2.txt', lambda x, y: pycryptonight.cn_slow_hash(x, 2, 0, 0))

    def test_slow4(self):
        self.tst_method('tests-slow-4.txt', lambda x, y: pycryptonight.cn_slow_hash(x, 4, 0, y))

    def tst_method(self, fname, fnc):
        with pkg_resources.resource_stream(__name__, os.path.join('data', fname)) as data_file:
            for idx, line in enumerate(data_file):
                line = line.strip()
                if not line:
                    continue

                height = 0
                expected, inp = line[:64], line[65:]
                if b' ' in inp:
                    inp, height = inp.split(b' ')
                    height = int(height)

                res = fnc(binascii.unhexlify(inp), height)
                self.assertEqual(binascii.unhexlify(expected), res)


if __name__ == "__main__":
    unittest.main()  # pragma: no cover



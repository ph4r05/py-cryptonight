import sys
import os
if os.name == 'nt' and not (os.path.isfile("unistd.h") or os.path.isfile("getopt.h")):
    print("[!] Windows detected, writing required header files...")
    with open("unistd.h", "w") as f:
        f.write("""
#ifndef _UNISTD_H
#define _UNISTD_H    1

/* This file intended to serve as a drop-in replacement for
*  unistd.h on Windows.
*  Please add functionality as neeeded.
*  Original file from: http://stackoverflow.com/a/826027
*/

#include <stdlib.h>
#include <io.h>
#include <getopt.h> /* getopt at: https://gist.github.com/bikerm16/1b75e2dd20d839dcea58 */
#include <process.h> /* for getpid() and the exec..() family */
#include <direct.h> /* for _getcwd() and _chdir() */

#define srandom srand
#define random rand

/* Values for the second argument to access.
These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
#define X_OK    R_OK    /* execute permission - unsupported in Windows, use R_OK instead. */
#define F_OK    0       /* Test for existence.  */

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
/* read, write, and close are NOT being #defined here,
* because while there are file handle specific versions for Windows,
* they probably don't work for sockets.
* You need to look at your app and consider whether
* to call e.g. closesocket().
*/

#define ssize_t int
#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
/* should be in some equivalent to <sys/types.h> */
typedef __int8            int8_t;
typedef __int16           int16_t; 
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;

#endif /* unistd.h  */
    """)
    print("[+] Done writing unistd.h")
    with open("getopt.h", "w") as f:
        f.write("""
/* Declarations for getopt.
   Copyright (C) 1989, 1990, 1991, 1992, 1993 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option) any
   later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef _GETOPT_H
#define _GETOPT_H 1

#ifdef	__cplusplus
extern "C" {
#endif

/* For communication from `getopt' to the caller.
   When `getopt' finds an option that takes an argument,
   the argument value is returned here.
   Also, when `ordering' is RETURN_IN_ORDER,
   each non-option ARGV-element is returned here.  */

extern char *optarg;

/* Index in ARGV of the next element to be scanned.
   This is used for communication to and from the caller
   and for communication between successive calls to `getopt'.

   On entry to `getopt', zero means this is the first call; initialize.

   When `getopt' returns EOF, this is the index of the first of the
   non-option elements that the caller should itself scan.

   Otherwise, `optind' communicates from one call to the next
   how much of ARGV has been scanned so far.  */

extern int optind;

/* Callers store zero here to inhibit the error message `getopt' prints
   for unrecognized options.  */

extern int opterr;

/* Set to an option character which was unrecognized.  */

extern int optopt;

/* Describe the long-named options requested by the application.
   The LONG_OPTIONS argument to getopt_long or getopt_long_only is a vector
   of `struct option' terminated by an element containing a name which is
   zero.

   The field `has_arg' is:
   no_argument		(or 0) if the option does not take an argument,
   required_argument	(or 1) if the option requires an argument,
   optional_argument 	(or 2) if the option takes an optional argument.

   If the field `flag' is not NULL, it points to a variable that is set
   to the value given in the field `val' when the option is found, but
   left unchanged if the option is not found.

   To have a long-named option do something other than set an `int' to
   a compiled-in constant, such as set a value from `optarg', set the
   option's `flag' field to zero and its `val' field to a nonzero
   value (the equivalent single-letter option character, if there is
   one).  For long options that have a zero `flag' field, `getopt'
   returns the contents of the `val' field.  */

struct option
{
#if	__STDC__
  const char *name;
#else
  char *name;
#endif
  /* has_arg can't be an enum because some compilers complain about
     type mismatches in all the code that assumes it is an int.  */
  int has_arg;
  int *flag;
  int val;
};

/* Names for the values of the `has_arg' field of `struct option'.  */

#define	no_argument		0
#define required_argument	1
#define optional_argument	2

//#if __STDC__ || defined(PROTO)
//#if defined(__GNU_LIBRARY__)
/* Many other libraries have conflicting prototypes for getopt, with
   differences in the consts, in stdlib.h.  To avoid compilation
   errors, only prototype getopt for the GNU C library.  */
extern int getopt (int argc, char *const *argv, const char *shortopts);
//#endif /* not __GNU_LIBRARY__ */
extern int getopt_long (int argc, char *const *argv, const char *shortopts,
		        const struct option *longopts, int *longind);
extern int getopt_long_only (int argc, char *const *argv,
			     const char *shortopts,
		             const struct option *longopts, int *longind);

/* Internal only.  Users should not call this directly.  */
/* extern int _getopt_internal (int argc, char *const *argv,
			     const char *shortopts,
		             const struct option *longopts, int *longind,
			     int long_only); */
//#else /* not __STDC__ */
//extern int getopt ();
//extern int getopt_long ();
//extern int getopt_long_only ();

//extern int _getopt_internal ();
//#endif /* not __STDC__ */

#ifdef	__cplusplus
}
#endif

#endif /* _GETOPT_H */

        
        """)
    print("[+] Done writing getopt.h")
    print("[*] Setting up setuptools for setup")
else:
    print("[+] Windows C_HEADER Requirements already Satisfied")
    print("[*] Setting up setuptools for setup...")
from setuptools import setup
from setuptools import Extension
from setuptools import find_packages

version = '0.3.1'

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
    compile_args = [] # AzeS: Maybe some cl.exe args that would be interesting?
else:
    compile_args = [
    '-std=gnu11' if not no_gnu else '-std=c11',
    '-maes' if not no_aes else None
    ]

libs = [

]

if sys.platform == 'win32':
    libs = ['advapi32', 'user32']


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
                        include_dirs=['.', 'src/', 'src/cryptonight'],
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

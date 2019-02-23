#include <Python.h>

#include "pycryptonight.h"
#include "cryptonight/hash-ops.h"


PyDoc_STRVAR(_pycryptonight_cn_fast_hash__doc__,
"cn_fast_hash(data) -> data\n"
"\n"
"Fast hashing, Keccak-256.\n");

#define FUNC_DEF_CN_FAST_HASH {"cn_fast_hash", (PyCFunction)_pycryptonight_cn_fast_hash,\
                                    METH_VARARGS | METH_KEYWORDS, _pycryptonight_cn_fast_hash__doc__}

static PyObject *_pycryptonight_cn_fast_hash(PyObject *self, PyObject *args, PyObject *kwargs)
{
#if PY_MAJOR_VERSION >= 3
    static const char *format = "y#|:cn_fast_hash";
#else
    static const char *format = "s#|:cn_fast_hash";
#endif
    static char *keywords[] = {"data", NULL};

    Py_ssize_t input_len = 0;
    const char *data = NULL;
    char hash[HASH_SIZE];
    PyObject *result = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, format, keywords, &data, &input_len)) {
        goto bail;
    }

    if (input_len < 0 || data == NULL){
        PyErr_SetString(PyExc_ValueError, "invalid input");
        goto bail;
    }

    cn_fast_hash(data, input_len, hash);

#if PY_MAJOR_VERSION >= 3
    result = PyBytes_FromStringAndSize(hash, HASH_SIZE); // Py_BuildValue("y#", hash, HASH_SIZE);
#else
    result = PyString_FromStringAndSize(hash, HASH_SIZE); //Py_BuildValue("s#", hash, HASH_SIZE);
#endif
    return result;

bail:
    return NULL;
}


PyDoc_STRVAR(_pycryptonight_cn_slow_hash__doc__,
"cn_slow_hash(data, variant=0, prehashed=0) -> data\n"
"\n"
"Slow hashing, CryptoNight\n");

#define FUNC_DEF_CN_SLOW_HASH {"cn_slow_hash", (PyCFunction)_pycryptonight_cn_slow_hash,\
                                    METH_VARARGS | METH_KEYWORDS, _pycryptonight_cn_slow_hash__doc__}

static PyObject *_pycryptonight_cn_slow_hash(PyObject *self, PyObject *args, PyObject *kwargs)
{
#if PY_MAJOR_VERSION >= 3
    static const char *format = "z#|iil:cn_slow_hash";
#else
    static const char *format = "s#|iil:cn_slow_hash";
#endif
    static char *keywords[] = {"data", "variant", "prehashed", "height", NULL};

    Py_ssize_t input_len=0;
    char *data = NULL;
    char hash[HASH_SIZE];
    int variant = 0;
    int prehashed = 0;
    long int height = 0;
    PyObject *result = NULL;

    if (!PyArg_ParseTupleAndKeywords(args, kwargs, format, keywords, &data, &input_len, &variant, &prehashed, &height)) {
        goto bail;
    }

    if (input_len < 0 || data == NULL){
        PyErr_SetString(PyExc_ValueError, "invalid input");
        goto bail;
    }

    cn_slow_hash(data, input_len, hash, variant, prehashed, height);

#if PY_MAJOR_VERSION >= 3
    result = PyBytes_FromStringAndSize(hash, HASH_SIZE); // Py_BuildValue("y#", hash, HASH_SIZE);
#else
    result = PyString_FromStringAndSize(hash, HASH_SIZE); //Py_BuildValue("s#", hash, HASH_SIZE);
#endif
    return result;

bail:
    return NULL;
}


static PyMethodDef PyCryptonightMethods[] = {
    FUNC_DEF_CN_FAST_HASH,
    FUNC_DEF_CN_SLOW_HASH,
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef PyCryptonightModule = {
    PyModuleDef_HEAD_INIT,
    "_pycryptonight",
    "...",
    -1,
    PyCryptonightMethods
};

PyMODINIT_FUNC PyInit__pycryptonight(void) {
    return PyModule_Create(&PyCryptonightModule);
}

#else

PyMODINIT_FUNC init_pycryptonight(void) {
    (void) Py_InitModule("_pycryptonight", PyCryptonightMethods);
}
#endif

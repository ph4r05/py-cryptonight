#if defined(STATIC_JIT) && (!defined(__x86_64__) || defined(NO_JIT))
#undef STATIC_JIT
#endif

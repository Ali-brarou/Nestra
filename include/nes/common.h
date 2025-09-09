#ifndef NES_COMMON_H

#ifdef __cplusplus
# define NES_STATIC_ASSERT(cond, msg) static_assert(cond, msg)
#else 
# define NES_STATIC_ASSERT(cond, msg) _Static_assert(cond, msg)
#endif

#endif

#ifndef NES_COMMON_H

#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h> 

#define NES_ASSERT(expr) assert(expr)

#define __NES_STATIC_ASSERT(cond, msg, ...) _Static_assert(cond, msg) 
#define NES_STATIC_ASSERT(cond, ...) __NES_STATIC_ASSERT(cond, ##__VA_ARGS__, #cond)

#define NES_LOG_ERROR(fmt, ...) \
    fprintf(stderr, "[ERROR] %s:%d:%s(): " fmt "\n", \
            __FILE__, __LINE__, __func__, ##__VA_ARGS__)

#endif

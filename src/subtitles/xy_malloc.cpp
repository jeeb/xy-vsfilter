/************************************************************************/
/* author: xy                                                           */
/* date: 20110514                                                       */
/************************************************************************/
#include "xy_malloc.h"
#include <stdint.h>
#include <malloc.h>
#include <string.h>

#define ALIGN 16

void* xy_malloc(size_t i_size, size_t align_shift)
{
    void* ptr = NULL;
    ptr = _aligned_offset_malloc(i_size, ALIGN, align_shift);
    if (!ptr) {
        return nullptr;
    }
    return ptr;
}

void xy_free(void* p)
{
    if (p) {
        _aligned_free(p);
    }
}

void* xy_realloc(void* p, size_t i_size, size_t align_shift)
{
    void* ptr = NULL;
    ptr = _aligned_offset_realloc(p, i_size, ALIGN, align_shift);
    if (!ptr) {
        return nullptr;
    }
    return ptr;
}

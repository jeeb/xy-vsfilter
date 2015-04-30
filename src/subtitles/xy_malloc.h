/************************************************************************/
/* author: xy                                                           */
/* date: 20110514                                                       */
/************************************************************************/
#ifndef SUBTITLES_XY_MALLOC_H_
#define SUBTITLES_XY_MALLOC_H_

#include <malloc.h>

const int kAlign = 16;

inline void* xy_malloc(size_t size)
{
    return _aligned_malloc(size, kAlign);
}

inline void* xy_malloc(size_t size, size_t align_shift)
{
    return _aligned_offset_malloc(size, kAlign, align_shift);
}

inline void xy_free(void* p)
{
    _aligned_free(p);
}

// xy_realloc functions currently not used anywhere
#if 0
inline void* xy_realloc(void* p, size_t size)
{
    return _aligned_realloc(p, size, kAlign);
}

inline void* xy_realloc(void* p, size_t size, size_t align_shift)
{
    return _aligned_offset_realloc(p, size, kAlign, align_shift);
}
#endif
#endif // SUBTITLES_XY_MALLOC_H_

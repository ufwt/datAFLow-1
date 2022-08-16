//===-- baggy_bounds.h - baggy_bounds interface -------------------*- C -*-===//
///
/// \file
/// BaggyBounds constants
///
//===----------------------------------------------------------------------===//

#ifndef BAGGY_BOUNDS_H
#define BAGGY_BOUNDS_H

#include <stdint.h>

#include "fuzzalloc/fuzzalloc.h"

#if defined(__cplusplus)
extern "C" {
#endif // __cplusplus

/// Slot size (in bytes)
extern const unsigned kSlotSize;

/// Size of metadata
extern const size_t kMetaSize;

/// Efficiently calculate the next power-of-2 of `X`
uint64_t bb_nextPow2(uint64_t X);

/// Efficiently calculate log2 of `X`
uint64_t bb_log2(uint64_t X);

void *__bb_malloc(tag_t Tag, size_t Size);
void *__bb_calloc(tag_t Tag, size_t NMemb, size_t Size);
void *__bb_realloc(tag_t Tag, void *Ptr, size_t Size);
void __bb_free(void *Ptr);

void __bb_register(void *Obj, size_t Size);
tag_t __bb_lookup(void *Ptr, uintptr_t *Base);

#if defined(__cplusplus)
}
#endif // __cplusplus

#endif // BAGGY_BOUNDS_H
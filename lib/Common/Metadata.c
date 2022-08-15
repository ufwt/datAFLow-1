//===-- Metadata.c - Metadata kinds -------------------------------*- C -*-===//
///
/// \file
/// Fuzzalloc LLVM metadata kinds
///
//===----------------------------------------------------------------------===//

#include "fuzzalloc/Metadata.h"

const char *kFuzzallocHeapifiedAllocaMD = "fuzzalloc.heapified_alloca";
const char *kFuzzallocInstrumentedDerefMD = "fuzzalloc.instrumented_deref";
const char *kFuzzallocNoInstrumentMD = "fuzzalloc.noinstrument";
const char *kFuzzallocBBAllocMD = "fuzzalloc.bb_alloc";
const char *kFuzzallocLoweredNewMD = "fuzzalloc.lowered_new";
const char *kFuzzallocLoweredDeleteMD = "fuzzalloc.lowered_delete";

const char *kNoSanitizeMD = "nosanitize";
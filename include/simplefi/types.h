#ifndef __SIMPLEFI_TYPES_H
#define __SIMPLEFI_TYPES_H

#include <stdint.h>
#include <stddef.h>

using BOOLEAN = uint8_t;
using INT8 = int8_t;
using UINT8 = uint8_t;
using INT16 = int16_t;
using UINT16 = uint16_t;
using INT32 = int32_t;
using UINT32 = uint32_t;
using INT64 = int64_t;
using UINT64 = uint64_t;
using UINTN = uintptr_t;

using EFI_HANDLE = void*;
using EFI_EVENT  = EFI_HANDLE;
using EFI_STATUS = UINTN;

#define EFI_SUCCESS ((EFI_STATUS)0)

using CHAR16 = wchar_t;

#endif
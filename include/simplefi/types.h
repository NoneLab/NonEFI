#ifndef __SIMPLEFI_TYPES_H
#define __SIMPLEFI_TYPES_H

#include <stdint.h>
#include <stddef.h>

using VOID = void;
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

using EfiPhysicalAddress = UINT64;
using EfiVirtualAddress = UINT64;

// Task Priority
using EfiTPL = UINTN;

#define EFI_SUCCESS ((EFI_STATUS)0)

using CHAR16 = wchar_t;

// Memory Type
enum EfiAllocateType
{
    AllocateAnyPages,
    AllocateMaxAddress,
    AllocateAddress,
    MaxAllocateType
};

enum EfiMemoryType
{
    EfiReservedMemoryType,
    EfiLoaderCode,
    EfiLoaderData,
    EfiBootServicesCode,
    EfiBootServicesData,
    EfiRuntimeServicesCode,
    EfiRuntimeServicesData,
    EfiConventionalMemory,
    EfiUnusableMemory,
    EfiACPIReclaimMemory,
    EfiACPIMemoryNVS,
    EfiMemoryMappedIO,
    EfiMemoryMappedIOPortSpace,
    EfiPalCode,
    EfiPersistentMemory,
    EfiUnacceptedMemoryType,
    EfiMaxMemoryType
};

enum EfiLocateSearchType
{
    AllHandles,
    ByRegisterNotify,
    ByProtocol
};

struct EfiMemoryDescriptor
{
    UINT32 Type;
    EfiPhysicalAddress PhysicalStart;
    EfiVirtualAddress VirtualStart;
    UINT64 NumberOfPages;
    UINT64 Attribute;
};

struct EfiGuid
{
    UINT32 guid1;
    UINT16 guid2;
    UINT16 guid3;
    UINT8  guid4[8];
};

enum EfiInterfaceType
{
    EFI_NATIVE_INTERFACE
};

struct EfiTableHeader 
{
    UINT64  Signature;
    UINT32  Revision;
    UINT32  HeaderSize;
    UINT32  CRC32;
    UINT32  Reserved;
};

#endif
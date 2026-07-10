#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_MISCELLANEOUS_RUNTIME_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_MISCELLANEOUS_RUNTIME_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

enum EfiResetType
{
    EfiResetCold,
    EfiResetWarm,
    EfiResetShutdown,
    EfiResetPlatformSpecific
};

// Capsule Service

#define CAPSULE_FLAGS_PERSIST_ACROSS_RESET 0x00010000
#define CAPSULE_FLAGS_POPULATE_SYSTEM_TABLE 0x00020000
#define CAPSULE_FLAGS_INITIATE_RESET 0x00040000

struct EfiCapsuleBlockDescriptor
{
    UINT64 Length;
    union
    {
        EfiPhysicalAddress DataBlock;
        EfiPhysicalAddress ContinuationPointer;
    } Union;
};

struct EfiCapsuleHeader
{
    EfiGuid CapsuleGuid;
    UINT32 HeaderSize;
    UINT32 Flags;
    UINT32 CapsuleImageSize;
};

struct EfiCapsuleTable
{
    UINT32 CapsuleArrayNumber;
    VOID* CapsulePtr[1];
};

using EfiResetSystemFn = VOID (EFIAPI *)(
    EfiResetType ResetType,
    EFI_STATUS ResetStatus,
    UINTN DataSize,
    VOID* ResetData
);

using EfiGetNextHighMonotonicCountFn = EFI_STATUS (EFIAPI *)(
    UINT32* HighCount
);

using EfiUpdateCapsuleFn = EFI_STATUS (EFIAPI *)(
    EfiCapsuleHeader** CapsuleHeaderArray,
    UINTN CapsuleCount,
    EfiPhysicalAddress ScatterGatherList
);

using EfiQueryCapsuleCapabilities = EFI_STATUS (EFIAPI *)(
    EfiCapsuleHeader** CapsuleHeaderArray,
    UINTN CapsuleCount,
    UINT64* MaximumCapsuleSize,
    EfiResetType* ResetType
);

using EfiQueryVariableInfo = EFI_STATUS (EFIAPI *)(
    UINT32 Attributes,
    UINT64* MaximumVariableStorageSize,
    UINT64* RemainingVariableStorageSize,
    UINT64* MaximumVariableSize
);

#endif
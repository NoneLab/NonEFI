#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_MEMORY_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_MEMORY_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

using EfiAllocatePagesFn = EFI_STATUS (EFIAPI *)(
    EfiAllocateType Type,
    EfiMemoryType MemoryType,
    UINTN Pages,
    EfiPhysicalAddress* Memory
);

using EfiFreePagesFn = EFI_STATUS (EFIAPI *)(
    EfiPhysicalAddress Memory,
    UINTN Pages
);

using EfiGetMemoryMapFn = EFI_STATUS (EFIAPI *)(
    UINTN* MemoryMapSize,
    EfiMemoryDescriptor* MemoryMap,
    UINTN* MapKey,
    UINTN* DescriptorSize,
    UINT32* DescriptorVersion
);

using EfiAllocatePoolFn = EFI_STATUS (EFIAPI *)(
    EfiMemoryType PoolType,
    UINTN Size,
    VOID** Buffer
);

using EfiFreePoolFn = EFI_STATUS (EFIAPI *)(
    VOID* Buffer
);

#endif
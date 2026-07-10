#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_VIRTUAL_MEMORY_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_VIRTUAL_MEMORY_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

using EfiSetVirtualAddressMapFn = EFI_STATUS (EFIAPI *)(
    UINTN MemoryMapSize,
    UINTN DescriptorSize,
    UINT32 DescriptiorVersion,
    EfiMemoryDescriptor* VirtualMap
);

using EfiConvertPointerFn = EFI_STATUS (EFIAPI *)(
    UINTN DebugDisposition,
    VOID** Address
);

#endif
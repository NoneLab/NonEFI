#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_IMAGE_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_IMAGE_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

struct EfiDevicePathProtocol;

using EfiImageLoadFn = EFI_STATUS (EFIAPI *)(
    BOOLEAN BootPolicy,
    EFI_HANDLE ParentImageHandle,
    EfiDevicePathProtocol* DevicePath,
    VOID* SourceBuffer,
    UINTN SourceSize,
    EFI_HANDLE ImageHandle
);

using EfiImageStartFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ImageHandle,
    UINTN* ExitDataSize,
    CHAR16** ExitData
);

using EfiImageUnloadFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ImageHandle
);

using EfiExitFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ImageHandle,
    EFI_STATUS ExitStatus,
    UINTN ExitDataSIze,
    CHAR16* ExitData
);

using EfiExitBootServicesFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ImageHandle,
    UINTN MapKey
);

#endif
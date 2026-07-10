#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_MISCELLANEOUS_BOOT_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_MISCELLANEOUS_BOOT_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

using EfiSetWatchdogTimerFn = EFI_STATUS (EFIAPI *)(
    UINTN Timeout,
    UINT64 WatchdogCode,
    UINTN DataSize,
    CHAR16* WatchdogData
);

using EfiStallFn = EFI_STATUS (EFIAPI *)(
    UINTN Microseconds
);

using EfiCopyMemFn = VOID (EFIAPI *)(
    VOID* Destination,
    VOID* Source,
    UINTN Length
);

using EfiSetMemFn = VOID (EFIAPI *)(
    VOID* Buffer,
    UINTN Size,
    UINT8 Value
);

using EfiGetNextMonotonicCountFn = EFI_STATUS (EFIAPI *)(
    UINT64* Count
);

using EfiInstallConfigurationTableFn = EFI_STATUS (EFIAPI *)(
    EfiGuid* Guid,
    VOID* Table
);

using EfiCalculateCRC32Fn = EFI_STATUS (EFIAPI *)(
    VOID* Data,
    UINTN DataSize,
    UINT32* Crc32
);

#endif
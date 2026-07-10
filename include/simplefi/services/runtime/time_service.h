#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_TIME_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_TIME_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

struct EfiTime 
{
    UINT16  Year;
    UINT8   Month;
    UINT8   Day; 
    UINT8   Hour;
    UINT8   Minute;
    UINT8   Second;
    UINT8   Padl;
    UINT32  Nanosecond;
    INT16   TimeZone;
    UINT8   Daylight;
    UINT8   Pad2;
};

struct EfiTimeCapabilities
{
    UINT32  Resolution;
    UINT32  Accuracy;
    BOOLEAN SetsToZero;
};

using EfiGetTimeFn = EFI_STATUS (EFIAPI *)(
    EfiTime* Time,
    EfiTimeCapabilities* Capabilities
);

using EfiSetTimeFn = EFI_STATUS (EFIAPI *)(
    EfiTime* Time
);

using EfiGetWakeUpTimeFn = EFI_STATUS (EFIAPI *)(
    BOOLEAN* Enabled,
    BOOLEAN* Pending,
    EfiTime* Time
);

using EfiSetWakeUpTimeFn = EFI_STATUS (EFIAPI *)(
    BOOLEAN Enable,
    EfiTime* Time
);

#endif
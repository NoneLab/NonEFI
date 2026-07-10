#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_TASK_PRIORITY_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_TASK_PRIORITY_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

using EfiRaiseTPLFn = EfiTPL (EFIAPI *)(
    EfiTPL NewTpl
);

using EfiRestoreTPLFn = VOID (EFIAPI *)(
    EfiTPL OldTpl
);

#endif
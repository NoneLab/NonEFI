#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>
#include <simplefi/services/runtime/time_service.h>
#include <simplefi/services/runtime/variable_service.h>
#include <simplefi/services/runtime/virtual_memory_service.h>
#include <simplefi/services/runtime/miscellaneous_runtime_service.h>

#define EFI_RUNTIME_SERVICES_SIGNATURE  0x56524553544e5552
#define EFI_RUNTIME_SERVICES_REVISION   EFI_SPECIFICATION_VERSION

struct EfiRuntimeServices
{
    EfiTableHeader Hdr;

    // Time Services
    EfiGetTimeFn GetTime;
    EfiSetTimeFn SetTime;
    EfiGetWakeUpTimeFn GetWakeupTime;
    EfiSetWakeUpTimeFn SetWakeupTime;

    // Virtual Memory Services
    EfiSetVirtualAddressMapFn SetVirtualAddressMap;
    EfiConvertPointerFn ConvertPointer;

    // Variable Services
    EfiGetVariableFn GetVariable;
    EfiGetNextVariableNameFn GetNextVariableName;
    EfiSetVariableFn SetVariable;

    // Miscellaneous Services
    EfiGetNextHighMonotonicCountFn GetNextHighMonotonicCount;
    EfiResetSystemFn ResetSystem;

    // UEFI 2.0 Capsule Services
    EfiUpdateCapsuleFn UpdateCapsule;
    EfiQueryCapsuleCapabilities QueryCapsuleCapabilities;

    // Miscellaneous UEFI 2.0 Service
    EfiQueryVariableInfo QueryVariableInfo;
};

#endif
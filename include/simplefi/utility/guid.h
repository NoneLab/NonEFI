#ifndef __SIMPLEFI_GUID_TABLE_H
#define __SIMPLEFI_GUID_TABLE_H

#include "../types.h"
#include <simplefi/utility/runtime.h>

struct EfiSystemTable;

template<typename Protocol>
inline constexpr bool DependentFalse = false;

// Reference from Google's Fuchsia 
template<typename Protocol>
constexpr const EfiGuid& EfiGuidTable = [](){static_assert(DependentFalse<Protocol>, "Specialization missing"); }();

EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    EfiGuid& guid,
    VOID* outProtocol
);

template<typename Protocol>
EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    Protocol& protocol
)
{
    return OpenProtocol(handle, EfiGuidTable<Protocol>, &protocol);
}

#endif
#ifndef __SIMPLEFI_GUID_TABLE_H
#define __SIMPLEFI_GUID_TABLE_H

#include <simplefi/types.h>
#include <simplefi/defs.h>
#include <simplefi/utility/runtime.h>

EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid,
    VOID** outProtocol
);

template<typename Protocol>
EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    Protocol*& protocol
)
{
    return OpenProtocol(handle, GET_GUID(Protocol), reinterpret_cast<VOID**>(&protocol));
}

#endif
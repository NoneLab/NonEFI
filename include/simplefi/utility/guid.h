#ifndef __SIMPLEFI_UTILITY_GUID_H
#define __SIMPLEFI_UTILITY_GUID_H

#include <simplefi/types.h>
#include <simplefi/defs.h>
#include <simplefi/utility/runtime.h>

#include <expected>

#include <ltl/memory.h>
#include <ltl/expected.h>

template<typename Protocol>
struct ProtocolDeleter;

template<typename Protocol>
using ProtocolPtr = ltl::unique_ptr<Protocol, ProtocolDeleter<Protocol>>;

EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid,
    VOID** outProtocol
);

EFI_STATUS CloseProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid
);

template<typename Protocol>
EFI_STATUS CloseProtocol(
    EFI_HANDLE handle
)
{
    return CloseProtocol(handle, GET_GUID(Protocol));
}

template<typename Protocol>
ltl::expected<ProtocolPtr<Protocol>, EFI_STATUS> OpenProtocol(
    EFI_HANDLE handle
)
{
    VOID* protocol = nullptr;
    auto status = OpenProtocol(handle, GET_GUID(Protocol), &protocol);
    if (status)
        return ltl::unexpected(status);

    return ProtocolPtr<Protocol>(
        reinterpret_cast<Protocol*>(protocol),
        ProtocolDeleter<Protocol> {
            handle
        }
    );
}

template<typename Protocol>
struct ProtocolDeleter
{
    EFI_HANDLE handle = nullptr;
    void operator()(Protocol* passed)
    {
        UNUSED_PARAMETER(passed);

        if (!this->handle)
            CloseProtocol<Protocol>(this->handle);
    }
};

#endif
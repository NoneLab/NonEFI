#include "simplefi/defs.h"
#include <simplefi/types.h>
#include <simplefi/utility/guid.h>
#include <simplefi/protocols/loaded_image.h>
#include <simplefi/protocols/device_path.h>
#include <simplefi/protocols/simple_text_input.h>
#include <simplefi/protocols/simple_text_output.h>

#include <simplefi/efi.h>
#include <simplefi/utility/runtime.h>

#include <stdio.h>

EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid,
    VOID** outProtocol
)
{
    auto bs = Runtime::GetSysTable()->BootServices;

    return bs->OpenProtocol(
        handle,
        &guid,
        outProtocol,
        Runtime::GetHandle(),
        nullptr,
        EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL
    );
}

EFI_STATUS CloseProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid
)
{
    auto bs = Runtime::GetSysTable()->BootServices;

    auto status =  bs->CloseProtocol(
        handle,
        &guid,
        Runtime::GetHandle(),
        nullptr
    );

    printf("Check Close Return value : 0x%llx", status);

    return status;
}
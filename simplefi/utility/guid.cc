#include "simplefi/defs.h"
#include <simplefi/types.h>
#include <simplefi/utility/guid.h>
#include <simplefi/protocols/device_path.h>
#include <simplefi/protocols/simple_text_input.h>
#include <simplefi/protocols/simple_text_output.h>

#include <simplefi/efi.h>
#include <simplefi/utility/runtime.h>

const EfiGuid TextInputProtocolGuid = EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID;
const EfiGuid TextOutputProtocolGuid = EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;
const EfiGuid DevicePathProtocol = EFI_DEVICE_PATH_PROTOCOL_GUID;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiSimpleTextInputProtocol> = TextInputProtocolGuid;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiSimpleTextOutputProtocol> = TextOutputProtocolGuid;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiDevicePathProtocol> = DevicePathProtocol;

EFI_STATUS OpenProtocol(
    EFI_HANDLE handle,
    const EfiGuid& guid,
    VOID* outProtocol
)
{
    auto bs = Runtime::GetSysTable()->BootServices;

    return bs->OpenProtocol(
        handle,
        &guid,
        &outProtocol,
        Runtime::GetHandle(),
        nullptr,
        EFI_OPEN_PROTOCOL_BY_HANDLE_PROTOCOL
    );
}
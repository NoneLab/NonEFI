#include <simplefi/types.h>
#include <simplefi/guid_table.h>
#include <simplefi/protocols/device_path.h>
#include <simplefi/protocols/simple_text_input.h>
#include <simplefi/protocols/simple_text_output.h>

const EfiGuid TextInputProtocolGuid = EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID;
const EfiGuid TextOutputProtocolGuid = EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID;
const EfiGuid DevicePathProtocol = EFI_DEVICE_PATH_PROTOCOL_GUID;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiSimpleTextInputProtocol> = TextInputProtocolGuid;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiSimpleTextOutputProtocol> = TextOutputProtocolGuid;

template<>
constexpr const EfiGuid& EfiGuidTable<EfiDevicePathProtocol> = DevicePathProtocol;
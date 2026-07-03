#ifndef __SIMPLEFI_PROTOCOLS_SIMPLE_TEXT_INPUT_H
#define __SIMPLEFI_PROTOCOLS_SIMPLE_TEXT_INPUT_H

#include "simplefi/types.h"
#include "simplefi/defs.h"

#define EFI_SIMPLE_TEXT_INPUT_PROTOCOL_GUID \
 {0x387477c1,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

extern const EfiGuid TextInputProtocolGuid;

struct EfiInputKey;
struct EfiSimpleTextInputProtocol;

using EfiInputResetFn = EFI_STATUS (EFIAPI*)(
    EfiSimpleTextInputProtocol*  This,
    BOOLEAN                     ExtendedVerification
);

using EfiInputReadKeyFn = EFI_STATUS (EFIAPI*)(
    EfiSimpleTextInputProtocol*  This,
    EfiInputKey*                Key
);

struct EfiSimpleTextInputProtocol
{
    EfiInputResetFn     Reset;
    EfiInputReadKeyFn   ReadKeyStroke;
    EFI_EVENT           WaitForKey;

};

#endif
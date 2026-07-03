#ifndef __SIMPLEFI_PROTOCOLS_SIMPLE_TEXT_OUTPUT_H
#define __SIMPLEFI_PROTOCOLS_SIMPLE_TEXT_OUTPUT_H

#include "simplefi/defs.h"
#include "simplefi/types.h"

#define EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL_GUID \
 {0x387477c2,0x69c7,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

extern const EfiGuid TextOutputProtocolGuid;

struct EfiSimpleTextOutputProtocol;

using EfiTextResetFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    BOOLEAN                     ExtendedVerification
);

using EfiTextStringFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    CHAR16*                     String
);

using EfiTextTestStringFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    CHAR16*                     String
);

using EfiTextQueryModeFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    UINTN                       ModeNumber,
    UINTN*                      Columns,
    UINTN*                      Rows
);

using EfiTextSetModeFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    UINTN                       ModeNumber
);

using EfiTextSetAttributeFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    UINTN                       Attribute
);

using EfiTextClearScreenFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This
);

using EfiTextSetCursorPositionFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    UINTN                       Column,
    UINTN                       Row
);

using EfiTextEnableCursorFn = EFI_STATUS (EFIAPI * )(
    EfiSimpleTextOutputProtocol* This,
    BOOLEAN                     Visible
);

struct SimpleTextOutputMode
{
    INT32 MaxMode;
    INT32 Mode;
    INT32 Attribute;
    INT32 CursorColumn;
    INT32 CursorRow;
    BOOLEAN CursorVisible;
};

struct EfiSimpleTextOutputProtocol 
{
    EfiTextResetFn Reset;
    EfiTextStringFn OutputString;
    EfiTextTestStringFn TestString;
    EfiTextQueryModeFn QueryMode;
    EfiTextSetModeFn SetMode;
    EfiTextSetAttributeFn SetAttribute;
    EfiTextClearScreenFn ClearScreen;
    EfiTextSetCursorPositionFn SetCursorPosition;
    EfiTextEnableCursorFn EnableCursor;
    SimpleTextOutputMode* Mode;
};

#endif
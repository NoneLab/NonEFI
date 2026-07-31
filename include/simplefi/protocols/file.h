#ifndef __SIMPLEFI_PROTOCOLS_FILE_H
#define __SIMPLEFI_PROTOCOLS_FILE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

#define EFI_FILE_PROTOCOL_REVISION           0x00010000
#define EFI_FILE_PROTOCOL_REVISION2          0x00020000
#define EFI_FILE_PROTOCOL_LATEST_REVISION EFI_FILE_PROTOCOL_REVISION2

//******************************************************
// Open Modes
//******************************************************
#define EFI_FILE_MODE_READ       0x0000000000000001
#define EFI_FILE_MODE_WRITE      0x0000000000000002
#define EFI_FILE_MODE_CREATE     0x8000000000000000

//******************************************************
// File Attributes
//******************************************************
#define EFI_FILE_READ_ONLY       0x0000000000000001
#define EFI_FILE_HIDDEN          0x0000000000000002
#define EFI_FILE_SYSTEM          0x0000000000000004
#define EFI_FILE_RESERVED        0x0000000000000008
#define EFI_FILE_DIRECTORY       0x0000000000000010
#define EFI_FILE_ARCHIVE         0x0000000000000020
#define EFI_FILE_VALID_ATTR      0x0000000000000037

struct EfiFileProtocol;
struct EfiFileIoToken
{
    EFI_EVENT Event;
    EFI_STATUS Status;
    UINTN BufferSize;
    VOID* Buffer;
};

using EfiFileOpenFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiFileProtocol** NewHandle,
    const CHAR16* FileName,
    UINT64 OpenMode,
    UINT64 Attributes
);

using EfiFileCloseFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This
);

using EfiFileDeleteFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This
);

using EfiFileReadFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    UINTN* BufferSize,
    VOID* Buffer
);

using EfiFileWriteFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    UINTN* BufferSize,
    CONST VOID* Buffer
);

using EfiFileOpenExFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiFileProtocol** NewHandle,
    CHAR16* FileName,
    UINT64 OpenMode,
    UINT64 Attributes,
    EfiFileIoToken* Token
);

using EfiFileReadExFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiFileIoToken* Token
);

using EfiFileWriteExFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiFileIoToken* Token
);

using EfiFileFlushExFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiFileIoToken* Token
);

using EfiFileSetPositionFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    UINT64 Position
);

using EfiFileGetPositionFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    UINT64* Position
);

using EfiFileGetInfoFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiGuid* InformationType,
    UINTN* BuffreSize,
    VOID* Buffer
);

using EfiFileSetInfoFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This,
    EfiGuid* InformationType,
    UINTN BufferSize,
    VOID* Buffer
);

using EfiFileFlushFn = EFI_STATUS (EFIAPI *)(
    EfiFileProtocol* This
);

struct EfiFileProtocol
{
    UINT64 Revision;
    EfiFileOpenFn Open;
    EfiFileCloseFn Close;
    EfiFileDeleteFn Delete;
    EfiFileReadFn Read;
    EfiFileWriteFn Write;
    EfiFileGetPositionFn GetPosition;
    EfiFileSetPositionFn SetPosition;
    EfiFileGetInfoFn GetInfo;
    EfiFileSetInfoFn SetInfo;
    EfiFileFlushFn Flush;
    EfiFileOpenExFn OpenEx;
    EfiFileReadExFn ReadEx;
    EfiFileWriteExFn WriteEx;
    EfiFileFlushExFn FlushEx;
};

#endif
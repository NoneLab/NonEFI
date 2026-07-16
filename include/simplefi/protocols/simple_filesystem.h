#ifndef __SIMPLEFI_PROTOCOLS_SIMPLE_FILESYSTEM_H
#define __SIMPLEFI_PROTOCOLS_SIMPLE_FILESYSTEM_H

#include <simplefi/types.h>
#include <simplefi/defs.h>

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID \
 {0x0964e5b22,0x6459,0x11d2,\
  {0x8e,0x39,0x00,0xa0,0xc9,0x69,0x72,0x3b}}

#define EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_REVISION 0x00010000

struct EfiSimpleFileSystemProtocol;
struct EfiFileProtocol;

using EfiSimpleFileSystemProtocolOpenVolumeFn = EFI_STATUS (EFIAPI *)(
    EfiSimpleFileSystemProtocol* This,
    EfiFileProtocol** Root
);

struct EfiSimpleFileSystemProtocol
{
    UINT64 Revision;
    EfiSimpleFileSystemProtocolOpenVolumeFn OpenVolume;
};

#endif
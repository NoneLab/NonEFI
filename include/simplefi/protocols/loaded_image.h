#ifndef __SIMPLEFI_PROTOCOLS_LOADED_IMAGE_H
#define __SIMPLEFI_PROTOCOLS_LOADED_IMAGE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>
#include <simplefi/services/boot/image_service.h>

#define EFI_LOADED_IMAGE_PROTOCOL_GUID \
  {0x5B1B31A1,0x9562,0x11d2,\
    {0x8E,0x3F,0x00,0xA0,0xC9,0x69,0x72,0x3B}}

extern const EfiGuid LoadedImageProtocolGuid;

#define EFI_LOADED_IMAGE_DEVICE_PATH_PROTOCOL_GUID \
    {0xbc62157e,0x3e33,0x4fec,\
   {0x99,0x20,0x2d,0x3b,0x36,0xd7,0x50,0xdf}}

#define EFI_LOADED_IMAGE_PROTOCOL_REVISION 0x1000

struct EfiSystemTable;
struct EfiDevicePathProtocol;

struct EfiLoadedImageProtocol
{
    DEFINE_GUID(EFI_LOADED_IMAGE_PROTOCOL_GUID);

    UINT32 Revision;
    EFI_HANDLE ParentHandle;
    EfiSystemTable* SystemTable;

    EFI_HANDLE DeviceHandle;
    EfiDevicePathProtocol* FilePath;
    VOID* Reserved;

    VOID* ImageBase;
    UINT64 ImageSize;
    EfiMemoryType ImageCodeType;
    EfiMemoryType ImageDataType;
    EfiImageUnloadFn Unload;
};

#endif
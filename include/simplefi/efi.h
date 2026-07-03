/* 
 *          simplefi/efi.h
 *  
 *  Author : Nakada Tokumei <nakada_tokumei@protonmail.com>
 *  Description : EFI standard data type that reference from UEFI Specification
 * 
 */

#ifndef __SIMPLEFI_EFI_H
#define __SIMPLEFI_EFI_H

#include "types.h"
#include <simplefi/protocols/simple_text_input.h>
#include <simplefi/protocols/simple_text_output.h>

struct EfiTableHeader 
{
    UINT64  Signature;
    UINT32  Revision;
    UINT32  HeaderSize;
    UINT32  CRC32;
    UINT32  Reserved;
};

struct EfiSystemTable
{
    EfiTableHeader                  Hdr;
    CHAR16*                         FWVendor;
    UINT32                          FWRevision;
    EFI_HANDLE                      ConsoleInHandle;
    EfiSimpleTextInputProtocol*     ConIn;
    EFI_HANDLE                      ConsoleOutHandle;
    EfiSimpleTextOutputProtocol*    ConOut;
    EFI_HANDLE                      StandardErrorHandle;
    EfiSimpleTextOutputProtocol*    StdErr;
    void*                           RuntimeServcies;
    void*                           BootServices;
    UINTN                           NumberOfTableEntries;
    void*                           ConfigurationTable;
};

void InitializeRuntime(
    EFI_HANDLE ImageHandle, 
    EfiSystemTable* SystemTable
);

#endif
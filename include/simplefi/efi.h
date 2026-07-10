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
#include <simplefi/services/boot_service.h>
#include <simplefi/services/runtime_service.h>
#include <simplefi/protocols/device_path.h>
#include <simplefi/protocols/simple_text_input.h>
#include <simplefi/protocols/simple_text_output.h>

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
    EfiRuntimeServices*             RuntimeServcies;
    EfiBootServices*                BootServices;
    UINTN                           NumberOfTableEntries;
    void*                           ConfigurationTable;
};

void InitializeRuntime(
    EFI_HANDLE ImageHandle, 
    EfiSystemTable* SystemTable
);

// Declarition main function
extern "C"
EFI_STATUS EFIAPI
EfiMain(EFI_HANDLE ImageHandle, EfiSystemTable* SystemTable);

#endif
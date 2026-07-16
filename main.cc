#include <simplefi/efi.h>
#include <simplefi/defs.h>
#include <simplefi/types.h>

#include <stdio.h>

EFI_STATUS EFIAPI
EfiMain(EFI_HANDLE ImageHandle, EfiSystemTable* SystemTable)
{
    simplefi::Runtime::InitializeRuntime(ImageHandle, SystemTable);
    printf("Hello, newlib on UEFI\r\n");
    return EFI_SUCCESS;
}
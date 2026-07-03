#include <simplefi/efi.h>
#include <simplefi/defs.h>
#include <simplefi/types.h>

#include <stdio.h>

extern "C"
EFI_STATUS EFIAPI
EfiMain(EFI_HANDLE ImageHandle, EfiSystemTable* SystemTable)
{
    InitializeRuntime(ImageHandle, SystemTable);
    SystemTable->ConOut->OutputString(
        SystemTable->ConOut,
        const_cast<CHAR16*>(L"Hello UEFI\r\n")
    );
    printf("Hello, newlib on UEFI\r\n");
    return EFI_SUCCESS;
}
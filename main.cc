#include <simplefi/efi.h>
#include <simplefi/defs.h>
#include <simplefi/types.h>

extern "C"
EFI_STATUS EFIAPI
EfiMain(EFI_HANDLE ImageHandle, EfiSystemTable* SystemTable)
{
    SystemTable->ConOut->OutputString(
        SystemTable->ConOut,
        const_cast<CHAR16*>(L"Hello UEFI\r\n")
    );
    return EFI_SUCCESS;
}
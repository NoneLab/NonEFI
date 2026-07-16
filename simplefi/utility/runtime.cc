#include <simplefi/utility/runtime.h>

#include <simplefi/efi.h>

static EFI_HANDLE gImageHandle = nullptr;
static EfiSystemTable* gSysTable = nullptr;

void Runtime::InitializeRuntime(
    EFI_HANDLE ImageHandle, 
    EfiSystemTable* SystemTable
)
{
    gImageHandle = ImageHandle;
    gSysTable = SystemTable;
}

EFI_HANDLE Runtime::GetHandle()
{
    return gImageHandle;
}

EfiSystemTable* Runtime::GetSysTable()
{
    return gSysTable;
}

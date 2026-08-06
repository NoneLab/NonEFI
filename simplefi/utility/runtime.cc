#include <simplefi/utility/runtime.h>

#include <simplefi/efi.h>
#include <simplefi/utility/guid.h>
#include <simplefi/protocols/loaded_image.h>

#include <ltl/utility.h>

#include <pepe/pe.h>

#include <stdio.h>

static EFI_HANDLE gImageHandle = nullptr;
static EfiSystemTable* gSysTable = nullptr;

namespace
{

void CallConsturctor()
{
    if (auto ret = OpenProtocol<EfiLoadedImageProtocol>(gImageHandle); ret.has_value())
    {
        auto loadedImage = ltl::move(ret).value();
        pepe::PECoff(loadedImage->ImageBase).CallConstructors();
    }
}

}  // namespace

void Runtime::InitializeRuntime(
    EFI_HANDLE ImageHandle, 
    EfiSystemTable* SystemTable
)
{
    gImageHandle = ImageHandle;
    gSysTable = SystemTable;
    
    CallConsturctor();
}

EFI_HANDLE Runtime::GetHandle()
{
    return gImageHandle;
}

EfiSystemTable* Runtime::GetSysTable()
{
    return gSysTable;
}

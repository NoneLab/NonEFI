#ifndef __SIMPLEFI_UTILITY_RUNTIME_H
#define __SIMPLEFI_UTILITY_RUNTIME_H

#include <simplefi/types.h>

// Forward Declaring
struct EfiSystemTable;

struct Runtime
{
    static void InitializeRuntime(
        EFI_HANDLE ImageHandle, 
        EfiSystemTable* SystemTable
    );

    static EFI_HANDLE GetHandle();
    static EfiSystemTable* GetSysTable();
};


#endif
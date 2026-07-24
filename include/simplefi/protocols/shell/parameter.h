#ifndef __SIMPLEFI_PROTOCOLS_SHELL_PARAMETER_H
#define __SIMPLEFI_PROTOCOLS_SHELL_PARAMETER_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

#define EFI_SHELL_PARAMETERS_PROTOCOL_GUID \
 { 0x752f3136, 0x4e16, 0x4fdc, \
 { 0xa2, 0x2a, 0xe5, 0xf4, 0x68, 0x12, 0xf4, 0xca } }

struct EfiShellParametersProtocol
{
    DEFINE_GUID(EFI_SHELL_PARAMETERS_PROTOCOL_GUID);
    CHAR16** Argv;
    UINTN Argc;
    SHELL_FILE_HANDLE StdIn;
    SHELL_FILE_HANDLE StdOut;
    SHELL_FILE_HANDLE StdErr;
};

#endif
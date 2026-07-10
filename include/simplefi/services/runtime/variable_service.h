#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_VARIABLE_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_RUNTIME_VARIABLE_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

//******************************************************
// Variable Attributes
//******************************************************
#define EFI_VARIABLE_NON_VOLATILE                           0x00000001
#define EFI_VARIABLE_BOOTSERVICE_ACCESS                     0x00000002
#define EFI_VARIABLE_RUNTIME_ACCESS                         0x00000004
#define EFI_VARIABLE_HARDWARE_ERROR_RECORD                  0x00000008

//This attribute is identified by the mnemonic 'HR' elsewhere
//in this specification.
//Reserved                                                  0x00000010

#define EFI_VARIABLE_TIME_BASED_AUTHENTICATED_WRITE_ACCESS  0x00000020
#define EFI_VARIABLE_APPEND_WRITE                           0x00000040
#define EFI_VARIABLE_ENHANCED_AUTHENTICATED_ACCESS          0x00000080

//This attribute indicates that the variable payload begins
//with an EFI_VARIABLE_AUTHENTICATION_3 structure, and
//potentially more structures as indicated by fields of this
//structure. See definition below and in SetVariable().

#define EFI_VARIABLE_AUTHENTICATION_3_CERT_ID_SHA256 1

struct EfiVariableAuthentication3CertID
{
    UINT8 Type;
    UINT32 IdSize;
    UINT8 Id[1];    // Variable Length Size Array
};

using EfiGetVariableFn = EFI_STATUS (EFIAPI*)(
    CHAR16* VariableName,
    EfiGuid* VendorGuid,
    UINT32* Attributes,
    UINTN* DataSize,
    VOID* Data
);

using EfiGetNextVariableNameFn = EFI_STATUS (EFIAPI*)(
    UINTN* VariableNameSize,
    CHAR16* VariableName,
    EfiGuid* VendorGuid
);

using EfiSetVariableFn = EFI_STATUS (EFIAPI*)(
    CHAR16* VariableName,
    EfiGuid* VendorGuid,
    UINT32 Attributes,
    UINTN DataSize,
    VOID* Data
);

#endif
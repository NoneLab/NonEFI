#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_PROTOCOL_HANDLER_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_PROTOCOL_HANDLER_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>

struct EfiDevicePathProtocol;

struct EfiOpenProtocolInformationEntry
{
    EFI_HANDLE AgentHandle;
    EFI_HANDLE ControllerHandle;
    UINT32 Attributes;
    UINT32 OpenCount;
};

using EfiInstallProtocolInterfaceFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE* Handle,
    const EfiGuid* Protocol,
    EfiInterfaceType InterfaceType,
    VOID* Interface
);

using EfiUninstallProtocolInterfaceFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    VOID* Interface
);

using EfiReinstallProtocolInterfacefn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    VOID* OldInterface,
    VOID* NewInterface
);

using EfiRegisterProtocolNotifyFn = EFI_STATUS (EFIAPI *)(
    const EfiGuid* Protocol,
    EFI_EVENT Event,
    VOID** Registration
);

using EfiLocateHandleFn = EFI_STATUS (EFIAPI *)(
    EfiLocateSearchType SearchType,
    const EfiGuid* Protocol,
    VOID* SearchKey,
    UINTN* BufferSize,
    EFI_HANDLE* Buffer
);

using EfiHandleProtocolFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    VOID** Interface
);

using EfiLocateDevicePathFn = EFI_STATUS (EFIAPI *)(
    const EfiGuid* Protocol,
    EfiDevicePathProtocol** DevicePath,
    EFI_HANDLE* Device
);

using EfiOpenProtocolFn = EFI_STATUS (*)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    VOID** Interface,
    EFI_HANDLE AgentHandle,
    EFI_HANDLE ControllerHandle,
    UINT32 Attributes
);

using EfiCloseProtocolFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    EFI_HANDLE AgentHandle,
    EFI_HANDLE ControllerHandle
);

using EfiOpenProtocolInformationFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    const EfiGuid* Protocol,
    EfiOpenProtocolInformationEntry** EntryBuffer,
    UINTN* EntryCount
);

using EfiConnectControllerFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ControllerHandle,
    EFI_HANDLE* DriverImageHandle,
    EfiDevicePathProtocol* RemainingDevicePath,
    BOOLEAN Recursive
);

using EfiDisconnectControllerFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE ControllerHandle,
    EFI_HANDLE DriverImageHandle,
    EFI_HANDLE ChildHandle
);

using EfiProtocolsPerHandleFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    EfiGuid*** ProtocolBuffer,
    UINTN* ProtocolBufferCount
);

using EfiLocateHandleBufferFn = EFI_STATUS (EFIAPI *)(
    EfiLocateSearchType SearchType,
    const EfiGuid* Protocol,
    VOID* SearchKey,
    UINTN* NoHandles,
    EFI_HANDLE **Buffer
);

using EfiLocateProtocolFn = EFI_STATUS (EFIAPI *)(
    const EfiGuid* Protocol,
    VOID* Registration,
    VOID** Interface
);

using EfiInstallMultipleProtocolInterfacesFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE *Handle,
    ...
);

using EfiUninstallMultipleProtocolInterfacesFn = EFI_STATUS (EFIAPI *)(
    EFI_HANDLE Handle,
    ...
);

#endif
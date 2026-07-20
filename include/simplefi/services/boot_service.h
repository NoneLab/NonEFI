#ifndef __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_SERVICE_H
#define __SIMPLEFI_PROTOCOLS_SERVICES_BOOT_SERVICE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>
#include <simplefi/services/boot/image_service.h>
#include <simplefi/services/boot/memory_service.h>
#include <simplefi/services/boot/event_time_service.h>
#include <simplefi/services/boot/task_priority_service.h>
#include <simplefi/services/boot/protocol_handler_service.h>
#include <simplefi/services/boot/miscellaneous_boot_service.h>

#define EFI_BOOT_SERVICES_SIGNATURE 0x56524553544f4f42
#define EFI_BOOT_SERVICES_REVISION EFI_SPECIFICATION_VERSION

struct EfiBootServices
{
    EfiTableHeader Hdr;

    // Task Priority Services
    EfiRaiseTPLFn RaiseTPL;
    EfiRestoreTPLFn RestoreTPL;

    // Memory Services
    EfiAllocatePagesFn AllocatePages;
    EfiFreePagesFn FreePages;
    EfiGetMemoryMapFn GetMemoryMap;
    EfiAllocatePoolFn AllocatePool;
    EfiFreePoolFn FreePool;

    // Event & Timer Services
    EfiCreateEventFn CreateEvent;
    EfiSetTimerFn SetTimer;
    EfiWaitForEventFn WaitForEvent;
    EfiSignalEventFn SignalEvent;
    EfiCloseEventFn CloseEvent;
    EfiCheckEventFn CheckEvent;

    // Protocol Handler Services
    EfiInstallProtocolInterfaceFn InstallProtocolInterface;
    EfiReinstallProtocolInterfacefn ReinstallProtocolInterface;
    EfiUninstallProtocolInterfaceFn UninstallProtocolInterface;
    EfiHandleProtocolFn HandleProtocol;
    VOID* Reserved; // Just Reserved :=D
    EfiRegisterProtocolNotifyFn RegisterProtocolNotify;
    EfiLocateHandleFn LocateHandle;
    EfiLocateDevicePathFn LocateDevicePath;
    EfiInstallConfigurationTableFn InstallConfigurationTable;

    // Image Services
    EfiImageLoadFn LoadImage;
    EfiImageStartFn StartImage;
    EfiExitFn Exit;
    EfiImageUnloadFn UnloadImage;
    EfiExitBootServicesFn ExitBootServices;

    // Miscellaneous Services
    EfiGetNextMonotonicCountFn GetNextMonotonicCount;
    EfiStallFn Stall;
    EfiSetWatchdogTimerFn SetWatchDogTimer;

    // DriverSupport Services
    EfiConnectControllerFn ConnectController;
    EfiDisconnectControllerFn EfiDisconnectControllerFn;

    // Open and Close Protocol Services
    EfiOpenProtocolFn OpenProtocol;
    EfiCloseProtocolFn CloseProtocol;
    EfiOpenProtocolInformationFn OpenProtocolInformation;

    // Library Services
    EfiProtocolsPerHandleFn ProtocolsPerHandle;
    EfiLocateHandleBufferFn LocateHandleBuffer;
    EfiLocateProtocolFn LocateProtocol;
    EfiInstallMultipleProtocolInterfacesFn InstallMultipleProtocolInterfaces;
    EfiUninstallMultipleProtocolInterfacesFn UninstallMultipleProtocolInterfaces;

    // CRC Services
    EfiCalculateCRC32Fn CalculateCrc32;

    // Miscellaneous Services
    EfiCopyMemFn CopyMem;
    EfiSetMemFn SetMem;
    EfiCreateEventExFn CreateEventEx;
};

#endif
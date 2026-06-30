#ifndef __SIMPLEFI_DEFS_H
#define __SIMPLEFI_DEFS_H

#if defined(__x86_64__) && !defined (_WIN32)
#define EFIAPI __attribute__((ms_abi))
#else
#define EFIAPI
#endif

#endif
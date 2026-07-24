#ifndef __SIMPLEFI_UTILITY_SHELL_H
#define __SIMPLEFI_UTILITY_SHELL_H

#include <stdio.h>
#include <ltl/vector.h>
#include <ltl/expected.h>
#include <ltl/string_view.h>
#include <simplefi/types.h>

ltl::expected<ltl::vector<ltl::vector<wchar_t>>, EFI_STATUS> GetShellParameters();

#endif
#ifndef __SIMPLEFI_GUID_TABLE_H
#define __SIMPLEFI_GUID_TABLE_H

#include "types.h"

template<typename Protocol>
inline constexpr bool DependentFalse = false;

// Reference from Google's Fuchsia 
template<typename Protocol>
constexpr const EfiGuid& EfiGuidTable = [](){static_assert(DependentFalse<Protocol>, "Specialization missing");}();

#endif
#include <new>
#include <cstddef>
#include <cstdint>
#include <simplefi/efi.h>
#include <simplefi/defs.h>
#include <simplefi/types.h>
#include <simplefi/utility/runtime.h>

namespace std
{
const std::nothrow_t nothrow;
}

void* operator new(std::size_t count, const std::nothrow_t& tag)
{
    UNUSED_PARAMETER(tag);

    void* ret = nullptr;
    Runtime::GetSysTable()->BootServices->AllocatePool(EfiLoaderData, count, &ret);
    return ret;
}

void* operator new(std::size_t count)
{
    return operator new(count, std::nothrow);
}

void* operator new(std::size_t count, std::align_val_t al)
{
    UNUSED_PARAMETER(al);
    return operator new(count);
}

void* operator new[](std::size_t count, std::nothrow_t tag)
{
    return operator new(count, tag);
}

void* operator new[](std::size_t count)
{
    return operator new(count);
}

void operator delete(void* ptr) noexcept
{
    Runtime::GetSysTable()->BootServices->FreePool(ptr);
}

void operator delete[](void* ptr) noexcept
{
    operator delete(ptr);
}

void operator delete(void* ptr, std::size_t size, std::align_val_t al)
{
    operator delete(ptr);
}

void operator delete(void* ptr, std::size_t size)
{
    operator delete(ptr);
}

void operator delete[](void* ptr, std::size_t size, std::align_val_t al)
{
    operator delete(ptr);
}

void operator delete[](void* ptr, std::size_t size)
{
    operator delete(ptr);
}

void operator delete(void* ptr, std::align_val_t) noexcept 
{
    operator delete(ptr);
}
#include <exception>

extern "C" int __cdecl _purecall()
{
    __builtin_trap();
}

namespace std
{

[[noreturn]]
void __throw_bad_alloc()
{
    __builtin_trap();
}

}
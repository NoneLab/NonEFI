#include <simplefi/defs.h>
#include <simplefi/types.h>

#include <stdio.h>

// Temparay Implementation
namespace std::__1
{

[[noreturn]]
void __libcpp_verbose_abort(char const* str, ...)
{
    printf("Aborted : %s\r\n", str);
    while(true);
}

}
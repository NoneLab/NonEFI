#include <simplefi/utility/shell.h>

#include <simplefi/types.h>
#include <simplefi/utility/guid.h>
#include <simplefi/protocols/shell/parameter.h>

#include <ltl/vector.h>
#include <ltl/expected.h>
#include <ltl/string_view.h>
#include <ltl/utility.h>

ltl::expected<ltl::vector<ltl::vector<wchar_t>>, EFI_STATUS> GetShellParameters()
{
    ltl::vector<ltl::vector<wchar_t>> ret;

    ProtocolPtr<EfiShellParametersProtocol> shellParam = nullptr;

    if (auto val = OpenProtocol<EfiShellParametersProtocol>(Runtime::GetHandle()); val.has_value())
    {
        for (UINTN i = 0; i < val->get()->Argc; i++)
        {
            ltl::wstring_view wstr = val->get()->Argv[i];
            
            ret.emplace_back(
                wstr.data(), wstr.data() + wstr.size()
            );
            ret.back().push_back(L'\0');
        }
    }
    else 
    {
        return ltl::unexpected(val.error());
    }
    
    return ret;
}
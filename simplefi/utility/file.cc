#include <simplefi/utility/file.h>

#include <simplefi/types.h>
#include <simplefi/protocols/file.h>

#include <ltl/expected.h>

ltl::expected<SimpleFile, EFI_STATUS> SimpleFile::Open(
    const ltl::vector<CHAR16>& FileName,
    UINT64 OpenMode,
    UINT64 Attributes
)
{
    return this->Open(
        FileName.data(),
        OpenMode,
        Attributes
    );
}

ltl::expected<SimpleFile, EFI_STATUS> SimpleFile::Open(
    const CHAR16* FileName,
    UINT64 OpenMode,
    UINT64 Attributes
)
{
    EFI_STATUS status = EFI_SUCCESS;
    EfiFileProtocol* file = nullptr;

    status = ptr->Open(
        ptr.get(), 
        &file, 
        FileName, 
        OpenMode, 
        Attributes
    );
    if (status)
        return ltl::unexpected(status);

    return SimpleFile { file };
}

ltl::expected<UINTN, EFI_STATUS> SimpleFile::Write(
    const CHAR8* data,
    UINTN size
)
{
    EFI_STATUS status = EFI_SUCCESS;
    UINTN retSize = size;

    status = ptr->Write(
        ptr.get(),
        &retSize,
        data
    );

    if (status)
        return ltl::unexpected(status);

    return retSize;
}

ltl::expected<UINTN, EFI_STATUS> SimpleFile::Write(
    const ltl::vector<CHAR8>& data
)
{
    return this->Write(
        data.data(),
        data.size()
    );
}

ltl::expected<SimpleFile, EFI_STATUS> SimpleFS::OpenVolume()
{
    EFI_STATUS status;
    EfiFileProtocol* root = nullptr;

    status = ptr->OpenVolume(ptr.get(), &root);

    if (status)
        return ltl::unexpected(status);

    return SimpleFile { root };
}

void FileCloser::operator()(EfiFileProtocol* me)
{
    if (me)
        me->Close(me);
}
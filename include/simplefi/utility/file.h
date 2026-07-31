#ifndef __SIMPLEFI_UTILITY_FILE_H
#define __SIMPLEFI_UTILITY_FILE_H

#include <simplefi/defs.h>
#include <simplefi/types.h>
#include <simplefi/protocols/file.h>
#include <simplefi/protocols/simple_filesystem.h>

#include <ltl/vector.h>
#include <ltl/memory.h>
#include <ltl/utility.h>
#include <ltl/expected.h>

#include "guid.h"


struct FileCloser
{
    void operator()(EfiFileProtocol* me);
};

using FilePtr = ltl::unique_ptr<EfiFileProtocol, FileCloser>;

class SimpleFile
{
    FilePtr ptr;
public:
    explicit SimpleFile(FilePtr ptr) : ptr(ltl::move(ptr)) { }
    explicit SimpleFile(EfiFileProtocol* ptr = nullptr) : ptr(ptr) { }
    SimpleFile(const SimpleFile&) = delete;
    SimpleFile& operator=(const SimpleFile&) = delete;

    SimpleFile(SimpleFile&&) noexcept = default;
    SimpleFile& operator=(SimpleFile&&) noexcept = default;

    ~SimpleFile() = default;

    ltl::expected<SimpleFile, EFI_STATUS> Open(
        const ltl::vector<CHAR16>& FileName,
        UINT64 OpenMode,
        UINT64 Attributes
    );

    ltl::expected<SimpleFile, EFI_STATUS> Open(
        const CHAR16* FileName,
        UINT64 OpenMode,
        UINT64 Attributes
    );

    ltl::expected<UINTN, EFI_STATUS> Write(
        const CHAR8* data,
        UINTN size
    );

    ltl::expected<UINTN, EFI_STATUS> Write(
        const ltl::vector<CHAR8>& data
    );
};

class SimpleFS
{
    ProtocolPtr<EfiSimpleFileSystemProtocol> ptr;
public:
    explicit SimpleFS(ProtocolPtr<EfiSimpleFileSystemProtocol> ptr) : ptr(ltl::move(ptr)) { }
    explicit SimpleFS(EfiSimpleFileSystemProtocol* ptr) : ptr(ptr) { }
    ~SimpleFS() = default;

    SimpleFS(SimpleFS&&) noexcept = default;
    SimpleFS& operator=(SimpleFS&&) noexcept = default;


    ltl::expected<SimpleFile, EFI_STATUS> OpenVolume();
};
#endif
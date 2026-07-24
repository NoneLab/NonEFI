#include <simplefi/efi.h>
#include <simplefi/types.h>
#include <simplefi/utility/runtime.h>

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <errno.h>
#include <sys/cdefs.h>
#include <sys/reent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <locale.h>
#include <wchar.h>

#include <ltl/span.h>
#include <ltl/memory.h>

__BEGIN_DECLS

struct _reent _impure_data = _REENT_INIT(_impure_data);
struct _reent *_impure_ptr = &_impure_data;
struct _reent *_global_impure_ptr = &_impure_data;

static int set_reent_errno(struct _reent *r, int err) {
    if (r) {
        r->_errno = err;
    }
    errno = err;
    return -1;
}

int *__errno (void)
{
    return nullptr;
}

void *_malloc_r(struct _reent *r, size_t size) 
{
    (void)r;
    (void)size;
    return nullptr;
}

void _free_r(struct _reent *r, void *ptr) {
    (void)r;
    (void)ptr;
}

_ssize_t _read_r(struct _reent *r, int fd, void *buf, size_t len) {
    (void)fd;
    (void)buf;
    (void)len;
    return set_reent_errno(r, ENOSYS);
}

_ssize_t _write_r(struct _reent *r, int fd, const void *buf, size_t len) {
    (void)r;
    (void)fd;
    (void)buf;
    size_t i;

    if (!Runtime::GetSysTable())
        return 0;
    
    if (fd == 1)
    {
        ltl::span<const char> strBuf = { reinterpret_cast<const char*>(buf), len };
        ltl::unique_ptr<wchar_t[]> tmpDst(new wchar_t[len + 1]);

        for(i = 0; i < strBuf.size(); i++)
            tmpDst[i] = static_cast<wchar_t>(strBuf[i]);

        tmpDst[strBuf.size()] = L'\0';

        Runtime::GetSysTable()->ConOut->OutputString(
            Runtime::GetSysTable()->ConOut,
            tmpDst.get()
        );
    }
    return (_ssize_t)len;
}

_off_t _lseek_r(struct _reent *r, int fd, _off_t offset, int whence) {
    (void)fd;
    (void)offset;
    (void)whence;
    return (_off_t)set_reent_errno(r, ENOSYS);
}

int _close_r(struct _reent *r, int fd) {
    (void)fd;
    return set_reent_errno(r, ENOSYS);
}

int _fstat_r(struct _reent *r, int fd, struct stat *st) {
    (void)fd;

    if (!st) {
        return set_reent_errno(r, EINVAL);
    }

    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty_r(struct _reent *r, int fd) {
    (void)r;
    (void)fd;
    return 1;
}

int _vfprintf_r(struct _reent *r,
   FILE *fp,
   const char *fmt,
   __va_list ap) {
    return _vfiprintf_r(r, fp, fmt, ap);
}

__END_DECLS

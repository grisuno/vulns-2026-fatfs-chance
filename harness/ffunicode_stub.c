/*---------------------------------------------------------------------------
 * ffunicode_stub.c — minimal Unicode stubs for the test harness
 *
 * When FF_USE_LFN >= 1 and FF_CODE_PAGE = 437, ff.c calls ff_oem2uni()
 * ff_uni2oem() and ff_wtoupper() which normally come from ffunicode.c.
 * These stubs are sufficient for all harness tests because no test opens
 * a file path containing non-ASCII characters.
 *---------------------------------------------------------------------------*/

#include "ff.h"

WCHAR ff_oem2uni(WCHAR oem, WORD cp)
{
    (void)cp;
    return (oem < 0x80) ? oem : 0;
}

WCHAR ff_uni2oem(DWORD uni, WORD cp)
{
    (void)cp;
    return (uni < 0x80) ? (WCHAR)uni : 0;
}

/* ff.h declares ff_wtoupper as:  DWORD ff_wtoupper(DWORD uni)  */
DWORD ff_wtoupper(DWORD chr)
{
    if (chr >= 'a' && chr <= 'z') return chr - ('a' - 'A');
    return chr;
}

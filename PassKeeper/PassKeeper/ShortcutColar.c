#include "Bibliotecas.h"

void ShortcutColar()
{
	HGLOBAL   hglb;
	LPTSTR    lptstr;
	HWND hwnd;


		if (!IsClipboardFormatAvailable(CF_TEXT)) return GetLastError();
		if (!OpenClipboard(NULL)) return GetLastError();

		hglb = GetClipboardData(CF_TEXT);
		if (hglb != NULL)
		{
			lptstr = GlobalLock(hglb);
			if (lptstr != NULL)
			{
				ReplaceSelection(hwnd, lptstr);
				GlobalUnlock(hglb);
			}
		}
		CloseClipboard();

		return ;
}


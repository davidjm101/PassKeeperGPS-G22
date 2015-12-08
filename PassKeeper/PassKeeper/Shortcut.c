#include "Bibliotecas.h"

void ShortcutCopiar(cliente *cliente1, char nome_conta[])
{
	conta *aux = cliente1->lista;

	while (strcmp(nome_conta, aux->nome)!= 0)
	{
		aux = aux->prox;
	}

	wchar_t wdadoes[20];
	mbstowcs(wdadoes, aux->password, strlen(aux->password) + 1);
	
	LPWSTR cwdBuffer = wdadoes;


	DWORD len = wcslen(cwdBuffer);
	HGLOBAL hdst;
	LPWSTR dst;

	hdst = GlobalAlloc(GMEM_MOVEABLE | GMEM_DDESHARE, (len + 1) * sizeof(WCHAR));
	dst = (LPWSTR)GlobalLock(hdst);
	memcpy(dst, cwdBuffer, len * sizeof(WCHAR));
	dst[len] = 0;
	GlobalUnlock(hdst);

	if (!OpenClipboard(NULL)) return GetLastError();
	EmptyClipboard();
	if (!SetClipboardData(CF_UNICODETEXT, hdst)) return GetLastError();
	CloseClipboard();

	return 0;
}
#include "Bibliotecas.h"

void BailOut(char *msg)
{
	fprintf(stderr, "Exiting: %s\n", msg);
	exit(1);
}
char* ShortcutColar(){ 

	HANDLE h;

	if (!OpenClipboard(NULL))
		BailOut("Can't open clipboard");

	h = GetClipboardData(CF_TEXT);

	//printf("%s\n", (char *)h);

	CloseClipboard();

	return h;
}


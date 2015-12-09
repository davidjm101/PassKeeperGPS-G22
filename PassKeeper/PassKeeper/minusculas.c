#include "Bibliotecas.h"

void minusculas(char palavra[])
{
	int i;
	int aux = strlen(palavra);
	for (i = 0; i < aux; i++)
	{
		palavra[i] = tolower(palavra[i]);
	}
}
#include "Bibliotecas.h"

int minusculas(char palavra[])
{
	int i;
	int aux = strlen(palavra);

	if (aux == 0 || palavra == NULL || strcmp(palavra, " ")==0)
	{
		return 1;
	}

	for (i = 0; i < aux; i++)
	{
		palavra[i] = tolower(palavra[i]);
	}
	return 0;
}
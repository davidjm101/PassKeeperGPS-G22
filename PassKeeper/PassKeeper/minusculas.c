#include "Bibliotecas.h"

void minusculas(char palavra[])
{
	int i;
	int aux = strlen(palavra);

	if (aux == 0)
	{
		strcpy(palavra,"erro na conversao");
		return;
	}

	for (i = 0; i < aux; i++)
	{
		palavra[i] = tolower(palavra[i]);
	}
}
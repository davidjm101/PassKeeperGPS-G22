#include "Bibliotecas.h"

int gera_pass_auto(char password[])
{
	int i = 0;

	if (password == NULL )
	{
		return 1;
	}
	char maiusculas[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z' };

	char minusculas[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z' };

	char numeros[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	char especiais[10] = { '!', '?', '#', '$', '%', '&', '@', '+', '-', '_' };

	srand(time(NULL));
	int random = 0;
	for (i = 0; i < MAX_PASS-1; i++)
	{
		if (i == 0 || i == 4 || i == 8 || i == 12)
		{
			random = rand() % 25;
			password[i] = maiusculas[random];
		}
		if (i == 1 || i == 5 || i == 9 || i == 13)
		{
			random = rand() % 25;
			password[i] = minusculas[random];
		}
		if (i == 2 || i == 6 || i == 10 || i == 14)
		{
			random = rand() % 9;
			password[i] = numeros[random];
		}
		if (i == 3 || i == 7 || i == 11 || i == 15)
		{
			random = rand() % 9;
			password[i] = especiais[random];
		}
	}
	password[MAX_PASS-1] = '\0';
	return 0;
}
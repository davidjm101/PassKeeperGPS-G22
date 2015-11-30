#include"Bibliotecas.h"

void desencripta(char palavra[])
{
	int num_chars = 0;
	int i = 0;
	int j = 0;
	char original[72] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
						  'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
						  'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
						  'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
						  'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7',
						  '8', '9', '!', '?', '#', '$', '%', '&', '@', '+', '-', '_' };

	char aleatoria[72] = { '8', 'y', 'W', 'm', 'K', 'a', '9', 'z', 'X', 'n', 'L', 'b',
						   '!', 'A', 'Y', 'o', 'M', 'c', '?', 'B', 'Z', 'p', 'N', 'd',
						   '#', 'C', '0', 'q', 'O', 'e', '$', 'D', '1', 'r', 'P', 'f',
						   '%', 'E', '2', 's', 'Q', 'g', '&', 'F', '3', 't', 'R', 'h',
						   '@', 'G', '4', 'u', 'S', 'i', '+', 'H', '5', 'v', 'T', 'j',
						   '-', 'I', '6', 'w', 'U', 'k', '_', 'J', '7', 'x', 'V', 'l' };

	num_chars = strlen(palavra);

	for (i = 0; i < num_chars; i++)
	{
		for (j = 0; j < 72; j++)
		{
			if (palavra[i] == aleatoria[j])
			{
				palavra[i] = original[j];
				break;
			}
			else
			{
				if (palavra[i] == ' ')
				{
					break;
				}
			}
		}
	}
}
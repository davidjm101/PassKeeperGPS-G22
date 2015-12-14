#include "Bibliotecas.h"

//funcao que verifica se a masterkey segue as guidelines impostas para que a sua criacao seja possivel
//se a masterkey seguir as guidelines imposta retorna true
// senao retorna false
bool verifica_master_guidelines(char masterkey[MAX_MK])
{
	int conta_maiusculas = 0;
	int conta_minisculas = 0;
	int conta_numeros = 0;
	int conta_especiais = 0;
	int i = 0;

	
	
	//verifca se a masterkey tem os caracteres minimos ou maximo obrigatorios
	if (strlen(masterkey) < 12 || strlen(masterkey) > 16)
	{
		return false;
	}
	else
	{
		for (i = 0; i < 100; i++)
		{
			//verifica se o caracter e minusculo
			if (masterkey[i] >= 'a' && masterkey[i] <= 'z')
			{
				conta_minisculas++;
			}
			//verifica se o caracter e maiusculo
			else if (masterkey[i] >= 'A' && masterkey[i] <= 'Z')
			{
				conta_maiusculas++;
			}
			//verifica se o caracter e numero
			else if (masterkey[i] >= '1' && masterkey[i] <= '9')
			{
				conta_numeros++;
			}
			else if (masterkey[i] == '!' || masterkey[i] == '?' || masterkey[i] == '#' || masterkey[i] == '$' || masterkey[i] == '%' || masterkey[i] == '&' || masterkey[i] == '@' || masterkey[i] == '+' || masterkey[i] == '-' || masterkey[i] == '_')
			{
				conta_especiais++;
			}
		}
	}

	//verifica que a masterkey tem 2 minusculas, 2 maiusculas e 4 numeros
	if (conta_minisculas >= 2 && conta_maiusculas >= 2 && conta_numeros >= 4 && conta_especiais>=4)//falta depois implementar para os caracteres especiais
	{
		return true;
	}
	else
		return false;
}
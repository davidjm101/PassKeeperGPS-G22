#include "Bibliotecas.h"

void pesquisar_conta()
{
	char nome_conta[MAX_NOME]="";
	
	titulo();
	printf("\n			Pesquisar Conta       \n\n");
	printf("Indique o nome da conta a pesquisar (Pode indicar apenas um prefixo do nome): ");
	scanf(" %[^\n]", nome_conta);
	printf("\nResultados");
	//fazer um ciclo que apresenta os dados das contas que tenham aquele nome ou que começam por aquelas letras
}
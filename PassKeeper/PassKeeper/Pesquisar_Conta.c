#include "Bibliotecas.h"

void pesquisar_conta(cliente *cliente1)
{
	char nome_conta[MAX_NOME]="";
	int cont = 1;
	conta *aux = cliente1->lista;

	// Ciclo para verificar se esta a ver bem as contas
	while (aux != NULL)
	{
		printf("\n\t%d. %s\tlogin:%s  pass:%s", cont, aux->nome, aux->login, aux->password);
		cont++;
		aux = aux->prox;
	}
	printf("\n\n");
	system("PAUSE");



	/*titulo();
	printf("\n			Pesquisar Conta       \n\n");
	printf("Indique o nome da conta a pesquisar (Pode indicar apenas um prefixo do nome): ");
	scanf(" %[^\n]", nome_conta);
	printf("\nResultados");*/
	//fazer um ciclo que apresenta os dados das contas que tenham aquele nome ou que começam por aquelas letras
}
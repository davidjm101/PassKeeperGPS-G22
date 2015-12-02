#include "Bibliotecas.h"

void pesquisar_conta(cliente *cliente1)
{
	int i;
	int tam;
	int flag;
	int contador=0;
	int contador_pesq = 0;
	char nome_conta[MAX_NOME] = "";
	conta *aux = cliente1->lista;
	char j;

	system("cls");
	titulo();
	printf("\n			Pesquisar Conta       \n\n");
	printf("Indique o nome da conta a pesquisar (Pode indicar apenas um prefixo do nome): ");
	fflush(stdin);
	gets(nome_conta);
	
		for (i = 0; i < MAX_NOME; i++)
		{
			j = nome_conta[i];
			if (j != '\0')
				contador++;
			else
				break;
		}
	tam = contador;

	while (aux != NULL)
	{
		flag = 0;
		for (i = 0; i < tam; i++)
		{
			if (aux->nome[i] == nome_conta[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			contador_pesq++;
			printf("%d.\t%s\n", contador_pesq, aux->nome);
		}
		aux = aux->prox;
	}
	system("PAUSE");
}
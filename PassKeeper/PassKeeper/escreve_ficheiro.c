#include "Bibliotecas.h"

void escreve_ficheiro(cliente *cliente, char nomePasta[]){
	FILE *f = NULL;
	conta *aux;

	aux = cliente->lista;

	//strcat(nomePasta, "/.bin");
	f = fopen(nomePasta, "wb+"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro nao foi criado com sucesso!\n");
		system("PAUSE");
		return 0;
	}
	//encripta os dados do cliente
	if (encripta(cliente->username) == 1)
	{
		printf("Erro ao encriptar\n");
		system("PAUSE");
		exit(0);
	}
	if (encripta(cliente->masterkey) == 1)
	{
		printf("Erro ao encriptar\n");
		system("PAUSE");
		exit(0);
	}
	if (encripta(cliente->perg_seguranca) == 1)
	{
		printf("Erro ao encriptar\n");
		system("PAUSE");
		exit(0);
	}
	if (encripta(cliente->resp_seguranca) == 1)
	{
		printf("Erro ao encriptar\n");
		system("PAUSE");
		exit(0);
	}
	
	
	

	fwrite(cliente, sizeof(*cliente), 1, f);

	while (aux != NULL)
	{
		//encripta dados das contas
		
		
		
		if (encripta(aux->login) == 1)
		{
			printf("Erro ao encriptar\n");
			system("PAUSE");
			exit(0);
		}
		if (encripta(aux->nome) == 1)
		{
			printf("Erro ao encriptar\n");
			system("PAUSE");
			exit(0);
		}
		if (encripta(aux->password) == 1)
		{
			printf("Erro ao encriptar\n");
			system("PAUSE");
			exit(0);
		}
	

		fwrite(aux, sizeof(conta), 1, f);
		aux = aux->prox;
	}

	printf("\n");

	fclose(f);
}
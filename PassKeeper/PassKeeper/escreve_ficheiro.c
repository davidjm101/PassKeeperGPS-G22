#include "Bibliotecas.h"

void escreve_ficheiro(cliente *cliente, char nomePasta[]){
	FILE *f = NULL;
	conta *aux;

	aux = cliente->lista;

	//strcat(nomePasta, "/.bin");
	f = fopen(nomePasta, "wb+"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro não foi criado com sucesso!\n");
		system("PAUSE");
		return 0;
	}
	//encripta os dados do cliente
	encripta(cliente->username);
	encripta(cliente->masterkey);
	encripta(cliente->perg_seguranca);
	encripta(cliente->resp_seguranca);

	fwrite(cliente, sizeof(*cliente), 1, f);

	while (aux != NULL)
	{
		//encripta dados das contas
		encripta(aux->login);
		encripta(aux->nome);
		encripta(aux->password);

		fwrite(aux, sizeof(conta), 1, f);
		aux = aux->prox;
	}

	printf("\n");

	fclose(f);
}
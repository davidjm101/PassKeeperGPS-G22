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

	fwrite(cliente, sizeof(*cliente), 1, f);

	while (aux != NULL)
	{
		fwrite(aux, sizeof(conta), 1, f);
		aux = aux->prox;
	}

	fclose(f);
}
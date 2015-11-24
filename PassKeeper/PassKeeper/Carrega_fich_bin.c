#include "Bibliotecas.h"

pcliente carrega_fich_bin()
{
	int i = 0;
	pcliente cliente;
	pconta aux, novo;
	char nome_fich[15] = ".bin";
	FILE *f;

	f = fopen(nome_fich, "rb");
	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro n�o foi encontrado!\n");
		system("PAUSE");
		return 0;
	}

	cliente = malloc(sizeof(cliente)); // aloca espa�o em mem�ria para uma estrutura do tipo cliente

	fread(cliente, sizeof(cliente), 1, f); // l� uma estrutura do ficheiro bin�rio

	cliente->lista = malloc(sizeof(conta)); // aloca espa�o em mem�ria para uma estrutura do tipo conta e esse espa�o fica apontado pelo ponteiro lista
											// corresponde ao primeiro elemento da lista
	fread(cliente->lista, sizeof(conta), 1, f); // l� uma estrutura do ficheiro bin�rio

	aux = cliente->lista; // ponteiro auxiliar fica a apontar para a primeira estrutura

	for (i = 1; i < cliente->num_contas; i++) //ciclo para carregar todas as contas do utilizador
	{
		novo = malloc(sizeof(conta)); // aloca espa�o para uma nova conta
		fread(novo, sizeof(conta), 1, f); // l� do ficheiro bin�rio
		aux->prox = novo; // ponteiro prox do elemento anterior fica a apontar para o novo elemento
		aux = novo; // ponteiro aux(ultimo elemento da lista) � actualizado
	}

	fclose(f); // ficheiro bin�rio fechado

	return cliente;
}
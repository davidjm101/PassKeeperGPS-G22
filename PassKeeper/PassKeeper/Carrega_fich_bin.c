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
		printf("\nErro! Ficheiro não foi encontrado!\n");
		system("PAUSE");
		return 0;
	}

	cliente = malloc(sizeof(cliente)); // aloca espaço em memória para uma estrutura do tipo cliente

	fread(cliente, sizeof(cliente), 1, f); // lê uma estrutura do ficheiro binário

	cliente->lista = malloc(sizeof(conta)); // aloca espaço em memória para uma estrutura do tipo conta e esse espaço fica apontado pelo ponteiro lista
											// corresponde ao primeiro elemento da lista
	fread(cliente->lista, sizeof(conta), 1, f); // lê uma estrutura do ficheiro binário

	aux = cliente->lista; // ponteiro auxiliar fica a apontar para a primeira estrutura

	for (i = 1; i < cliente->num_contas; i++) //ciclo para carregar todas as contas do utilizador
	{
		novo = malloc(sizeof(conta)); // aloca espaço para uma nova conta
		fread(novo, sizeof(conta), 1, f); // lê do ficheiro binário
		aux->prox = novo; // ponteiro prox do elemento anterior fica a apontar para o novo elemento
		aux = novo; // ponteiro aux(ultimo elemento da lista) é actualizado
	}

	fclose(f); // ficheiro binário fechado

	return cliente;
}
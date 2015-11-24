#include "Bibliotecas.h"

int cria_fich_bin(pcliente cliente)
{
	int i = 0;
	int j = 0;
	int num_contas = 0;
	FILE *f = NULL;

	char nome_fich[15] = ".bin";
	pconta escreve;
	pconta aux;

	f = fopen(nome_fich, "wb"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro não foi criado com sucesso!\n");
		system("PAUSE");
		return 0;
	}

	fwrite(&cliente, 1, sizeof(cliente), f); // escreve no ficheiro binário a informação relativa ao cliente (utilizador) (login, masterkey, pergunta secreta, etc)
	escreve = cliente->lista;
	num_contas = cliente->num_contas;

	for (i = 0; i < num_contas; i++)
	{
		fwrite(&escreve, 1, sizeof(conta), f);
		aux = escreve->prox;

	}

}
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
	escreve = cliente->lista; // ponteiro para lista de contas é copiado para a variavel escreve
	num_contas = cliente->num_contas; // numero de contas do cliente é guardado numa variavel para correr a lista correctamente
	

	for (i = 0; i < num_contas; i++) //ciclo para correr lista de contas
	{
		fwrite(&escreve, 1, sizeof(conta), f); // escreve conta para ficheiro binário
		aux = escreve;							// ponteiro para a conta actual é copiado
		escreve = escreve->prox;				// ponteiro escreve passa a apontar para o proximo elemento da lista
		free(aux);								// memória alocada para a conta actual é libertada
	}

	free(cliente);	// memoria alocada para o cliente é libertada
	fclose(f); // ficheiro binário é fechado
}
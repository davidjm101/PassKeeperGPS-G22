#include "Bibliotecas.h"

int cria_fich_bin(cliente *cliente, char nomePasta[])
{
	int i = 0;
	int num_contas = 0;
	FILE *f = NULL;
	// DUVIDA ------------- editar para mais de 15?
	//char nome_fich[15] = ".bin";
	strcat(nomePasta, "/.bin");

	pconta escreve;
	pconta aux;
	
	f = fopen(nomePasta, "wb"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro não foi criado com sucesso!\n");
		system("PAUSE");
		return 0;
	}

	cliente->num_contas = 0;
	cliente->lista = NULL;
	// encriptação dos dados para escrita
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
	//escreve dados no ficheiro binário
	fwrite(cliente, sizeof(*cliente), 1, f); // escreve no ficheiro binário a informação relativa ao cliente (utilizador) (login, masterkey, pergunta secreta, etc)
	
	//cliente->lista = malloc(sizeof(conta));
	//cliente->lista = NULL;
	//num_contas = 0;
	//escreve = cliente->lista; // ponteiro para lista de contas é copiado para a variavel escreve
	//num_contas = cliente->num_contas; // numero de contas do cliente é guardado numa variavel para correr a lista correctamente

	//for (i = 0; i <= num_contas; i++) //ciclo para correr lista de contas
	//{
	//	fwrite(cliente->lista, sizeof(conta), 1, f); // escreve conta para ficheiro binário
	//	aux = escreve;							// ponteiro para a conta actual é copiado
	//	escreve = escreve->prox;				// ponteiro escreve passa a apontar para o proximo elemento da lista
	//	free(aux);								// memória alocada para a conta actual é libertada
	//}

	//free(cliente);	// memoria alocada para o cliente é libertada
	
	fclose(f); // ficheiro binário é fechado
}
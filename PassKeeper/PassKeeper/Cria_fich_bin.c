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

	//f = fopen(nome_fich, "wb"); // cria ficheiro
	
	f = fopen(nomePasta, "wb"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro n�o foi criado com sucesso!\n");
		system("PAUSE");
		return 0;
	}

	cliente->num_contas = 0;
	cliente->lista = NULL;
	// encripta��o dos dados para escrita
	encripta(cliente->username);
	encripta(cliente->masterkey);
	encripta(cliente->perg_seguranca);
	encripta(cliente->resp_seguranca);
	//escreve dados no ficheiro bin�rio
	fwrite(cliente, sizeof(*cliente), 1, f); // escreve no ficheiro bin�rio a informa��o relativa ao cliente (utilizador) (login, masterkey, pergunta secreta, etc)
	
	//cliente->lista = malloc(sizeof(conta));
	//cliente->lista = NULL;
	//num_contas = 0;
	//escreve = cliente->lista; // ponteiro para lista de contas � copiado para a variavel escreve
	//num_contas = cliente->num_contas; // numero de contas do cliente � guardado numa variavel para correr a lista correctamente

	//for (i = 0; i <= num_contas; i++) //ciclo para correr lista de contas
	//{
	//	fwrite(cliente->lista, sizeof(conta), 1, f); // escreve conta para ficheiro bin�rio
	//	aux = escreve;							// ponteiro para a conta actual � copiado
	//	escreve = escreve->prox;				// ponteiro escreve passa a apontar para o proximo elemento da lista
	//	free(aux);								// mem�ria alocada para a conta actual � libertada
	//}

	//free(cliente);	// memoria alocada para o cliente � libertada
	
	fclose(f); // ficheiro bin�rio � fechado
}
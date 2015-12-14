#include "Bibliotecas.h"

int cria_fich_bin(cliente *cliente, char nomePasta[])
{
	int i = 0;
	int num_contas = 0;
	FILE *f = NULL;
	strcat(nomePasta, "/.bin");

	pconta escreve;
	pconta aux;
	
	f = fopen(nomePasta, "wb"); // cria ficheiro

	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		printf("\nErro! Ficheiro nao foi criado com sucesso!\n");
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
	

	fclose(f); // ficheiro binário é fechado
}
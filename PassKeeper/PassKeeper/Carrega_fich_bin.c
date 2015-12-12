#include "Bibliotecas.h"

pcliente carrega_fich_bin(char nomePasta[])
{
	int i = 0;
	pcliente cliente;
	pconta aux, novo;
	//char nome_fich[15] = ".bin";
	char nome_fich[22];
	FILE *f;

	strcpy(nome_fich, strcat(nomePasta, "/.bin"));

	f = fopen(nome_fich, "rb");
	if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	{
		//printf("\nErro! Ficheiro n�o foi encontrado!\n");
		//system("PAUSE");
		return 0;
	}

	cliente = malloc(sizeof(*cliente)); // aloca espa�o em mem�ria para uma estrutura do tipo cliente

	fread(cliente, sizeof(*cliente), 1, f); // l� uma estrutura do ficheiro bin�rio
	
	//desencripta��o dos dados do ficheiro
	desencripta(cliente->username);
	desencripta(cliente->masterkey);
	desencripta(cliente->perg_seguranca);
	desencripta(cliente->resp_seguranca);
	//
	cliente->lista = malloc(sizeof(conta)); // aloca espa�o em mem�ria para uma estrutura do tipo conta e esse espa�o fica apontado pelo ponteiro lista
											// corresponde ao primeiro elemento da lista
	if (fread(cliente->lista, sizeof(conta), 1, f) == 0){
		cliente->lista = NULL;
	}
	else
	{
			aux = cliente->lista;
			desencripta(aux->login);
			desencripta(aux->nome);
			desencripta(aux->password);
	}
	

	//if (fread(cliente->lista, sizeof(conta), 1, f) == NULL) // l� uma estrutura do ficheiro bin�rio
	//{
	//	cliente->lista = NULL;
	//	cliente->num_contas = 0;
	//	aux = cliente->lista; // ponteiro auxiliar fica a apontar para a primeira estrutura
	//}
	//else{
	//	novo = malloc(sizeof(conta)); // aloca espa�o para uma nova conta
	//	fread(novo, sizeof(conta), 1, f); // l� do ficheiro bin�rio
	//	aux->prox = novo; // ponteiro prox do elemento anterior fica a apontar para o novo elemento
	//	aux = novo; // ponteiro aux(ultimo elemento da lista) � actualizado
	//}

	
	for (i = 1; i < cliente->num_contas; i++) //ciclo para carregar todas as contas do utilizador
	{
		novo = malloc(sizeof(conta)); // aloca espa�o para uma nova conta
		fread(novo, sizeof(conta), 1, f); // l� do ficheiro bin�rio
		//desencripta os dados
		desencripta(novo->login);
		desencripta(novo->nome);
		desencripta(novo->password);
		aux->prox = novo; // ponteiro prox do elemento anterior fica a apontar para o novo elemento
		aux = novo; // ponteiro aux(ultimo elemento da lista) � actualizado
	}

	fclose(f); // ficheiro bin�rio fechado

	return cliente;
}
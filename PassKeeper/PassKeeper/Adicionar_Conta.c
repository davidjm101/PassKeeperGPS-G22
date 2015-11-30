#include "Bibliotecas.h"

void adicionar_conta(cliente *cliente1, char nomePasta[])
{
	int opcao_menu = 0;
	int controlo = 0;
	conta conta, *aux, *novo;
	FILE *f = NULL;

	aux = cliente1->lista;


	titulo();
	printf("\n					Adicionar Conta       \n\n");
	printf("Indique o login: ");
	scanf(" %[^\n]", conta.login);
	do
	{
		printf("\nIndique se pretende password (1-Manual   2-Automatica): ");
		controlo = scanf("%d", &opcao_menu);
		if (entradas_int(controlo) == 0)
		{
			controlo = 0;
			opcao_menu = 0;
		}
		else
		{
			controlo = 1;
		}
	} while (controlo < 1 || opcao_menu < 1 || opcao_menu>2);

	if (opcao_menu == 1)
	{
		printf("\nIndique a password: ");
		scanf(" %[^\n]", conta.password);
	}
	else
	{
		//chamar a funcao que gere passwords automaticas
		printf("Password gerada com sucesso");
	}
	printf("\nIndique nome da conta: ");
	scanf(" %[^\n]", conta.nome);

	if (aux == NULL)
	{
		novo = malloc(sizeof(conta));
		strcpy(novo->login, conta.login);
		strcpy(novo->nome, conta.nome);
		strcpy(novo->password, conta.password);
		novo->prox = NULL;
		cliente1->num_contas++;
		cliente1->lista = novo;
	}
	else{
		while (aux->prox != NULL)
		{
			aux = aux->prox;
		}
		novo = malloc(sizeof(conta));
		strcpy(novo->login, conta.login);
		strcpy(novo->nome, conta.nome);
		strcpy(novo->password, conta.password);
		novo->prox = NULL;
		aux->prox = novo;
		cliente1->num_contas++;
	}
	//cliente1->lista = aux;

	escreve_ficheiro(cliente1, nomePasta);

	//strcat(nomePasta, "/.bin");
	//f = fopen(nomePasta, "wb"); // cria ficheiro

	//if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	//{
	//	printf("\nErro! Ficheiro n�o foi criado com sucesso!\n");
	//	system("PAUSE");
	//	return 0;
	//}

	//fwrite(cliente1, sizeof(pcliente), 1, f);

	printf("\nConta adicionada!!");
	printf("\nLogin %s", conta.login);
	printf("\nPass %s", conta.password);
	printf("\nNome %s", conta.nome);
	system("PAUSE");

	//fwrite()
	//adicionar a struct a lista ligada
}
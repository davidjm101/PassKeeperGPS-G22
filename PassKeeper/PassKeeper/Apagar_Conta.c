#include "Bibliotecas.h"

void apagar_conta(cliente *cliente1, char nomePasta[])
{
	char nome_conta[MAX_NOME]="";
	int opcao_menu, controlo;
	int cont = 1;
	conta *aux = cliente1->lista;


	titulo();
	printf("\n			Apagar Conta       \n\n");
	printf("indique o nome da conta a apagar: ");
	scanf(" %[^\n]", nome_conta);

	do{
		printf("\nPretende mesmo apagar a conta (1-Sim  2-Nao): ");
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
	} while (controlo<1 || opcao_menu<1 || opcao_menu>2);

	if (opcao_menu == 1)
	{
		printf("\nConta apagada!");
	}

	/*
	Ciclo para encontrar a conta escolhida para a remoção
	Começa por analisar a primeira estrutura com um if
	de seguida entra num ciclo While enquanto não encontra
	um nome equivalente ao inserido pelo utilizador
	*/
	//if que verifica a primeira entrada
	if (aux != NULL)
	{
		if (strcmp(nome_conta, aux->nome) == 0)
		{
			aux = aux->prox;
			cliente1->lista = aux;
		}
	}
	else{
		printf("\n\n\t Não existem contas para remover!");
	}

	//Ciclo while que procura o nome equivalente
	while (aux != NULL)
	{
		if (aux->prox != NULL){
			if (strcmp(nome_conta, aux->prox->nome) == 0)
			{
				aux->prox = aux->prox->prox;
			}
		}
		else{
			if (strcmp(nome_conta, aux->nome) == 0)
				aux = NULL;
			}
		aux = aux->prox;
	}
	cliente1->num_contas--;
	escreve_ficheiro(cliente1, nomePasta);

	system("PAUSE");
}
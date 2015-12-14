#include "Bibliotecas.h"

void pesquisar_conta(cliente *cliente1)
{
	int i;
	int tam;
	int flag;
	int contador = 0;
	int contador_pesq = 0;
	char nome_conta[MAX_NOME] = "";
	char array_aux[5];
	char array_aux_copia[7];
	char nomeCopiar[MAX_NOME];
	conta *aux = cliente1->lista;
	char j;
	int numero;
	char comando[10];
	

	system("cls");
	titulo();
	printf("\n			Pesquisar Conta       \n\n");
	printf("Indique o nome da conta a pesquisar (Pode indicar apenas um prefixo do nome): ");
	fflush(stdin);
	scanf("%s", &nome_conta);

		for (i = 0; i < MAX_NOME; i++)
		{
			j = nome_conta[i];
			if (j != '\0')
				contador++;
			else
				break;
		}

		tam = contador;
		if (minusculas(nome_conta) == 1)
		{
			printf("Erro de operacao");
			return;
		}
		
		if (strcmp(nome_conta, "tudo") == 0)
		{
			while (aux != NULL)
			{
				contador_pesq++;
				printf("%d.  Nome:  %-20sPassword:  %-20s\tLogin:  %-20s\n", contador_pesq, aux->nome, aux->password, aux->login);
				aux = aux->prox;
			}
		}
		else
		{
			contador_pesq = 0;
			while (aux != NULL)
			{
				flag = 0;
				for (i = 0; i < tam; i++)
				{
					if (aux->nome[i] == nome_conta[i])
						flag = 1;
					else
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1)
				{
					contador_pesq++;
					printf("%d.  Nome:  %-20sPassword:  %-20s\tLogin:  %-20s\n", contador_pesq, aux->nome, aux->password, aux->login);
				}
				aux = aux->prox;
			}
		}

		printf("Copiar(Password)/Sair (indique o comando que pertende) : ");
		fflush(stdin);
		scanf("%s", &comando);

		if (comando != NULL)
		{
			
			if (minusculas(comando) == 1)
			{
				printf("Erro de operacao");
				return;
			}

			if (strcmp(comando, "copiar") == 0 && cliente1->num_contas > 0)
			{
				printf("Insira o nome da conta para copiar a password : ");
				scanf("%s", &nomeCopiar);
				ShortcutCopiar(cliente1, nomeCopiar);
			}
			if (strcmp(comando, "sair") == 0)
			{
				return;
			}
		}
		else{
			printf("Comando não existente ou não há contas para pesquisar\n\n");
			return;
		}
		printf("\n");
}



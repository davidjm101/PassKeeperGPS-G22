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
			if (i<5)
			array_aux[i] = nome_conta[i];
			if (j != '\0')
				contador++;
			else
				break;
		}
		tam = contador;
		
		if (strcmp(nome_conta, "tudo") == 0)
		{
			while (aux != NULL)
			{
				contador_pesq++;
				printf("%d.  Login:%s  Password:%s  Nome:%s\n",contador_pesq, aux->login, aux->password, aux->nome);
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
					printf("%d.  Login:%s  Password:%s  Nome:%s\n", contador_pesq, aux->login, aux->password, aux->nome);
				}
				aux = aux->prox;
			}
		}

		printf("Copiar(Password)/Sair (indique o comando que pertende) : ");
		fflush(stdin);
		scanf("%s", &comando);
		for (i = 0; i < 7; i++)
		{
			array_aux_copia[i] = tolower(comando[i]);
		}
		if (strcmp(array_aux_copia, "copiar") == 0)
		{
			printf("Insira o nome da conta para copiar a password : ");
			scanf("%s", &nomeCopiar);
			ShortcutCopiar(cliente1, nomeCopiar);
		}
		if (strcmp(array_aux_copia, "sair") == 0)
		{
			return;
		}
		
	}



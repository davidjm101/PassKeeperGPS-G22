#include "Bibliotecas.h"

void editar_conta(cliente *cliente1)
{
	char nome_conta[MAX_NOME]="";
	char le_dado[MAX_NOME];
	char password[MAX_PASS];
	int opcao_menu = 0;
	int controlo = 0 ;
	int i = 0;
	conta *aux = cliente1->lista;
	titulo();
	printf("\n			Editar Conta       \n\n");
	printf("Indique o nome da conta a editar: ");
	fflush(stdin);
	gets(nome_conta);
	while (aux != NULL)
	{
		if (strcmp(nome_conta, aux->nome) == 1)
		{
			aux = aux->prox;
		}
		else
		{
			break;
		}

	}
	
	if (aux == NULL)
	{
		printf("Nome da conta nao encontrado");
	}
	else
	{
		do{
			printf("\nIndique o que pretende editar (1-Login  2-Password  3-Nome da conta): "); 
			fflush(stdin);
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
		} while (controlo<1 || opcao_menu<1 || opcao_menu>3);

		if (opcao_menu == 1)
		{
			printf("Indique o novo login: ");
			fflush(stdin);
			gets(le_dado);
			printf("Pretende alterar mesmo o login para %s (1-Sim 2-Nao):", le_dado);
			do{
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
				strcpy(aux->login, le_dado);
				printf("Login editado");
			}
			else
			{
				printf("Login nao editado!");
			}

		}


		else if (opcao_menu == 2)
		{
			printf("Indique o tipo de password (1-Manual 2-Automatica) : ");
			do{
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
				printf("Introduza a nova password: ");
				fflush(stdin);
				gets(password);
			}
			else if (opcao_menu == 2)
			{
				//chamar a funcao de gerar passwords automaticas
			}
			
			printf("Pretende alterar mesmo a password para %s (1-Sim 2-Nao):", le_dado);
			do{
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
				strcpy(aux->password, le_dado);
				printf("Password editada");
			}
			else
			{
				printf("Password nao editada!");
			}
		}


		else if (opcao_menu == 3)
		{
			printf("Indique o novo nome: ");
			fflush(stdin);
			gets(le_dado);
			printf("Pretende alterar mesmo o nome para %s (1-Sim 2-Nao):", le_dado);
			do{
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
				strcpy(aux->nome, le_dado);
				printf("Nome editado");
			}
			else
			{
				printf("Nome nao editado!");
			}
		}


		printf("\nLogin %s", aux->login);
		printf("\nPass %s", aux->password);
		printf("\nNome %s", aux->nome);
	}
}
	

		
	
	



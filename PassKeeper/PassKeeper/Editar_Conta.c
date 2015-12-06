#include "Bibliotecas.h"

void editar_conta(cliente *cliente1, char nomePasta[])
{
	char nome_conta[MAX_NOME]="";
	char le_dado[MAX_NOME]="";
	char password[MAX_PASS]="";
	int opcao_menu = 0;
	int controlo = 0 ;
	int i = 0;
	bool verifica = false;
	conta *aux = cliente1->lista;
	


	system("cls");
	titulo();
	printf("\n			Editar Conta       \n\n");
	printf("Indique o nome da conta a editar: ");
	fflush(stdin);
	gets(nome_conta);

	//ciclo que verifica se existe algum conta com o nome indicado pelo utilizador
	while (aux != NULL)
	{
		//compara o nome introduzido, pelo nome de conta ja existente
		//se encontrar sai do ciclo
		if (strcmp(nome_conta, aux->nome) == 0)
		{
			break;
		}
		//se nao for igual compara com o proximo nome
		else
		{
			aux = aux->prox;		
		}
	}
	
	//caso nao encontrar nenhum nome indica ao utilizador
	if (aux == NULL)
	{
		printf("Nome da conta nao encontrado!");
		system("PAUSE");
	}
	else
	{
		do{
			printf("\nIndique o que pretende editar (1-Login  2-Password  3-Nome da conta): "); 
			fflush(stdin);
			//verifica que a opcao introduzido é um numero e nao um caracter
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
			do
			{
				printf("Indique o novo login: ");
				fflush(stdin);
				gets(le_dado);
				// verifica se o login tem entre os minimos e maximos caracteres pedidos
				if (strlen(le_dado) < 1 || strlen(le_dado) > 100)
				{
					verifica = false;
					printf("\nLogin nao tem caracteres suficientes ou tem caracteres a mais (deve ter entre 1 e 100 caracteres)!\n");
				}
				else
				{
					verifica = true;
				}
			} while (verifica == false);
			
			
			printf("Pretende alterar mesmo o login para %s (1-Sim 2-Nao):", le_dado);
			do{
				controlo = scanf("%d", &opcao_menu);
				//verifica que a opcao introduzido é um numero e nao um caracter
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
				printf("Login editado!");
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
				fflush(stdin);
				controlo = scanf("%d", &opcao_menu);
				//verifica que a opcao introduzido é um numero e nao um caracter
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
				do
				{
					printf("Introduza a nova password: ");
					fflush(stdin);
					gets(password);
					// verifica se a password tem entre os minimos e maximos caracteres pedidos
					if (strlen(password) < 1 || strlen(password) > 16)
					{
						verifica = false;
						printf("\nPassword nao tem caracteres suficientes ou tem caracteres a mais (deve ter entre 1 e 16 caracteres)!\n");
					}
					else
					{
						verifica = true;
					}
				} while (verifica == false);
				
			}
			else if (opcao_menu == 2)
			{
				gera_pass_auto(password);
			}
			
			printf("Pretende alterar mesmo a password para %s (1-Sim 2-Nao):", password);
			do{
				fflush(stdin);
				controlo = scanf("%d", &opcao_menu);
				//verifica que a opcao introduzido é um numero e nao um caracter
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
				strcpy(aux->password, password);
				printf("Password editada!");
			}
			else
			{
				printf("Password nao editada!");
			}
		}


		else if (opcao_menu == 3)
		{
			do{
				printf("Indique o novo nome: ");
				fflush(stdin);
				gets(le_dado);
				// verifica se o nome tem entre os minimos e maximos caracteres pedidos
				if (strlen(le_dado) < 3|| strlen(le_dado) > 100)
				{
					verifica = false;
					printf("\nLNome nao tem caracteres suficientes ou tem caracteres a mais (deve ter entre 3 e 100 caracteres)!\n");
				}
				else
				{
					verifica = true;
				}
			} while (verifica == false);
			
	
			printf("Pretende alterar mesmo o nome para %s (1-Sim 2-Nao):", le_dado);
			do{
				controlo = scanf("%d", &opcao_menu);
				//verifica que a opcao introduzido é um numero e nao um caracter
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
				printf("Nome editado!");
			}
			else
			{
				printf("Nome nao editado!");
			}
		}

		escreve_ficheiro(cliente1, nomePasta);
		printf("\nLogin %s", aux->login);
		printf("\nPass %s", aux->password);
		printf("\nNome %s\n", aux->nome);
		system("PAUSE");
	}
}
	

		
	
	



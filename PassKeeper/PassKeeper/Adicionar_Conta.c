#include "Bibliotecas.h"

void adicionar_conta(cliente *cliente1, char nomePasta[])
{
	char opcao[10];
	int opcao_menu = 0;
	int controlo = 0;
	conta conta, *aux, *novo;
	FILE *f = NULL;
	bool existe = false;//variavel que serve para verificar se o nome da conta ja existe associado a outra conta
	bool verifica = false; //para verificar se o login, nome e password tem os caracteres suficientes
	aux = cliente1->lista;

	system("cls");
	titulo();
	printf("\n					Adicionar Conta       \n\n");
	
	do
	{
		printf("Indique o login: ");
		fflush(stdin);
		fgets(conta.login, MAX_LOG, stdin);
		strtok(conta.login, "\n");
		// verifica se o login tem entre os minimos e maximos caracteres pedidos
		if (strlen(conta.login) < 1 || strlen(conta.login) > MAX_LOG)
		{
			verifica = false;
			printf("\nLogin nao tem caracteres suficientes ou tem caracteres a mais (deve ter entre 1 e 100 caracteres)!\n");
		}
		else
		{
			verifica = true;
		}
	} while (verifica == false);
	
	do
	{
		printf("\nIndique se pretende password (1-Manual   2-Automatica  3-Colar): ");
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
	} while (controlo < 1 || opcao_menu < 1 || opcao_menu > 3);

	if (opcao_menu == 1)
	{
		do{
			printf("\nIndique a password: ");
			fflush(stdin);
			fgets(conta.password, MAX_PASS, stdin);
			strtok(conta.password, "\n");
			// verifica se a password tem entre os minimos e maximos caracteres pedidos
			if (strlen(conta.password) < 1 || strlen(conta.password) > MAX_PASS)
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
	else if (opcao_menu==2)
	{
		controlo = gera_pass_auto(conta.password);
		if (controlo == 1)
		{
			printf("Erro fatal");
			system("PAUSE");
			exit(0);
		}
		else
		{
			printf("Password gerada com sucesso");
		}
		
	}
	else
	{
		char *h = ShortcutColar();
		printf("Password utilizada\t%s", h);
		strcpy(conta.password, h);
	}

	do
	{
		existe = false;
		do{
			printf("\nIndique nome da conta (nome 'tudo' e invalido): ");
			fflush(stdin);
			fgets(conta.nome, MAX_NOME, stdin);
			strtok(conta.nome, "\n");
			minusculas(conta.nome);
			// verifica se o nome tem entre os minimos e maximos caracteres pedidos
			if (strlen(conta.nome) < 3 || strlen(conta.nome) > MAX_NOME || strcmp(conta.nome, "tudo") == 0 )
			{
				verifica = false;
				printf("\nNome nao tem numero de caracteres ideal!\n");
			}
			else
			{
				verifica = true;
			}
		} while (verifica == false);
		

		//ciclo que verifica se existe alguma conta ja com o mesmo nome
		while (aux != NULL)
		{
			if (strcmp(conta.nome, aux->nome) == 0)
			{
				existe = true;
				break;
			}
			else
			{
				aux = aux->prox;
			}

		}

		if (existe==true)
		{
			printf("\nNome de conta existente ou inválido, tente novamente");
		}
	} while (existe==true);
	

	aux = cliente1->lista;
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


	escreve_ficheiro(cliente1, nomePasta);

	strtok(nomePasta, "/");
	

	printf("\nConta adicionada!!");
	printf("\nLogin %s", conta.login);
	printf("\nPass %s", conta.password);
	printf("\nNome %s", conta.nome);
	system("PAUSE");

}
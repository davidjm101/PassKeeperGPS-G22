#include "Bibliotecas.h"

void adicionar_conta(cliente *cliente1, char nomePasta[])
{
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
		gets(conta.login);
		// verifica se o login tem entre os minimos e maximos caracteres pedidos
		if (strlen(conta.login) < 1 || strlen(conta.login) > 100)
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
		printf("\nIndique se pretende password (1-Manual   2-Automatica): ");
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
	} while (controlo < 1 || opcao_menu < 1 || opcao_menu>2);

	if (opcao_menu == 1)
	{
		do{
			printf("\nIndique a password: ");
			fflush(stdin);
			gets(conta.password);
			// verifica se a password tem entre os minimos e maximos caracteres pedidos
			if (strlen(conta.password) < 1 || strlen(conta.password) > 16)
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
	else
	{
		gera_pass_auto(conta.password);
		printf("Password gerada com sucesso");
	}

	do
	{
		existe = false;
		do{
			printf("\nIndique nome da conta: ");
			fflush(stdin);
			gets(conta.nome);
			// verifica se o nome tem entre os minimos e maximos caracteres pedidos
			if (strlen(conta.nome) < 3 || strlen(conta.nome) > 100)
			{
				verifica = false;
				printf("\nLNome nao tem caracteres suficientes ou tem caracteres a mais (deve ter entre 3 e 100 caracteres)!\n");
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
			printf("\nExiste uma conta ja com esse nome, escolha outro nome de conta!");
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
	//cliente1->lista = aux;

	escreve_ficheiro(cliente1, nomePasta);

	//strcat(nomePasta, "/.bin");
	//f = fopen(nomePasta, "wb"); // cria ficheiro

	//if (f == NULL) // verifica se o ficheiro foi criado com sucesso
	//{
	//	printf("\nErro! Ficheiro não foi criado com sucesso!\n");
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
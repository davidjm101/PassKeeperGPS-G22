#include "Bibliotecas.h"

void registo()
{
	cliente cliente;
	char nomePasta[16];
	bool verifica = false;

	system("cls");
	titulo();
	printf("\n			Registo       \n\n");
	
	do
	{
		printf("Introduza o username que pretende: ");
		fflush(stdin);
		gets(cliente.username);
		// verifica se o username tem entre os minimos e maximos caracteres pedidos
		if (strlen(cliente.username) < 3 || strlen(cliente.username) > 100)
		{
			verifica = false;
			printf("\nUsername nao tem caracteres suficientes ou tem caracteres a mais!\n");
		}
		else
		{
			verifica = true;
		}
	} while (verifica == false);
	

	do
	{
		printf("\nIndique a MasterKey que pretende");
		printf("\n(a sua MasterKey deve conter no minimo 4 numeros");
		printf("\n4 letras(2 maiusculas e 2 minisculas)");
		printf("\ne 4 caracteres especiais dos seguintes( ! ? # $ % & @ + - _ ): ");
		fflush(stdin);
		gets(cliente.masterkey);
		verifica=verifica_master_guidelines(cliente.masterkey);
		if (verifica == false)
		{
			printf("\nA MasterKey inserida nao cumpre as guidelines necessarias\n");
		}
	} while (verifica == false);
	

	do
	{
		printf("\nIndique a sua pergunta de seguranca: ");
		fflush(stdin);
		gets(cliente.perg_seguranca);
		// verifica se a pergunta de segurança tem entre os minimos e maximos caracteres pedidos
		if (strlen(cliente.perg_seguranca) < 1 || strlen(cliente.perg_seguranca) > 100)
		{
			verifica = false;
			printf("\nPergunta de seguranca nao tem caracteres suficientes ou tem caracteres a mais!\n");
		}
		else
		{
			verifica = true;
		}
	} while (verifica==false); 
	

	do
	{
		printf("Indique a resposta a sua pergunta de seguranca: ");
		fflush(stdin);
		gets(cliente.resp_seguranca);
		// verifica se a resposta a pergunta de segurança tem entre os minimos e maximos caracteres pedidos
		if (strlen(cliente.resp_seguranca) < 4 || strlen(cliente.resp_seguranca) > 32)
		{
			verifica = false;
			printf("\nResposta a pergunta de seguranca nao tem caracteres suficientes ou tem caracteres a mais!\n");
		}
		else
		{
			verifica = true;
		}
	} while (verifica == false);
	
	do{
		printf("\nIndique o nome da pasta onde sera guardado o ficheiro com as suas contas: ");
		fflush(stdin);
		gets(nomePasta);
		if (strlen(nomePasta) < 4 || strlen(nomePasta) > 16)
		{
			verifica = false;
			printf("\nPasta está a exceder limite de caracteres\n");
		}
		else
		{
			verifica = true;
		}
	} while (verifica == false);
	
	//Parcela de código que cria pasta conforme o nome dado no nomePasta
	int check = _mkdir(nomePasta, NULL);

	if (!check)
		printf("Directory created\n");
	else
	{
		printf("Unable to create directory\n");
		exit(1);
	}

	cria_fich_bin(&cliente, nomePasta);

	printf("\n\tNome: %s",cliente.username);
	printf("\n\tMaster: %s", cliente.masterkey);
	printf("\n\tPerg: %s", cliente.perg_seguranca);
	printf("\n\tNome: %s\n", cliente.resp_seguranca);
	system("PAUSE");
}
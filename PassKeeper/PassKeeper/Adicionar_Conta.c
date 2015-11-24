#include "Bibliotecas.h"

void adicionar_conta()
{
	int opcao_menu = 0;
	int controlo = 0;
	conta conta;
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
	} while (controlo<1 || opcao_menu<1 || opcao_menu>2);

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


	printf("\nConta adicionada!!");
	printf("\nLogin %s", conta.login);
	printf("\nPass %s", conta.password);
	printf("\nNome %s", conta.nome);

	//adicionar a struct a lista ligada
}
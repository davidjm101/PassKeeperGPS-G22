#include "Bibliotecas.h"

void adicionar_conta()
{
	int opcao_menu, controlo;
	titulo();
	printf("\n					Adicionar Conta       \n\n");
	printf("Indique o login: ");
	//fazer scanf da string para a struct das contas
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
		//fazer scanf da string para a struct das contas
	}
	else
	{
		//chamar a funcao que gere passwords automaticas
		printf("Password gerada com sucesso");
	}
	printf("\nIndique nome da conta: ");
	//fazer scanf da string para a struct das contas

	printf("\nConta adicionada!!");
	//fazer um printf com a informação do login, atraves da struct conta
	//fazer um printf com a informação da password, atraves da struct conta
	//fazer um printf com a informação do nome da conta, atraves da struct conta
}
#include "Bibliotecas.h"

void editar_conta()
{
	char nome_conta[MAX_NOME]="";
	int opcao_menu, controlo;
	titulo();
	printf("\n			Editar Conta       \n\n");
	printf("Indique o nome da conta a editar: ");
	scanf(" %[^\n]", nome_conta);

	//funcao que verifica se a conta existe 
	//se exitir imprimir os dados da conta em questao
	do{
		printf("\nIndique o que pretende editar (1-Login  2-Password  3-Nome da conta): ");
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
		//fazer scanf para a struct
		printf("Conta editada");
	}
	else if (opcao_menu == 2)
	{
		printf("Indique a nova password: ");
		//fazer scanf para a struct
		printf("Conta editada");
	}
	else 
	{
		printf("Indique o novo nome: ");
		//fazer scanf para a struct
		printf("Conta editada");
	}
}
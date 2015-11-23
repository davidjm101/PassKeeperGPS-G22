#include "Bibliotecas.h"

void menu_contas()
{
	int opcao_menu, controlo;
	do{
		do{
			titulo();
			printf("\n					Menu Contas       \n\n");
			printf("1- Adicionar conta\n");
			printf("2- Editar conta\n");
			printf("3- Apagar Conta\n");
			printf("4- Pesquisar Conta\n");
			printf("5- Logout\n\n");
			printf("Indique a opcao que pretende: ");
			fflush(stdin);
			controlo = scanf("%d", &opcao_menu);// controlo serve para verificar que apenas inteiros sao inseridos

			if (entradas_int(controlo) == 0)
			{
				controlo = 0;
				opcao_menu = 0;
			}
			else
			{
				controlo = 1;
			}
		} while (controlo<1 || opcao_menu<1 || opcao_menu>5);


		switch (opcao_menu)
		{
		case 1:
			//adicionar_conta();
			break;
		case 2:
			//editar_conta();
			break;
		case 3:
			//apagar_conta();
			break;
		case 4:
			//pesquisar_conta()
			break;
		case 5:
			//chamar a funcao para fazer logout
			break;
		default:
			break;
		}
	} while (1);




	printf("\n");

}
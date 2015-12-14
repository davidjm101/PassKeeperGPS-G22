#include "Bibliotecas.h"

void menu_contas(char nomeConta[], cliente *cliente, char nomePasta[])
{
	int opcao_menu, controlo;
	do{
		do{
			system("cls");
			titulo();
			printf("\n					Menu Contas       \n\n");
			printf("\n\tBem vindo %s\n\n", nomeConta);
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
			adicionar_conta(cliente, nomePasta);
			cliente = carrega_fich_bin(nomePasta);
			break;
		case 2:
			if (editar_conta(cliente, nomePasta) == 1)
				cliente = carrega_fich_bin(nomePasta);
			break;
		case 3:
			apagar_conta(cliente, nomePasta);
			cliente = carrega_fich_bin(nomePasta);
			break;
		case 4:
			pesquisar_conta(cliente);
			break;
		case 5:
			escreve_ficheiro(cliente, nomePasta);
			printf("Ate a proxima %s\n", nomeConta);
			system("PAUSE");
			exit(0);
			break;
		default:
			break;
		}
	} while (1);




	printf("\n");

}
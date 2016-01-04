#include "Bibliotecas.h"


void menu(){
	int opcao_menu,controlo;
	do{
			do{
				system("cls");
				titulo();
				printf("\n					Bem Vindo       \n\n");
				printf("1- Login\n");
				printf("2- Efectuar Registo\n");
				printf("3- Recuperar Master Key\n");
				printf("4- Manual de Intrucao\n");
				printf("5- Sair\n\n");
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
				login();
				break;
			case 2:
				registo();
				break;
			case 3:
				recupera_MasterKey();
				//chamar a funcao de recuperar masterkey
				break;
			case 4:
				manual_intrucao();
				break;
			case 5:
				printf("O programa vai encerrar!\n");
				exit(0);  //Forcar saida do programa
				break;
			default:
				break;
			}
	} while (true);
	



	printf("\n");

}
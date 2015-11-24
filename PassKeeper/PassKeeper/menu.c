#include "Bibliotecas.h"


void menu(){
	int opcao_menu,controlo;
	do{
			do{
				titulo();
				printf("\n					Bem Vindo       \n\n");
				printf("1- Efectuar Registo\n");
				printf("2- Login\n");
				printf("3- Recuperar Master Key\n");
				printf("4- Manual de Intrucao\n\n");
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
			} while (controlo<1 || opcao_menu<1 || opcao_menu>4);


			switch (opcao_menu)
			{
			case 1:
				registo();
				break;
			case 2:
				login();
				break;
			case 3:
				//chamar a funcao de recuperar masterkey
				break;
			case 4:
				//chamar a funcao do manual
				break;
			default:
				break;
			}
	} while (1);
	



	printf("\n");

}
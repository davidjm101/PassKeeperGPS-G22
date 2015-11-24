#include "Bibliotecas.h"

void apagar_conta()
{
	char nome_conta[MAX_NOME]="";
	int opcao_menu, controlo;
	titulo();
	printf("\n			Apagar Conta       \n\n");
	printf("indique o nome da conta a apagar: ");
	scanf(" %[^\n]", nome_conta);
	//funcao que verifica se a conta existe
	//se existir fazer o print da informação da conta
	
	do{
		printf("\nPretende mesmo apagar a conta (1-Sim  2-Nao): ");
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
		//apagar a conta
		printf("\nConta apagada!");
	}

	
}
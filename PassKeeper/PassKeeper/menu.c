
void menu_principal(){
	int opcao_menu,controlo;
	do{
			do{
				printf("1- Criar nova conta\n");
				printf("2- Iniciar Sessao na sua conta\n");
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

			}
	} while (1);
	



	printf("\n");

}
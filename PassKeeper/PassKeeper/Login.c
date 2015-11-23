#include "Bibliotecas.h"

void login()
{
	char username[MAX_NOME]="";
	char masterkey[MAX_MK];
	bool verifica=false;
	do{
		titulo();
		printf("\n					Login       \n\n");
		printf("Introduza o seu username: ");
		scanf(" %[^\n]", username);
		printf("\nIntroduza a sua MasterKey: ");
		scanf(" %[^\n]", masterkey);
		verifica=//chamar a funcao que vai verificar se o username e login estao bem, e retornar um boolean true se estiver tudo certo
	} while (verifica==false);
	
	
	


}
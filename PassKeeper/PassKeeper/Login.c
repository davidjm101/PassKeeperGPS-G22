#include "Bibliotecas.h"

void login()
{
	// Libraria dirent utilizada para ler os folders dentro da pasta
	DIR *dir;
	struct dirent* ent;

	char username[MAX_NOME]="";
	char masterkey[MAX_MK];
	bool verifica=false;
	pcliente aux; // Auxiliar para verificar todas as pastas

	do{
		titulo();
		printf("\n					Login       \n\n");
		printf("Introduza o seu username: ");
		scanf(" %[^\n]", username);
		printf("\nIntroduza a sua MasterKey: ");
		scanf(" %[^\n]", masterkey);
		//chamar a funcao que vai verificar se o username e login estao bem, e retornar um boolean true se estiver tudo certo
	} while (verifica==true);

	dir = opendir("."); // Abre directoria atual
	while ((ent = readdir(dir)) != NULL) // Enquanto o leitor não der negativo escrever todos os que forem do tipo directoria
	{
		if (ent->d_type == DT_DIR){
			//printf("%*.*s\n", ent->d_namlen, ent->d_namlen, ent->d_name);  Mostra tudo o que encontra
			aux = carrega_fich_bin(ent->d_name);
			if (aux != NULL){
				if (strcmp(username, aux->username) == 0 && strcmp(masterkey, aux->masterkey) == 0)
					menu_contas(username, aux, ent->d_name);
			}
		}
	}
}
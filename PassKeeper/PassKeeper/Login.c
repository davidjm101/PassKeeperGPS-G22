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

	dir = opendir("."); // Abre directoria atual

	system("cls");
	titulo();
	printf("\n					Login       \n\n");
	printf("Introduza o seu username: ");
	fflush(stdin);
	fgets(username, MAX_USER, stdin);
	strtok(username, "\n");
	printf("\nIntroduza a sua MasterKey: ");
	fflush(stdin);
	fgets(masterkey, MAX_MK, stdin);
	strtok(masterkey, "\n");
	//chamar a funcao que vai verificar se o username e login estao bem, e retornar um boolean true se estiver tudo certo

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
	printf("Erro nos dados introduzidos\n");
	system("PAUSE");
}
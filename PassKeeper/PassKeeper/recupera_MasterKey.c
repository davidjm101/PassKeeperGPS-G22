#include "Bibliotecas.h"

void recupera_MasterKey(){
	// Libraria dirent utilizada para ler os folders dentro da pasta
	DIR *dir;
	struct dirent* ent;
	char perg_seg[30];
	char resp_seg[30];
	char nome_pasta[30];
	char nPasta[MAX_NOME] = "";
	bool verifica = false;
	pcliente aux;

	system("cls");
	titulo();
	printf("\n					Recuperacao da Master Key       \n\n");
	
	dir = opendir("."); // Abre directoria atual

	do
	{
		printf("\nDigite a sua Pasta : ");
		fflush(stdin);
		fgets(nPasta, MAX_MK, stdin);
		strtok(nPasta, "\n");

		while ((ent = readdir(dir)) != NULL) // Enquanto o leitor não der negativo escrever todos os que forem do tipo directoria
		{
			if (ent->d_type == DT_DIR)
			{
				if (strcmp(nPasta, ent->d_name) == 0)
				{
					aux = carrega_fich_bin(ent->d_name);
					if (aux != NULL)
						verifica = true;
					else
						return 0;
				}
			}
		}
		if (verifica == false) 
			printf("Login não encontrado");

	} while (verifica == false);

	printf("%s", aux->perg_seguranca);

	printf("\nDigite a sua resposta de seguranca : ");
	fflush(stdin);
	fgets(resp_seg, MAX_RS, stdin);
	strtok(resp_seg, "\n");

	if (strcmp(resp_seg, aux->resp_seguranca) != 0)
	{
		printf("\nResposta de seguranca incorreta");
		verifica = false;
	}
	else
	{
		verifica = true;
	}

	if (verifica == true)
	{
		printf("\n A sua Masterkey é  : %s\n", aux->masterkey);
		system("PAUSE");
	}
}
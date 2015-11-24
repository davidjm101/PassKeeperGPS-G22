#include "Bibliotecas.h"

void registo()
{
	cliente cliente;

	titulo();
	printf("\n			Registo       \n\n");
	printf("Introduza o username que pretende: ");
	scanf(" %[^\n]", cliente.username);

	printf("\nIndique a MasterKey que pretende");
	printf("\n(a sua MasterKey deve conter no minimo 4 numeros");
	printf("\n4 letras(2 maiusculas e duas minisculas)");
	printf("\ne 4 caracteres especiais (ex: ! $ & %): ");
	scanf(" %[^\n]", cliente.masterkey);

	//verificar se as normas da masterkey foram compridas

	printf("\nIndique a sua pergunta de seguranca: ");
	scanf(" %[^\n]", cliente.perg_seguranca);


	printf("Indique a resposta a sua pergunta de seguranca: ");
	scanf(" %[^\n]", cliente.resp_seguranca);

	printf("Indique o nome da pasta onde sera guardado o ficheiro com as suas contas: ");

}
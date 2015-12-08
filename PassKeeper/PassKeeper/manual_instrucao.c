#include "Bibliotecas.h"

void manual_intrucao()
{
	int opcao_menu, controlo;
	do{
		do{
			system("cls");
			titulo();
			printf("\n					Manual de Instrucao       \n\n");
			printf("1- Efectuar Registo\n");
			printf("2- Recuperar Master Key\n");
			printf("3- Adicionar conta\n");
			printf("4- Editar conta\n");
			printf("5- Apagar conta\n");
			printf("6- Pesquisar conta\n");
			printf("7- Sair\n\n");
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
		} while (controlo<1 || opcao_menu<1 || opcao_menu>7);


		switch (opcao_menu)
		{
		case 1:
			printf("Para efectuar um registo o utilizador deve indicar os dados necessarios para tal.\n");
			printf("Deve comecar por indicar o username que pretende,\n");
			printf("em seguida deve indicar a MasterKey que pretende, seguindo as guidelines indicadas,\n");
			printf("apos a introducao da Masterkey, devera indicar qual a sua pergunta de serguranca,\n");
			printf("de seguida indicar a resposta a pergunta de seguranca\n");
			printf("a pergunta e resposta de seguranca servirao para recuperar a MasterKey caso o utilizador assim o desejar.\n");
			printf("Por fim devera indicar o nome da pasta onde sera guardado o ficheiro que contem todas as contas.\n");
			system("PAUSE");
			break;
		case 2:
			printf("Para efectuar um registo o utilizador deve indicar os dados necessarios para tal.\n");
			printf("Deve comecar por indicar o username que pretende,\n");
			printf("em seguida deve indicar a MasterKey que pretende, seguindo as guidelines indicadas,\n");
			printf("apos a introducao da Masterkey, devera indicar qual a sua pergunta de serguranca,\n");
			printf("de seguida indicar a resposta a pergunta de seguranca\n");
			printf("a pergunta e resposta de seguranca servirao para recuperar a MasterKey caso o utilizador assim o desejar.\n");
			printf("Por fim devera indicar o nome da pasta onde sera guardado o ficheiro que contem todas as contas.\n");
			system("PAUSE");
			break;
		case 3:
			printf("Depois de o utilizador ter efectuado o login,podera editar uma conta.\n");
			printf("Para tal devera comecar por indicar o nome da conta a editar,\n");
			printf("em seguida sera mostrado ao utilizador todos os dados relativos a conta pesquisada.,\n");
			printf("O utilizador dever de seguida indicar qual o dados que pretende alterar,\n");
			printf("no caso de querer editar o login, devera indicar o novo login que pretende.\n");
			printf("Caso queira editar a password, devera indicar se quer uma password gerada manualmente ou automaticamente,\n");
			printf("no caso de escolher manualmente, devera indicar entao a nova password,\n");
			printf("no caso de escolher automaticamente, o programa ira criar uma nova password automatica substituindo a password antiga.\n");
			printf("Caso queira editar o nome, devera indicar o novo nome que pretende, sendo entao alterado o nome por este\n");
			system("PAUSE");
			break;
		case 4:
			printf("Depois de o utilizador ter efectuado o login,podera adicionar novas contas.\n");
			printf("Para tal devera comecar por indicar o login da conta,\n");
			printf("em seguida deve indicar a password que pretende, podera indicar se quer uma password manual ou automatica,\n");
			printf("no caso de escolher manual, o utilizador devera indicar a password,\n");
			printf("caso tenha escolhido automatica, o programa ira criar uma password automatica.\n");
			printf("Por fim o utilizador devera indicar o nome da conta que quer criar\n");
			printf("caso exista alguma conta com este nome, sera indicado que ja existe uma conta com este nome\n");
			system("PAUSE");
			break;
		case 5:
			printf("Depois de o utilizador ter efectuado o login,podera apagar uma conta.\n");
			printf("Para tal devera indicar o nome da conta a apagar,\n");
			printf("caso esta conta exista, o programa perguntara ao utilizador se realmente pretende apagar essa conta\n");
			printf("no caso de escolher sim, a conta sera entao apagada.\n");
			system("PAUSE");
			break;
		case 6:
			printf("Depois de o utilizador ter efectuado o login,podera pesquisar uma conta.\n");
			printf("Para tal devera indicar o nome da conta a pesquisar sendo pesquisado a conta com este nome,\n");
			printf("ou apenas um prefixo (ex: gma),sendo que serao pesquisado todas as contas que comecem por esse prefixo.\n");
			printf("Caso pretenda pesquisar todas as suas contas podera faze-lo escrevendo (tudo),sendo mostrado todas as conta que possui\n");
			system("PAUSE");
			break;
		case 7:
			return;
			break;

		default:
			break;
		}
	} while (1);




	printf("\n");
}
#define MAX_MK 17 // o numero maximo de caracteres para a master key, e para o nome da pasta
#define MAX_USER 101 // maximo de caracteres para o username, nome de conta e pergunta de segurança
#define MAX_RS 33 //  numero maximo de caracteres para a resposta a pergunta de segurança
#define MAX_PS 101 // numero maximo de caracteres para a pergunta de segurança
#define MAX_LOG 101 // numero maximo de caracteres para o login de uma conta
#define MAX_NOME 51 // numero maximo de caracteres para o nome de uma conta
#define MAX_PASS 17 // numero maximo de caracteres para a password de uma conta

typedef struct dados2 conta, *pconta; //pconta é um ponteiro para uma estrutura do tipo conta e conta é outro nome para struct dados2
struct dados2
{
	char nome[MAX_NOME];
	char login[MAX_LOG];
	char password[MAX_PASS];
	pconta prox; // ponteiro para o proximo elemento da lista ligada
};

typedef struct dados1 cliente, *pcliente; //pcliente é um ponteiro para uma estrutura do tipo cliente  e cliente é outro nome para struct dados1
struct dados1
{
	char username[MAX_USER];
	char masterkey[MAX_MK];
	char perg_seguranca[MAX_PS];
	char resp_seguranca[MAX_RS];
	int num_contas; // variável para contagem do numero de contas que o cliente tem guardadas
	pconta lista; // ponteiro para o inicio da lista ligada de estruturas do tipo conta
};

////////////////////   Protótipos das funções ////////////////////

void menu();
void manual_intrucao();
void titulo();
void registo();
bool verifica_master_guidelines(char *masterkey);
int entradas_int(int controlo);
void login();
void menu_contas(char nomeConta[], cliente *cliente, char nomePasta[]);
void adicionar_conta(cliente *cliente, char nomePasta[]);
void editar_conta(cliente *cliente1, char nomePasta[]);
void apagar_conta(cliente *cliente, char nomePasta[]);
void pesquisar_conta(cliente *cliente);
int cria_fich_bin(pcliente cliente, char nomePasta[]);
pcliente carrega_fich_bin(char nomePasta[]);


void ShortcutCopiar(cliente *cliente1, char nomeConta[]);
void escreve_ficheiro(cliente *cliente, char nomePasta[]);
void gera_pass_auto(char password[]);
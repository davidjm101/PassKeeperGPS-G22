#include "CuTest.h"
#include "Bibliotecas.h"
CuSuite* CuStringGetSuite(CuTest* tc);

///////////////testes para a funcao minusculas///////////////////
void teste_string(CuTest* tc)
{

	char s[] = "COPIAR";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "copiar", s);

}

void teste_string2(CuTest* tc)
{
	char s[] = "";
	int controlo = 0;
	controlo=minusculas(s);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

void teste_string3(CuTest* tc)
{
	char s[] = { NULL };
	int controlo = 0;
	controlo = minusculas(s);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}


void teste_string4(CuTest* tc)
{
	char s[] = " ";
	int controlo = 0;
	controlo = minusculas(s);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

void teste_string5(CuTest* tc)
{

	char s[] = "\n";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "\n", s);

}

void teste_string6(CuTest* tc)
{

	char s[] = "A ";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "a ", s);

}

void teste_string7(CuTest* tc)
{

	char s[] = "\t";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "\t", s);

}

///////////////testes para a funcao encripta///////////////////
void teste_encripta(CuTest* tc)
{
	int controlo=0;
	char palavra[] = { NULL};
	controlo=encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}


void teste_encripta2(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = "";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

void teste_encripta3(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = " ";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}

void teste_encripta4(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = " ";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, " ", palavra);
}

void teste_encripta5(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = "\n";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

///////////////testes para a funcao desencripta///////////////////
void teste_desencripta(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = { NULL };
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}


void teste_desencripta2(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = "";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

void teste_desencripta3(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = " ";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}

void teste_desencripta4(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = " ";
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, " ", palavra);
}

void teste_desencripta5(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = "\n";
	controlo = desencripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

///////////////testes para a funcao gera_pass_auto///////////////////
void teste_gerapass(CuTest* tc)
{
	int controlo = 0;
	char *palavra=  NULL;
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}

void teste_gerapass2(CuTest* tc)
{
	int controlo = 0;
	char palavra[MAX_PASS] = "\n";
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0 , controlo);
}

void teste_gerapass3(CuTest* tc)
{
	int controlo = 0;
	char palavra[MAX_PASS] = "";
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}

void teste_gerapass4(CuTest* tc)
{
	int controlo = 0;
	char palavra[MAX_PASS] = " ";
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}

void teste_gerapass5(CuTest* tc)
{
	int controlo = 0;
	char palavra[MAX_PASS] = "\t";
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}

void teste_gerapass6(CuTest* tc)
{
	int controlo = 0;
	char palavra[MAX_PASS] = "\0";
	controlo = gera_pass_auto(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 0, controlo);
}
CuSuite* CuStringGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, teste_string);
	SUITE_ADD_TEST(suite, teste_string2);
	SUITE_ADD_TEST(suite, teste_string3);
	SUITE_ADD_TEST(suite, teste_string4);
	SUITE_ADD_TEST(suite, teste_string5);
	SUITE_ADD_TEST(suite, teste_string6);
	SUITE_ADD_TEST(suite, teste_string7);
	SUITE_ADD_TEST(suite, teste_encripta);
	SUITE_ADD_TEST(suite, teste_encripta2);
	SUITE_ADD_TEST(suite, teste_encripta3);
	SUITE_ADD_TEST(suite, teste_encripta4);
	SUITE_ADD_TEST(suite, teste_encripta5);
	SUITE_ADD_TEST(suite, teste_desencripta);
	SUITE_ADD_TEST(suite, teste_desencripta2);
	SUITE_ADD_TEST(suite, teste_desencripta3);
	SUITE_ADD_TEST(suite, teste_desencripta4);
	SUITE_ADD_TEST(suite, teste_desencripta5);
	SUITE_ADD_TEST(suite, teste_gerapass);
	SUITE_ADD_TEST(suite, teste_gerapass2);
	SUITE_ADD_TEST(suite, teste_gerapass3);
	SUITE_ADD_TEST(suite, teste_gerapass4);
	SUITE_ADD_TEST(suite, teste_gerapass5);
	SUITE_ADD_TEST(suite, teste_gerapass6);

	return suite;
}



void run_alltest(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();
	CuSuiteAddSuite(suite, CuStringGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}
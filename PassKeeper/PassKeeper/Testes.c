#include "CuTest.h"
#include "Bibliotecas.h"
CuSuite* CuStringGetSuite(CuTest* tc);

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


void teste_gerapass(CuTest* tc)
{
	int controlo = 0;
	char palavra[] = { NULL };
	controlo = encripta(palavra);
	CuString* str = CuStringNew();
	CuAssertIntEquals(tc, 1, controlo);
}


CuSuite* CuStringGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, teste_string);
	SUITE_ADD_TEST(suite, teste_string2);
	SUITE_ADD_TEST(suite, teste_string3);
	SUITE_ADD_TEST(suite, teste_string4);
	SUITE_ADD_TEST(suite, teste_encripta);
	SUITE_ADD_TEST(suite, teste_encripta2);
	SUITE_ADD_TEST(suite, teste_encripta3);
	SUITE_ADD_TEST(suite, teste_encripta4);
	SUITE_ADD_TEST(suite, teste_desencripta);
	SUITE_ADD_TEST(suite, teste_desencripta2);
	SUITE_ADD_TEST(suite, teste_desencripta3);
	SUITE_ADD_TEST(suite, teste_desencripta4);
	SUITE_ADD_TEST(suite, teste_gerapass);

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
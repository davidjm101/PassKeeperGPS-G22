#include "CuTest.h"
#include "Bibliotecas.h"
CuSuite* CuStringGetSuite(CuTest* tc);

void teste_string(CuTest* tc)
{

	char s[] = " ";
	minusculas(NULL);
	CuString* str = CuStringNew();

	CuAssertStrEquals(tc, "x ?", s);


	CuAssertIntEquals(tc, 11, 11);

}

void teste_string2(CuTest* tc)
{

	char s[] = "COPIAR";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "copiar", s);
}

void teste_string3(CuTest* tc)
{

	char s[] = "SAIR";
	minusculas(s);
	CuString* str = CuStringNew();
	CuAssertStrEquals(tc, "sair", s);
}


CuSuite* CuStringGetSuite(void)
{
	CuSuite* suite = CuSuiteNew();

	SUITE_ADD_TEST(suite, teste_string);
	SUITE_ADD_TEST(suite, teste_string2);
	SUITE_ADD_TEST(suite, teste_string3);
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
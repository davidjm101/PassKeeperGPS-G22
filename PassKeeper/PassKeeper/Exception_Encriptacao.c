#include "Bibliotecas.h"

void trata_exception(int a)
{
	if (a == 1) // excepção para o encripta (argumento passado como null)
	{
		//exception_encripta = 1;
		return;
	}
	if (a == 2) // excepção para o desencripta (argumento passado como null)
	{
		//exception_desencripta = 1;
		return;
	}
}
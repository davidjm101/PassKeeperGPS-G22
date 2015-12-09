#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void encripta(char palavra[]);
void desencripta(char palavra[]);
void gera_pass_auto(char password[]);
void trata_exception(int a);

int exception_encripta = 0;
int exception_desencripta = 0;

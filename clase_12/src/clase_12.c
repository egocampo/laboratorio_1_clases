/*
 ============================================================================
 Name        : clase_12.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* arrayEnteros[10];
	int* pInt;
	int i, j;
	for(i=0;i<10;i++)
	{
		arrayEnteros[i] = NULL;
	}
for(i=0;i<5;i++)
	{
		pInt = (int*) malloc(sizeof(int));
		arrayEnteros[i] = pInt;
	}
//	for(i=0;i<5;i++)
//	{
//		arrayEnteros[i] = (int*) malloc(sizeof(int));
//	}
	free(arrayEnteros[2]);
	arrayEnteros[2] = NULL;
	for(j=0;j<10;j++)
	{
		printf("[%d]: %p\n",j,arrayEnteros[j]);
	}
	return EXIT_SUCCESS;
}


/*
 ============================================================================
 Name        : clase_06.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

#define LIMITE 5

int main(void)
{
	int arrayInt[LIMITE]={21,18,15,9,5};
	int i;
	int posicionMinimo;

	for(i=0;i<LIMITE-1;i++)
	{
		arr_searchPositionOfMinimum(arrayInt, LIMITE, i, &posicionMinimo);
		if(i != posicionMinimo)
		{
			arr_intercambiarPosicion(arrayInt, i,posicionMinimo);
		}
	}
	arr_imprimirArrayInt(arrayInt, LIMITE);
	return EXIT_SUCCESS;
}

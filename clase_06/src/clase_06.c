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

int sortLudmila(int* pArray, int len);


#define LIMITE 5

int main(void)
{
	int array[LIMITE]={2,8,5,7,6};
	arr_sortLudmila(array, LIMITE);
	arr_printfArrayInt(array, LIMITE);
	return EXIT_SUCCESS;
}

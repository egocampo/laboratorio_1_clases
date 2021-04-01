/*
 ============================================================================
 Name        : clase_05_arrays.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "array.h"
#define CANT_EDADES 5
#define REINTENTOS 3
#define MINIMO 0
#define MAXIMO 99

int main(void) {
	int arrayNumero[CANT_EDADES]={1,2,3,4,5};
	arr_imprimirArrayInt(arrayNumero, CANT_EDADES);
	return EXIT_SUCCESS;
}

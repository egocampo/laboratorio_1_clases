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

int main(void) {
	int arrayNumero[CANT_EDADES];
	int maximo;
	int minimo;
	int suma;
	float promedio;
	for(int i=0;i<CANT_EDADES;i++)
	{
		utn_getInteger(&arrayNumero[i],"Ingrese la edad: ","Edad no válida\n",3,0,99);
	}
	arr_calcularMaximoInt(arrayNumero,CANT_EDADES,&maximo);
	printf("maximo: %d\n",maximo);
	arr_calcularMinimoInt(arrayNumero,CANT_EDADES,&minimo);
	printf("minimo: %d\n",minimo);
	arr_calcularSumaInt(arrayNumero,CANT_EDADES,&suma);
	printf("suma: %d\n",suma);
	arr_calcularPromedioInt(arrayNumero,CANT_EDADES,&promedio);
	printf("promedio: %.2f\n",promedio);
	return EXIT_SUCCESS;
}

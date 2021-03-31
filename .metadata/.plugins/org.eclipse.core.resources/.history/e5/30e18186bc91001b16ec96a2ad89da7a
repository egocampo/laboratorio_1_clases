/*
 ============================================================================
 Name        : Clase_05.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrays.c"
#define CANTIDAD_EDADES 2
#define UTN_MIN_EDAD 0
#define UTN_MAX_EDAD 99
#define UTN_REINTENTOS 3

int main(void) {
	int arrayEdades[CANTIDAD_EDADES];
	int maximo;
	int minimo;
	for(int i=0;i<CANTIDAD_EDADES;i++)
	{
		utn_getInteger(&arrayEdades[i],"Ingrese la edad: ","Edad no válida",UTN_REINTENTOS,UTN_MIN_EDAD,UTN_MAX_EDAD);
	}
	arr_calcularMaximoInt(arrayEdades,CANTIDAD_EDADES,&maximo);
	arr_calcularMinimoInt(arrayEdades,CANTIDAD_EDADES,&minimo);
	printf("El mayor es %d",maximo);
	printf("El menor es %d",minimo);
	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : clase_10.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "gets.h"
#include "validations.h"
#include "sMascotas.h"
#include "sRazas.h"
#include "funciones.h"

int main(void)
{
//	Mascota arrayMascotas[10];
//	Razas arrayRazas[10];
//	int contadorMascotas=0;
//
//	inicializarArrayMascota(arrayMascotas, 10);
//	inicializarArrayRazas(arrayRazas, 10);
//	hardcodeoEstructuras(arrayMascotas, arrayRazas,&contadorMascotas);
//	for(int i=0;i<5;i++)
//		imprimirMascota(arrayMascotas,i,arrayRazas);
//	alta_mascota(arrayMascotas, 10, arrayRazas);

	int a;
	char caracter='x';
	char listaBlanca[3]="mfn";
//	for(int i=0;i<2;i++)
//		printf("%c\n",listaBlanca[i][0]);
	a=val_isInWhiteList(&caracter, listaBlanca, 3);
	printf("%d",a);
	return EXIT_SUCCESS;
}

// int get_String(char* mensaje, char* mensajeError, int limite, char* pResultado, char* listaBlanca[]);


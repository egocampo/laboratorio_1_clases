/*
 * sRazas.c
 *
 *  Created on: 20 abr. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "gets.h"
#include "validations.h"
#include "sMascotas.h"
#include "sRazas.h"

void inicializarArrayRazas(Razas* pArrayParaInicializar,int limite)
{
	int i;
	for(i=0;i<limite;i++)
	{
		pArrayParaInicializar[i].flagIsEmpty = 1;
	}
}

void hardcodearEstructuraRaza(Razas* arrayRazas,int posicion,char* descripcion, char* tamanio, char* paisOrigen)
{
	strcpy(arrayRazas[posicion].descripcion,descripcion);
	strcpy(arrayRazas[posicion].tamanio,tamanio);
	strcpy(arrayRazas[posicion].paisOrigen,paisOrigen);
}

//void imprimirRaza(Razas* arrayParaImprimir,int posicion)
//{
//	printf("Raza: %s",arrayParaImprimir[posicion].descripcion);
//}

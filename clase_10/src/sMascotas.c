/*
 * sMascotas.c
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

void inicializarArrayMascota(Mascota* pArrayParaInicializar,int limite)
{
	int i;
	for(i=0;i<limite;i++)
	{
		pArrayParaInicializar[i].flagIsEmpty = 1;
	}
}

void hardcodearEstructuraMascota(Mascota* arrayMascotas,int posicion,char* nombre, int edad, char sexo, char* tipo,int raza, int* contadorIdMascotas)
{
	strcpy(arrayMascotas[posicion].nombre,nombre);
	arrayMascotas[posicion].edad = edad;
	arrayMascotas[posicion].sexo = sexo;
	strcpy(arrayMascotas[posicion].tipo,tipo);
	arrayMascotas[posicion].raza = raza;
	arrayMascotas[posicion].flagIsEmpty = 0;
	*contadorIdMascotas=*contadorIdMascotas+1;
}



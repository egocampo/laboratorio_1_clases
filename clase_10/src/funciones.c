/*
 * funciones.c
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
#include "funciones.h"

void hardcodeoEstructuras(Mascota* arrayMascotas, Razas* arrayRazas,int* cantidadMascotas)
{
	hardcodearEstructuraRaza(arrayRazas,0,"siames","chico","tailandia");
	hardcodearEstructuraRaza(arrayRazas,1,"doberman","grande","alemania");
	hardcodearEstructuraRaza(arrayRazas,2,"persa","mediano","persia");
	hardcodearEstructuraRaza(arrayRazas,3,"pastor belga","grande","belgica");

	hardcodearEstructuraMascota(arrayMascotas,0,"ego",10,'m',"perro",1,cantidadMascotas);
	hardcodearEstructuraMascota(arrayMascotas,1,"very",9,'f',"perro",3,cantidadMascotas);
	hardcodearEstructuraMascota(arrayMascotas,2,"perla",2,'f',"gato",2,cantidadMascotas);
	hardcodearEstructuraMascota(arrayMascotas,3,"tomas",2,'m',"gato",0,cantidadMascotas);
	hardcodearEstructuraMascota(arrayMascotas,4,"felipe",1,'m',"gato",0,cantidadMascotas);
}

void imprimirMascota(Mascota* arrayMascotas,int posicion,Razas* arrayRazas)
{
	printf("Nombre: %s\n",arrayMascotas[posicion].nombre);
	printf("Edad: %d años\n",arrayMascotas[posicion].edad);
	printf("Edad: %c\n",arrayMascotas[posicion].sexo);
	printf("Tipo: %s\n",arrayMascotas[posicion].tipo);
	printf("Raza: %s\n",arrayRazas[arrayMascotas[posicion].raza].descripcion);
	printf("Pais de origen: %s\n\n",arrayRazas[arrayMascotas[posicion].raza].paisOrigen);
}

void alta_mascota(Mascota* arrayMascotas, int len,Razas* arrayRazas)
{
	int indice;
	char bufferName[20];
	int bufferAge;
	char bufferSex;
	indice=buscarIndiceVacio(arrayMascotas, len);
	if(get_name(bufferName, 20,"Ingrese nombre: ","Error. ",3)==1)
	{
		if(get_int(&bufferAge,5,"Ingrese edad: ","Error. ",1,0,40,3,1)==1)
		{

		}
	}
//	strcpy(arrayMascotas[posicion].nombre,nombre);
//	arrayMascotas[posicion].edad = edad;
//	arrayMascotas[posicion].sexo = sexo;
//	strcpy(arrayMascotas[posicion].tipo,tipo);
//	arrayMascotas[posicion].raza = raza;
//	arrayMascotas[posicion].flagIsEmpty = 0;
//	*contadorIdMascotas=*contadorIdMascotas+1;
}

int buscarIndiceVacio(Mascota* arrayMascotas, int len)
{
	int i;
	int returnFunction = -1;
	for(i=0;i<len;i++)
	{
		if(arrayMascotas[i].flagIsEmpty==1)
		{
			returnFunction = i;
			break;
		}
	}
	return returnFunction;
}




//void altaMascota(Mascota* )

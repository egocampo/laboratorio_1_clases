/*
 * producto.c
 *
 *  Created on: 16 abr. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utn.h"
#include "producto.h"

void prod_inicializarArray(Producto* pArrayParaInicializar,int limite)
{
	int i;
	for(i=0;i<limite;i++)
	{
		pArrayParaInicializar[i].flagIsEmpty = 1;
	}
}

int prod_altaProducto(Producto* pArrayParaInicializar,int limite,int indice)
{
	Producto prodAux;
	int returnFunction = -1;
	if(pArrayParaInicializar != NULL && limite > 0 && indice < limite)
	{
		returnFunction = 0;
		if(utn_getName(prodAux.nombre,32,"Ingrese el nombre: ", "Error. ",3)==1)
		{
			if(utn_getName(prodAux.descripcion,128,"Ingrese la descripcion: ", "Error. ",3)==1)
			{
				pArrayParaInicializar[indice]=prodAux;
				pArrayParaInicializar[indice].flagIsEmpty = 0;
			}
		}
	}
	return returnFunction;
}

int prod_printProducto(Producto* pArrayParaImprimir,int limite,int indice)
{
	int returnFunction = -1;
	if(pArrayParaImprimir != NULL && limite > 0 && indice < limite)
	{
		returnFunction = 0;
		printf("%s\n",pArrayParaImprimir[indice].nombre);
		printf("%s\n",pArrayParaImprimir[indice].descripcion);
	}
	return returnFunction;
}

int prod_buscarIndiceVacio(Producto* pArrayDondeBuscar,int limite)
{
	int returnFunction = -2;
	int i;
	if(pArrayDondeBuscar != NULL && limite > 0)
	{
		returnFunction = -1;
		for(i=0;i<limite;i++)
		{
			if(pArrayDondeBuscar[i].flagIsEmpty==0)
			{
				returnFunction = i;
			}
		}
	}
	return returnFunction;
}

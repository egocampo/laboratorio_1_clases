/*
 * estructuraBase.c
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include "estructuraBase.h"

/*
 * \brief Obtiene el indice de un elemento de un array de estructura a traves del campo id.
 * \param estructura* arrayEstructura Array de estructura donde buscar el id y devolver el indice
 * \param int len Tamaño del arrayEstructura
 * \param int id Identificador a buscar
 * \return -2 error de validación, -1 no encontró el elemento, mayor a 0 devuelve el indice.
 * */
int getIndexById(estructuraBase* arrayEstructura, int len, int id)
{
	int returnFunction = -2;
	int i;
	if(arrayEstructura != NULL && len > 0 && id > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(arrayEstructura[i].idEstructura==id)
			{
				returnFunction=i;
			}
		}
	}
	return returnFunction;
}

/*
 * \brief Imprime todos los elementos de una estructura
 * \param estructura* arrayEstructuraBase Array de estructura que imprimir
 * \param int len Tamaño del arrayEstructuraBase
 * \char* mensaje Texto a imprimir previo al listado
 * \return -1 error de validacion, 0 si imprime ok
 */
int printEsctructura(estructuraBase* arrayEstructura, int len, char* mensaje)
{
	int returnFunction = -1;
	int i;
	if(arrayEstructura != NULL && len > 0)
	{
		returnFunction = 0;
		printf("%s\n",mensaje);
		for(i=0;i<len;i++)
		{
			printf("Id: %d\n",arrayEstructura[i].idEstructura); // imprimir cada campo de la estructura
//			printf("\n");
//			printf("\n");
		}
	}
	return returnFunction;
}

/*
 * \brief Inicializa un arrayEstructuraBase asigando el valor 1 al campo flagIsEmpty
 * \param estructura* arrayEstructuraBase Array de estructura que inicializar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -1 error de validacion, 0 si no hubo errores
 * */
int initArray(estructuraBase* arrayEstructuraBase, int len)
{
	int returnFunction = -1;
	int i;
	if(arrayEstructuraBase != NULL && len)
	{
		returnFunction = 0;
		for(i=0;i<len;i++)
		{
			arrayEstructuraBase[i].flagIsEmpty = 1;
		}
	}
	return returnFunction;
}

/*
 * \brief Busca dentro de un arrayEstructuraBase el primer indice cuyo campo isEmpty sea verdadero
 * \param estructura* arrayEstructuraBase Array de estructura donde buscar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -2 error de validacion, -1 no hay ningun espacio vacio, 0 o mayor es la posicion libre
 * */
int searchIndexEmpty(estructuraBase* arrayEstructuraBase, int len)
{
	int returnFunction = -2;
	int i;
	if(arrayEstructuraBase != NULL && len > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(arrayEstructuraBase[i].flagIsEmpty == 1)
			{
				returnFunction = i;
				break;
			}
		}
	}
	return returnFunction;
}

/*
 * \brief Ordenamiento de array por método de insersión
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int ordenamientoInsersionEstructuraPorId(estructuraBase* arrayEstructura, int len)
{
	int retorno = -1;
	if(arrayEstructura != NULL && len > 0)
	{
		retorno = 0;
		int i, j;
		estructuraBase temp;
		for(i=1;i<len;i++)
		{
			temp=arrayEstructura[i];
			j=i-1;
			while(j>=0 && temp.idEstructura < arrayEstructura[j].idEstructura)
			{
				arrayEstructura[j+1] = arrayEstructura[j];
				j--;
			}
			arrayEstructura[j+1] = temp;
		}
	}
	return retorno;
}

/*
 * estructuraBase.c
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "gets.h"

/*
 * \brief Obtiene el indice de un elemento de un array de estructura a traves del campo id.
 * \param estructura* arrayEstructura Array de estructura donde buscar el id y devolver el indice
 * \param int len Tamaño del arrayEstructura
 * \param int id Identificador a buscar
 * \return -2 error de validación, -1 no encontró el elemento, mayor a 0 devuelve el indice.
 * */
int pan_getIndexById(Pantalla* arrayEstructuraBase, int len, int id)
{
	int returnFunction = -2;
	int i;
	if(arrayEstructuraBase != NULL && len > 0 && id > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(arrayEstructuraBase[i].idPantalla==id)
			{
				returnFunction = i;
				break;
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
int pan_printEsctructuraBase(Pantalla* arrayEstructuraBase, int len, char* mensaje)
{
	int returnFunction = -1;
	int i;
	if(arrayEstructuraBase != NULL && len > 0)
	{
		returnFunction = 0;
		printf("%s",mensaje);
		for(i=0;i<len;i++)
		{
				if(arrayEstructuraBase[i].flagIsEmpty == 0)
				{
					printf("Indice: %d\n",i);
					printf("Id: %d\n",arrayEstructuraBase[i].idPantalla); // imprimir cada campo de la estructura
					printf("Dirección: %s\n",arrayEstructuraBase[i].direccion);
					printf("Tipo pantalla: %d\n",arrayEstructuraBase[i].tipoPantalla);
					printf("Tipo pantalla: %s\n",arrayEstructuraBase[i].nombrePantalla);
					printf("Precio diario: $ %d\n",arrayEstructuraBase[i].precioDiario);
					printf("Flag is empty: %d\n",arrayEstructuraBase[i].flagIsEmpty);
					printf("\n");
			}
		}
	}
	return returnFunction;
}

int pan_printPantallaPorIndice(Pantalla* arrayEstructuraBase, char* mensaje,int indice)
{
	int returnFunction = -1;
	if(arrayEstructuraBase != NULL)
	{
		returnFunction = 0;
		printf("%s",mensaje);
		printf("Indice: %d\n",indice);
		printf("Id: %d\n",arrayEstructuraBase[indice].idPantalla); // imprimir cada campo de la estructura
		printf("Dirección: %s\n",arrayEstructuraBase[indice].direccion);
		printf("Tipo pantalla: %d\n",arrayEstructuraBase[indice].tipoPantalla);
		printf("Tipo pantalla: %s\n",arrayEstructuraBase[indice].nombrePantalla);
		printf("Precio diario: $ %d\n",arrayEstructuraBase[indice].precioDiario);
		printf("Flag is empty: %d\n",arrayEstructuraBase[indice].flagIsEmpty);
		printf("\n");
	}
	return returnFunction;
}

/*
 * \brief Inicializa un arrayEstructuraBase asigando el valor 1 al campo flagIsEmpty
 * \param estructura* arrayEstructuraBase Array de estructura que inicializar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -1 error de validacion, 0 si no hubo errores
 * */
int pan_initArray(Pantalla* arrayEstructuraBase, int len)
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
int pan_searchIndexEmpty(Pantalla* arrayEstructuraBase, int len)
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
int pan_ordenamientoInsersionEstructuraBasePorId(Pantalla* arrayPantalla, int len)
{
	int retorno = -1;
	if(arrayPantalla != NULL && len > 0)
	{
		retorno = 0;
		int i, j;
		Pantalla temp;
		for(i=1;i<len;i++)
		{
			temp=arrayPantalla[i];
			j=i-1;
			while(j>=0 && temp.idPantalla < arrayPantalla[j].idPantalla)
			{
				arrayPantalla[j+1] = arrayPantalla[j];
				j--;
			}
			arrayPantalla[j+1] = temp;
		}
	}
	return retorno;
}

int pan_altaPantalla(Pantalla* arrayPantalla, int len, int* contadorIdPantalla)
{
	int returnFunction = -1;
	Pantalla buffer;
	int indice = pan_searchIndexEmpty(arrayPantalla, 100);
	if(arrayPantalla != NULL && len > 0 && contadorIdPantalla >= 0)
	{
		returnFunction = 0;
		if(indice >= 0 && indice < len)
		{
			buffer.idPantalla = *contadorIdPantalla;
			if(get_text(buffer.direccion,50,"Dirección: ","Error. ",3)==1)
				if(get_int(&buffer.tipoPantalla,2,"Tipo pantalla (0: LED / 1: LCD): ","Error. ",1,0,1,3,0)==1)
					if(get_text(buffer.nombrePantalla,50,"Nombre de pantalla: ","Error. ",3)==1)
						if(get_int(&buffer.precioDiario,8,"Precio diario: $","Error. ",1,1,99999,3,0)==1)
						{
							buffer.flagIsEmpty = 0;
							arrayPantalla[indice] = buffer;
							*contadorIdPantalla = *contadorIdPantalla + 1;

						}
		}

	}
	return returnFunction;
}

int pan_modificarPantalla(Pantalla* arrayPantalla, int len, int contadorPantallas)
{
	int returnFunction = -1;
	int opcionElegida;
	Pantalla buffer;
	if(arrayPantalla != NULL && len > 0 && contadorPantallas >= 0)
	{
		returnFunction = 0;
		pan_printEsctructuraBase(arrayPantalla, 100,"Listado de pantallas\n");
		if(get_int(&opcionElegida,3,"Seleccionar pantalla: ","Error. ",1,1,contadorPantallas-1,3,0)==1)
		{
			buffer.idPantalla = opcionElegida;
			if(get_text(buffer.direccion,50,"Dirección: ","Error. ",3)==1)
				if(get_int(&buffer.tipoPantalla,2,"Tipo pantalla (0: LED / 1: LCD): ","Error. ",1,0,1,3,0)==1)
					if(get_text(buffer.nombrePantalla,50,"Nombre de pantalla: ","Error. ",3)==1)
						if(get_int(&buffer.precioDiario,8,"Precio diario: $","Error. ",1,1,99999,3,0)==1)
						{
							arrayPantalla[pan_getIndexById(arrayPantalla, 100,opcionElegida)] = buffer;
						}
		}

	}
	return returnFunction;
}

int pan_bajaPantalla(Pantalla* arrayPantalla, int contadorPantallas)
{
	int returnFunction = -1;
	int opcionElegida;
	if(arrayPantalla != NULL && contadorPantallas >= 0)
	{
		returnFunction = 0;
		pan_printEsctructuraBase(arrayPantalla, 100,"Listado de pantallas\n");
		if(get_int(&opcionElegida,4,"Seleccionar pantalla: ","Error. ",1,1,contadorPantallas-1,3,0)==1)
		{
			arrayPantalla[pan_getIndexById(arrayPantalla, 100,opcionElegida)].flagIsEmpty = 1;
		}
	}
	return returnFunction;
}

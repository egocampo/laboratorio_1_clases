/*
 * arrays.c
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */
#include <stdio.h>
#include <stdlib.h>



/* arr_calcularMaximoInt: calcula el mayor numero de un array
 * pArray: dirección de memoria del array
 * limite: tamaño del array
 * maximo: direccion de memoria para almacenar el mayor numero
 * */
int arr_calcularMaximoInt(int* pArray, int limite, int* maximo)
{
	int retorno = -1;
	if(pArray != NULL && limite>=0 && maximo != NULL)
	{
		retorno = -2;
		int bufferIntMax=pArray[0];
		for(int i=0;i<limite;i++)
		{
			if(pArray[i]>bufferIntMax)
			{
				bufferIntMax=pArray[i];
				retorno=0;
			}
		}
		*maximo = bufferIntMax;
	}
	return retorno;
}

/* arr_calcularMinimoInt: calcula el mayor numero de un array
 * pArray: dirección de memoria del array
 * limite: tamaño del array
 * minimo: direccion de memoria para almacenar el menor numero
 * */
int arr_calcularMinimoInt(int* pArray, int limite, int* minimo)
{
	int retorno = -1;
	if(pArray != NULL && limite>=0 && minimo != NULL)
	{
		retorno = -2;
		int bufferIntMin=pArray[0];
		for(int i=0;i<limite;i++)
		{
			if(pArray[i]>bufferIntMin)
			{
				bufferIntMin=pArray[i];
				retorno=0;
			}
		}
		*minimo = bufferIntMin;
	}
	return retorno;
}


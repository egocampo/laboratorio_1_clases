/*
 * array.c
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"
#include "array.h"

/*
 * arr_calcularMaximoInt: calcula el maximo numero de un array
 * *array: puntero a la dirección de memoria del array
 * limite: tamaño del array
 * *resultado: puntero a la dirección de memoria donde almacenar el maximo
 * retorno: 0 sin errores, -1 error de validación de datos.
 * */
int arr_calcularMaximoInt(int* array,int limite, int* resultado)
{
	int retorno = -1;
	if(array != NULL && limite >= 0 && resultado != NULL)
	{
		retorno = 0;
		int bufferIntMax=array[0];
		for(int i=0;i<limite;i++)
		{
			if(array[i]>bufferIntMax)
			{
				bufferIntMax=array[i];
			}
		}
		*resultado = bufferIntMax;
	}
	return retorno;
}
/*
 * arr_calcularMinimoInt: calcula el minimo numero de un array
 * *array: puntero a la dirección de memoria del array
 * limite: tamaño del array
 * *resultado: puntero a la dirección de memoria donde almacenar el maximo
 * * retorno: 0 sin errores, -1 error de validación de datos.
 * */
int arr_calcularMinimoInt(int* array,int limite, int* resultado)
{
	int retorno = -1;
	if(array != NULL && limite >= 0 && resultado != NULL)
	{
		retorno = 0;
		int bufferIntMin=array[0];
		for(int i=0;i<limite;i++)
		{
			if(array[i]<bufferIntMin)
			{
				bufferIntMin=array[i];
			}
		}
		*resultado = bufferIntMin;
	}
	return retorno;
}
/*
 * arr_calcularSumaInt: acumula los numeros de un array
 * *array: puntero a la dirección de memoria del array
 * limite: tamaño del array
 * *resultado: puntero a la dirección de memoria donde almacenar el acumulado
 * * retorno: 0 sin errores, -1 error de validación de datos.
 * */
int arr_calcularSumaInt(int* array,int limite, int* resultado)
{
	int retorno = -1;
	if(array != NULL && limite >= 0 && resultado != NULL)
	{
		retorno = 0;
		int acumulador = 0;
		for(int i=0;i<limite;i++)
		{
			acumulador += array[i];
		}
		*resultado = acumulador;
	}
	return retorno;
}
/*
 * arr_calcularPromedioInt: calcula el promedio de valores de un array
 * *array: puntero a la dirección de memoria del array
 * limite: tamaño del array
 * *resultado: puntero a la dirección de memoria donde almacenar el promedio
 * * retorno: 0 sin errores, -1 error de validación de datos.
 * */
int arr_calcularPromedioInt(int* array,int limite, float* resultado)
{
	int retorno = -1;
	if(array != NULL && limite >= 0 && resultado != NULL)
	{
		retorno = 0;
		int acumulador = 0;
		for(int i=0;i<limite;i++)
		{
			acumulador += array[i];
		}
		*resultado=acumulador/(float)limite;
	}
	return retorno;
}
/*
 * arr_buscarNumeroInt: busca si existe un valor en un array
 * *array: puntero a la dirección de memoria del array
 * limite: tamaño del array
 * *resultado: puntero a la dirección de memoria donde almacenar el promedio
 * * retorno: 0 si encuentra el numero, -2 si no lo encuentra, -1 si hubo error de validación de datos.
 * */
int arr_buscarNumeroInt(int* array,int limite,int numeroBuscado)
{
	int retorno = -1;
	if(array != NULL && limite >=0)
	{
		retorno = -2;
		for(int i=0;i<limite;i++)
		{
			if(array[i]==numeroBuscado)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

void arr_getIntegers(int* array,int limite, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo)
{
	for(int i=0;i<limite;i++)
	{
		utn_getInteger(&array[i], pTexto, pTextoError, reintentos, minimo, maximo);
	}

}

void arr_burbujeo(int* array,int limite,int* arrayOrdenado)
{
	int arrayAuxiliar[limite];
	int aux;
	for(int i=0;i<limite;i++)
	{
		arrayAuxiliar[i]=array[i];
	}
	for(int i=0;i<limite-1;i++)
	{
		for(int j=i+1;j<limite;j++)
		{
			if(arrayAuxiliar[i]>arrayAuxiliar[j])
			{
				aux=arrayAuxiliar[i];
				arrayAuxiliar[i]=arrayAuxiliar[j];
				arrayAuxiliar[j]=aux;
			}
		}
	}
	for(int i=0;i<limite;i++)
	{
		arrayOrdenado[i]=arrayAuxiliar[i];
	}
}

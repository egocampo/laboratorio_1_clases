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
#include "matematicas.h"

//-------------------------------------------------------------------------------------------------------

//////////////////////////////////////////////
/////       * ARRAYS DE ENTEROS *        /////
//////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------------
// INGRESO DE DATOS
/*
 * \brief Pide numeros enteros entre dos valores y los almacena en un array usando la funcion utn_getInteger, con texto de error y reintentos
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param pTexto Texto a mostrar previo al ingreso
 * \param pTextoError Texto a mostar en caso de validacion erronea de dato ingresado
 * \param reintentos Cantidad de reintentos en caso de ingreso de dato erroneo
 * \param minimo Valor inicial de ingreso
 * \param maximo Valor final de ingreso
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_getIntWithMinMax(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pTexto != NULL && pTextoError != NULL && reintentos >= 0 && minimo < maximo)
	{
		retorno = 0;
		for(int i=0;i<len;i++)
		{
			utn_getInteger(&pArray[i], pTexto, pTextoError, reintentos, minimo, maximo);
		}
	}
	return retorno;
}
/*
 * \brief Pide numeros enteros y los almacena en un array usando la funcion utn_getInteger, con texto de error y reintentos
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param pTexto Texto a mostrar previo al ingreso
 * \param pTextoError Texto a mostar en caso de validacion erronea de dato ingresado
 * \param reintentos Cantidad de reintentos en caso de ingreso de dato erroneo
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_getIntSimple(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pTexto != NULL && pTextoError != NULL && reintentos >= 0)
	{
		retorno = 0;
		for(int i=0;i<len;i++)
		{
			utn_getIntWithoutMinimumOrMaximum(&pArray[i], pTexto, pTextoError, reintentos);
		}
	}
	return retorno;
}
/*
 * \brief Obtiene numeros enteros para un array indicando el valor de "posición +1" en el mensaje
 * \param pArray Puntero a la dirección de memoria del array
 * \param pText Mensaje de entrada
 * \param len Tamaño del array
 * \return 0 si no hubo  error, -1 si hubo error de validación
 * */
int arr_getIntShowingPosition(int* pArray, int len,char* pText)
{
	int retorno = -1;
	if(pArray != NULL && pText != NULL && len > 0 )
	{
		retorno = 0;
		int i;
		for(i=0;i<len;i++)
		{
			printf("%s #%d: ",pText,i+1);
			__fpurge(stdin);
			scanf("%d",&pArray[i]);
		}
	}
	return retorno;
}

//-------------------------------------------------------------------------------------------------------
// ORDENAMIENTO
/*
 * \brief Ordenamiento de burbujeo eficiente en sentido creciente o decreciente de un array de enteros
 * \param pArray Puntero a la dirección de memoria del array entero a ordenar
 * \param len Tamaño del array pArray
 * \param flagDecreasing 1 si se debe ordenar de mayor a menor, 1 si se debe ordenar de menor a mayor
 * \return 0 si no hubo errores, -1 si hubo error de validacion de datos
 */
int arr_efficientBubbleInt(int* pArray, int len, int flagDecreasing)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && (flagDecreasing == 1 || flagDecreasing == 0))
	{
		retorno = 0;
		int i;
		int flagSwap;
		if(flagDecreasing)
		{
			do
			{
				flagSwap = 0;
				len--;
				for(i=0;i<len;i++)
				{
					if(pArray[i]>pArray[i+1])
					{
						flagSwap = 1;
						arr_swapInt(pArray, i, i+1);
					}
				}
			}while(flagSwap==1);
		}
		else
		{
			do
			{
				flagSwap = 0;
				len--;
				for(i=0;i<len;i++)
				{
					if(pArray[i]<pArray[i+1])
					{
						flagSwap = 1;
						arr_swapInt(pArray, i, i+1);
					}
				}
			}while(flagSwap==1);
		}
	}
	return retorno;
}

//-------------------------------------------------------------------------------------------------------
// BUSQUEDA
/*
 * \brief Busca si existe un valor entero en un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param numeroBuscado valor buscado en el array
 * \return 0 si encuentra el numero, 1 si no lo encuentra, -1 si hubo error de validación de datos.
 * */
int arr_searchValueInt(int* pArray,int len,int numeroBuscado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 1;
		for(int i=0;i<len;i++)
		{
			if(pArray[i]==numeroBuscado)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}
/*
 * \brief Busca el valor maximo de un array de enteros
 * \param pArray puntero a la dirección de memoria del array donde buscar
 * \param len tamaño del array pArray
 * \param pResultado puntero a la dirección de memoria donde almacenar el valor maximo
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_searchMaximumValueInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		retorno = 0;
		int bufferIntMax=pArray[0];
		for(int i=0;i<len;i++)
		{
			if(pArray[i]>bufferIntMax)
			{
				bufferIntMax=pArray[i];
			}
		}
		*pResultado = bufferIntMax;
	}
	return retorno;
}
/*
 * \brief Busca el valor minimo de un array de enteros
 * \param pArray puntero a la dirección de memoria del array donde buscar
 * \param len tamaño del array pArray
 * \param pResultado puntero a la dirección de memoria donde almacenar el valor maximo
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_searchMinimumValueInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		retorno = 0;
		int bufferIntMin=pArray[0];
		for(int i=0;i<len;i++)
		{
			if(pArray[i]<bufferIntMin)
			{
				bufferIntMin=pArray[i];
			}
		}
		*pResultado = bufferIntMin;
	}
	return retorno;
}
/*
 * \brief Busca el minimo valor de un array desde una posicion dada y devuelve la posicion del elemento
 * \param pArray Puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param initial Posicion dentro del array del primer elemento de búsqueda
 * \param pPosicionRetorno Puntero a la dirección de memoria donde almacenar la posicion del minimo
 * \return devuelve la posición del minimo dentro del array, o -1 si hubo error de validación
 * */
int arr_searchPositionOfMinimumInt(int* pArray,int len, int initial,int* pPosicionRetorno)
{
	int retorno = -1;
	int minimumPosition;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		minimumPosition=initial;
		int i;
		int minimum=pArray[initial];
		for(i=initial;i<len;i++)
		{
			if(pArray[i]<minimum)
			{
				minimum=pArray[i];
				minimumPosition=i;
			}
		}
		*pPosicionRetorno=minimumPosition;
	}
	return retorno;
}


//-------------------------------------------------------------------------------------------------------
// OPERACIONES VARIAS
/*
* \brief Intercambia dos posiciones de un array entero
 * \param pArray Puntero a la dirección de memoria del array
 * \param i posicion a intercambiar
 * \param j posicion a intercambiar
 * \return 0 si se pudo realizar o -1 si hubo error de validación
 * */
int arr_swapInt(int* pArray, int i, int j)
{
	int aux, retorno = -1;
	if(pArray != NULL && i>=0 && j>=0)
	{
		retorno = 0;
		aux = pArray[i];
		pArray[i] = pArray[j];
		pArray[j] = aux;
	}
	return retorno;
}
/*
 * \brief Imprime el contenido de un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_printfArrayInt(int* pArray,int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		for(int i=0;i<len;i++)
		{
			printf("[DEBUG] Indice: %d - Valor: %d\n",i,pArray[i]);
		}
	}
	return retorno;
}
/*
 * \brief Inicializa un array de enteros con valor un valor dado
 * \param pArray Puntero a la dirección de memoria del array a inicializar
 * \param len Tamaño del puntero
 * \param value valor inicial dado
 * \return 0 si no hubo errores, -1 si hubo error de validacion
 * */
int arr_initializeArrayInt(int* pArray, int len, int value)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		for(int i=0;i<len;i++)
		{
			pArray[i]=value;
		}
	}
	return retorno;
}

//-------------------------------------------------------------------------------------------------------
// MATEMATICAS
/*
 * \brief Acumula los numeros de un array de enteros
 * \param pArray: puntero a la dirección de memoria del array
 * \param len: tamaño del array
 * \param pResultado puntero a la dirección de memoria donde almacenar el acumulado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_accumulateInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		retorno = 0;
		int accumulator = 0;
		for(int i=0;i<len;i++)
		{
			accumulator += pArray[i];
		}
		*pResultado = accumulator;
	}
	return retorno;
}
/*
 * \brief Calcula el promedio de valores de un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param pResultado: puntero a la dirección de memoria donde almacenar el promedio
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_calculateAverageInt(int* pArray,int len, float* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && pResultado != NULL)
	{
		retorno = 0;
		int acumulador = 0;
		arr_accumulateInt(pArray, len, &acumulador);
		*pResultado=acumulador/(float)len;
	}
	return retorno;
}


//-------------------------------------------------------------------------------------------------------

//////////////////////////////////////////////
/////      * ARRAYS DE FLOTANTES *       /////
//////////////////////////////////////////////

//-------------------------------------------------------------------------------------------------------
// INGRESO DE DATOS


//-------------------------------------------------------------------------------------------------------
// ORDENAMIENTO


//-------------------------------------------------------------------------------------------------------
// BUSQUEDA


//-------------------------------------------------------------------------------------------------------
// OPERACIONES VARIAS


//-------------------------------------------------------------------------------------------------------
// MATEMATICAS


//////////////////////////////////////////////
/////            SIN ORDENAR            //////
//////////////////////////////////////////////

/*
 * \brief Algoritomo diseñado de manera colaborativa en clase. Burbujeo "eficiente" buscando el valor entero minimo para ordenar de menor a mayor
 * \param pArray Puntero a la dirección de memoria del array
 * \param len Tamaño del array
 * \return 0 si no hubo errores, -1 si hubo error de validacion de datos
 * */
int arr_sortLudmila(int* pArray, int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		int i, positionMinimum;
		for(i=0;i<len-1;i++)
		{
			arr_searchPositionOfMinimumInt(pArray, len, i, &positionMinimum);
			if(i != positionMinimum)
			{
				arr_swapInt(pArray, i, positionMinimum);
			}
		}
	}
	return retorno;
}

/*
 * \brief Ordenamiento de array por método de burbujeo básico, guardando el resultado en otro array
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param arrayOrdenado puntero a la dirección de memoria del array ordenado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_burbujeoBasico(int* pArray,int len,int* arrayOrdenado)
{
	int retorno = -1;
	if(pArray != NULL && len > 0 && arrayOrdenado != NULL)
	{
		retorno = 0;
		int arrayAuxiliar[len];
		int aux;
		for(int i=0;i<len;i++)
		{
			arrayAuxiliar[i]=pArray[i];
		}
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				if(arrayAuxiliar[i]>arrayAuxiliar[j])
				{
					aux=arrayAuxiliar[i];
					arrayAuxiliar[i]=arrayAuxiliar[j];
					arrayAuxiliar[j]=aux;
				}
			}
		}
		for(int i=0;i<len;i++)
		{
			arrayOrdenado[i]=arrayAuxiliar[i];
		}
	}
	return retorno;
}

/*
 * \brief Ordenamiento de array por método de burbujeo eficiente
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_burbujeoEficiente(int* pArray,int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		int j, aux;
		int flagNoEstaOrdenado = 1;
		while(flagNoEstaOrdenado==1)
		{
			flagNoEstaOrdenado = 0;
			for(j=1;j<len;j++)
			{
				if(pArray[j]<pArray[j-1])
				{
					aux=pArray[j];
					pArray[j-1]=pArray[j];
					pArray[j-1]=aux;
					flagNoEstaOrdenado = 1;
				}
			}
		}
	}
	return retorno;
}

/*
 * \brief Ordenamiento de array por método de insersión
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_ordenamientoInsersion(int* pArray,int len)
{
	int retorno = -1;
	if(pArray != NULL && len > 0)
	{
		retorno = 0;
		int i, j;
		int temp;
		for(i=1;i<len;i++)
		{
			temp=pArray[i];
			j=i-1;
			while(j>=0 && temp < pArray[j])
			{
				pArray[j+1] = pArray[j];
				j--;
			}
			pArray[j+1] = temp;
		}
	}
	return retorno;
}





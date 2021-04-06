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

/*
 * \brief Calcula el valor maximo de un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param pResultado puntero a la dirección de memoria donde almacenar el maximo
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_buscarMaximoInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
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
 * \brief Calcula el valor minimo de un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param pResultado puntero a la dirección de memoria donde almacenar el maximo
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_buscarMinimoInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
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
 * \brief Acumula los numeros de un array de enteros
 * \param pArray: puntero a la dirección de memoria del array
 * \param len: tamaño del array
 * \param pResultado puntero a la dirección de memoria donde almacenar el acumulado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_acumularInt(int* pArray,int len, int* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
	{
		retorno = 0;
		int acumulador = 0;
		for(int i=0;i<len;i++)
		{
			acumulador += pArray[i];
		}
		*pResultado = acumulador;
	}
	return retorno;
}

/*
 * \brief Acumula los numeros de un array de enteros
 * \param pArray: puntero a la dirección de memoria del array
 * \param len: tamaño del array
 * \param pResultado puntero a la dirección de memoria donde almacenar el acumulado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_acumularFloat(float* pArray,int len, float* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
	{
		retorno = 0;
		float acumulador = 0;
		for(int i=0;i<len;i++)
		{
			acumulador += pArray[i];
		}
		*pResultado = acumulador;
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
int arr_calcularPromedioInt(int* pArray,int len, float* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
	{
		retorno = 0;
		int acumulador = 0;
		arr_acumularInt(pArray, len, &acumulador);
		*pResultado=acumulador/(float)len;
	}
	return retorno;
}
/*
* \brief Calcula el promedio de valores de un array de flotantes
* \param pArray puntero a la dirección de memoria del array
* \param len tamaño del array
* \param pResultado: puntero a la dirección de memoria donde almacenar el promedio
* \return 0 sin errores, -1 error de validación de datos.
* */
int arr_calcularPromedioFloat(float* pArray,int len, float* pResultado)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pResultado != NULL)
	{
		retorno = 0;
		float acumulador = 0;
		arr_acumularFloat(pArray, len, &acumulador);
		*pResultado=acumulador/len;
	}
	return retorno;
}
/*
 * \brief Busca si existe un valor en un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param numeroBuscado valor buscado en el array
 * \return 0 si encuentra el numero, 1 si no lo encuentra, -1 si hubo error de validación de datos.
 * */
int arr_buscarInt(int* pArray,int len,int numeroBuscado)
{
	int retorno = -1;
	if(pArray != NULL && len >=0)
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
 * \brief Ordenamiento de array por método de burbujeo básico, guardando el resultado en otro array
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param arrayOrdenado puntero a la dirección de memoria del array ordenado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_getIntegers(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pTexto != NULL && pTextoError != NULL && reintentos >= 0 && minimo < maximo)
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
 * \brief Ordenamiento de array por método de burbujeo básico, guardando el resultado en otro array
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param arrayOrdenado puntero a la dirección de memoria del array ordenado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_getIntegersWithoutMinimumOrMaximum(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pTexto != NULL && pTextoError != NULL && reintentos >= 0)
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
 * \brief Ordenamiento de array por método de burbujeo básico, guardando el resultado en otro array
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param arrayOrdenado puntero a la dirección de memoria del array ordenado
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_getFloat(float* pArray,int len, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0 && pTexto != NULL && pTextoError != NULL && reintentos >= 0 && minimo < maximo)
	{
		retorno = 0;
		for(int i=0;i<len;i++)
		{
			utn_getFloat(&pArray[i], pTexto, pTextoError, reintentos, minimo, maximo);
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
	if(pArray != NULL && len >= 0 && arrayOrdenado != NULL)
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
	if(pArray != NULL && len >= 0)
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
	if(pArray != NULL && len >= 0)
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

/*
 * \brief Imprime el contenido de un array de enteros
 * \param pArray puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return 0 sin errores, -1 error de validación de datos.
 * */
int arr_imprimirArrayInt(int* pArray,int len)
{
	int retorno = -1;
	if(pArray != NULL && len >= 0)
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
 * \brief Obtiene floats para un array indicando la posición de ingreso en el mensaje
 * \param pArray Puntero a la dirección de memoria del array
 * \param pTexto Mensaje de entrada
 * \param len Tamaño del array
 * \return 0 si no hubo  error, -1 si hubo error de validación
 * */
int arr_getFloatWithPositions(float* pArray,char* pTexto, int len)
{
	int retorno = -1;
	if(pArray != NULL && pTexto != NULL && len >=0 )
	{
		retorno = 0;
		int i;
		for(i=0;i<len;i++)
		{
			printf("%s #%d: ",pTexto,i);
			__fpurge(stdin);
			scanf("%f",&pArray[i]);
		}
	}
	return retorno;
}

/*
 * \brief Busca el minimo valor y devuelve la posicion
 * \param pArray Puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \param inicio Posicion del primer elemento de búsqueda
 * \param pPosicionRetorno Puntero a la dirección de memoria donde almacenar la posicion del minimo
 * \return devuelve la posición del minimo dentro del array, o -1 si hubo error de validación
 * */
int arr_searchPositionOfMinimum(int* pArray,int len, int inicio,int* pPosicionRetorno)
{
	int retorno = -1;
	int posicionMinimo;
	if(pArray != NULL && len >=0)
	{
		retorno = 0;
		posicionMinimo=inicio;
		int i;
		int minimum=pArray[inicio];
		for(i=inicio;i<len;i++)
		{
			if(pArray[i]<minimum)
			{
				minimum=pArray[i];
				posicionMinimo=i;
			}
		}
		*pPosicionRetorno=posicionMinimo;
	}
	return retorno;
}

/*
 * \brief Busca el maximo valor y devuelve la posicion
 * \param pArray Puntero a la dirección de memoria del array
 * \param len tamaño del array
 * \return devuelve la posición del maximo dentro del array, o -1 si hubo error de validación
 * */
int arr_searchPositionOfMaximum(float* pArray,int len)
{
	int retorno = -1;
	if(pArray != NULL && len >=0)
	{
		retorno = 0;
		float maximum=pArray[0];
		int i;
		for(i=1;i<len;i++)
		{
			if(pArray[i]>maximum)
			{
				maximum=pArray[i];
				retorno=i;
			}
		}
	}
	return retorno;
}

int arr_intercambiarPosicion(int* pArray, int i, int j)
{
	int retorno = -1;
	int aux;
	if(pArray != NULL)
	{
		retorno = 0;
		aux = pArray[i];
		pArray[i] = pArray[j];
		pArray[j] = aux;
	}
	return retorno;
}

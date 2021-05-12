/*
 * utn.
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>
#include "utn.h"

/*
 * \brief Recibe una cadena con fgets, le remueve el enter del final y almacena el resultado
 * \param string Puntero a la direccion de memoria del string
 * \param len Tamaño del array. Limite de caracteres/digitos
 * \return -1 si hubo error de validacion, 0 si no hubo errores.
 * */
int utn_myGets(char* pResultado, int len)
{
	int returnFunction = -1;
	__fpurge(stdin);
	if(pResultado != NULL && len > 0 && fgets(pResultado,len,stdin)==pResultado)
	{
		__fpurge(stdin);
		if(pResultado[strlen(pResultado)-1]== '\n')
		{
			pResultado[strlen(pResultado)-1]='\0';
		}
		returnFunction = 0;
	}
	return returnFunction;
}
//**************************************************************

int utn_getString(char* pResultado,int len)
{
	int returnFunction = -1;
	if(pResultado != NULL && len > 0)
	{
		returnFunction = 1;
		utn_myGets(pResultado,len);
	}
	return returnFunction;
}

//-------------------------------------------------------------------------------------------------------------------------------

/*
 * \brief Indica si un string es un numero entero
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto numero
 * \return -1 error de validacion, 0 no es un numero entero, 1 sí es un numero entero.
 * */
int utn_isValidNumberInt(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i=0;
	if(numero != NULL)
	{
		returnFunction = 1;
		if((numero[i] < '0' || numero[i] > '9') && numero[i] !='-')
		{
			returnFunction = 0;
		}
		else
		{
			while(numero[i] != 0) // busco el final
			{
				if(numero[i]<'0' || numero[i]>'9')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un numero flotante
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto numero
 * \return -1 error de validacion, 0 no es un numero flotante, 1 sí es un numero flotante.
 * */
int utn_isValidNumberFloat(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i;
	if(numero != NULL)
	{
		returnFunction = 1;
		if(flagSigned)
		{
			i = 1;
			if((numero[0]<'0' || numero[0]>'9') && numero[0] != '.' && numero[0] != '-')
			{
				returnFunction = 0;
			}
			else
			{
				while(numero[i] != 0) // busco el final
				{
					if((numero[i]<'0' || numero[i]>'9') && numero[i] != '.')
					{
						returnFunction = 0;
						break;
					}
					i++;
				}
			}
		}
		else
		{
			i = 0;
			while(numero[i] != 0) // busco el final
			{
				if((numero[i]<'0' || numero[i]>'9') && numero[i] != '.')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
	}
	return returnFunction;
}

int utn_isValidName(char* nombre)
{
	int i=0;
	int returnFunction = -2;
	if(nombre != NULL)
	{
		returnFunction = 1;
		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]=='Z'))
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}

int utn_isValidDni(char* dni)
{
	int i=0;
	int returnFunction = -2;
	if(dni != NULL)
	{
		returnFunction = 1;
		while(dni[i] != 0) // busco el final
		{
			if(dni[i]<'0' || dni[i]>'9')
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}

int utn_isValidCuit(char* cuit)
{
	int i=0;
	int returnFunction = -2;
	if(cuit != NULL)
	{
		returnFunction = 1;
		while(cuit[i] != 0) // busco el final
		{
			if(cuit[i]<'0' || cuit[i]>'9')
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
//		if(utn_cuitDigitoVerificador(cuit)!=cuit[strlen(cuit)])
//		{
//			returnFunction = 0;
//		}
	}
	return returnFunction;
}

int utn_cuitDigitoVerificador(char* cuit)
{
	int returnFunction = -1;
	if(cuit != NULL)
	{
		int auxiliares[10]={5,4,3,2,7,6,5,4,3,2};
		char auxCuitChar[10];
		int auxCuitInt[10];
		int acumulador=0;
		//float promedio;
		int i;
		for(i=0;i<10;i++)
		{
			auxCuitChar[i]=cuit[i];
			switch(auxCuitChar[i])
			{
				case '0':
					auxCuitInt[i] = 0;
					break;
				case '1':
					auxCuitInt[i] = 1;
					break;
				case '2':
					auxCuitInt[i] = 2;
					break;
				case '3':
					auxCuitInt[i] = 3;
					break;
				case '4':
					auxCuitInt[i] = 4;
					break;
				case '5':
					auxCuitInt[i] = 5;
					break;
				case '6':
					auxCuitInt[i] = 6;
					break;
				case '7':
					auxCuitInt[i] = 7;
					break;
				case '8':
					auxCuitInt[i] = 8;
					break;
				case '9':
					auxCuitInt[i] = 9;
					break;
			}
			acumulador += auxCuitInt[i]*auxiliares[i];
		}
		//promedio=acumulador/11.0;
		//returnFunction=11-round((promedio-(int)promedio)*10);
	}
	return returnFunction;
}

//-----------------------------------------------------------------------------------------------------------

int utn_getName(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(utn_getString(buffer, len) && utn_isValidName(buffer))
			{
				strcpy(pResultado,buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

//-------------------------------------------------------------------------------------------------------------------------

int utn_getDni(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(utn_getString(buffer, len) && utn_isValidDni(buffer))
			{
				*pResultado=atoi(buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

//-------------------------------------------------------------------------------------------------------------------------

int utn_getCuit(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(utn_getString(buffer, len) && utn_isValidCuit(buffer)==1)
			{
				*pResultado=atoi(buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

//-------------------------------------------------------------------------------------------------------------------------

/*
 * \brief Pide un numero flotante
 * \param float* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el punto, el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos: 1 o no: 0
 * \return Devuelve 1 si pudo obtener un flotante, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int utn_getNumberFloat(float* pResultado,int len,char* mensaje,char* mensajeError,int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(utn_getString(buffer,len) && utn_isValidNumberFloat(buffer,flagSigned)==1)
			{
				*pResultado=atof(buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un numero entero
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos: 1 o no: 0
 * \return Devuelve 1 si pudo obtener un entero, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int utn_getNumberInt(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(utn_getString(buffer,len) && utn_isValidNumberFloat(buffer,flagSigned)==1)
			{
				*pResultado=atoi(buffer);
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

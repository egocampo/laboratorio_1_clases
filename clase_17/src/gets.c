/*
 * gets.c
 *
 *  Created on: 18 abr. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "gets.h"
#include "validations.h"

#define LEN_DNI 9
#define LEN_CUIT 12
#define LEN_EMAIL 30

/*_| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |
   | |              FUNCION PRINCIPAL             | |
 __| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |*/
/*
 * \brief Recibe una cadena con fgets, le remueve el enter del final y devuelve el resultado por referencia
 * \param string Puntero a la direccion de memoria del string
 * \param len Tamaño del array. Limite de caracteres/digitos
 * \return -1 si hubo error de validacion, 1 si no hubo errores.
 * */
int get_myGets(char* pResultado, int len)
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
		returnFunction = 1;
	}
	return returnFunction;
}

/*_| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |
   | |          FUNCIONES DE OBTENCION            | |
 __| |____________________________________________| |__
(__   ____________________________________________   __)
   | |                                            | |*/

/*
 * \brief Pide un numero entero
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño de la lista blanca
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return Devuelve 1 si pudo obtener un entero, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */

int get_char(char* caracter,char* listaBlanca,int len, char* mensaje, char* mensajeError, int reintentos)
{
	int returnFunction = -1;
	char buffer;
	returnFunction = 0;
	if(caracter != NULL && listaBlanca != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(&buffer,2) && val_isInWhiteList(&buffer, listaBlanca, len)==1)
			{
				*caracter = buffer;
				returnFunction = 1;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int get_int(int* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	int bufferInt;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidInt(buffer,flagSigned)==1)
			{
				bufferInt=atoi(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferInt <= maximo && bufferInt >= minimo)
					{
						*pResultado = bufferInt;
						returnFunction = 1;
						break;
					}
				}
				else
				{
					*pResultado = bufferInt;
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int get_intAsChar(char* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	int bufferInt;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidInt(buffer,flagSigned)==1)
			{
				bufferInt=atoi(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferInt <= maximo && bufferInt >= minimo)
					{
						strncpy(pResultado,buffer,len);
						returnFunction = 1;
						break;
					}
				}
				else
				{
					strncpy(pResultado,buffer,len);
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un numero flotante
 * \param float* pResultado Puntero a la dirección de memoria donde guardar el valor obtenido y validado
 * \param int len Tamaño del array indica el maximo de digitos del numero (hay que descontar el EOF y el signo menos, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int flagMaximoMinimo: Indica si acepta valores maximos y minimos (1) o no (0)
 * \param int minimo Valor minimo a recibir
 * \param int maximo Valor maximo a recibir
 * \param int reintentos Cantidad de reintentos
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return Devuelve 1 si pudo obtener un flotante, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	float bufferFloat;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidFloat(buffer,flagSigned)==1)
			{
				bufferFloat=atof(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferFloat <= maximo && bufferFloat >= minimo)
					{
						*pResultado = bufferFloat;
						returnFunction = 1;
						break;
					}
				}
				else
				{
					*pResultado = bufferFloat;
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

int get_floatAsChar(char* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned)
{
	int returnFunction = -1;
	char buffer[len];
	float bufferFloat;
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer,len) && val_isValidFloat(buffer,flagSigned)==1)
			{
				bufferFloat=atof(buffer);
				if(flagMaximoMinimo == 1)
				{
					if(bufferFloat <= maximo && bufferFloat >= minimo)
					{
						strncpy(pResultado,buffer,len);
						returnFunction = 1;
						break;
					}
				}
				else
				{
					strncpy(pResultado,buffer,len);
					returnFunction = 1;
					break;
				}
			}
			printf("%s",mensajeError);
			reintentos--;
		}
	}
	return returnFunction;
}

/*
 * \brief Pide un nombre
 * \param int* pResultado Puntero a la dirección de memoria donde guardar el dato obtenido y validado
 * \param int len Tamaño del array indica el maximo de caracteres del nombre (hay que descontar el EOF y espacios, si corresponde)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un nombre, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && val_isValidName(buffer))
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

/*
 * \brief Pide un texto no vacio
 * \param char* pResultado Puntero a la dirección de memoria donde guardar el texto obtenido
 * \param int len Tamaño del array indica el maximo de caracteres del texto (hay que descontar el EOF)
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un texto, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos)
{
	int returnFunction = -1;
	char buffer[len];
	if(pResultado != NULL && len > 0 && mensaje != NULL)
	{
		returnFunction = 0;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, len) && buffer[0] != 0)
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

/*
 * \brief Pide un dni
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el dni
 * \param int len Tamaño máximo del dni
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un dni, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[LEN_DNI];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_DNI) && val_isValidDni(buffer))
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

/*
 * \brief Pide un cuit
 * \param char* pResultado Dirección de memoria del array de caracteres donde almacenar el cuit
 * \param char* mensaje Mensaje que se muestra previo al ingreso
 * \param char* mensajeError Mensaje que se muestra ante ingreso erróneo
 * \param int reintentos Cantidad de reintentos
 * \return Devuelve 1 si pudo obtener un cuit, 0 si no lo pudo obtener, -1 si hubo error de validación
 * */
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -2;
	char buffer[LEN_CUIT];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_CUIT) && val_isValidCuit(buffer)==1)
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

int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos)
{
	int returnFunction = -1;
	char buffer[LEN_EMAIL];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		returnFunction = -1;
		while(reintentos >= 0)
		{
			printf("%s",mensaje);
			if(get_myGets(buffer, LEN_EMAIL) && val_isValidEmail(buffer)==1)
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

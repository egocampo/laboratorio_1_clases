/*
 * utn.c
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"  // lo incluimos por si otra funcion tambien lo usa

/*
 * utn_getInteger: pide un numero entero al usuario y lo valida con reintentos
 * int* pNumeroSolicitado: dirección donde almacenar el numero ingresado validado
 * char* pTexto: texto que se muestra antes del ingreso
 * char* pTextoError: texto que se muestra en caso de error
 * int reintentos: cantidad de reintentos tras ingreso erroneo
 * int minimo: valor minimo del rango
 * int maximo: valor maximo del rango
 * retorno: devuelve  0 si no hubo error o -1 si no pudo en los intentos estipulados
 * */
int utn_getInteger(int* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos, int minimo, int maximo)
{
	int retorno=0;
	int numeroSolicitado;
	do
	{
		printf("%s",pTexto);
		__fpurge(stdin);
		if(scanf("%d",&numeroSolicitado)==1) // scanf retorna la cantidad de variables que pudo capturar, si no devuelve 1 hay un error, ej al poner "hola"
		{
			if(numeroSolicitado<minimo || numeroSolicitado>maximo)
			{
				printf("%s",pTextoError);
				reintentos--;
				retorno=-1;
			}
			else
			{
				*pNumeroSolicitado=numeroSolicitado;
				retorno=0;
				break;
			}
		}
		else
		{
			printf("%s\n",pTextoError);
			reintentos--;
			retorno=-1;
		}
	}while(reintentos>0);
	return retorno;
}
/*
 * utn_getFloat: pide un numero flotante al usuario y lo valida con reintentos
 * float* pNumeroSolicitado: dirección donde almacenar el numero ingresado validado
 * char* pTexto: texto que se muestra antes del ingreso
 * char* pTextoError: texto que se muestra en caso de error
 * int reintentos: cantidad de reintentos tras ingreso erroneo
 * int minimo: valor minimo del rango
 * int maximo: valor maximo del rango
 * retorno: devuelve  0 si no hubo error o -1 si no pudo en los intentos estipulados
 * */
int utn_getFloat(float* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos, int minimo, int maximo)
{
	int retorno=0;
	float numeroSolicitado;
	do
	{
		printf("%s",pTexto);
		__fpurge(stdin);
		if(scanf("%f",&numeroSolicitado)==1) // scanf retorna las variables que puede convertir, si no devuelve una hay un error, ej al poner "hola"
		{
			if(numeroSolicitado<minimo || numeroSolicitado>maximo)
			{
				printf("%s\n",pTextoError);
				reintentos--;
				retorno=-1;
			}
			else
			{
				*pNumeroSolicitado=numeroSolicitado;
				retorno=0;
				break;
			}
		}
		else
		{
			printf("%s\n",pTextoError);
			reintentos--;
			retorno=-1;
		}
	}while(reintentos>0);
	return retorno;
}

int utn_getChar(char* pCaracterSolicitado,char* pTexto,char* pTextoError,int reintentos, char opcionUno, char opcionDos)
{
	int retorno=0;
	char caracterSolicitado;
	do
	{
		printf("%s",pTexto);
		__fpurge(stdin);
		if(scanf("%c",&caracterSolicitado)==1) // scanf retorna las variables que puede convertir, si no devuelve una hay un error
		{
			if(caracterSolicitado != opcionUno && caracterSolicitado != opcionDos)
			{
				printf("%s",pTextoError);
				reintentos--;
				retorno=-1;
			}
			else
			{
				*pCaracterSolicitado=caracterSolicitado;
				retorno=0;
				break;
			}
		}
		else
		{
			printf("%s",pTextoError);
			reintentos--;
			retorno=-1;
		}
	}while(reintentos>0);
	return retorno;
}
/*
 * utn_getFloat: pide un numero flotante al usuario y lo valida con reintentos
 * float* pNumeroSolicitado: dirección donde almacenar el numero ingresado validado
 * char* pTexto: texto que se muestra antes del ingreso
 * char* pTextoError: texto que se muestra en caso de error
 * int reintentos: cantidad de reintentos tras ingreso erroneo
 * int minimo: valor minimo del rango
 * int maximo: valor maximo del rango
 * retorno: devuelve  0 si no hubo error o -1 si no pudo en los intentos estipulados
 * */
int utn_getFloatWithoutMinimumOrMaximum(float* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos)
{
	int retorno=0;
	float numeroSolicitado;
	do
	{
		printf("%s",pTexto);
		__fpurge(stdin);
		if(scanf("%f",&numeroSolicitado)==1) // scanf retorna las variables que puede convertir, si no devuelve una hay un error, ej al poner "hola"
		{
			*pNumeroSolicitado=numeroSolicitado;
			retorno=0;
			break;
		}
		else
		{
			printf("%s\n",pTextoError);
			reintentos--;
			retorno=-1;
		}
	}while(reintentos>0);
	return retorno;
}

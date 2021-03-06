/*
 * utn.c
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "utn.h"  // para mis bibliotecas se usan comillas


int utn_getInteger(int* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos, int minimo, int maximo)
{
	int retorno = -1;
	int bufferInt;
	if(pNumeroSolicitado != NULL && pTexto != NULL && pTextoError != NULL && minimo<=maximo && reintentos>=0)
	{
		retorno = -2;
		do
		{
			printf("%s",pTexto);
			__fpurge(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pNumeroSolicitado = bufferInt;
				retorno = 0;
				break;
			}
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

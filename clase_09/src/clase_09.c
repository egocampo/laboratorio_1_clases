/*
 ============================================================================
 Name        : clase_09.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "utn.h"
#include "producto.h"

#define QTY_PRODUCTOS 200

typedef struct
{
	char tipoGlobal[14];
	char numeroPrincipal[8];
	char digitoVerificador[1];
}NumeroDeCuit;

int isValidCuit(char* cuitParaValidar)
{
	int returnFunction = -1;
	if(cuitParaValidar != NULL)
	{
		returnFunction = 0;
		if(cuitParaValidar[0] >= '0' && cuitParaValidar[0] <= '9')
		{
			if(cuitParaValidar[1] >= '0' && cuitParaValidar[1] <= '9')
			{
				if(cuitParaValidar[2] == '-')
				{
					if(cuitParaValidar[3] >= '0' && cuitParaValidar[3] <= '9')
					{
						if(cuitParaValidar[4] >= '0' && cuitParaValidar[4] <= '9')
						{
							if(cuitParaValidar[5] >= '0' && cuitParaValidar[5] <= '9')
							{
								if(cuitParaValidar[6] >= '0' && cuitParaValidar[6] <= '9')
								{
									if(cuitParaValidar[7] >= '0' && cuitParaValidar[7] <= '9')
									{
										if(cuitParaValidar[8] >= '0' && cuitParaValidar[8] <= '9')
										{
											if(cuitParaValidar[9] >= '0' && cuitParaValidar[9] <= '9')
											{
												if(cuitParaValidar[10] >= '0' && cuitParaValidar[10] <= '9')
												{
													if(cuitParaValidar[11] == '-')
													{
														if(cuitParaValidar[12] >= '0' && cuitParaValidar[12] <= '9')
														{
															returnFunction = 1;
														}
													}
												}
											}
										}
									}

								}
							}
						}
					}
				}
			}
		}
	}
	return returnFunction;
}

int getCuit(char* pResultado)
{
	int returnFunction = 0;
	char auxCuitChar[14];
	NumeroDeCuit auxCuit;
	utn_getString(auxCuitChar,14);
	if(isValidCuit(auxCuitChar)==1)
	{
		auxCuit.tipoGlobal
		//strcpy(pResultado,auxCuit);
		returnFunction = 1;
	}
	return returnFunction;
}

int main(void)
{
	//int a;

	//NumeroDeCuit cuit;
	char cuit[14];
	if(getCuit(cuit)==1)
	{
		printf("%s",cuit);
	}

	return EXIT_SUCCESS;
}












//typedef struct
//{
//	int dia;
//	int mes;
//	int anio;
//}Fecha;

//void imprimirFecha(Fecha fechaParaImprimir)
//{
//	printf("%d/%d/%d",fechaParaImprimir.dia,
//			fechaParaImprimir.mes,
//			fechaParaImprimir.anio);
//}
//
//void imprimirFechaConPuntero(Fecha* pFechaParaImprimir)
//{
//	printf("%d/%d/%d",pFechaParaImprimir->dia,
//					  pFechaParaImprimir->mes,
//					  (*pFechaParaImprimir).anio);
//}

//Fecha f;
//f.dia = 15;
//f.mes = 4;
//f.anio = 2021;
//
//imprimirFecha(f);

/*
 * validations.c
 *
 *  Created on: 19 abr. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>
#include "gets.h"
#include "validations.h"

int val_isInWhiteList(char* caracterParaComparar, char* listaBlanca,int len)
{
	int returnFunction = 0;
	int i;
	for(i=0;i<len;i++)
	{
		if(*caracterParaComparar == listaBlanca[i])
		{
			returnFunction = 1;
		}
	}
	return returnFunction;
}


/*
 * \brief Indica si un string es un numero entero
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto numero
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return -1 error de validacion, 0 no es un numero entero, 1 sí es un numero entero.
 * */
int val_isValidInt(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i;
	if(numero != NULL)
	{
		returnFunction = 1;
		if((numero[0] < '0' || numero[0] > '9') && numero[0] !='-')
		{
			returnFunction = 0;
		}
		else
		{
			i = 1;
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
 * \param int flagSigned Indica si recibe negativos (1) o no (0)
 * \return -1 error de validacion, 0 no es un numero flotante, 1 sí es un numero flotante.
 * */
int val_isValidFloat(char* numero, int flagSigned)
{
	int returnFunction = -1;
	int i;
	if(numero != NULL)
	{
		returnFunction = 1;
		if(flagSigned)
		{
			if((numero[0]<'0' || numero[0]>'9') && numero[0] != '.' && numero[0] != '-')
			{
				returnFunction = 0;
			}
			else
			{
				i = 1;
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

/*
 * \brief Indica si un string es un nombre valido
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto nombre
 * \return -1 error de validacion, 0 no es un nombre, 1 sí es un nombre.
 * */
int val_isValidName(char* nombre)
{
	int i=0;
	int returnFunction = -1;
	if(nombre != NULL)
	{
		returnFunction = 1;
		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==' '))
			{
				returnFunction = 0;
				break;
			}
			i++;
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un dni valido
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto dni
 * \return -1 error de validacion, 0 no es un dni valido, 1 sí es un dni valido.
 * */
int val_isValidDni(char* dni)
{
	int i=0;
	int returnFunction = -1;
	if(dni != NULL)
	{
		returnFunction = 1;
		if(val_cantidadDigitos(dni)>6)
		{
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
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}

/*
 * \brief Indica si un string es un dni valido
 * \param char* numero Puntero a la dirección de memoria del string con el supuesto dni
 * \return -1 error de validacion, 0 no es un dni valido, 1 sí es un dni valido.
 * */
int val_isValidCuit(char* cuit)
{
	int i=0;
	int returnFunction = -1;
	if(cuit != NULL)
	{
		returnFunction = 1;
		if(val_cantidadDigitos(cuit)>9 && val_cuitDigitoVerificador(cuit))
		{
			while(cuit[i] != 0) // busco el final
			{
				if(cuit[i]<'0' || cuit[i]>'9')
				{
					returnFunction = 0;
					break;
				}
				i++;
			}
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}
/*
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
*/

int val_cantidadDigitos(char* arrayParaVerificar)
{
	int contadorDigitos=-1;
	if(arrayParaVerificar != NULL)
	{
		for(contadorDigitos=0;;contadorDigitos++)
		{
			if(arrayParaVerificar[contadorDigitos]==0)
				break;
		}
	}
	return contadorDigitos;
}


int val_cuitDigitoVerificador(char* cuit)
{
	int returnFunction = -1;
	int auxiliares[10]={5,4,3,2,7,6,5,4,3,2};
	int auxCuitInt[11];
	int acumulador=0;
	int digitoVerificador;
	float promedio;
	int i;
	if(cuit != NULL)
	{
		for(i=0;i<11;i++)
		{
			switch(cuit[i])
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
		}
		for(i=0;i<10;i++)
		{
			acumulador += auxCuitInt[i]*auxiliares[i];
		}
		promedio=acumulador/11.0;
		digitoVerificador=11-round((promedio-(int)promedio)*10);
		if(digitoVerificador==auxCuitInt[10])
		{
			returnFunction = 1;
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}

int val_isValidEmail(char* email)
{
	int i=0;
	int returnFunction = -1;
	int contadorPuntos = 0;
	int contadorArroba = 0;
	if(email != NULL)
	{
		returnFunction = 1;
		if(email[0] != '.' && email[0] != '@')
		{
			while(email[i] != 0) // busco el final
			{
				if(!((email[i]>='a' && email[i]<='z') || (email[i]>='A' && email[i]<='Z') || (email[i]>='0' || email[i]<='9') ||
						email[i]=='@' || email[i]=='-' || email[i]=='_' || email[i]=='.'))
				{
					returnFunction = 0;
					break;
				}
				i++;
				if(email[i]=='.')
					contadorPuntos++;
				if(email[i]=='@')
					contadorArroba++;
				if(contadorArroba > 1)
				{
					returnFunction = 0;
					break;
				}
			}
			if(contadorPuntos < 1)
			{
				returnFunction = 0;
			}
		}
		else
		{
			returnFunction = 0;
		}
	}
	return returnFunction;
}




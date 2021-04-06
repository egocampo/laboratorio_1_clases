/*
 * matematicas.c
 *
 *  Created on: 17 mar. 2021
 *      Author: egabr
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "matematicas.h"

/*
 * utn_sumNumbers : suma dos numeros dados
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* sumResult: direccion de memoria para guardar el resultado de la suma
 * */
int utn_sumNumbers(float numberOne,float numberTwo, float* sumResult)
{
	*sumResult = numberOne + numberTwo;
	return 0;
}
/*
 * utn_subtractionNumbers : resta dos numeros dados
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* subtractionResult: direccion de memoria para guardar el resultado de la resta
 * */
int utn_subtractionNumbers(float numberOne,float numberTwo, float* subtractionResult)
{
	*subtractionResult = numberOne - numberTwo;
	return 0;
}
/*
 * utn_divisionNumbers : divide un numero dado por otro numero dado
 * int numberOne: dividendo
 * int numberTwo: divisor
 * int* sumResult: direccion de memoria para guardar el resultado de la division
 * returnFunction: devuelve 0 si no hubo error, devuelve -1 si el divisor es cero (no puede dividirse entre cero)
 * */
int utn_divisionNumbers(float numberOne,float numberTwo, float* divisionResult)
{
	int returnFunction = 0;
	if(numberTwo == 0)
	{
		returnFunction = -1;
	}
	*divisionResult = numberOne / numberTwo;
	return returnFunction;
}
/*
 * utn_multiplicationNumbers : multiplica un numero dado por otro numero dado
 * int numberOne: primer numero
 * int numberTwo: segundo numero
 * int* sumResult: direccion de memoria para guardar el resultado de la multiplicacion
 * */
int utn_multiplicationNumbers(float numberOne,float numberTwo, float* multiplicationResult)
{
	*multiplicationResult = numberOne * numberTwo;
	return 0;
}
/*
 * utn_factorialNumber : calcula el factorial de un numero dado
 * int number: numero dado
 * int* factorial: direccion de memoria para guardar el factorial
 * retunrFunction: devuelve 0 si no hubo error, devuelve -1 si el numero dado es negativo, devuelve -2 si el numero es decimal,
 *  devuelve -3 si el numero dado es muy grande para calular el factorial
 * */
int utn_factorialNumber(float number, long long int* factorial)
{
	#define MAX_FACTORIAL 20
	int i;
	unsigned long long int auxiliarFactorial = 1;
	int returnFunction = 0;
	if(utn_isInt(number))
	{
		if(number > 0)
		{
			if(number > MAX_FACTORIAL)
			{
				returnFunction=-3;
			}
			else
			{
				for(i = 0;i < number - 1;i++)
				{
					auxiliarFactorial = auxiliarFactorial * (number - i);
				}
				*factorial = auxiliarFactorial;
			}
		}
		else if(number == 0)
		{
			*factorial = 1;
		}
		else
		{
			returnFunction = -1;
		}
	}
	else
	{
		returnFunction=-2;
	}
	return returnFunction;
}

/*
 * isInt(): devuelve si un numero es entero o no
 * float number: numero a analizar
 * auxiliar: numero para comparar
 * returnFunction: devuelve 1 si es entero o 0 si no lo es
 * */
int utn_isInt(float number)
{
	int auxiliar=number;
	int returnFunction;
	if(auxiliar-number==0)
	{
		returnFunction=1;
	}
	else
	{
		returnFunction=0;
	}
	return returnFunction;
}



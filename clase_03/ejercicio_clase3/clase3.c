/******************************************************************
* Programa: Ejemplo Clase 3
*
* Objetivo:
*   -Crear una función que permita ingresar un numero al usuario y lo retorne.
*   -Crear una función que reciba el radio de un círculo y retorne su área
*   -Utilizar las funciones de los puntos 1 y 2 para hacer un programa que calcule
*    el área de un círculo cuyo radio es ingresado por el usuario
*   -Documentar las funciones al estilo Doxygen
*
* Aspectos a destacar:
*   -Declaración de funciones que devuelven y reciben valores
*   -Hacer notar que el uso de funciones evita el código repetido y ayuda a que
*    el mismo sea mas legible
*   -La función debería comenzar indicando el objetivo que persigue y el
*    significado de sus parámetros.
*
* Version: 0.1 del 29 diciembre de 2015
* Autor: Mauricio Dávila
* Revisión: Ernesto Gigliotti
*
* *******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846

float ingresarNumero();
float calcularArea(float radioCirculo);

int main()
{
	float radioCirculo;
	float areaCirculo;

	printf("Ingrese el radio del circulo: ");
	radioCirculo = ingresarNumero();
	areaCirculo = calcularArea(radioCirculo);

	printf("\nUn circulo de radio: %.1f tiene un area de: %.1f\n",
			radioCirculo, areaCirculo);
	return 0;
}

float ingresarNumero()
{
	float bufferFloat;
	scanf("%f",&bufferFloat);
	return bufferFloat;
}
float calcularArea(float radioCirculo)
{
	float areaCirculo;
	areaCirculo = radioCirculo*radioCirculo*M_PI;
	return areaCirculo;
}

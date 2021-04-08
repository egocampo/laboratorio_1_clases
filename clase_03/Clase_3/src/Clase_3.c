/*
 ============================================================================
 Name        : Clase_3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Repaso punteros
 ============================================================================
 */
/* cada variable tiene direccion de memoria y valor
 * toda variable tiene valor,
 * cuando no puedo determinar el valor es "basura"
 * "*" => operador de indirección
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

float dividir(float numero1,float numero2, float* resultado);
float sumar(float sumandoA, float sumandoB, float* pResultado);
float restar(float minuendo, float sustraendo, float* pResultado);
float multiplicar(float factorA, float factorB, float* pResultado);

int main(void)
{
	float numeroA;
	float numeroB;
	float resultado;
	int operacionElegida;
	int retornoFuncion;
	char continuar;

	do
	{
	printf("Ingrese #1: ");
	scanf("%f",&numeroA);
	printf("Ingrese #2: ");
	scanf("%f",&numeroB);
	printf("Seleccione la operación a realizar \n\t(1:suma / 2:resta / 3:multiplicacion / 4:division): ");
	scanf("%d",&operacionElegida);
	while(operacionElegida<0 || operacionElegida>4)
	{
		printf("Operación no válida. Seleccione la operación a realizar \n\t(1:suma / 2:resta / 3:multiplicacion / 4:division): ");
		scanf("%d",&operacionElegida);
	}

	switch(operacionElegida)
	{
		case 1:
			retornoFuncion=sumar(numeroA,numeroB,&resultado);
			break;
		case 2:
			retornoFuncion=restar(numeroA,numeroB,&resultado);
			break;
		case 3:
			retornoFuncion=multiplicar(numeroA,numeroB,&resultado);
			break;
		case 4:
			retornoFuncion=dividir(numeroA,numeroB,&resultado);
			break;
	}

	if(retornoFuncion==0)
	{
		printf("El resultado es: %.2f\n",resultado);
	}
	else
	{
		printf("Ha ocurrido un error.\n");
	}
	printf("¿Desea realizar otra operacion? [s = si]");
	__fpurge(stdin);
	scanf("%c",&continuar);
	//system("clear");
	}while(continuar=='s');
	return EXIT_SUCCESS;
}

float sumar(float sumandoA, float sumandoB, float* pResultado)
{
	*pResultado=sumandoA+sumandoB;
	return 0;
}

float restar(float minuendo, float sustraendo, float* pResultado)
{
	*pResultado=minuendo-sustraendo;
	return 0;
}

float multiplicar(float factorA, float factorB, float* pResultado)
{
	*pResultado=factorA*factorB;
	return 0;
}

float dividir(float dividendo,float divisor, float* pResultado)
{
	if(divisor==0)
	{
		return -1;
	}
	*pResultado=dividendo/divisor;
	return 0;
}

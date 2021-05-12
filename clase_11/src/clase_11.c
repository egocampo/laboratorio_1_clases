/*
 ============================================================================
 Name        : clase_11.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "pantalla.h"
#include "contratacion.h"
#include "gets.h"

int main(void)
{
	Pantalla arrayPantallas[100];
	Contratacion arrayContrataciones[1000];
	int contadorIdPantalla = 1;
	int contadorIdContratacion = 1;
	int opcionElegida;
	pan_initArray(arrayPantallas, 100);
	con_initArray(arrayContrataciones, 1000);
	do
	{
		system("clear");
		printf("Menú principal\n\nPantalla:\n 1) Altas\n 2) Modificaciones\n 3) Baja\n 4) Imprimir\n 5) Alta Contrato\n");
		get_int(&opcionElegida, 3,"Ingrese opción: ","Opción no válida. ",1,1,11,3,0);
		switch(opcionElegida)
		{
			case 1:
				pan_altaPantalla(arrayPantallas, 100, &contadorIdPantalla);
				printf("\nPresione una tecla para continuar...");
				getchar();
				break;
			case 2:
				pan_modificarPantalla(arrayPantallas, 100,contadorIdPantalla);
				printf("\nPresione una tecla para continuar...");
				getchar();
				break;
			case 3:
				pan_bajaPantalla(arrayPantallas,contadorIdPantalla);
				printf("\nPresione una tecla para continuar...");
				getchar();
				break;
			case 4:
				pan_printEsctructuraBase(arrayPantallas, 3,"");
				printf("\nPresione una tecla para continuar...");
				getchar();
				break;
			case 5:
				con_altaContrato(arrayContrataciones, 1000, &contadorIdContratacion, arrayPantallas, &contadorIdPantalla);
				printf("\nPresione una tecla para continuar...");
				getchar();
				break;
			case 6:
				con_modificarContrato(arrayContrataciones, 1000, contadorIdContratacion,arrayPantallas,contadorIdPantalla);
		}
	}while(opcionElegida!=11);
	return EXIT_SUCCESS;
}

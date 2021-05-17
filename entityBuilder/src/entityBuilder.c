/*
 ============================================================================
 Name        : entityBuilder.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Builder.h"
#include "menues.h"
#include "gets.h"
#define TAM_NOMBRE 50
#define TAM_PARAMETROS 100
int main(void)
{
	int opcionMenuPrincipal;
	char nombreEstructura[TAM_NOMBRE] = "";
	char detalleParametros[TAM_PARAMETROS] = "";
	do
	{
		opcionMenuPrincipal = 0;
		menu_imprimirMenuPrincipal(nombreEstructura,detalleParametros);
		get_int(&opcionMenuPrincipal, 2,"Opcion: ","Error. ",1,1,5,3,0);
		switch(opcionMenuPrincipal)
		{
		case 1:
			get_name(nombreEstructura, TAM_NOMBRE,"Ingrese el nombre de la entidad: ","Error. ",3);
			menu_mensajeContinuar();
			break;
		case 2:
			get_text(detalleParametros, TAM_PARAMETROS,"Ingrese los parámetros: ","Error. ",3);
			menu_mensajeContinuar();
			break;
		case 3:
			if(strcmp(nombreEstructura,"")!=0 && strcmp(detalleParametros,"")!=0)
			{
				builder_constructor(nombreEstructura,detalleParametros);
			}
			else
			{
				printf("Primero debe ingresar nombre de entidad y detalle de parámetros.");
			}
			menu_mensajeContinuar();
			break;
		case 4:
			menu_imprimirAyuda();
			break;
		}
	}while(opcionMenuPrincipal != 5);

	return EXIT_SUCCESS;
}

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
#define TAM_NOMBRE_ENTIDAD 50
#define TAM_PARAMETROS_ENTIDAD 100
int main(void)
{
	int opcionMenuPrincipal;
	char nombreEntidad[TAM_NOMBRE_ENTIDAD] = "Producto";
	char detalleParametros[TAM_PARAMETROS_ENTIDAD] = "char* nombre;char* descripcion;float precioUnitario;int idProducto;";
	do
	{
		opcionMenuPrincipal = 0;
		menu_imprimirMenuPrincipal(nombreEntidad,detalleParametros);
		get_int(&opcionMenuPrincipal, 2,"Ingrese una opcion: ","",1,1,5,0,0);
		switch(opcionMenuPrincipal)
		{
		case 1:
			get_name(nombreEntidad, TAM_NOMBRE_ENTIDAD,"\nIngrese el nombre de la entidad: ","Error.",3);
			menu_mensajeContinuar();
			break;
		case 2:
			get_text(detalleParametros, TAM_PARAMETROS_ENTIDAD,"\nIngrese los parámetros: ","Error.",3);
			menu_mensajeContinuar();
			break;
		case 3:
			if(strcmp(nombreEntidad,"")!=0 && strcmp(detalleParametros,"")!=0)
			{
				builder_constructor(nombreEntidad,detalleParametros);
			}
			else
			{
				printf("\nPrimero debe ingresar nombre de entidad y detalle de parámetros.\n");
			}
			menu_mensajeContinuar();
			break;
		case 4:
			menu_imprimirAyuda();
			break;
		}
	}while(opcionMenuPrincipal != 5);
	menu_imprimirMensajeDespedida();
	return EXIT_SUCCESS;
}

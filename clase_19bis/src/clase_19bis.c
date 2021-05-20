/*
 ============================================================================
 Name        : clase_19bis.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "producto.h"
#include "menues.h"
#include "gets.h"
#define QTY_PRODUCTOS 50

int main(void)
{
	Producto* listadoProductos[QTY_PRODUCTOS];
	producto_initArray(listadoProductos, QTY_PRODUCTOS);
	int opcionMenuPrincipal;
	do
	{
		opcionMenuPrincipal = 0;
		menu_imprimirMenuPrincipal();
		get_int(&opcionMenuPrincipal, 2, "Seleccione su opción: ","",1,1,7,0,0);
		switch(opcionMenuPrincipal)
		{
			case 1:
				producto_altaProducto(listadoProductos,QTY_PRODUCTOS);
				break;
			case 2:
				producto_bajaProducto(listadoProductos,QTY_PRODUCTOS);
				break;
			case 3:
				producto_modificarProducto(listadoProductos, QTY_PRODUCTOS);
				break;
			case 4:
				producto_cargarDatosDesdeArchivo(listadoProductos);
				break;
			case 5:
				producto_guardarEnArchivo(listadoProductos, QTY_PRODUCTOS);
				break;
			case 6:
				producto_imprimirListado(listadoProductos, QTY_PRODUCTOS);
				break;
		}
	}while(opcionMenuPrincipal != 7);
	menu_imprimirMensajeDespedida();
	return EXIT_SUCCESS;
}

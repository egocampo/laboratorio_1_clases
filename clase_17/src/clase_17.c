/*
 ============================================================================
 Name        : clase_17.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/*
Una empresa importadora que comercializa productos textiles, decide registrarlos de la siguiente manera:
·       idProducto (numérico)
·       descripción (alfanumérico)
·       nacionalidad (teniendo en cuenta que cada país tiene su propio Id y descripción con su nombre)
·       tipo (teniendo en cuenta de que este puede tener más características: Id, Marca, Fabrica y tipo de tela.)
·       precio por unidad (numérico decimal)
Realizar un programa que permita interactuar con un menú de usuarios con las
 siguientes opciones:
1. ALTA Producto: Se ingresan los datos de UN solo producto. Siempre y cuando
 haya espacio disponible en el array.
 2. BAJA Producto: A partir del ingreso del ID. Si existe el producto desaparece de
 la lista, dejando espacio disponible para un nuevo producto.
 3. MODIFICACIÓN Producto: A partir del ingreso del ID. Si existe se podrá
 modificar el precio o el tipo.
 4. LISTADO Productos.
 5. LISTADO ordenado por precio.
 6. LISTADO ordenado por descripción
*/

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"
#include "Nacionalidad.h"
#include "Tipo.h"
#include "menues.h"
#include "Builder.h"
#include "gets.h"
#include "validations.h"
#define QTY_PRODUCTOS 10


int main(void) {
	Producto* listadoProductos[10];
	producto_initArray(listadoProductos, 10);
//	for(int i=0;i<10;i++)
//		listadoProductos[i] = NULL;
	Producto* auxProducto;
	int opcionMenuPrincipal;
//	auxProducto = producto_newParam(110,"Caballo",3,3,3);
//	printf("Id Producto: %d\nDescripcion: %s",auxProducto->idProducto,
//			auxProducto->descripcion);
	do
	{
		opcionMenuPrincipal = 0;
		menu_imprimirMenuPrincipal();
		get_int(&opcionMenuPrincipal, 2,"Ingrese su opción: ","Error. ",1,1,5,3,0);
		switch(opcionMenuPrincipal)
		{
			case 1:
				auxProducto = producto_new();
				if(producto_pedirDatos(auxProducto))
				{
					listadoProductos[0] = auxProducto;
				}
				menu_mensajeContinuar();
				break;
			case 2:
				producto_delete(listadoProductos[0]);
				menu_mensajeContinuar();
				break;
			case 3:
				printf("%p",listadoProductos[2]);
				menu_mensajeContinuar();
				break;
			case 4:
				printf("%s",listadoProductos[0]->descripcion);
				menu_mensajeContinuar();
				break;
		}
	}while(opcionMenuPrincipal != 5);
	menu_imprimirMensajeDespedida();
	return EXIT_SUCCESS;
}

//	builder_constructor("Empleado");
//	builder_setter("Empleado","int","nombre");


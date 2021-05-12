/*
 * Producto.c
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include "Producto.h"


Producto* producto_new(void)
{
	return malloc(sizeof(Producto));
}

//int idProducto;
//char descripcion[50];
//int idNacionalidad;
//int idTipo;
//float precioUnitario;

Producto* producto_newParam(int idProducto,char* descripcion,int idNacionalidad,int idTipo,float precioUnitario)
{
	int auxProducto = producto_new();
	if(auxProducto != NULL)
	{
		if(producto_setIdProducto(this, idProducto) < 0 || producto_setDescripcion(this, descripcion) < 0)
		{
			producto_delete(auxProducto);
		}
	}
	return auxProducto;
}

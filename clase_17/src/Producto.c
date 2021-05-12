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
	Producto* auxProducto = producto_new();
	if(auxProducto != NULL)
	{
		//if(producto_setIdProducto(auxProducto, idProducto) < 0 || producto_setDescripcion(auxProducto, descripcion) < 0)
		{
			producto_delete(auxProducto);
			auxProducto = NULL;
		}
	}
	return auxProducto;
}

int producto_delete(Producto* this)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this);
		retorno = 0;
	}
	return retorno;
}





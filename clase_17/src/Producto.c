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

Producto* producto_newParam(Producto* this,int idProducto,char* descripcion,int idNacionalidad,int idTipo,float precioUnitario)
{
	int auxProducto = producto_new();
}

Producto* producto_delete(Producto* this);

int producto_setIdProducto(Producto* this,int idProducto);
int producto_getIdProducto(Producto* this,int* flagError);

int producto_setDescripcion(Producto* this,int descripcion);
char* producto_getDescripcion(Producto* this,int* flagError);

int producto_setIdNacionalidad(Producto* this,int idNacionalidad);
int producto_getIdNacionalidad(Producto* this,int* flagError);

int producto_setIdTipo(Producto* this,int idTipo);
int producto_getIdTipo(Producto* this,int* flagError);

int producto_setPrecioUnitario(Producto* this,int precioUnitario);
int producto_getPrecioUnitario(Producto* this,int* flagError);

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
		if(producto_setIdProducto(auxProducto, idProducto) < 0)
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

int producto_setIdProducto(Producto* this,int idProducto)
{
	int retorno = -1;
	if(this != NULL && producto_isValidId(idProducto))
	{
		this->idProducto = idProducto;
		retorno = 0;
	}
	return retorno;
}

int producto_isValidId(int idProducto)
{
	return 1;
}

int producto_getIdProducto(Producto* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL )
	{
		auxId = this->idProducto;
		*flagError = 0;
	}
	return auxId;
}

//int producto_setDescripcion(Producto* this,int descripcion);
//char* producto_getDescripcion(Producto* this,int* flagError);
//int producto_setIdNacionalidad(Producto* this,int idNacionalidad);
//int producto_getIdNacionalidad(Producto* this,int* flagError);
//int producto_setIdTipo(Producto* this,int idTipo);
//int producto_getIdTipo(Producto* this,int* flagError);
//int producto_setPrecioUnitario(Producto* this,int precioUnitario);
//int producto_getPrecioUnitario(Producto* this,int* flagError);
//
//

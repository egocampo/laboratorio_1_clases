/*
 * Producto.c
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#include "Nacionalidad.h"
#include "Tipo.h"
#include "gets.h"
#include "validations.h"

int producto_initArray(Producto* listadoProductos[],int len)
{
	int returnFunction = -1;
	int i;
	if(listadoProductos != NULL && len > 0)
	{
		returnFunction = 0;
		for(i=0;i<len;i++)
		{
			listadoProductos[i] = NULL;
		}
	}
	return returnFunction;
}

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
		if(producto_setIdProducto(auxProducto, idProducto) < 0 || producto_setDescripcion(auxProducto, descripcion) < 0)
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

int producto_getIdProducto(Producto* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL)
	{
		auxId = this->idProducto;
		*flagError = 0;
	}
	return auxId;
}

int producto_isValidId(int idProducto)
{
	return 1;
}

int producto_setDescripcion(Producto* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && producto_isValidDescripcion(descripcion))
	{
		strcpy(this->descripcion,descripcion);
		retorno = 0;
	}
	return retorno;
}

char* producto_getDescripcion(Producto* this,int* flagError)
{
	*flagError = -1;
	char* auxDescripcion = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxDescripcion = this->descripcion;
		*flagError = 0;
	}
	return auxDescripcion;
}

int producto_isValidDescripcion(char* descripcion)
{
	return 1;
}

int producto_pedirDatos(Producto* this)
{
	int returnFuncion = -1;
	Producto bufferProducto;
	if(this != NULL)
	{
		returnFuncion = 0;
		if(get_text(bufferProducto.descripcion,50,"Ingrese descripción: ","Error. ",3))
		{
			producto_setDescripcion(this,bufferProducto.descripcion);
			returnFuncion = 1;
		}
	}
	return returnFuncion;
}

//int producto_setIdNacionalidad(Producto* this,int idNacionalidad);
//int producto_getIdNacionalidad(Producto* this,int* flagError);
//int producto_setIdTipo(Producto* this,int idTipo);
//int producto_getIdTipo(Producto* this,int* flagError);
//int producto_setPrecioUnitario(Producto* this,int precioUnitario);
//int producto_getPrecioUnitario(Producto* this,int* flagError);
//
//

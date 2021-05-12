/*
 * Producto.h
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

/*
Una empresa importadora que comercializa productos textiles, decide registrarlos de la siguiente manera:
·       idProducto (numérico)
·       descripción (alfanumérico)
·       nacionalidad (teniendo en cuenta que cada país tiene su propio Id y descripción con su nombre)
·       tipo (teniendo en cuenta de que este puede tener más características: Id, Marca, Fabrica y tipo de tela.)
·       precio por unidad (numérico decimal)
*/

typedef struct
{
	int idProducto;
	char descripcion[50];
	int idNacionalidad;
	int idTipo;
	float precioUnitario;
}Producto;

typedef struct
{
	int idNacionalidad;
	char descripcion[50];
}Nacionalidad;

typedef struct
{
	int idTipo;
	char marca[50];
	char fabrica[50];
	char tipoTela[50];
}Tipo;

Producto* producto_new(void);
Producto* producto_newParam(Producto* this,int idProducto,char* descripcion,int idNacionalidad,int idTipo,float precioUnitario);
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

int nacionalidad_setIdNacionalidad(Nacionalidad* this,int idNacionalidad);
int nacionalidad_getIdNacionalidad(Nacionalidad* this,int* flagError);
int nacionalidad_setDescripcion(Nacionalidad* this,int descripcion);
char* nacionalidad_getDescripcion(Nacionalidad* this,int* flagError);

int tipo_setIdTipo(Tipo* this,int idTipo);
int tipo_getIdTipo(Tipo* this,int* flagError);
int tipo_setMarca(Tipo* this,int marca);
char* tipo_getMarca(Tipo* this,int* flagError);
int tipo_setFabrica(Tipo* this,int fabrica);
char* tipo_getFabrica(Tipo* this,int* flagError);
int tipo_setTipoTela(Tipo* this,int tipoTela);
char* tipo_getTipoTela(Tipo* this,int* flagError);

#endif /* PRODUCTO_H_ */

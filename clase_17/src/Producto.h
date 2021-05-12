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





Producto* producto_new(void);
Producto* producto_newParam(int idProducto,char* descripcion,int idNacionalidad,int idTipo,float precioUnitario);
int producto_delete(Producto* this);

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



#endif /* PRODUCTO_H_ */

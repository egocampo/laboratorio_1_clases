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

#endif /* PRODUCTO_H_ */

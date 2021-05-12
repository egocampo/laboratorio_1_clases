/*
 * producto.h
 *
 *  Created on: 16 abr. 2021
 *      Author: gabriel
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

typedef struct
{
	char nombre[32];
	char descripcion[128];
	float precio;
	int flagIsEmpty;
}Producto;

void prod_inicializarArray(Producto* pArrayParaInicializar,int limite);
int prod_altaProducto(Producto* pArrayParaInicializar,int limite,int indice);
int prod_printProducto(Producto* pArrayParaImprimir,int limite,int indice);
int prod_buscarIndiceVacio(Producto* pArrayDondeBuscar,int limite);

#endif /* PRODUCTO_H_ */

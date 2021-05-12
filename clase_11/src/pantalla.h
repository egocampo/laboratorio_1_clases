/*
 * estructuraBase.h
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

typedef struct
{
	int idPantalla;
	int flagIsEmpty;
	char direccion[50];
	int tipoPantalla;
	char nombrePantalla[50];
	int precioDiario;
}Pantalla;

int pan_initArray(Pantalla* arrayEstructuraBase, int len);
int pan_getIndexById(Pantalla* array, int len, int id);
int pan_printEsctructuraBase(Pantalla* arrayEstructuraBase, int len, char* mensaje);
int pan_searchIndexEmpty(Pantalla* arrayEstructuraBase, int len);
int pan_ordenamientoInsersionEstructuraBasePorId(Pantalla* arrayEstructuraBase, int len);
int pan_altaPantalla(Pantalla* arrayPantalla, int len, int* contadorIdPantalla);
int pan_modificarPantalla(Pantalla* arrayPantalla, int len, int contadorPantallas);
int pan_bajaPantalla(Pantalla* arrayPantalla, int contadorPantallas);
int pan_printPantallaPorIndice(Pantalla* arrayEstructuraBase, char* mensaje,int indice);

#endif /* PANTALLA_H_ */

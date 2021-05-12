/*
 * estructuraBase.h
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */

#ifndef CONTRATACION_H_
#define CONTRATACION_H_
#include "pantalla.h"

typedef struct
{
	int idContratacion;
	int flagIsEmpty;
	int cantidadDias;
	char nombreArchivo[50];
	int idPantalla;
	char cuitCliente[12];
}Contratacion;

int con_initArray(Contratacion* arrayEstructuraBase, int len);
int con_getIndexById(Contratacion* array, int len, int id);
int con_printEsctructuraBase(Contratacion* arrayEstructuraBase, int len, char* mensaje);
int con_searchIndexEmpty(Contratacion* arrayEstructuraBase, int len);
int con_ordenamientoInsersionEstructuraBasePorId(Contratacion* arrayEstructuraBase, int len);
int con_altaContrato(Contratacion* arrayContratacion, int len, int* contadorIdContratacion, Pantalla* arrayPantalla,int* contadorIdPantalla);
int con_modificarContrato(Contratacion* arrayContrataciones, int len, int contadorContrataciones,Pantalla* arrayPantalla,int idContadorPantalla);


#endif /* CONTRATACION_H_ */

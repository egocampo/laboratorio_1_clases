/*
 * estructuraBase.h
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */

#ifndef ESTRUCTURABASE_H_
#define ESTRUCTURABASE_H_

typedef struct
{
	int idEstructura;
	int flagIsEmpty;
}estructuraBase;

int initArray(estructuraBase* arrayEstructura, int len);
int getIndexById(estructuraBase* array, int len, int id);
int printEsctructura(estructuraBase* arrayEstructura, int len, char* mensaje);
int searchIndexEmpty(estructuraBase* arrayEstructura, int len);
int ordenamientoInsersionEstructuraPorId(estructuraBase* arrayEstructura, int len);


#endif /* ESTRUCTURABASE_H_ */

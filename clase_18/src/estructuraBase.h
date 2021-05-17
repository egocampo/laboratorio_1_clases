/*
 * estructuraBase.h
 *
 *  Created on: 14 may. 2021
 *      Author: gabriel
 */

#ifndef ESTRUCTURABASE_H_
#define ESTRUCTURABASE_H_

typedef struct
{
	int id;
	char nombre[50];
	float numero;
}Estructura;

Estructura* estructura_new(void);
Estructura* estructura_newParam(char* nombre,int idEmpleado);
int estructura_delete(Estructura* this);

int estructura_setNombre(Estructura* this, char* nombre);
char* estructura_getNombre(Estructura* this,int* flagError);
int estructura_setId(Estructura* this, int idEstructura);
int estructura_getId(Estructura* this,int* flagError);

int estructura_initArray(Estructura* list[],int len); //int estructura_initArray(Estructura** list);
int estructura_buscarIniceVacio(Estructura* list[],int len);
int estructura_generarId(void);
int estructura_alta(Estructura* list[],int len);
int estructura_imprimirLista(Estructura* list[],int len);


#endif /* ESTRUCTURABASE_H_ */

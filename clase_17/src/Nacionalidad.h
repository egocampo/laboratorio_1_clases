/*
 * Nacionalidad.h
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

typedef struct
{
	int idNacionalidad;
	char descripcion[50];
}Nacionalidad;

int nacionalidad_setIdNacionalidad(Nacionalidad* this,int idNacionalidad);
int nacionalidad_getIdNacionalidad(Nacionalidad* this,int* flagError);
int nacionalidad_setDescripcion(Nacionalidad* this,int descripcion);
char* nacionalidad_getDescripcion(Nacionalidad* this,int* flagError);

/*
 * Tipo.h
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

#ifndef TIPO_H_
#define TIPO_H_

typedef struct
{
	int idTipo;
	char marca[50];
	char fabrica[50];
	char tipoTela[50];
}Tipo;

int tipo_setIdTipo(Tipo* this,int idTipo);
int tipo_getIdTipo(Tipo* this,int* flagError);
int tipo_setMarca(Tipo* this,int marca);
char* tipo_getMarca(Tipo* this,int* flagError);
int tipo_setFabrica(Tipo* this,int fabrica);
char* tipo_getFabrica(Tipo* this,int* flagError);
int tipo_setTipoTela(Tipo* this,int tipoTela);
char* tipo_getTipoTela(Tipo* this,int* flagError);

#endif /* TIPO_H_ */

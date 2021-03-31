/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#ifndef UTN_H_
#define UTN_H_

#define UTN_MIN_EDAD 0
#define UTN_MAX_EDAD 99
#define UTN_REINTENTOS 3
#define UTN_OPCION_SI 's'
#define UTN_OPCION_NO 'n'

int utn_getInteger(int* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos, int minimo, int maximo);
int utn_getFloat(float* pNumeroSolicitado,char* pTexto,char* pTextoError,int reintentos, int minimo, int maximo);
int utn_getChar(char* pCaracterSolicitado,char* pTexto,char* pTextoError,int reintentos, char opcionUno, char opcionDos);


#endif /* UTN_H_ */

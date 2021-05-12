/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#ifndef UTN_H_
#define UTN_H_

int utn_myGets(char* pResultado, int len);
int utn_getString(char* pResultado,int len);
int utn_isValidName(char* nombre);
int utn_getName(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int utn_getDni(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);

int utn_getCuit(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int utn_isValidCuit(char* dni);
int utn_cuitDigitoVerificador(char* cuit);

int utn_isValidNumberInt(char* numero, int flagSigned);
int utn_isValidNumberFloat(char* numero, int flagSigned);

int utn_getNumberFloat(float* pResultado,int len,char* mensaje,char* mensajeError,int reintentos,int flagSigned);
int utn_getNumberInt(int* pResultado,int len,char* mensaje,char* mensajeError,int reintentos,int flagSigned);

#endif /* UTN_H_ */

/*
 * gets.h
 *
 *  Created on: 18 abr. 2021
 *      Author: gabriel
 */

#ifndef GETS_H_
#define GETS_H_

int get_myGets(char* pResultado, int len);

int get_int(int* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);
int get_float(float* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);
int get_name(char* pResultado,int len,char* mensaje,char* mensajeError,int reintentos);
int get_text(char* pResultado,int len,char* mensaje,char* mensajeError, int reintentos);
int get_dni(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_cuit(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_email(char* pResultado,char* mensaje,char* mensajeError,int reintentos);
int get_char(char* caracter,char* listaBlanca,int len, char* mensaje, char* mensajeError, int reintentos);
int get_intAsChar(char* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);
int get_floatAsChar(char* pResultado,int len,char* mensaje,char* mensajeError,int flagMaximoMinimo, int minimo, int maximo, int reintentos,int flagSigned);


//int get_char(char* caracter,char* listaBlanca,int lenListaBlanca);


#endif /* GETS_H_ */

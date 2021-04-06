/*
 * array.h
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */

#ifndef ARRAY_H_
#define ARRAY_H_

int arr_getIntegers(int* array,int limite, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo);
int arr_getIntegersWithoutMinimumOrMaximum(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos);
int arr_getFloat(float* pArray,int len, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo);
int arr_buscarMaximoInt(int* array,int limite, int* resultado);
int arr_buscarMinimoInt(int* pArray,int len, int* pResultado);
int arr_calcularPromedioInt(int* array,int limite, float* resultado);
int arr_acumularInt(int* array,int limite, int* resultado);
int arr_buscarInt(int* array,int limite,int numeroBuscado);
int arr_burbujeoBasico(int* array,int limite,int* arrayOrdenado);
int arr_burbujeoEficiente(int* array,int len);
int arr_ordenamientoInsersion(int* array,int len);
int arr_imprimirArrayInt(int* pArray,int len);
int arr_calcularPromedioFloat(float* pArray,int len, float* pResultado);
int arr_acumularFloat(float* pArray,int len, float* pResultado);
int arr_getFloatWithPositions(float* pArray,char* pTexto, int len);
int arr_searchPositionOfMinimum(int* pArray,int len, int inicio,int* pPosicionRetorno);
int arr_searchPositionOfMaximum(float* pArray,int len);
int arr_intercambiarPosicion(int* pArray, int i, int j);

#endif /* ARRAY_H_ */

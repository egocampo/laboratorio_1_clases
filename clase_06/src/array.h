/*
 * array.h
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */

#ifndef ARRAY_H_
#define ARRAY_H_

//-------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////
/////       * ARRAYS DE ENTEROS *        /////
//////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------
// INGRESO DE DATOS
int arr_getIntSimple(int* pArray,int len, char* pTexto,char* pTextoError, int reintentos);
int arr_getIntWithMinMax(int* array,int limite, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo);
int arr_getIntShowingPosition(int* pArray, int len,char* pText);
//-------------------------------------------------------------------------------------------------------
// ORDENAMIENTO
int arr_efficientBubbleInt(int* pArray, int limite, int flagDecreasing);
//-------------------------------------------------------------------------------------------------------
// BUSQUEDA
int arr_searchMaximumValueInt(int* pArray,int len, int* pResultado);
int arr_searchMinimumValueInt(int* pArray,int len, int* pResultado);
int arr_searchValueInt(int* array,int limite,int numeroBuscado);
int arr_searchPositionOfMinimumInt(int* pArray,int len, int initial,int* pPosicionRetorno);
//-------------------------------------------------------------------------------------------------------
// OPERACIONES VARIAS
int arr_swapInt(int* pArray, int i, int j);
int arr_printfArrayInt(int* pArray,int len);
int arr_initializeArrayInt(int* pArray, int len, int value);
//-------------------------------------------------------------------------------------------------------
// MATEMATICAS
// ARRAYS DE ENTEROS
int arr_accumulateInt(int* array,int limite, int* resultado);
int arr_calculateAverageInt(int* array,int limite, float* resultado);

//-------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////
/////      * ARRAYS DE FLOTANTES *       /////
//////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------
// INGRESO DE DATOS

//-------------------------------------------------------------------------------------------------------
// ORDENAMIENTO

//-------------------------------------------------------------------------------------------------------
// BUSQUEDA

//-------------------------------------------------------------------------------------------------------
// OPERACIONES VARIAS

//-------------------------------------------------------------------------------------------------------
// MATEMATICAS

//-------------------------------------------------------------------------------------------------------
//////////////////////////////////////////////
/////            SIN ORDENAR            //////
//////////////////////////////////////////////
//-------------------------------------------------------------------------------------------------------
int arr_burbujeoBasico(int* array,int limite,int* arrayOrdenado);
int arr_burbujeoEficiente(int* array,int len);
int arr_ordenamientoInsersion(int* array,int len);
int arr_sortLudmila(int* pArray, int len);
//-------------------------------------------------------------------------------------------------------

#endif /* ARRAY_H_ */

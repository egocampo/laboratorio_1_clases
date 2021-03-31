/*
 * array.h
 *
 *  Created on: 30 mar. 2021
 *      Author: gabriel
 */

#ifndef ARRAY_H_
#define ARRAY_H_

void arr_getIntegers(int* array,int limite, char* pTexto,char* pTextoError, int reintentos, int minimo, int maximo);
int arr_calcularMaximoInt(int* array,int limite, int* resultado);
int arr_calcularMinimoInt(int* array,int limite, int* resultado);
int arr_calcularPromedioInt(int* array,int limite, float* resultado);
int arr_calcularSumaInt(int* array,int limite, int* resultado);
int arr_buscarNumeroInt(int* array,int limite,int numeroBuscado);
void arr_burbujeo(int* array,int limite,int* arrayOrdenado);

#endif /* ARRAY_H_ */

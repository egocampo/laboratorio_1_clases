/*
 * sRazas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: gabriel
 */

#ifndef SRAZAS_H_
#define SRAZAS_H_

typedef struct
{
	int idRazas;
	char descripcion[20];
	char tamanio[10];
	char paisOrigen[10];
	int flagIsEmpty;
}Razas;

void hardcodearEstructuraRaza(Razas* arrayRazas,int posicion,char* descripcion, char* tamanio, char* paisOrigen);
//void imprimirRaza(Razas* arrayParaImprimir,int posicion);
void inicializarArrayRazas(Razas* pArrayParaInicializar,int limite);



#endif /* SRAZAS_H_ */

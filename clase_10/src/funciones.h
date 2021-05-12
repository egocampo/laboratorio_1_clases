/*
 * funciones.h
 *
 *  Created on: 20 abr. 2021
 *      Author: gabriel
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

void imprimirMascota(Mascota* arrayMascotas,int posicion,Razas* arrayRazas);
void hardcodeoEstructuras(Mascota* arrayMascotas, Razas* arrayRazas,int*);
int buscarIndiceVacio(Mascota* arrayMascotas, int len);
void alta_mascota(Mascota* arrayMascotas, int len,Razas* arrayRazas);



#endif /* FUNCIONES_H_ */

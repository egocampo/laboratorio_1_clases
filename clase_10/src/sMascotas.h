/*
 * sMascotas.h
 *
 *  Created on: 20 abr. 2021
 *      Author: gabriel
 */
#ifndef SMASCOTAS_H_
#define SMASCOTAS_H_

typedef struct
{
	int idMascota;
	char nombre[20];
	int edad;
	char sexo;
	char tipo[10];
	int raza;
	int flagIsEmpty;
}Mascota;

void hardcodearEstructuraMascota(Mascota* arrayMascotas,int posicion,char* nombre, int edad, char sexo, char* tipo,int raza, int* contadorIdMascotas);
void inicializarArrayMascota(Mascota* pArrayParaInicializar,int limite);


#endif /* SMASCOTAS_H_ */

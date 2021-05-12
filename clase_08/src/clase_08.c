/*
 ============================================================================
 Name        : clase_08.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Estructuras
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>
#include "utn.h"

int main(void)
{
	char a[10]="444";
	printf("%d",utn_isValidNumberFloat(a));


	//char nombre[80];
//	int dni;
//	if(utn_getDni(&dni, 20,"dni: " ,"error. ",3)==1)
//	{
//		printf("%d",dni);
//	}
	return EXIT_SUCCESS;
}

//	Persona arrayEmpleados[QTY_EMPLEADOS];
//	per_alta(arrayEmpleados,QTY_EMPLEADOS,0,"Gabriel","Ocampo",1.65,60);
//	printf("Nombre: %s\n",arrayEmpleados[0].nombre);
//	printf("Apellido: %s\n",arrayEmpleados[0].apellido);
//	printf("Peso: %.2f\n",arrayEmpleados[0].peso);
//	printf("Altura: %.2f\n",arrayEmpleados[0].medida);

//
//
//char nombres[80][QTY_PERSONAS]={"Mario","Gabriel","Lucas","Gisela","Victoria"};
//float medida[QTY_PERSONAS];
//float peso[QTY_PERSONAS];
//int posicionMedidaMaxima;
//int posicionPesoMaximo;
//
//arr_getFloatWithMinMax(medida,QTY_PERSONAS, "Ingrese medida (en metros): ","Error. ",0,3,3);
//arr_getFloatWithMinMax(peso,QTY_PERSONAS,"Ingrese peso (en kilos): ","Error. ",0,300,3);
//arr_searchPositionOfMaximumFloat(medida, QTY_PERSONAS,0, &posicionMedidaMaxima);
//arr_searchPositionOfMaximumFloat(medida, QTY_PERSONAS,0, &posicionPesoMaximo);
//
//printf("La medida maxima corresponde a: %s es: %.2f Mts y su peso es: %.2f Kgs\n", nombres[0,posicionMedidaMaxima],medida[posicionMedidaMaxima],peso[posicionMedidaMaxima]);
//printf("El peso máximo corresponde a: %s es: %.2f Mts y su peso es: %.2f Kgs\n", nombres[0,posicionPesoMaximo],peso[posicionPesoMaximo],medida[posicionPesoMaximo]);

//printf("Nombre: %s\n",arrayPersona[0].nombre);
//printf("Peso: %.2f\n",arrayPersona[0].peso);
//printf("Altura: %.2f\n",arrayPersona[0].medida);


//	arrayPersona[0].medida = 1.78;
//	arrayPersona[0].peso = 60.5;
//	strncpy(arrayPersona[0].nombre,"Juan",QTY_PERSONAS);

//int i;
//char nombre[80];
//Persona arrayPersona[QTY_PERSONAS];
////int posicionMedidaMaxima;
//for(i=0;i<QTY_PERSONAS;i++)
//{
////		utn_getNumberFloat(&arrayPersona[i].medida,"Medida: ","Error. ",0,4,3);
////		utn_getNumberFloat(&arrayPersona[i].peso,"Peso: ","Error. ",0,300,3);
//	utn_getText(nombre,50,"Nombre: ");
//	strncpy(arrayPersona[i].nombre,nombre,50);
//	printf("%s\n",arrayPersona[i].nombre);
//}
////	buscarMayorMedida(arrayPersona, &posicionMedidaMaxima);
////	printf("Mayor medida: %.2f mts, pesa: %.2f kgs",arrayPersona[posicionMedidaMaxima].medida,arrayPersona[posicionMedidaMaxima].peso);
//
//void buscarMayorMedida(Persona* pArray,int* pPosicionRetorno)
//{
//	int i;
//	int maximumPosition;
//	float maximum=pArray[0].medida;
//	for(i=1;i<QTY_PERSONAS;i++)
//	{
//		if(pArray[i].medida > maximum)
//		{
//			maximum = pArray[i].medida;
//			maximumPosition = i;
//		}
//	}
//	*pPosicionRetorno = maximumPosition;
//}


/*
 * estructuraBase.c
 *
 *  Created on: 22 abr. 2021
 *      Author: gabriel
 */
#include <stdio.h>
#include <stdlib.h>
#include "contratacion.h"
#include "pantalla.h"
#include "gets.h"
#include "string.h"

///*
// * \brief Obtiene el indice de un elemento de un array de estructura a traves del campo id.
// * \param estructura* arrayEstructura Array de estructura donde buscar el id y devolver el indice
// * \param int len Tamaño del arrayEstructura
// * \param int id Identificador a buscar
// * \return -2 error de validación, -1 no encontró el elemento, mayor a 0 devuelve el indice.
// * */
//int con_getIndexById(Contratacion* arrayEstructuraBase, int len, int id)
//{
//	int returnFunction = -2;
//	int i;
//	if(arrayEstructuraBase != NULL && len > 0 && id > 0)
//	{
//		returnFunction = -1;
//		for(i=0;i<len;i++)
//		{
//			if(arrayEstructuraBase[i].idEstructuraBase==id)
//			{
//				returnFunction=i;
//			}
//		}
//	}
//	return returnFunction;
//}

/*
 * \brief Imprime todos los elementos de una estructura
 * \param estructura* arrayEstructuraBase Array de estructura que imprimir
 * \param int len Tamaño del arrayEstructuraBase
 * \char* mensaje Texto a imprimir previo al listado
 * \return -1 error de validacion, 0 si imprime ok
 */
int con_printEsctructuraBase(Contratacion* arrayEstructuraBase, int len, char* mensaje)
{
	int returnFunction = -1;
	int i;
	if(arrayEstructuraBase != NULL && len > 0)
	{
		returnFunction = 0;
		printf("%s\n",mensaje);
		for(i=0;i<len;i++)
		{
			printf("Id: %d\n",arrayEstructuraBase[i].idContratacion); // imprimir cada campo de la estructura
//			printf("\n");
//			printf("\n");
		}
	}
	return returnFunction;
}

/*
 * \brief Inicializa un arrayEstructuraBase asigando el valor 1 al campo flagIsEmpty
 * \param estructura* arrayEstructuraBase Array de estructura que inicializar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -1 error de validacion, 0 si no hubo errores
 * */
int con_initArray(Contratacion* arrayEstructuraBase, int len)
{
	int returnFunction = -1;
	int i;
	if(arrayEstructuraBase != NULL && len)
	{
		returnFunction = 0;
		for(i=0;i<len;i++)
		{
			arrayEstructuraBase[i].flagIsEmpty = 1;
		}
	}
	return returnFunction;
}

/*
 * \brief Busca dentro de un arrayEstructuraBase el primer indice cuyo campo isEmpty sea verdadero
 * \param estructura* arrayEstructuraBase Array de estructura donde buscar
 * \param int len Tamaño del arrayEstructuraBase
 * \return -2 error de validacion, -1 no hay ningun espacio vacio, 0 o mayor es la posicion libre
 * */
int con_searchIndexEmpty(Contratacion* arrayEstructuraBase, int len)
{
	int returnFunction = -2;
	int i;
	if(arrayEstructuraBase != NULL && len > 0)
	{
		returnFunction = -1;
		for(i=0;i<len;i++)
		{
			if(arrayEstructuraBase[i].flagIsEmpty == 1)
			{
				returnFunction = i;
				break;
			}
		}
	}
	return returnFunction;
}

///*
// * \brief Ordenamiento de array por método de insersión
// * \param pArray puntero a la dirección de memoria del array
// * \param len tamaño del array
// * \return 0 sin errores, -1 error de validación de datos.
// * */
//int con_ordenamientoInsersionEstructuraBasePorId(Contratacion* arrayEstructuraBase, int len)
//{
//	int retorno = -1;
//	if(arrayEstructuraBase != NULL && len > 0)
//	{
//		retorno = 0;
//		int i, j;
//		Contratacion temp;
//		for(i=1;i<len;i++)
//		{
//			temp=arrayEstructuraBase[i];
//			j=i-1;
//			while(j>=0 && temp.idEstructuraBase < arrayEstructuraBase[j].idEstructuraBase)
//			{
//				arrayEstructuraBase[j+1].idEstructuraBase = arrayEstructuraBase[j].idEstructuraBase;
//				j--;
//			}
//			arrayEstructuraBase[j+1] = temp;
//		}
//	}
//	return retorno;
//}

int con_altaContrato(Contratacion* arrayContratacion, int len, int* contadorIdContratacion, Pantalla* arrayPantalla,int* contadorIdPantalla)
{
	int returnFunction = -1;
	Contratacion buffer;
	int indice = con_searchIndexEmpty(arrayContratacion, 100);
	int pantallaSeleccionada;
	if(1)
	{
		pan_printEsctructuraBase(arrayPantalla, 5,"Pantallas \n");
		if(get_int(&pantallaSeleccionada, 4,"Seleccione una pantalla: ","Error. ",1,1,*contadorIdPantalla,3,0)==1)
		{
			if(pan_getIndexById(arrayPantalla,100,pantallaSeleccionada) >=0 && arrayPantalla[pan_getIndexById(arrayPantalla,100,pantallaSeleccionada)].flagIsEmpty == 0)
			{
				if(arrayPantalla[pan_getIndexById(arrayPantalla,100,pantallaSeleccionada)].flagIsEmpty==0)
				{
					returnFunction = 0;
					if(indice >= 0 && indice < len)
					{
						buffer.idContratacion = *contadorIdContratacion;
						if(get_cuit(buffer.cuitCliente,"Cuit: " ,"Error. ",3)==1)
							if(get_int(&buffer.cantidadDias,4,"Cant. de dias: ","Error. ",1,1,999,3,0)==1)
								if(get_text(buffer.nombreArchivo,50,"Nombre del archivo: ","Error. ",3)==1)
									{
										buffer.flagIsEmpty = 0;
										arrayContratacion[indice] = buffer;
										*contadorIdContratacion = *contadorIdContratacion + 1;
									}
					}
				}
				else
				{
					printf("Pantalla no disponible.");
					getchar();
				}
			}
			else
			{
				printf("Pantalla no disponible.");
				getchar();
			}
		}
	}
	return returnFunction;
}

int con_modificarContrato(Contratacion* arrayContrataciones, int len, int contadorContrataciones,Pantalla* arrayPantalla,int idContadorPantalla)
{
	int returnFunction = -1;
	char cuitCliente[12];
	//int opcionElegida;
	//Pantalla buffer;
	if(arrayContrataciones != NULL && len > 0 && contadorContrataciones >= 0)
	{
		get_cuit(cuitCliente, "Ingrese el cuit del cliente: ","Error. ",3);
		returnFunction = 0;
		for(int i=0;i<len;i++)
		{
			if(strcmp(arrayContrataciones[i].cuitCliente,cuitCliente)==0)
			{
				pan_printPantallaPorIndice(arrayPantalla, "Lista de pantallas\n",i);
				printf("\nPresione una tecla para continuar...");
				getchar();
			}
		}
	}
	return returnFunction;
}

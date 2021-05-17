/*
 * estructuraBase.c
 *
 *  Created on: 14 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuraBase.h"

//Estructura* estructura_new(void)
//{
//	return (Estructura*) malloc(sizeof(Estructura));
//}
//
//Estructura* estructura_newParam(char* nombre,int idEmpleado)
//{
//	Estructura* auxEstructura = estructura_new();
//	if(auxEstructura != NULL)
//	{
//		if  ( 	estructura_setNombre(auxEstructura,nombre) < 0 ||
//				estructura_setId(auxEstructura,idEmpleado) < 0 )
//		{
//			estructura_delete(auxEstructura);
//			auxEstructura = NULL;
//		}
//	}
//	return auxEstructura;
//}
//
//int estructura_delete(Estructura* this)
//{
//	int retorno = -1;
//	if(this != NULL)
//	{
//		free(this);
//		retorno = 0;
//	}
//	return retorno;
//}
//
//int estructura_setNombre(Estructura* this, char* nombre)
//{
//	int retorno = -1;
//	if(this != NULL && nombre != NULL && isValidNombre(nombre))
//	{
//		strcpy(this->nombre,nombre);
//		retorno = 0;
//	}
//	return retorno;
//}

char* estructura_getNombre(Estructura* this,int* flagError)
{
	*flagError = -1;
	char* auxNombre = NULL;
	if(this != NULL && flagError != NULL )
	{
		auxNombre = this->nombre;
		*flagError = 0;
	}
	return auxNombre;
}
//
//int isValidNombre(char* nombre)
//{
//	return 1;
//}

//int estructura_setId(Estructura* this, int idEstructura)
//{
//	int retorno = -1;
//	if(this != NULL && isValidId(idEstructura))
//	{
//		this->id = idEstructura;
//		retorno = 0;
//	}
//	return retorno;
//}

int estructura_getId(Estructura* this,int* flagError)
{
	*flagError = -1;
	int auxId = -1;
	if(this != NULL && flagError != NULL )
	{
		auxId=this->id;
		*flagError = 0;
	}
	return auxId;
}

int isValidId(int idEmpleado)
{
	return 1;
}

//************************************************************************

//int estructura_initArray(Estructura* list[],int len) //int emp_initArray(Empleado** empleados)
//{
//	int i;
//	for(i=0; i<len; i++)
//	{
//		list[i] = NULL; // 0
//	}
//	return 0;
//}

//int estructura_buscarIniceVacio(Estructura* list[],int len)
//{
//	int ret=-1;
//	int i;
//	for(i=0; i<len; i++)
//	{
//		if(list[i]==NULL)
//		{
//			ret =  i;
//			break;
//		}
//	}
//	return ret;
//}

//int estructura_generarId(void)
//{
//	static int contador = 0; // NO ES LOCAL DE LA FUNCION
//	contador++;
//	return contador;
//}

//int estructura_alta(Estructura* list[],int len)
//{
//	char nombreAux[50];
//	char apellidoAux[50];
//	char dniAux[20];
//	int indiceLibre;
//	int idEmpleado;
//	Estructura* pEstructura;
//	int ret=-1;
//	indiceLibre = estructura_buscarIniceVacio(list,len);
//	if(indiceLibre>=0)
//	{
//		if(utn_getString("Nombre:","nahhh",nombreAux,50,2)==0)
//		{
//			if(utn_getString("Apellido:","nahhh",apellidoAux,50,2)==0)
//			{
//				if(utn_getStringWithOnlyNumbers("DNI:","nahhh",dniAux,20,2)==0)
//				{
//					// genero el ID
//					idEmpleado = estructura_generarId();
//					// construyo espacio de memoria
//					pEstructura = estructura_newParam(nombreAux,idEmpleado);
//					if(pEstructura!=NULL)
//					{
//						// lo cargo en el array
//						list[indiceLibre] = pEstructura;
//						ret=0;
//					}
//				}
//			}
//		}
//	}
//	else
//	{
//		printf("No hay ma' lugarrr\n");
//	}
//	return ret;
//}

int estructura_imprimirLista(Estructura* list[],int len)
{
	int ret=-1;
	int i;
	int flagError;
	char* pNombre;
	int id;
	for(i=0;i<len;i++)
	{
		if(list[i]!=NULL)
		{
			// lo imprimo
			pNombre = estructura_getNombre(list[i],&flagError);
			id = estructura_getId(list[i],&flagError);
			printf("Nombre:%s id:%d\n",pNombre,id);
		}
	}
	return ret;
}

//int estructura_imprimirListado(Estructura* list[],int len)
//{
//	int retorno = -1;
//	int i;
//	for(i=0;i<len;i++)
//	{
//		if(list[i]!=NULL)
//		{
//			estructura_imprimirPosicion(list[i]);
//			retorno = 0;
//		}
//	}
//	return retorno;
//}
//
//void estructura_imprimirPosicion(Estructura* this)
//{
//	printf("Campos de i");
//}


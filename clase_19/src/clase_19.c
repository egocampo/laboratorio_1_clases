/*
 ============================================================================
 Name        : clase_19.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "gets.h"

int main(void)
{
	Empleado* listadoEmpleados[50];
	Empleado* bufferEmpleado;
	char bufferNombre[50];
	char bufferApellido[50];
	char bufferDni[50];
	char bufferIdEmpleado[10];
	int bufferIdEmpleadoParseado;
	int r,i;
	int contador = 0;

	FILE* pFile;
	pFile = fopen("listadoEmpleados","r");
	if(pFile != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
					bufferNombre,
					bufferApellido,
					bufferDni,
					bufferIdEmpleado);
			if(r == 4)
			{
				bufferIdEmpleadoParseado = atoi(bufferIdEmpleado);
				bufferEmpleado = empleado_newParam(bufferNombre,
						bufferApellido,
						bufferDni,
						bufferIdEmpleadoParseado);
				listadoEmpleados[contador] = bufferEmpleado;
				contador++;
			}
			else
			{
				break;
			}
		}while(1);

		fclose(pFile);
	}
	else
	{
		printf("No se pudo abrir el archivo");
	}

//	printf("ALTA\n\n");
//
//	if(get_name(bufferNombre, 50,"Ingrese nombre: ","",1)==1)
//		if(get_name(bufferApellido, 50,"Ingrese apellido: ","",1)==1)
//			if(get_dni(bufferDni, "Ingrese DNI: ","",1)==1)
//			{
//				bufferEmpleado = empleado_newParam(bufferNombre, bufferApellido, bufferDni, contador);
//				if(bufferEmpleado != NULL)
//				{
//					listadoEmpleados[contador] = bufferEmpleado;
//					contador++;
//				}
//			}
//
	empleado_imprimirListado(listadoEmpleados, contador);

	printf("\n\nBORRAR\n\n");

	int opcionBorrar;
	if(get_int(&opcionBorrar, 2, "Ingrese el indice a borrar: ","",0,1,contador,3,0)==1)
	{
		printf("\n\nBorrado: %d\n\n",opcionBorrar);
		empleado_delete(listadoEmpleados[opcionBorrar]);
		listadoEmpleados[opcionBorrar] = NULL;
	}

	pFile = fopen("listadoEmpleados","w");
	char bufferEscritura[4096];
	int longitudBufferEscritura;
	for(i=0;i<contador;i++)
	{
		if(listadoEmpleados[i] != NULL)
		{
			sprintf(bufferEscritura,"%s,%s,%s,%d\n",
					listadoEmpleados[i]->nombre,
					listadoEmpleados[i]->apellido,
					listadoEmpleados[i]->dni,
					listadoEmpleados[i]->idEmpleado);
			longitudBufferEscritura = strlen(bufferEscritura);
			fwrite(bufferEscritura,sizeof(char),longitudBufferEscritura,pFile);
		}
	}

	empleado_imprimirListado(listadoEmpleados, contador);


	return 0;
}

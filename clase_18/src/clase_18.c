/*
 ============================================================================
 Name        : clase_18.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Builder.h"
#include "validations.h"
#include "estructuraBase.h"
#include "gets.h"
#define TAM_NOMBRE 20
int main(void)
{

	char nombreEstructura[50]= "Alumnos";
	char detalleParametros[100] = {"int id;char* nombre;float nota;"};

	builder_constructor(nombreEstructura,detalleParametros);

	return EXIT_SUCCESS;
}

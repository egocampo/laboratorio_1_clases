/*
 * Nacionalidad.c
 *
 *  Created on: 11 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Producto.h"
#include "Nacionalidad.h"
#include "Tipo.h"

typedef struct
{
	int idEmpleado;
	char nombre[50];
	char apellido[50];
	float sueldo;
}Empleado;

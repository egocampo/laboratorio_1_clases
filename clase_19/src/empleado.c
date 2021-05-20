#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

Empleado* empleado_new(void)
{
	return malloc(sizeof(Empleado));
}

Empleado* empleado_newParam(char* nombre,char* apellido,char* dni,int idEmpleado)
{
	Empleado* pEmpleado = empleado_new();
	if(nombre != NULL && apellido != NULL && dni != NULL && idEmpleado > 0)
	{
		if(isValidNombre(nombre))
			if(isValidApellido(apellido))
				if(isValidDni(dni))
					if(isValidIdEmpleado(idEmpleado))
					{
						strcpy(pEmpleado->nombre,nombre);
						strcpy(pEmpleado->apellido,apellido);
						strcpy(pEmpleado->dni,dni);
						pEmpleado->idEmpleado=idEmpleado;
					}
	}
	else
	{
		pEmpleado = NULL;
	}
	return pEmpleado;
}

void empleado_delete(Empleado* this)
{
	free(this);
}

int empleado_initArray(Empleado* list[],int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{		retorno = 0;
		for(i=0; i<len; i++)
		{
			list[i] = NULL;
		}
	}
	return retorno;
}

int empleado_setNombre(Empleado* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre))
	{
		retorno = 0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}

char* empleado_getNombre(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxNombre = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxNombre = this->nombre;
		*flagError = 0;
	}
	return auxNombre;
}

int isValidNombre(char* nombre)
{
	return 1;
}

int empleado_setApellido(Empleado* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL && isValidApellido(apellido))
	{
		retorno = 0;
		strcpy(this->apellido,apellido);
	}
	return retorno;
}

char* empleado_getApellido(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxApellido = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxApellido = this->nombre;
		*flagError = 0;
	}
	return auxApellido;
}

int isValidApellido(char* apellido)
{
	return 1;
}

int empleado_setDni(Empleado* this,char* dni)
{
	int retorno = -1;
	if(this != NULL && dni != NULL && isValidDni(dni))
	{
		retorno = 0;
		strcpy(this->dni,dni);
	}
	return retorno;
}

char* empleado_getDni(Empleado* this,int* flagError)
{
	*flagError = -1;
	char* auxDni = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxDni = this->nombre;
		*flagError = 0;
	}
	return auxDni;
}

int isValidDni(char* dni)
{
	return 1;
}

int empleado_setIdEmpleado(Empleado* this,int idEmpleado)
{
	int retorno = -1;
	if(this != NULL && idEmpleado > 0 && isValidIdEmpleado(idEmpleado))
	{
		retorno = 0;
		this->idEmpleado = idEmpleado;
	}
	return retorno;
}

int empleado_getIdEmpleado(Empleado* this,int* flagError)
{
	*flagError = -1;
	int auxIdEmpleado = -1;
	if(this != NULL && flagError != NULL)
	{
		auxIdEmpleado=this->idEmpleado;
		*flagError = 0;
	}
	return auxIdEmpleado;
}

int isValidIdEmpleado(int idEmpleado)
{
	return 1;
}

int empleado_buscarIndiceVacio(Empleado* list[],int len)
{
	int retorno = -1;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i]==NULL)
		{
			retorno =  i;
			break;
		}
	}
	return retorno;
}

int empleado_generarId(void)
{
	static int contadorId = 0;
	contadorId++;
	return contadorId;
}

int empleado_imprimirListado(Empleado* list[],int len)
{
	int retorno = -1;
	int i;
	for(i=0;i<len;i++)
	{
		if(list[i]!=NULL)
		{
			empleado_imprimirPosicion(list[i]);
			retorno = 0;
		}
	}
	return retorno;
}

void empleado_imprimirPosicion(Empleado* this)
{
	printf("%s - %s - %s - %d\n",
			this->nombre,
			this->apellido,
			this->dni,
			this->idEmpleado);
}

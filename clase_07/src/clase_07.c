/*
 ============================================================================
 Name        : clase_07.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#include "matematicas.h"
#include "string.h"

#define LIMITE 10

int main(void)
{
	int numero;
	utn_getNumber(&numero, "Numero: ","e. ",0,10,1);
	printf("%d",numero);
	return EXIT_SUCCESS;
}

// NULL ES UN DEFINE QUE VALE 0
// EXAMEN: SIZE OF SE EJECUTA EN PRECOMPILACION
// sizeof: sentencia de pre compilacion, se remplaza por un valor antes de compilar.
// SI LE PONGO EL NOMBRE DE UN ARRAY DEVUELVE EL TAMAÑO DEL ARRAY
// strlen ES UNA FUNCION, CUENTA TODOS LOS SIMBOLOS HASTA ENCONTAR UN '\0'

// fgets agrega un enter (10) \n al final

// char* pArray
// char pArray[]
// esto es lo mismo que printf("%s",texto);
//
//void myPrintDeCadena(char* pArray)
//{
//	int i=0;
//	while(pArray[i] != 0)
//	{
//		printf("%c",pArray[i]);
//		i++;
//	}
//}
//
//int main(void)
//{
//	int i,j;
//	// '\0' = 0 (ascii)
//	char texto[20]={'H','o','l','a','\0','H','o','l','a','\0'};  // COMILLA SIMPLEEEEE
//
//	i = strlen(texto);
//	j = sizeof(texto);
//
//	printf("%d\n",i);
//	printf("%d\n",j);
//	return EXIT_SUCCESS;
//}


//char texto[11];
//scanf("%s",texto);
//printf("ingresaste: %s", texto);

//char texto[11];
//fgets(texto,11,stdin);
//printf("%s",texto);

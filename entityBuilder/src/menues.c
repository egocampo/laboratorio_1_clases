/*
 * menues.c
 *
 *  Created on: 4 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "menues.h"

void menu_imprimirMenuPrincipal(char* nombreEstructura,char* detalleParametros)
{
	system("clear");
			printf("ENTITY BUILDER\n"
					"‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n"
					"MENU PRINCIPAL\n"
					"‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n"
					"1) Ingresar NOMBRE de entidad: %s\n"
					"2) Ingresar CAMPOS de la entidad: %s\n"
					"3) Generar archivos .C y .H\n"
					"4) Ayuda\n"
					"5) Salir del programa\n\n",
					nombreEstructura,detalleParametros);
}

void menu_imprimirAyuda(void)
{
	system("clear");
			printf("AYUDA\n"
					"‾‾‾‾‾\n\nNOMBRE de la entidad: debe ingresarse sólo el nombre,\n"
					"\tcon la primer letra mayúscula.\n"
					"CAMPOS de la entidad: debe ingresarse entre llaves\n"
					"\ty al final de cada campo poner punto y coma.\n"
					"\tEjemplo: {int id;char* nombre;float altura;}\n");
			menu_mensajeContinuar();
}

void menu_imprimirSubMenuInformes(void)
{
	system("clear");
	printf("Submenú de informes:\n"
			"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n\n"
			"a) Listado de empleados ordenados alfabéticamente por Apellido y Sector.\n"
			"b) Total y promedio de los salarios, y cuántos empleados superan\n   el salario promedio.\n"
			"c) Volver al Menú Principal.\n\n");
}

void menu_mensajeContinuar(void)
{
	printf("\nPresione cualquier tecla para continuar...");
	getchar();
}

void menu_imprimirSectores(void)
{
	printf("\nListado de sectores:\n"
			"1) Programación\n"
			"2) Diseño\n"
			"3) Soporte técnico\n"
			"4) RR.HH.\n"
			"5) Mantenimiento\n");
}

void menu_modificarEmpleado(void)
{
	printf("\nOpciones disponibles para modificar:\n"
			"a) Nombre\n"
			"b) Apellido\n"
			"c) Salario\n"
			"d) Sector\n"
			"e) Cancelar modificación\n");
}

void menu_imprimirMensajeDespedida(void)
{
	system("clear");
	printf("\nSaliendo de la aplicación... ¡Hasta luego!\n"
			"\n"
			"     _________\n"
			"    / ======= \\ \n"
			"   / __________\\ \n"
			"  | ___________ | \n"
			"  | |         | | \n"
			"  | | GO-Prog | | \n"
			"  | |_________| | \n"
			"  \\=____________/ \n"
			"  / ''''''''''' \\ \n"
			" / ::::::::::::: \\ \n"
			"(_________________) \n"
			"\n"
			"\nSoftware desarrollado por:\n"
			"\n"
			"█▀▀ █▀█   █▀█ █▀█ █▀█ █▀▀\n"
			"█▄█ █▄█   █▀▀ █▀▄ █▄█ █▄█\n"
			"\n"
			"Buenos Aires, Argentina\n"
			"web: www.redactando.com.ar\n"
			"whatsapp: 11-2233-4455\n\n");


}


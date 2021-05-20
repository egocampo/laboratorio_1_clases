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

void menu_imprimirMenuPrincipal(void)
{
	system("clear");
			printf("EMPRESA SERIA S.R.L.\n"
					"‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n"
					"MENU PRINCIPAL\n"
					"‾‾‾‾‾‾‾‾‾‾‾‾‾‾\n"
					"1) ALTA Producto\n"
					"2) BAJA Producto\n"
					"3) MODIFICAR Producto\n"
					"4) Cargar desde ARCHIVO\n"
					"5) Guardar en ARCHIVO\n"
					"6) Imprimir listado de Productos\n"
					"7) Salir del programa\n\n");
}

void menu_imprimirAyuda(void)
{
	system("clear");
			printf("AYUDA\n"
					"‾‾‾‾‾\n\nNOMBRE de la entidad: debe ingresarse sólo el nombre,\n"
					"\tcon la primer letra mayúscula.\n\n"
					"CAMPOS de la entidad: al final de cada campo poner punto y coma.\n"
					"\tLos tamaños de los arrays de caracteres se deben definir\n"
					"\tluego manualmente.\n"
					"\tEjemplo: int id;char* nombre;float altura;\n");
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

void menu_modificarProducto(char* nombre,char* descripcion,float precioUnitario)
{
	printf("\nOpciones disponibles para modificar:\n"
			"a) Nombre: %s\n"
			"b) Descripcion: %s\n"
			"c) Precio Unitario: %.2f\n"
			"d) Cancelar modificación\n",
			nombre,descripcion,precioUnitario);
}

void menu_imprimirMensajeDespedida(void)
{
	system("clear");
	printf("\nSaliendo de la aplicación... ¡Hasta luego!\n"
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
			"\nSoftware desarrollado por:\n"
			"\n"
			"█▀▀ █▀█   █▀█ █▀█ █▀█ █▀▀\n"
			"█▄█ █▄█   █▀▀ █▀▄ █▄█ █▄█\n"
			"\n"
			"Buenos Aires, Argentina\n"
			"web: www.redactando.com.ar\n"
			"whatsapp: 11-2233-4455\n\n");


}


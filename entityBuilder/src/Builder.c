/*
 * Builder.c
 *
 *  Created on: 13 may. 2021
 *      Author: gabriel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menues.h"
#include "Builder.h"
#define TAM_BUFFER_NOMBRE_ARCHIVO 50
#define TAM_NOMBRE_ENTIDAD 20
#define TAM_TIPO_CAMPO 20
#define TAM_NOMBRE_CAMPO 30

FILE* pArchivoPuntoC;

int builder_constructor(char* nombreEntidad, char* listadoParametros)
{
	FILE* pArchivoPuntoC;
	FILE* pArchivoPuntoH;

//	int tamListadoParametros = strlen(listadoParametros);

	char bufferNombreArchivo[TAM_BUFFER_NOMBRE_ARCHIVO];
	char nombreEntidadMinuscula[TAM_NOMBRE_ENTIDAD];
	builder_entidadMinuscula(nombreEntidad, nombreEntidadMinuscula);
	char listadoParametrosComma[100];
	builder_generarListadoParametrosComma(listadoParametros,listadoParametrosComma);

	sprintf(bufferNombreArchivo,"%s.c",nombreEntidadMinuscula);
	pArchivoPuntoC=fopen(bufferNombreArchivo,"w");

	sprintf(bufferNombreArchivo,"%s.h",nombreEntidadMinuscula);
	pArchivoPuntoH=fopen(bufferNombreArchivo,"w");

	int cantidadParametros = 0;
	int i;
	for(i=0;i<strlen(listadoParametros);i++)
	{
		if(listadoParametros[i] == ';')
			cantidadParametros++;
	}
	char bufferTipoCampo[TAM_TIPO_CAMPO];
	char bufferNombreCampo[TAM_NOMBRE_CAMPO];
	char bufferNombreCampoMayuscula[TAM_NOMBRE_CAMPO];

// INCLUDES
	fprintf(pArchivoPuntoC,"#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include \"%s.h\"\n\n",
			nombreEntidadMinuscula);
	fprintf(pArchivoPuntoH,""
			"typedef struct\n"
			"{\n"
			"\t%s\n"
			"}%s;\n\n",
			listadoParametros,nombreEntidad);

// NEW
	fprintf(pArchivoPuntoC,"%s* %s_new(void)\n{\n\treturn malloc(sizeof(%s));\n}\n\n",
						nombreEntidad,nombreEntidadMinuscula,nombreEntidad);
	fprintf(pArchivoPuntoH,"%s* %s_new(void);\n",
						nombreEntidad,nombreEntidadMinuscula);

// NEWPARAM
	fprintf(pArchivoPuntoC,""
			"%s* %s_newParam(%s)\n"
			"{\n"
			"\t%s* buffer%s = NULL;\n"
			"\tif(%s)\n"
			"\t{\n"
			"\t\tbuffer%s = %s_new();\n"
			"\t\tif(/*INGRESAR AQUI LOS SETTERS DE CADA CAMPO COMO != 0 ||*/)\n"
			"\t\t{\n"
			"\t\t\tfree(buffer%s);\n"
			"\t\t\tbuffer%s = NULL;\n"
			"\t\t}\n"
			"\t}\n"
			"\treturn buffer%s;\n"
			"}\n"
			"\n",
			nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma,
			nombreEntidad,nombreEntidad,
			listadoParametros,
			nombreEntidad,nombreEntidad,
			nombreEntidad,
			nombreEntidad,
			nombreEntidad);
	fprintf(pArchivoPuntoH,"%s* %s_newParam(%s);\n",
						nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma);

// NEWPARAM FROM TXT
	fprintf(pArchivoPuntoC,""
			"%s* %s_newParamFromText(%s)\n"
			"{\n"
			"\t%s* buffer%s = %s_new();\n"
			"\tif(%s)\n"
			"\t{\n"
			"\t\tif(/*INGRESAR AQUI LOS SETTERS DE CADA CAMPO COMO || (LOS INT/FLOAT PASANDOLOS POR ATOI/ATOF)*/)\n"
			"\t\t{\n"
			"\t\t\tfree(buffer%s);\n"
			"\t\t\tbuffer%s = NULL;\n"
			"\t\t}\n"
			"\t}\n"
			"\treturn buffer%s;\n"
			"}\n"
			"\n",
			nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma,
			nombreEntidad,nombreEntidad,nombreEntidadMinuscula,
			listadoParametros,
			nombreEntidad,
			nombreEntidad,
			nombreEntidad);
	fprintf(pArchivoPuntoH,"%s* %s_newParam(%s);\n",
				nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma);

// DELETE
	fprintf(pArchivoPuntoC,"int %s_delete(%s* this,int indice)\n{\n"
						"\tint retorno = -1;\n"
						"\tif(this != NULL)\n"
						"\t{\n"
						"\t\tfree(this);\n"
						"\t\tthis[indice] = NULL;\n"
						"\t\tretorno = 0;\n"
						"\t}\n"
						"\treturn retorno;\n"
						"}\n\n",
						nombreEntidadMinuscula,nombreEntidad);
	fprintf(pArchivoPuntoH,"int %s_delete(%s* this);\n",
						nombreEntidadMinuscula,nombreEntidad);

//	INIT ARRAY
	fprintf(pArchivoPuntoC,""
			"int %s_initArray(%s* list[],int len)\n"
			"{\n"
			"\tint retorno = -1;\n"
			"\tint i;\n"
			"\tif(list != NULL && len > 0)\n"
			"\t{"
			"\t\tretorno = 0;\n"
			"\t\tfor(i=0; i<len; i++)\n"
			"\t\t{\n"
			"\t\t\tlist[i] = NULL;\n"
			"\t\t}\n"
			"\t}\n"
			"\treturn retorno;\n"
			"}\n\n",
			nombreEntidadMinuscula,nombreEntidad);
	fprintf(pArchivoPuntoH,""
			"int %s_initArray(%s* list[],int len);\n\n",
			nombreEntidadMinuscula,nombreEntidad);

// CAMPOS
	for(i=0;i<cantidadParametros;i++)
	{
		builder_obtenerParametro(listadoParametros, bufferTipoCampo, bufferNombreCampo);
		builder_entidadMayuscula(bufferNombreCampo, bufferNombreCampoMayuscula);
		char caracterBufferTipoCampo = bufferTipoCampo[0];

		switch(caracterBufferTipoCampo)
		{
		case 'i':
			fprintf(pArchivoPuntoC,""
					"int %s_set%s(%s* this,int %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s > 0 && %s_isValid%s(%s))\n"
					"\t{\n"
					"\t\tretorno = 0;\n"
					"\t\tthis->%s = %s;\n"
					"\t}\n"
					"\treturn retorno;\n"
					"}\n\n"
					"int %s_get%s(%s* this,int* flagError)\n"
					"{\n"
					"\t*flagError = -1;\n"
					"\tint aux%s = -1;\n"
					"\tif(this != NULL && flagError != NULL)\n"
					"\t{\n"
					"\t\taux%s=this->%s;\n"
					"\t\t*flagError = 0;\n"
					"\t}\n"
					"\treturn aux%s;\n"
					"}\n\n"
					"int %s_isValid%s(int %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampoMayuscula,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			fprintf(pArchivoPuntoH,""
					"int %s_set%s(%s* this,int %s);\n"
					"int %s_get%s(%s* this,int* flagError);\n"
					"int %s_isValid%s(int %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			break;
		case 'c':
			fprintf(pArchivoPuntoC,""
					"int %s_set%s(%s* this,char* %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s != NULL && %s_isValid%s(%s))\n"
					"\t{\n"
					"\t\tretorno = 0;\n"
					"\t\tstrcpy(this->%s,%s);\n"
					"\t}\n"
					"\treturn retorno;\n"
					"}\n\n"
					"char* %s_get%s(%s* this,int* flagError)\n"
					"{\n"
					"\t*flagError = -1;\n"
					"\tchar* aux%s = NULL;\n"
					"\tif(this != NULL && flagError != NULL)\n"
					"\t{\n"
					"\t\taux%s = this->%s;\n"
					"\t\t*flagError = 0;\n"
					"\t}\n"
					"\treturn aux%s;\n"
					"}\n\n"
					"int %s_isValid%s(char* %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampoMayuscula,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			fprintf(pArchivoPuntoH,""
					"int %s_set%s(%s* this,char* %s);\n"
					"char* %s_get%s(%s* this,int* flagError);\n"
					"int %s_isValid%s(char* %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			break;
		case 'f':
			fprintf(pArchivoPuntoC,""
					"int %s_set%s(%s* this,float %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s > 0 && %s_isValid%s(%s))\n"
					"\t{\n"
					"\t\tretorno = 0;\n"
					"\t\tthis->%s = %s;\n"
					"\t}\n"
					"\treturn retorno;\n"
					"}\n\n"
					"float %s_get%s(%s* this,int* flagError)\n"
					"{\n"
					"\t*flagError = -1;\n"
					"\tfloat aux%s = -1;\n"
					"\tif(this != NULL && flagError != NULL)\n"
					"\t{\n"
					"\t\taux%s=this->%s;\n"
					"\t\t*flagError = 0;\n"
					"\t}\n"
					"\treturn aux%s;\n"
					"}\n\n"
					"int %s_isValid%s(float %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampoMayuscula,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			fprintf(pArchivoPuntoH,""
					"int %s_set%s(%s* this,float %s);\n"
					"float %s_get%s(%s* this,int* flagError);\n"
					"int %s_isValid%s(float %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,bufferNombreCampo);
			break;
		}
	}

//	buscarIndiceVacio
	fprintf(pArchivoPuntoC,""
			"int %s_buscarIndiceVacio(%s* list[],int len)\n"
			"{\n"
			"\tint retorno = -1;\n"
			"\tint i;\n"
			"\tfor(i=0; i<len; i++)\n"
			"\t{\n"
			"\t\tif(list[i]==NULL)\n"
			"\t\t{\n"
			"\t\t\tretorno =  i;\n"
			"\t\t\tbreak;\n"
			"\t\t}\n"
			"\t}\n"
			"\treturn retorno;\n"
			"}\n\n",
			nombreEntidadMinuscula,nombreEntidad);
	fprintf(pArchivoPuntoH,""
			"\nint %s_buscarIndiceVacio(%s* list[],int len);\n",
			nombreEntidadMinuscula,nombreEntidad);

//	GENERAR ID
	fprintf(pArchivoPuntoC,""
			"int %s_generarId(void)\n"
			"{\n"
			"\tstatic int contadorId = 0;\n"
			"\tcontadorId++;\n"
			"\treturn contadorId;\n"
			"}\n\n",
			nombreEntidadMinuscula);
	fprintf(pArchivoPuntoH,""
			"int %s_generarId(void);\n",
			nombreEntidadMinuscula);

//	IMPRIMIR LISTADO
	fprintf(pArchivoPuntoC,""
			"int %s_imprimirListado(%s* list[],int len)\n"
			"{\n"
			"\tint retorno = -1;\n"
			"\tint i;\n"
			"\tfor(i=0;i<len;i++)\n"
			"\t{\n"
			"\t\tif(list[i]!=NULL)\n"
			"\t\t{\n"
			"\t\t\t%s_imprimirPosicion(list[i]);\n"
			"\t\t\tretorno = 0;\n"
			"\t\t}\n"
			"\t}\n"
			"\treturn retorno;\n"
			"}\n\n"
			"void %s_imprimirPosicion(%s* this)\n"
			"{\n"
			"\tprintf(\"Campos de i\");\n"
			"}\n\n",
			nombreEntidadMinuscula,nombreEntidad,
			nombreEntidadMinuscula,
			nombreEntidadMinuscula,nombreEntidad);
	fprintf(pArchivoPuntoH,""
			"int %s_imprimirListado(%s* list[],int len);\n"
			"void %s_imprimirPosicion(%s* this);\n",
			nombreEntidadMinuscula,nombreEntidad,
			nombreEntidadMinuscula,nombreEntidad);

	fclose(pArchivoPuntoC);
	fclose(pArchivoPuntoH);
	return 0;
}

//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

void builder_entidadMinuscula(char* nombreEntidad,char* nombreEntidadMinuscula)
{
	int indice;
	for (indice = 0; nombreEntidad[indice] != '\0'; indice++)
		nombreEntidadMinuscula[indice] = tolower(nombreEntidad[indice]);
	if(nombreEntidad[indice] == '\0')
		nombreEntidadMinuscula[indice] = '\0';
}

void builder_entidadMayuscula(char* nombreEntidad,char* nombreEntidadMayuscula)
{
	int i=1;
	nombreEntidadMayuscula[0]=toupper(nombreEntidad[0]);
	do
	{
		nombreEntidadMayuscula[i]=nombreEntidad[i];
		i++;
	}while(nombreEntidad[i-1]!=0);
}

void builder_obtenerParametro(char* listadoParametros,char* tipoCampo,char* nombreCampo)
{
	char bufferTipo[10];
	char bufferNombre[20];
	int i;
	int contadorBufferTipo = 0;
	int contadorBufferNombre = 0;
	static int inicialTipo = 0;
	for(i=inicialTipo;listadoParametros[i-1]!=32;i++)
	{
		if(listadoParametros[i]==32)
		{
			bufferTipo[contadorBufferTipo]=0;
			contadorBufferTipo++;
		}
		else
		{
			bufferTipo[contadorBufferTipo]=listadoParametros[i];
			contadorBufferTipo++;
		}
	}

	int contadorauxiliar=0;
	for(i=inicialTipo+strlen(bufferTipo)+1;listadoParametros[i-1]!=59;i++)
	{
		if(listadoParametros[i]==59)
		{
			bufferNombre[contadorBufferNombre]=0;
			contadorauxiliar+=i;
		}
		else
		{
			bufferNombre[contadorBufferNombre]=listadoParametros[i];
			contadorBufferNombre++;
		}
	}
	inicialTipo = contadorauxiliar+1;
	strcpy(tipoCampo,bufferTipo);
	strcpy(nombreCampo,bufferNombre);
}

void builder_generarListadoParametrosComma(char* listadoParametros,char* listadoParametrosComma)
{
	int i=0;
	do
	{
		if(listadoParametros[i]==59)
		{
			listadoParametrosComma[i] = 44;
		}
		else
		{
			listadoParametrosComma[i]=listadoParametros[i];
		}
		i++;
	}while(listadoParametros[i-1]!=0);
}

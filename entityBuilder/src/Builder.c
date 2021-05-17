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
#include "Builder.h"

FILE* pArchivoPuntoC;

int builder_constructor(char* nombreEntidad, char* listadoParametros)
{
	FILE* pArchivoPuntoC;
	FILE* pArchivoPuntoH;

	char bufferPuntoC[10000];
	char bufferPuntoH[10000];
	int longitudBufferPuntoC;
	int longitudBufferPuntoH;
	char bufferNombreArchivo[50];
	char nombreEntidadMinuscula[20];
	builder_entidadMinuscula(nombreEntidad, nombreEntidadMinuscula);

	sprintf(bufferNombreArchivo,"%s.c",nombreEntidadMinuscula);
	pArchivoPuntoC=fopen(bufferNombreArchivo,"w");

	sprintf(bufferNombreArchivo,"%s.h",nombreEntidadMinuscula);
	pArchivoPuntoH=fopen(bufferNombreArchivo,"w");

	int contadorComas = 0;
	int cantidadParametros;
	int i;
	for(i=0;i<strlen(listadoParametros);i++)
	{
		if(listadoParametros[i] == 59)
			contadorComas++;
	}
	cantidadParametros = contadorComas;
	char bufferTipoCampo[10];
	char bufferNombreCampo[20];
	char bufferNombreCampoMayuscula[20];

// INCLUDES
	sprintf(bufferPuntoC,"#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n#include \"%s.h\"\n\n",nombreEntidad);
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);

	sprintf(bufferPuntoH,""
			"typedef struct\n"
			"{\n"
			"\t%s\n"
			"}%s;\n\n",
			listadoParametros,nombreEntidad);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

// NEW
	sprintf(bufferPuntoC,"%s* %s_new(void)\n{\n\treturn malloc(sizeof(%s));\n}\n\n",
						nombreEntidad,nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,"%s* %s_new(void);\n",
						nombreEntidad,nombreEntidadMinuscula);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

// NEWPARAM,
	char listadoParametrosComma[100];
	generarListadoParametrosComma(listadoParametros,listadoParametrosComma);
	sprintf(bufferPuntoC,"%s* %s_newParam(%s)\n{\n\treturn malloc(sizeof(%s));\n}\n\n",
						nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma,nombreEntidad);
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,"%s* %s_newParam(%s);\n",
						nombreEntidad,nombreEntidadMinuscula,listadoParametrosComma);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

// DELETE
	sprintf(bufferPuntoC,"int %s_delete(%s* this)\n{\n"
						"\tint retorno = -1;\n"
						"\tif(this != NULL)\n"
						"\t{\n"
						"\t\tfree(this);\n"
						"\t\tretorno = 0;\n"
						"\t}\n"
						"\treturn retorno;\n"
						"}\n\n",
						nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,"int %s_delete(%s* this);\n",
						nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

//	INIT ARRAY
	sprintf(bufferPuntoC,""
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
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,""
			"int %s_initArray(%s* list[],int len);\n\n",
			nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);


// CAMPOS
	for(i=0;i<cantidadParametros;i++)
	{
		builder_obtenerParametro(listadoParametros, bufferTipoCampo, bufferNombreCampo);
		builder_entidadMayuscula(bufferNombreCampo, bufferNombreCampoMayuscula);
		char caracterBufferTipoCampo = bufferTipoCampo[0];

		switch(caracterBufferTipoCampo)
		{
		case 'i':
			sprintf(bufferPuntoC,""
					"int %s_set%s(%s* this,int %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s > 0 && isValid%s(%s))\n"
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
					"int isValid%s(int %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo);
			longitudBufferPuntoC=strlen(bufferPuntoC);
			fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
			sprintf(bufferPuntoH,""
					"int %s_set%s(%s* this,int %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo);
			longitudBufferPuntoH=strlen(bufferPuntoH);
			fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);
			break;
		case 'c':
			sprintf(bufferPuntoC,""
					"int %s_set%s(%s* this,char* %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s != NULL && isValid%s(%s))\n"
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
					"\t\taux%s = this->nombre;\n"
					"\t\t*flagError = 0;\n"
					"\t}\n"
					"\treturn aux%s;\n"
					"}\n\n"
					"int isValid%s(char* %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo);
			longitudBufferPuntoC=strlen(bufferPuntoC);
			fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
			sprintf(bufferPuntoH,""
					"int %s_set%s(%s* this,char* %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo);
			longitudBufferPuntoH=strlen(bufferPuntoH);
			fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);
			break;
		case 'f':
			sprintf(bufferPuntoC,""
					"int %s_set%s(%s* this,float %s)\n"
					"{\n"
					"\tint retorno = -1;\n"
					"\tif(this != NULL && %s > 0 && isValid%s(%s))\n"
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
					"int isValid%s(float %s)\n"
					"{\n"
					"\treturn 1;\n"
					"}\n\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampo,bufferNombreCampo,
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo,
					bufferNombreCampoMayuscula,
					bufferNombreCampoMayuscula,bufferNombreCampo);
			longitudBufferPuntoC=strlen(bufferPuntoC);
			fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
			sprintf(bufferPuntoH,""
					"int %s_set%s(%s* this,float %s);\n",
					nombreEntidadMinuscula,bufferNombreCampoMayuscula,nombreEntidad,bufferNombreCampo);
			longitudBufferPuntoH=strlen(bufferPuntoH);
			fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);
			break;
		}
	}

//	buscarIndiceVacio
	sprintf(bufferPuntoC,""
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
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,""
			"\nint %s_buscarIndiceVacio(%s* list[],int len);\n",
			nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

//	GENERAR ID
	sprintf(bufferPuntoC,""
			"int %s_generarId(void)\n"
			"{\n"
			"\tstatic int contadorId = 0;\n"
			"\tcontadorId++;\n"
			"\treturn contadorId;\n"
			"}\n\n",
			nombreEntidadMinuscula);
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,""
			"int %s_generarId(void);\n",
			nombreEntidadMinuscula);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);

//	IMPRIMIR LISTADO
	sprintf(bufferPuntoC,""
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
	longitudBufferPuntoC=strlen(bufferPuntoC);
	fwrite(bufferPuntoC,sizeof(char),longitudBufferPuntoC,pArchivoPuntoC);
	sprintf(bufferPuntoH,""
			"int %s_imprimirListado(%s* list[],int len);\n"
			"void %s_imprimirPosicion(%s* this)\n",
			nombreEntidadMinuscula,nombreEntidad,
			nombreEntidadMinuscula,nombreEntidad);
	longitudBufferPuntoH=strlen(bufferPuntoH);
	fwrite(bufferPuntoH,sizeof(char),longitudBufferPuntoH,pArchivoPuntoH);


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

void generarListadoParametrosComma(char* listadoParametros,char* listadoParametrosComma)
{
	int i;
	for(i=0;listadoParametros[i+1]!=0;i++)
	{
		if(listadoParametros[i]==59)
		{
			listadoParametrosComma[i] = 44;
		}
		else
		{
			listadoParametrosComma[i]=listadoParametros[i];
		}
	}
}





#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "producto.h"
#include "gets.h"
#include "menues.h"

Producto* producto_new(void)
{
	return malloc(sizeof(Producto));
}

Producto* producto_newParam(char* nombre,char* descripcion,float precioUnitario,int idProducto)
{
	Producto* bufferProducto = producto_new();
	if(nombre != NULL && descripcion != NULL && precioUnitario > 0 && idProducto > 0)
	{
		if(producto_setNombre(bufferProducto,nombre) != 0 ||
				producto_setDescripcion(bufferProducto,descripcion) != 0 ||
				producto_setPrecioUnitario(bufferProducto,precioUnitario) != 0 ||
				producto_setIdProducto(bufferProducto, idProducto) != 0)
		{
			free(bufferProducto);
		}
	}
	return bufferProducto;
}

Producto* producto_newParamFromTxt(char* nombre,char* descripcion,char* precioUnitario,char* idProducto)
{
	Producto* bufferProducto = producto_new();
	if(nombre != NULL && descripcion != NULL && precioUnitario != NULL && idProducto != NULL)
	{
		if(producto_setNombre(bufferProducto,nombre) != 0 || producto_setDescripcion(bufferProducto,descripcion) != 0 || producto_setPrecioUnitario(bufferProducto,atof(precioUnitario)) != 0 || producto_setIdProducto(bufferProducto, atoi(idProducto)) != 0)
		{

		}
	}
	else
	{
		free(bufferProducto);
	}
	return bufferProducto;
}

int producto_delete(Producto* this[],int indice)
{
	int retorno = -1;
	if(this != NULL)
	{
		free(this[indice]);
		this[indice] = NULL;
		retorno = 0;
	}
	return retorno;
}

int producto_initArray(Producto* list[],int len)
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

int producto_setNombre(Producto* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && producto_isValidNombre(nombre))
	{
		retorno = 0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}

char* producto_getNombre(Producto* this,int* flagError)
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

int producto_isValidNombre(char* nombre)
{
	return 1;
}

int producto_setDescripcion(Producto* this,char* descripcion)
{
	int retorno = -1;
	if(this != NULL && descripcion != NULL && producto_isValidDescripcion(descripcion))
	{
		retorno = 0;
		strcpy(this->descripcion,descripcion);
	}
	return retorno;
}

char* producto_getDescripcion(Producto* this,int* flagError)
{
	*flagError = -1;
	char* auxDescripcion = NULL;
	if(this != NULL && flagError != NULL)
	{
		auxDescripcion = this->descripcion;
		*flagError = 0;
	}
	return auxDescripcion;
}

int producto_isValidDescripcion(char* descripcion)
{
	return 1;
}

int producto_setPrecioUnitario(Producto* this,float precioUnitario)
{
	int retorno = -1;
	if(this != NULL && precioUnitario > 0 && producto_isValidPrecioUnitario(precioUnitario))
	{
		retorno = 0;
		this->precioUnitario = precioUnitario;
	}
	return retorno;
}

float producto_getPrecioUnitario(Producto* this,int* flagError)
{
	*flagError = -1;
	float auxPrecioUnitario = -1;
	if(this != NULL && flagError != NULL)
	{
		auxPrecioUnitario=this->precioUnitario;
		*flagError = 0;
	}
	return auxPrecioUnitario;
}

int producto_isValidPrecioUnitario(float precioUnitario)
{
	return 1;
}

int producto_setIdProducto(Producto* this,int idProducto)
{
	int retorno = -1;
	if(this != NULL && idProducto > 0 && producto_isValidIdProducto(idProducto))
	{
		retorno = 0;
		this->idProducto = idProducto;
	}
	return retorno;
}

int producto_getIdProducto(Producto* this,int* flagError)
{
	*flagError = -1;
	int auxIdProducto = -1;
	if(this != NULL && flagError != NULL)
	{
		auxIdProducto=this->idProducto;
		*flagError = 0;
	}
	return auxIdProducto;
}

int producto_isValidIdProducto(int idProducto)
{
	return 1;
}

int producto_buscarIndiceVacio(Producto* list[],int len)
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

int producto_generarId(void)
{
	static int contadorId = 0;
	contadorId++;
	return contadorId;
}

int producto_imprimirListado(Producto* list[],int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		printf("\nListado de Productos:\n\n");
		for(i=0;i<len;i++)
		{
			if(list[i]!=NULL)
			{
				producto_imprimirPosicion(list[i]);
				retorno = 0;
			}
		}
	}
	menu_mensajeContinuar();
	return retorno;
}

void producto_imprimirPosicion(Producto* this)
{
	printf("%s - %s - %.2f - %d\n",
			this->nombre,
			this->descripcion,
			this->precioUnitario,
			this->idProducto);
}

int producto_cargarDatosDesdeArchivo(Producto* list[])
{
	FILE* pArchivoProductos=fopen("/home/gabriel/UTN/primerCuatrimestre/"
			"programacion1_laboratorio1/repositoriosClonados/laboratorio1_clases/"
			"clase_19bis/src/listadoProductos","r");
	Producto* bufferProducto;
	int rs;
	char bufferNombre[50];
	char bufferDescripcion[50];
	char bufferPrecioUnitario[10];
	char bufferIdProducto[10];
	int indiceVacio;
	if(pArchivoProductos != NULL)
	{
		do
		{
			rs = fscanf(pArchivoProductos,"%[^,],%[^,],%[^,],%[^\n]\n",
					bufferNombre,
					bufferDescripcion,
					bufferPrecioUnitario,
					bufferIdProducto);
			if(rs == 4)
			{
				bufferProducto = producto_newParamFromTxt(bufferNombre, bufferDescripcion, bufferPrecioUnitario, bufferIdProducto);
				if(bufferProducto != NULL)
				{
					indiceVacio = producto_buscarIndiceVacio(list, 50);
					list[indiceVacio] = bufferProducto;
				}
			}
			else
			{
				break;
			}
		}while(1);
	}
	else
	{
		printf("\nNo se pudo abrir el archivo.\n");
	}
	fclose(pArchivoProductos);
	menu_mensajeContinuar();
	return 0;
}

int producto_altaProducto(Producto* list[],int lenList)
{
	Producto* bufferProducto = NULL;
	char bufferNombre[50];
	char bufferDescripcion[50];
	float bufferPrecioUnitario;
	int bufferIdProducto = -1;
	int indiceVacio;
	if(get_name(bufferNombre, 50,"Nombre: ","",3)==1 &&
			get_text(bufferDescripcion,50,"Descripcion: ","",3)==1 &&
			get_float(&bufferPrecioUnitario,10,"Precio Unitario: ","",1,1,1000,3,0)==1)
	{
		bufferIdProducto = producto_generarId();
		bufferProducto = producto_newParam(bufferNombre, bufferDescripcion, bufferPrecioUnitario, bufferIdProducto);
		if(bufferProducto != NULL)
		{
			indiceVacio = producto_buscarIndiceVacio(list, lenList);
			list[indiceVacio] = bufferProducto;
		}
	}
	menu_mensajeContinuar();
	return 0;
}

int producto_bajaProducto(Producto* list[],int lenList)
{
	int retorno = -1;
	if(list != NULL)
	{
		retorno = 0;
		int opcionElegidaBaja,indiceBaja;
		producto_imprimirListado(list, 50);
		if(get_int(&opcionElegidaBaja, 10,"\nIndice a BORRAR: ","",1,1,2000,3,0)==1)
		{
			indiceBaja = producto_buscarIndicePorId(list, lenList, opcionElegidaBaja);
			producto_delete(list,indiceBaja);
		}
	}
	menu_mensajeContinuar();
	return retorno;
}

int producto_buscarIndicePorId(Producto* list[],int lenList,int idProducto)
{
	int i;
	int retorno = -1;
	for(i=0;i<lenList;i++)
	{
		if(list[i] != NULL && list[i]->idProducto == idProducto)
		{
			retorno = i;
		}
	}
	return retorno;
}

int producto_modificarProducto(Producto* list[],int lenList)
{
	int retorno = -1;
	if(list != NULL)
	{
		retorno = 0;
		int opcionElegidaModificar,indiceModificar;
		char opcionSubMenuModificar;
		char bufferNombre[50];
		char bufferDescripcion[50];
		float bufferPrecioUnitario;
		int flagError;
		producto_imprimirListado(list, 50);
		if(get_int(&opcionElegidaModificar, 10,"\nId a MODIFICAR: ","",1,1,2000,3,0)==1)
		{
			indiceModificar = producto_buscarIndicePorId(list, lenList, opcionElegidaModificar);
			do
			{
				menu_modificarProducto(producto_getNombre(list[indiceModificar], &flagError),
						producto_getDescripcion(list[indiceModificar], &flagError),
						producto_getPrecioUnitario(list[indiceModificar], &flagError));
				if(get_char(&opcionSubMenuModificar, "abcdABCD", 9, "Ingrese el campo a modificar: ","",3)==1)
				{
					switch(opcionSubMenuModificar)
					{
						case 'a':
						case 'A':
							if(get_name(bufferNombre, 50,"Nombre: ","",3)==1)
							{
								producto_setNombre(list[indiceModificar], bufferNombre);
							}
							break;
						case 'b':
						case 'B':
							if(get_text(bufferDescripcion,50,"Descripcion: ","",3)==1)
							{
								producto_setDescripcion(list[indiceModificar], bufferDescripcion);
							}
							break;
						case 'c':
						case 'C':
							if(get_float(&bufferPrecioUnitario,10,"Precio Unitario: ","",1,1,1000,3,0)==1)
							{
								producto_setPrecioUnitario(list[indiceModificar], bufferPrecioUnitario);
							}
							break;
					}
				}
			}while(opcionSubMenuModificar != 'd' && opcionSubMenuModificar != 'D');
		}
	}
	menu_mensajeContinuar();
	return retorno;
}

int producto_guardarEnArchivo(Producto* list[],int lenList)
{
	FILE* pArchivoProductos=fopen("listadoProductos2","w");
	int i;
	char bufferWrite[4096];
	int lenBufferWrite;
	int flagError;
	if(pArchivoProductos != NULL)
	{
		for(i=0;i<lenList;i++)
		{
			if(list[i] != NULL)
			{
				sprintf(bufferWrite,"%s,%s,%.2f,%d\n",
						producto_getNombre(list[i], &flagError),
						producto_getDescripcion(list[i], &flagError),
						producto_getPrecioUnitario(list[i], &flagError),
						producto_getIdProducto(list[i], &flagError));
				lenBufferWrite = strlen(bufferWrite);
				fwrite(bufferWrite,sizeof(char),lenBufferWrite,pArchivoProductos);
			}
		}
	}
	fclose(pArchivoProductos);
	menu_mensajeContinuar();
	return 0;
}



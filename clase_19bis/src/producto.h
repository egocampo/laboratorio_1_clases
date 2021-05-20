typedef struct
{
	char nombre[50];
	char descripcion[50];
	float precioUnitario;
	int idProducto;
}Producto;

Producto* producto_new(void);
Producto* producto_newParam(char* nombre,char* descripcion,float precioUnitario,int idProducto);
Producto* producto_newParamFromTxt(char* nombre,char* descripcion,char* precioUnitario,char* idProducto);
int producto_delete(Producto* this[],int indice);  ////   cambio IMPORTANTE

int producto_initArray(Producto* list[],int len);

int producto_setNombre(Producto* this,char* nombre);
char* producto_getNombre(Producto* this,int* flagError);
int producto_isValidNombre(char* nombre);
int producto_setDescripcion(Producto* this,char* descripcion);
char* producto_getDescripcion(Producto* this,int* flagError);
int producto_isValidDescripcion(char* descripcion);
int producto_setPrecioUnitario(Producto* this,float precioUnitario);
float producto_getPrecioUnitario(Producto* this,int* flagError);
int producto_isValidPrecioUnitario(float precioUnitario);
int producto_setIdProducto(Producto* this,int idProducto);
int producto_getIdProducto(Producto* this,int* flagError);
int producto_isValidIdProducto(int idProducto);

int producto_buscarIndiceVacio(Producto* list[],int len);
int producto_generarId(void);
int producto_imprimirListado(Producto* list[],int len);
void producto_imprimirPosicion(Producto* this);

int producto_cargarDatosDesdeArchivo(Producto* list[]);
int producto_altaProducto(Producto* list[],int lenList);
int producto_bajaProducto(Producto* list[],int lenList);
int producto_buscarIndicePorId(Producto* list[],int lenList,int idProducto);
int producto_modificarProducto(Producto* list[],int lenList);
int producto_guardarEnArchivo(Producto* list[],int lenList);

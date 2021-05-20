typedef struct
{
	char nombre[50];
	char apellido[50];
	char dni[50];
	int idEmpleado;
}Empleado;

Empleado* empleado_new(void);
Empleado* empleado_newParam(char* nombre,char* apellido,char* dni,int idEmpleado);
void empleado_delete(Empleado* this);
int empleado_initArray(Empleado* list[],int len);

int empleado_setNombre(Empleado* this,char* nombre);
int empleado_setApellido(Empleado* this,char* apellido);
int empleado_setDni(Empleado* this,char* dni);
int empleado_setIdEmpleado(Empleado* this,int idEmpleado);

char* empleado_getNombre(Empleado* this,int* flagError);
int isValidNombre(char* nombre);
char* empleado_getApellido(Empleado* this,int* flagError);
int isValidApellido(char* apellido);
char* empleado_getDni(Empleado* this,int* flagError);
int isValidDni(char* dni);
int empleado_getIdEmpleado(Empleado* this,int* flagError);
int isValidIdEmpleado(int idEmpleado);

int empleado_buscarIndiceVacio(Empleado* list[],int len);
int empleado_generarId(void);
int empleado_imprimirListado(Empleado* list[],int len);
void empleado_imprimirPosicion(Empleado* this);

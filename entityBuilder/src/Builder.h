/*
 * Builder.h
 *
 *  Created on: 13 may. 2021
 *      Author: gabriel
 */

#ifndef BUILDER_H_
#define BUILDER_H_

int builder_constructor(char* nombreEntidad, char* listadoParametros);
void builder_entidadMinuscula(char* nombreEntidad,char* nombreEntidadMinuscula);
void builder_entidadMayuscula(char* nombreEntidad,char* nombreEntidadMayuscula);
int builder_setter(char* nombreEntidad,char* tipoDato,char* nombreCampo);
void builder_obtenerParametro(char* listadoParametros,char* tipoCampo,char* nombreCampo);
void builder_generarListadoParametrosComma(char* listadoParametros,char* listadoParametrosComma);

#endif /* BUILDER_H_ */

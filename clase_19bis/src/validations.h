/*
 * validations.h
 *
 *  Created on: 19 abr. 2021
 *      Author: gabriel
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int val_isValidInt(char* numero, int flagSigned);
int val_isValidFloat(char* numero, int flagSigned);
int val_isValidName(char* nombre);
int val_isValidDni(char* dni);
int val_isValidCuit(char* cuit);
int val_cantidadDigitos(char* arrayParaVerificar);
int val_cuitDigitoVerificador(char* cuit);
int val_isValidEmail(char* email);

int val_isInWhiteList(char* caracterParaComparar, char* listaBlanca,int len);


#endif /* VALIDATIONS_H_ */

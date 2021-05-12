/*
 * utn.h
 *
 *  Created on: 25 mar. 2021
 *      Author: gabriel
 */

#ifndef UTN_H_
#define UTN_H_

#define UTN_MIN_EDAD 0
#define UTN_MAX_EDAD 99
#define UTN_REINTENTOS 3
#define UTN_OPCION_SI 's'
#define UTN_OPCION_NO 'n'

int utn_getNumber(int* pResult, char* pText, char* pTextError, int min, int max, int qtyRetry);
int utn_getInt(int* pResult);
int utn_validateNumber(char* pArray);
int utn_myGets(char* string, int len);

int utn_getNumberFloat(float* pResult, char* pText, char* pTextError, int min, int max, int qtyRetry);
int utn_getFloat(float* pResult);
int utn_validateFloat(char* string);

int utn_getText(char* pResult, int len, char* pText);
int utn_getString(char* string,int len);
int utn_validateString(char* string);



#endif /* UTN_H_ */

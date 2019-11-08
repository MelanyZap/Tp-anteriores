#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int utn_getString(char* pBufferString,int limite);
int utn_getInt(int* pResultado);
int utn_getFloat(float* pResultado);
int utn_isFloat(char* pBuffer);
int utn_isLetra(char* pBuffer);
int utn_isIntConGuiones(char* pBuffer);
int utn_isInt(char* pBuffer);
int utn_getNombre(char* pNombre, char* msg, char* msgError);
int utn_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int utn_getEnteroSinLimites(int* pNum, int reint, char* msg, char* msgError);
int utn_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int utn_getString(char* pBufferString,int limite);
int utn_getInt(int* pResultado);
int utn_getFloat(float* pResultado);
int utn_isFloat(char* pBuffer);
int utn_isInt(char* pBuffer);
int utn_isIntConGuiones(char* pBuffer);
int utn_isLetra(char* pBuffer);
#endif // INPUT_H_INCLUDED

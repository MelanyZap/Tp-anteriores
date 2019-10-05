#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

int utn_getString(char string[], char mensaje[], char mensajeError[], int min, int max, int intentos);
int utn_isNum(char str[]);
int utn_getStringNum(char msj[],char input[]);
int utn_getFloat(float *puntero, char mensaje[], char mensajeError[], float min, float max, int intentos);
int utn_getInt(int *puntero, char mensaje[], char mensajeError[], int min, int max, int intentos);
void utn_functionGetString (char msj[],char input[]);
int validStrArray(char string[]);
#endif // INPUT_H_INCLUDED

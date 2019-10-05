#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include <string.h>
#include <ctype.h>
#include "funciones.h"


int utn_getString(char string[], char mensaje[], char mensajeError[], int min, int max, int intentos)
{
    int length;
    int control;
    printf("%s", mensaje);
    fflush(stdin);
    gets(string);
    control = validStrArray(string);
    length = strlen(string);
    intentos--;
    while((length < min || length > max || control == 0) && intentos >= 1)
        {
            intentos--;
            printf("%s", mensajeError);
            fflush(stdin);
            gets(string);
            control = validStrArray(string);
        }
    return control;
}

int utn_isNum(char str[])
{
    int ret = 1;
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            ret =  0;
        i++;
    }
    return ret;
}

int utn_getStringNum(char msj[],char input[])
{
    int ret = 0;
    char aux[256];
    utn_functionGetString(msj,aux);
    if(utn_isNum(aux))
    {
        strcpy(input,aux);
        ret = 1;
    }
    return ret;
}

int utn_getFloat(float *puntero, char mensaje[], char mensajeError[], float min, float max, int intentos)
{
    int control;
    int flag = 0;
    float aux;
    printf("%s", mensaje);
    control = scanf("%f", &aux);
    intentos--;
    while((control != 1 || aux < min || aux > max) && intentos>=1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            control = scanf("%f", &aux);
            intentos--;
        }
    if(control == 1)
        {
            flag = 1;
            *puntero = aux;
        }
    return flag;
}

int utn_getInt(int *puntero, char mensaje[], char mensajeError[], int min, int max, int intentos)
{
    int control;
    int flag = 0;
    int aux;
    printf("%s", mensaje);
    control = scanf("%d", &aux);
    intentos--;
    while((control != 1 || aux < min || aux > max) && intentos>=1)
        {
            printf("%s", mensajeError);
            fflush(stdin);
            control = scanf("%d", &aux);
            intentos--;
        }
    if(control == 1)
        {
            flag = 1;
            *puntero = aux;
        }
    return flag;
}

void utn_functionGetString (char msj[],char input[])
{
    printf("%s",msj);
    fflush(stdin) ;
    gets(input) ;
}

int validStrArray(char string[])
{
    int aux;
    int contador;
    for(contador = 0; contador < strlen(string); contador++)// recorre el array.
        {
        if(!(isalpha(string[contador]))) //isalpha Indica si un carácter es alfabético.
            {
                aux = 0; //Algún caracter no es letra.
                break;
            }
            aux = 1; //Todos los caracteres son letras.
        }
    return aux;
}


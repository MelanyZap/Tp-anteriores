#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
int valorA=0;
int valorB=0;
int resultadoSuma;
int resultadoResta;
int resultadoMultiplicacion;
float resultadoDivision;
double resultadoFactorialA;
double resultadoFactorialB;
int opcionElegida;

while(opcionElegida!=5)
{
    mostrarMenu(valorA,valorB);
    utn_tomarOpcion(&opcionElegida);
    switch(opcionElegida)
    {
        case 1:
            utn_ingresarOperando(&valorA);
            break;
        case 2:
            utn_ingresarOperando(&valorB);
            break;
        case 3:
            utn_calcularTodasLasOperaciones(valorA,valorB,&resultadoSuma,&resultadoResta,&resultadoMultiplicacion,&resultadoDivision,&resultadoFactorialA,&resultadoFactorialB);
            break;
        case 4:
            utn_mostrarResultados(valorA,valorB,resultadoSuma,resultadoResta,resultadoMultiplicacion,resultadoDivision,resultadoFactorialA,resultadoFactorialB);
            break;
    }
}
    return 0;
}


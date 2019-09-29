#include <stdio.h>
#include <stdlib.h>

/**
 * \brief muestra el menu de opciones
 * \param valorA primer valor que se guarda en A=0
 * \param valorB primer valor que se guarda en B=0
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int mostrarMenu(int valorA, int valorB)
{
    printf("\n1.Ingresar primer operando (A=%d)",valorA);
    printf("\n2.Ingresar segundo operando (B=%d)",valorB);
    printf("\n3.Calcular todas las operaciones");
    printf("\n4.Informar resultados");
    printf("\n5.Salir");
    printf("\nIngrese una opcion: ");
    return 0;
}
/**
 * \brief guarda el valor de la opcion elegida por el usuario
 * \param opcionElegida opcion que eligio el usuario
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int utn_tomarOpcion(int* opcionElegida)
{
    int auxiliarOpcion=0;
    scanf("%d",&auxiliarOpcion);
    if(auxiliarOpcion>0 && auxiliarOpcion<=5)
    {
        //Guardar en la Opcion Elegida
        *opcionElegida = auxiliarOpcion;
    }else{
        printf("\nError, opcion invalida.Ingrese nuevamente: ");
    }
    return 0;
}
/**
 * \brief el usuario ingresa el int y se guarda
 * \param operando donde se guarda el valor
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int utn_ingresarOperando(int* operando)
{
    int auxiliarOperando=0;
    scanf("%d",&auxiliarOperando);
    *operando = auxiliarOperando;
    return 0;
}
/**
 * \brief calcula el factorial de un numero
 * \param valor es el valor a ser calculado
 * \param resultadoFactorial guarda el resultado del calculo
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int utn_calcularFactorial(int valor,double* resultadoFactorial)
{
    int i;
    double factorial=1;
    //si valor igual 0, factorial igual 1. Si no calcular con el for.
    if(valor==0)
    {
        factorial=1;
    }else{
    for(i=1;i<=valor;i++)
    {
        factorial=factorial*i;
    }
    }
    *resultadoFactorial = factorial;
    return 0;
}
/**
 * \brief calcula todas las operaciones
 * \param valorA primer valor ingresado
 * \param valorB segundo valor ingresado
 * \param resultadoSuma calcula A+B
 * \param resultadoResta calcula A-B
 * \param resultadoMultiplicacion calcula A*B
 * \param resultadoDivision calcula A/B
 * \param resultadoFactorialA calcula el factorial del valorA
 * \param resultadoFactorialB calcula el factorial del valorB
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int utn_calcularTodasLasOperaciones(int valorA,int valorB,int* resultadoSuma,int* resultadoResta,int* resultadoMultiplicacion,float* resultadoDivision,double* resultadoFactorialA,double* resultadoFactorialB)
{
    *resultadoSuma = valorA+valorB;
    *resultadoResta = valorA-valorB;
    *resultadoMultiplicacion = valorA*valorB;
    if(valorB!=0)
    {
        *resultadoDivision = valorA/valorB;
    }
    utn_calcularFactorial(valorA,resultadoFactorialA);
    utn_calcularFactorial(valorB,resultadoFactorialB);
    system("PAUSE");
    return 0;
}
/**
 * \brief calcula todas las operaciones
 * \param valorA primer valor ingresado
 * \param valorB segundo valor ingresado
 * \param resultadoSuma muestra el resultado de A+B
 * \param resultadoResta muestra el resultado de A-B
 * \param resultadoMultiplicacion muestra el resultado de A*B
 * \param resultadoDivision muestra el resultado de A/B
 * \param resultadoFactorialA muestra el factorial del valorA
 * \param resultadoFactorialB muestra el factorial del valorB
 * \return devuelve 0 si esta todo bien, devuelve -1 si esta mal
 */
int utn_mostrarResultados(int valorA, int valorB,int resultadoSuma,int resultadoResta,int resultadoMultiplicacion,float resultadoDivision,double resultadoFactorialA,double resultadoFactorialB)
{
    printf("\nEl resultado de la suma es: %d",resultadoSuma);
    printf("\nEl resultado de la resta es: %d",resultadoResta);
    printf("\nEl resultado de la multiplicacion es %d",resultadoMultiplicacion);
    if(valorB!=0)
    {
        printf("\nEl resultado de la division es: %.2f",resultadoDivision);
    }else{
        printf("\nNo es posible dividir por cero");
    }
    printf("\nEl factorial de %d es: %.2f",valorA,resultadoFactorialA);
    printf(" y el factorial de %d es: %.2f",valorB,resultadoFactorialB);
    return 0;
}



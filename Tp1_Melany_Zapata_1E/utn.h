#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int mostrarMenu(int valorA, int valorB);
int utn_tomarOpcion(int* opcionElegida);
int utn_ingresarOperando(int* operando);
int utn_calcularTodasLasOperaciones(int valorA,int valorB,int* resultadoSuma,int* resultadoResta,int* resultadoMultiplicacion,float* resultadoDivision,double* resultadoFactorialA,double* resultadoFactorialB);
int utn_mostrarResultados(int valorA, int valorB,int resultadoSuma,int resultadoResta,int resultadoMultiplicacion,float resultadoDivision,double resultadoFactorialA,double resultadoFactorialB);
int utn_calcularFactorial(int valor,double* resultadoFactorial);
//
#endif // UTN_H_INCLUDED

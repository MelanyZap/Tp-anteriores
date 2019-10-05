#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define TAM_MAXs 3
#define TAM_MAXe 1000

int main()
{
    eEmployee employee[TAM_MAXe];
    initEmployees(employee,TAM_MAXe);
    eSector sector[TAM_MAXs];
    sectors(sector);
    int id;
    int continuar = 1;
    int increment;
    int valid;
    float total;
    float promedio;
    do{
        switch(menu())
        {
            case 1: addEmployee(employee,TAM_MAXe,sector,TAM_MAXs,&increment);
                    break;

            case 2: valid = validEmployee(employee,TAM_MAXe);
                    if(valid == -1)
                    {
                        printf("\nPrimero dar un alta un empleado.\n\n");
                        system("pause");
                    }
                    else
                    {
                        printEmployees(employee,TAM_MAXe,sector,TAM_MAXs);
                        system("pause");
                        valid = modifyEmployee(employee,TAM_MAXe,&id,sector,TAM_MAXs);
                        if(valid == -1)
                        {
                            printf("No existe empleado con el id: %d",id);
                        }
                        else if(valid == 0)
                        {
                            printf("La modificacion se ha cancelado.\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("La modificacion se ha realizado con exito!!!\n\n");
                            system("pause");
                        }
                    }
                    break;

                    case 3: valid = validEmployee(employee,TAM_MAXe);
                            if(valid == -1)
                            {
                                printf("\nPrimero da de alta un empleado\n\n");
                                system("pause");
                            }
                            else
                            {
                                valid = removeEmployee(employee,TAM_MAXe,id,sector,TAM_MAXs);
                                if(valid == -1)
                                {
                                    printf("No existe empleado con el id: %d",id);
                                }
                                else if(valid == 0)
                                {
                                    printf("La baja ha sido cancelada.\n\n");
                                    system("pause");
                                }
                                else
                                {
                                    printf("La baja de empleado se ha realizado con exito!!!\n\n");
                                    system("pause");
                                }
                            }
                            break;

                    case 4: valid = validEmployee(employee, TAM_MAXe);
                            if(valid == -1)
                            {
                                printf("Primero da de alta un empleado\n\n");
                                system("pause");
                            }
                            else
                            {
                                int continuar = 1;
                                do{
                                    switch(menuInformes())
                                    {
                                        case 1: sortEmployees(employee,TAM_MAXe,1);
                                                printEmployees(employee,TAM_MAXe,sector,TAM_MAXs);
                                                system("pause");
                                                break;

                                        case 2: total = totalSalary(employee,TAM_MAXe);
                                                promedio = promedioSalary(employee,TAM_MAXe);
                                                printf("El total de salarios es: %.2f \n\n",total);
                                                printf("El promedio de salario: %.2f \n\n",promedio);
                                                printf("Los empleados que superan el promedio son: \n\n");
                                                higherSalary(employee,TAM_MAXe,promedio);
                                                system("pause");
                                                break;

                                        case 3: continuar = 0;
                                                break;

                                        default: printf("\n Error. Caracter invalido.\n\n");
                                                 system("pause");
                                                 break;
                                    }
                                    }while(continuar);
                            }
                            break;
                                        case 5: continuar = 0;
                                                break;

                                        default: printf("\nError. Caracter invalido\n\n");
                                                system("pause");
                                                break;
            }
        }while(continuar);
    return 0;
}

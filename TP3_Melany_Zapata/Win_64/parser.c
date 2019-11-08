#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    char auxId[1024];
    char auxNombre[1024];
    char auxHorasTrabajadas[1024];
    char auxSueldo[1024];
    int flag = 1;
    int retorno = -1;
    while(!feof(pFile)) //mientras no sea el final del archivo
    {
        if(flag)
        {
            fscanf(pFile,"%s\n", auxId);
            flag = 0;
        }
        else if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo) == 4)
        {
            auxiliar = employee_newParametros(auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(auxiliar != NULL)
            {
                ll_add(pArrayListEmployee, auxiliar);
                retorno = 0;
            }
        }
        else
        {
            break;
        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int retorno = -1;
    int cantidad;
    do
    {
        auxiliar = employee_new();
        cantidad = fread(auxiliar, sizeof(Employee), 1, pFile); //lee
        if(auxiliar != NULL && cantidad == 1)
        {
            ll_add(pArrayListEmployee, auxiliar);
            retorno = 0;
        }
    }while(!feof(pFile));
    return retorno;
}

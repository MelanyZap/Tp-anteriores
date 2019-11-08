#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "input.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList* puntero en donde se buscaran los datos.
 * \return retorna 0 si salio todo bien, -1 si hay un error.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    pFile = fopen(path,"r");
    int retorno = 0;
    if(parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
    {
        printf("Se cargaron los datos correctamente.");
        retorno = 0;
    }
    else
    {
        printf("Error, los datos no se pudieron cargar.");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 si salio todo bien, -1 si hay un error.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    int retorno = -1;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("Los datos se cargaron exitosamente!!!\n");
        retorno = 0;
    }
    else
    {
        printf("Error, los datos no se pudieron cargar.\n");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Agrega un nuevo empleado.
*\param pArrayLinkedList va a recibir el array en donde se van a cargar los datos del empleado.
*\return retorna 0 si salio todo bien, -1 si hay un error.
*/
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_addEmployee(pArrayListEmployee) == 0)
    {
        printf("El nuevo empleado ha sido agregado correctamente.");
        retorno = 0;
    }
    else
    {
        printf("El nuevo empleado no ha podido ser agregado correctamente.");
    }
    return retorno;
}

/**\brief Recibe una LinkedList y un id para saber si existe ese mismo id o en que posicion se encuentra.
*\param pArrayEmployee, va a ser el array a recorrer.
*\param idE, va a ser el id del empleado y se va a ir comparando hasta que encuentra el mismo en la lista.
*\return retorna la posicion del array donde se encontro el id del empleado.
*/

int controller_buscarPorId(LinkedList* pArrayListEmployee, int idE)
{
    Employee* auxiliar;
    int i;
    int tam = ll_len(pArrayListEmployee);
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        for(i = 0; i < tam; i++)
        {
            auxiliar = (Employee*)ll_get(pArrayListEmployee, i);
            if(auxiliar != NULL && auxiliar->id == idE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Modifica los datos de un empleado
 * \param pArrayLinkedList va a recibir un array en donde se va a modificar.
 * \return retorna 0 si salio todo bien, -1 si hay un error.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int id;
    int index;
    char nombreAux[1050];
    int horas;
    int sueldoAux;
    int retorno = -1;
    if(pArrayListEmployee != NULL && utn_getEnteroSinLimites(&id,5,"\nIngrese el id del empleado que desear modificar: \n","\nEl id es invalido\n") == 0)
    {
        index = controller_buscarPorId(pArrayListEmployee,id);
        if(index >= 0)
        {
            auxiliar = ll_get(pArrayListEmployee,index);
            if(utn_getNombre(nombreAux,"Ingrese nuevo nombre del empleado: \n","\nError, nombre invalido\n") ==0 &&
               utn_getEnteroSinLimites(&horas,5,"\nIngrese las nuevas horas trabajadas por el empleado: \n","\nError, Re: \n") == 0 &&
                utn_getEnteroSinLimites(&sueldoAux,5,"\nIngrese el nuevo sueldo del empleado: \n", "\nError, Re: \n") == 0)
            {
                auxiliar->horasTrabajadas = horas;
                auxiliar->sueldo = sueldoAux;
                strcpy(auxiliar->nombre,nombreAux);
                retorno = 0;
            }
        }
        else
        {
            printf("Error, el id ingresado no existe en la lista.");
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 * \param pArrayListEmployee, va a recibir el array en el que se borrara el dato del empleado.
 * \return retorna 0 si salio todo bien, -1 si hay un error.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    int idE;
    int id;
    int retorno = -1;
    if(pArrayListEmployee != NULL && utn_getEnteroSinLimites(&idE, 10, "Ingrese el id que desea borrar: /n", "Error, id incorrecto./n") == 0)
    {
        id = controller_buscarPorId(pArrayListEmployee,idE);
        if(id >= 0)
        {
            auxiliar = ll_get(pArrayListEmployee,id);
            if(employee_delete(auxiliar) == 0)
            {
                retorno = 0;
                ll_remove(pArrayListEmployee,id);
            }
        }else
        {
            printf("El Id ingresado no existe./n");
        }
    }
    return retorno;
}

/**\brief Listado de empleados con sus datos
*\param pArrayLinkedList, va a recibir el array que se va a mostrar.
*/
void controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    char auxNombre[1050];
    int auxId;
    int auxHoras;
    int auxSueldo;
    int tam;
    int i;
    tam = ll_len(pArrayListEmployee);
    if(tam > 0)
    {
        for(i = 0; i < tam; i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            if(employee_getId(auxiliar, &auxId) == 0 && employee_getNombre(auxiliar, auxNombre) == 0 && employee_getHorasTrabajadas(auxiliar, &auxHoras) == 0 &&
                employee_getSueldo(auxiliar, &auxSueldo) == 0)
            {
                printf("Id: %d  Nombre: %s  Horas Trabajadas: %d  Sueldo: %d \n", auxId, auxNombre, auxHoras, auxSueldo);
            }
            else
            {
                printf("\nError. No se pudo mostrar la lista de empleados.\n");
            }
        }
    }
    else
    {
        printf("\nError.\n");
    }
}

/** \brief Ordenar empleados
 * \param pArrayListEmployee, va a recibir el array en donde se va a guardar.
 * \return retorna un 1 si salio todo bien o retorna 0 si hay un error.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    if(pArrayListEmployee != NULL)
    {
        employee_ordenarLista(pArrayListEmployee);
        retorno = 1;
    }
    return retorno;
}

/**\brief Guarda los datos de la LinkedList en el archivo de modo texto.
*\param pArrayListEmployee, va a recibir el array que se va a guardar.
*\param path, donde se guardaron los datos.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    FILE* pFile = fopen(path,"w");
    int i;
    int tam;
    tam = ll_len(pArrayListEmployee);
    int retorno = -1;
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < tam; i++)
        {
            auxiliar = ll_get(pArrayListEmployee,i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxiliar->id, auxiliar->nombre, auxiliar->horasTrabajadas, auxiliar->sueldo);
        }
    }
    fclose(pFile);
    return retorno;
}

/**\brief Guarda los datos de la LinkedList en el archivo de modo binario
*\param pArrayLinkedListRecibe el array a guardar.
*\param path, donde se guardaran los datos.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    FILE* pFile = fopen(path,"wb");
    int i;
    int retorno = -1;
    int tam = ll_len(pArrayListEmployee);
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < tam; i++)
        {
            auxiliar = ll_get(pArrayListEmployee, i);
            fwrite(auxiliar, sizeof(Employee), 1, pFile);
        }
    }
    fclose(pFile);
    return retorno;
}


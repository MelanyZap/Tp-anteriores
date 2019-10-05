#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#include "input.h"

/** \brief Muestra el menu de opciones principal.
 * \return retorna la opcion elegida por el usuario.
 */
int menu()
{
    int option;
    char aux[2];
    system("cls");
    printf("1.Alta de empleado\n");
    printf("2.Modificar empleado\n");
    printf("3.Baja de empleado\n");
    printf("4.Informar empleados\n");
    printf("5.Salir\n");
    while(!utn_getStringNum("Elija la opcion que quiere realizar: ",aux))
    {
        printf("\nError. Re\n");
        system("pause");
    }
    option = atoi(aux); //convierte en entero
    return option;
}

/** \brief Muestra el menu de opciones de modificacion de empleado.
* \param list es el array empleados.
* \param index es la posicion que tiene el empleado en el array.
* \param sector es el array de sector(existentes).
* \param lenS tamañao del array sector.
* \return valid -1 si es error, 0 si salio todo bien.
*
*/
int menuModify(eEmployee list[], int index, eSector sector[], int lenS)
{
    char newName[TAM_MAX];
    char newLastName[TAM_MAX];
    float newSalary;
    int newSector;
    int valid;
    int option;
    system("cls");
    printf(" 1.Modificar nombre\n");
    printf(" 2.Modificar apellido\n");
    printf(" 3.Modificar sueldo\n");
    printf(" 4.Modificar sector\n\n");
    valid = utn_getInt(&option, "Ingrese la opcion ha realizar: ", "Error,Re",1,4,5);
    switch(option)
    {
        case 1: valid = utn_getString(newName,"\nIngrese nuevo nombre del empleado: ","\nError,Re",3,TAM_MAX,5);
                strcpy(list[index].name, newName);
                break;

        case 2: valid = utn_getString(newLastName, "\nIngrese nuevo apellido del empleado: ", "\nError,Re: ",3,TAM_MAX,5);
                strcpy(list[index].lastName, newLastName);
                break;

        case 3: valid = utn_getFloat(&newSalary, "\nIngrese nuevo sueldo del empleado: ", "\nError,Re: ",2000,100000,5);
                list[index].salary = newSalary;
                break;

        case 4: listSectors(sector, lenS);
                valid = utn_getInt(&newSector, "\nIngrese nuevo sector del empleado: ", "\nError,Re: ",1,3,5);
                list[index].sector = newSector;
                break;
    }
    return valid;
}

/** \brief Muestra el menu de opciones de Informes.
 * \return retorna la opcion elegida por el usuario.
 *
 */
int menuInformes()
{
    int option;
    char aux[2];
    system("cls");
    printf("1.Listado de empleados\n");
    printf("2.Total y promedio de los salarios, empleados superan el salario promedio.\n");
    printf("3.Salir\n");
    while(!utn_getStringNum("Elija la opcion que quiere realizar ",aux))
    {
        printf("\nError,Re:");
        system("pause");

    }
    option = atoi(aux);
    return option;
}

/** \brief Inicializa todo el array en LIBRE(vacio).
* \param list es el array de empleados.
* \param len tamaño del array.
*
*/
void initEmployees(eEmployee list[], int len)
{
    int i;
    for(i = 0; i < len; i++)
    {
        list[i].isEmpty = LIBRE;
    }
}

/** \brief Indica que posiciones del array van a estar vacias, LIBRE(lugares vacios).
* \param list es el array de empleados.
* \param len tamaño del array.
* \return index -1 si es error, 0 si salio todo bien.
*
*/
int searchFree(eEmployee list[], int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == LIBRE) //
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Carga los sectores existentes.
* \param sectores es el array sector.
*
*/
void sectors(eSector sector[])
{
    int i;
    eSector sectors[] =
    {
        {1, "Compras"},
        {2, "RRHH"},
        {3, "Sistemas"}
    };

    for(i = 0; i < 3; i++)
    {
        sector[i] = sectors[i];
    }
}

/** \brief Recorre el array. Muestra los sectores existentes.
* \param sector es el array de sector.
* \param len tamaño del array.
*
*/
void listSectors(eSector sector[], int len)
{
    int i;
    printf("\nID    Descripcion\n\n");
    for(i = 0; i< len; i++)
    {
      printf("%d   %10s\n", sector[i].id,sector[i].descripcion);
    }
}

/** \brief Agrega un empleado en la primera posicion libre.
* \param list es el array de empleados.
* \param len tamaño del array de empleado.
* \param sector es el array de sector.
* \param lenS tamaño del array de sector.
* \param *increment direccion de memoria donde se va a guardar el id del empleado.
* \return retorno -1 si es error, 0 si salio todo bien.
*
*/
int addEmployee(eEmployee list[], int len, eSector sector[], int lenS, int *increment)
{
    eEmployee newEmp;
    int index;
    int retorno = -1;
    char continuar;
    int valid;
    index = searchFree(list, len);
    if(index == -1)
    {
        valid = -1;
    }
    else
    {
        newEmp.id = index+1;
        valid = utn_getString(newEmp.name, "Ingrese el nombre del empleado: ", "Error,Re",3,TAM_MAX,5);
        if(valid == 0)
        {
            printf("Error.\n");
        }
        else
        {
            valid = utn_getString(newEmp.lastName, "Ingrese el apellido del empleado: ", "Error,Re ",3,TAM_MAX,5);
            if(valid == 0)
            {
                printf("Error.\n");
            }
            else
            {
                valid = utn_getFloat(&newEmp.salary, "Ingrese el sueldo del empleado: ", "Error,Re",2000,100000,5);
                if(valid == 0)
                {
                    printf("Error.\n");
                }
                else
                {
                    listSectors(sector,lenS);
                    valid = utn_getInt(&newEmp.sector, "Ingrese el sector: ", "Error,Re",1,3,5);
                    if(valid == 0)
                    {
                        printf("Error.\n");
                    }
                    else
                    {
                        printf("\nEsta seguro que quiere dar de alta este empleado? s(si)/n(no): ");
                        fflush(stdin);
                        scanf("%c", &continuar);
                        if(continuar == 'n')
                        {
                            printf("El alta del empleado ha sido cancelada\n\n");
                        }
                        else
                        {
                            newEmp.isEmpty = OCUPADO;
                            (*increment)++;
                            newEmp.id = *increment;
                            list[index] = newEmp;
                            printf("\nEl empleado ha sido dado de alto con exito!!!\n\n");
                            retorno = 0;
                        }
                        system("pause");
                    }
                }
            }
        }
    }
    return retorno;
}

/** \brief Busca al empleado por su Id.
* \param list es el array de empleados.
* \param len tamaño del array de empleado.
* \param idEmp es el id del empleado.
* \return index -1 si es error, 0 si salio todo bien.
*
*/
int findEmployeeById(eEmployee list[], int len, int idEmp)
{
    int i;
    int index = -1;
    for(i = 0; i < len; i++)
    {
        if(list[i].id == idEmp && list[i].isEmpty == OCUPADO)
        {
            index = i;
            break;
        }
    }
    return index;
}

/** \brief Descripcion del sector.
* \param sector es el array de sector.
* \param len tamaño del array de sector.
* \param idS es el id perteneciente del sector.
* \param string es el array del destino de la descripcion del sector.
*
*/
void getSector(eSector sector[], int len, int idS, char string[])
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(sector[i].id == idS)
        {
            strcpy(string,sector[i].descripcion);
        }
    }
}

/** \brief Muestra los datos del empleado.
* \param list es el array de empleados.
* \param sector es el array de sector.
* \param lenS es el tamaño del array de sector.
*
*/
void showEmployee(eEmployee list, eSector sector[], int lenS)
{
    char description[TAM_MAXd];
    getSector(sector,lenS,list.sector,description);
    printf("%5d %10s %10s  %6.2f %10s\n", list.id,list.name,list.lastName,list.salary,description);
}

/** \brief Busca si existen empleados.
* \param list es el array de empleados.
* \param len es el tamaño del array.
* \return valid -1 si es error, 0 si salio todo bien.
*
*/
int validEmployee(eEmployee list[], int len)
{
    int valid = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            valid = i;
            break;
        }
    }
    return valid;
}

/** \brief Modifica los datos del empleado.
* \param list es el array de empleado.
* \param len es el tamaño del array de empleados.
* \param *idEmp es el puntero al id.
* \param sector es el array de sector.
* \param lenS es el tamaño del array de sector.
* \return retorno -1 si es error, 0 si salio todo bien.
*
*/
int modifyEmployee(eEmployee list[], int len, int *idEmp, eSector sector[], int lenS)
{
    int index;
    char continuar;
    int valid;
    int retorno;
    valid = utn_getInt(idEmp,"\nIngrese id del empleado: ","\nError,Re: ",1,20000,5);
    if(valid != 1)
    {
        retorno = 0;
        printf("Error de id.");
        system("pause");
    }
    else
    {
        index = findEmployeeById(list,len,*idEmp);
        if(index == -1)
        {
            retorno = -1;
        }
        else
        {
            printf("Id  Nombre  Apellido  Sueldo  Sector\n");
            showEmployee(list[index],sector,lenS);
            printf("\n¿Esta seguro que quiere modificar? s(si)/n(no): ");
            fflush(stdin);
            scanf("%c",&continuar);
            while(!(continuar == 's' || continuar == 'n'))
            {
                printf("Error,Re:");
                fflush(stdin);
                scanf("%c", &continuar);
            }
            if(continuar == 'N' || continuar == 'n')
            {
                retorno = 0;
            }
            else
            {
                retorno = menuModify(list,index,sector,lenS);
            }
        }
    }
    return retorno;
}

/** \brief Elimina un empleado, recibiendo su id como parametro.
* \param list es el array de empleados.
* \param len es el tamaño del array de empleados.
* \param idEmp es el id perteneciente al empleado.
* \param sector es el array de sector.
* \param lenS es el tamaño del array de sector.
* \return retorno -1 si es error, 0 si salio todo bien.
*
*/
int removeEmployee(eEmployee list[], int len, int idEmp, eSector sector[], int lenS)
{
    int index;
    char continuar;
    int valid;
    int retorno;
    system("cls");
    valid = utn_getInt(&idEmp, "\nIngrese id del empleado: ", "Error,Re: ",1,20000,5);
    if(valid != 1)
    {
        retorno = 0;
        printf("Error de id.");
    }
    else
    {
        index = findEmployeeById(list,len,idEmp);
        if(index == -1)
        {
            retorno = -1;
        }
        else
        {
            printf("   Id     Nombre     Apellido     Sueldo     Sector\n");
            showEmployee(list[index],sector,lenS);
            printf("\n¿Esta seguro que quiere dar de baja un empleado? s(si)/n(no): ");
            fflush(stdin);
            scanf("%c", &continuar);
            while(!(continuar == 'n' || continuar == 'N' || continuar == 's' || continuar == 'S'))
            {
                printf("Error,Re: ");
                fflush(stdin);
                scanf("%c", &continuar);
            }
            if(continuar == 'N' || continuar == 'n')
            {
                retorno = 0;
            }
            else
            {
                list[index].isEmpty = LIBRE;
                retorno = 1;
            }
        }
    }
    return retorno;
}

/** \brief Imprime el array de empleados.
* \param list es el array de empleados.
* \param len es el tamaño del array de empleados.
* \param sector es el array de sector.
* \param lenS es el tamaño del array de sector.
*
*/
void printEmployees(eEmployee list[], int len, eSector sector[], int lenS)
{
    int i;
    system("cls");
    printf("Id     Nombre     Apellido     Sueldo     Sector\n\n");
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            showEmployee(list[i],sector,lenS);
        }
    }
    printf("\n\n");
}

/** \brief Odena el array de empleados por apellido y sector de manera ascendente o descendente.
* \param list es el array de empleados.
* \param len es el tamaño del array.
* \param option (1) ordena de forma Ascendente, (0) ordena de forma Descendente.
*
*/
void sortEmployees(eEmployee list[], int len, int option)
{
    int i;
    int j;
    eEmployee aux;

    for(i = 0; i < len - 1; i++)
    {
        if(list[i].isEmpty == 1)
        {
            continue;
        }
        for(j = i + 1; j < len; j++)
        {
            if(list[j].isEmpty == 1)
            {
                continue;
            }
            switch(option)
            {
                case 0:
                        if(strcmp(list[i].lastName,list[j].lastName) < 0) //d
                        {
                            aux = list[i];
                            list[i]= list[j];
                            list[j] = aux;
                        }
                        break;

                case 1:
                        if(strcmp(list[i].lastName,list[j].lastName) > 0) //a
                        {
                            aux = list[i];
                            list[i] = list[j];
                            list[j] = aux;
                        }
                        break;
            }

            if(strcmp(list[i].lastName,list[j].lastName) == 0)
            {
                if(list[i].sector > list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j]= aux;
                }
            }
        }
    }
}

/** \brief Guarda los salarios de los empleados pero antes recorre el array.
* \param list es el array de empleados.
* \param len es el tamaño del array empleados.
* \return salary acumula todos los salarios de los empleados.
*
*/
float totalSalary(eEmployee list[], int len)
{
    int i;
    float salary = 0;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            salary = salary + list[i].salary;
        }
    }
    return salary;
}

/** \brief Cuenta la cantidad de empleados existentes.
* \param list es el array de empleados.
* \param len es el tamaño del array de empleados.
* \return qty cantidad de empleados existentes.
*
*/
int qtyEmployees(eEmployee list[], int len)
{
    int qty = 0;
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO)
        {
            qty++;
        }
    }

    return qty;
}

/** \brief Calcula el promedio del salario total de los empleados.
* \param list es el array de empleados.
* \param len es el tamaño del array de empleado.
* \return promedio retorna el promedio de todos los salarios.
*
*/
float promedioSalary(eEmployee list[], int len)
{
    int qty;
    float total;
    float promedio;
    qty = qtyEmployees(list,len);
    total = totalSalary(list,len);
    promedio = total / qty;
    return promedio;
}

/** \brief Muestra los empleados que superan el promedio de salarios.
* \param list es el array de empleados.
* \param len es el tamaño del array de empleados.
* \param promedio es el promedio de salario.
*
*/
void higherSalary(eEmployee list[], int len, float promedio)
{
    int i;
    for(i = 0; i < len; i++)
    {
        if(list[i].isEmpty == OCUPADO && list[i].salary >= promedio)
        {
            printf("Sueldo: %.2f",list[i].salary);
            printf("Empleado: %s %s\n",list[i].lastName,list[i].name);
        }
    }
}

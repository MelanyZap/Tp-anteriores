#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "controller.h"

/**\brief Crea un nuevo espacio en la memoria.
* \return retorna la nueva direccion de memoria creada.
*/
Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/**\brief Crea un nuevo espacio en memoria y setea los datos.
*\param idStr, cadena de caracteres en donde se va a guardar el id del empleado.
*\param nombreStr, cadena de caracteres en donde se va a guardar el nombre del empleado.
*\param horasTrabajadasStr, cadena de caracteres en donde se va a guardar las horas trabajadas por el empleado.
*\param sueldoStr, cadena de caracteres en donde se va a guardar el sueldo del empleado.
*\return retorna la nueva direccion de memoria creada.
*/
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL || employee_setId(this, idStr) || employee_setNombre(this, nombreStr) || employee_setHorasTrabajadas(this, horasTrabajadasStr) ||
        employee_setSueldo(this, sueldoStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

/**\brief Borra un espacio en la memoria creada.
*\param this, espacio en la memoria que se va a borrar.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe el nombre del empleado para guardarlo.
*\param this, es un espacio de memoria de tipo Employee.
*\param nombre, cadena de caracteres un nombre.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && validName(nombre) == 0)
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

/**\brief Busca un nombre y se devuelve ese nombre.
*\param this, espacio de memoria de tipo Employee.
*\param nombre, cadena de caracteres donde se guardara un nombre.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL) //en this se busca
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/**\brief Valida que la cadena de caracteres que recibio sea solo letras.
*\param nombre, cadena de caracteres que se va a validar.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/
int validName(char* nombre)
{
    int retorno = -1;
    if(utn_isLetra(nombre) == -1)
    {
        printf("\nEl nombre ingresado no es valido.\n");
        printf("\n%s\n", nombre);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe la cantidad de horas trabajadas por el empleado y las guarda.
*\param this, espacio de memoria de tipo Employee.
*\param horasTrabajadas va a ser la cadena de caracteres con las horas trabajadas por el empleado
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && validHorasTrabajadas(horasTrabajadas) == 0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe un dato donde se va a buscar las horas trabajadas por el empleado y devolvera la cantidad de las mismas.
*\param this, espacio de memoria de tipo Employee.
*\param horasTrabajadas es el puntero en donde se guardas las horas.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/**\brief Valida que las horas trabajadas sean solo numeros.
*\param horasTrabajadas es la cadena de caracteres que se va a validar.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int validHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = -1;
    if(utn_isInt(horasTrabajadas) == -1)
    {
        printf("\nError, las horas trabajadas no son validas. Ingrese solo numeros\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe el salario del empleado y lo guarda.
*\param this, espacio de memoria de tipo Employee.
*\param sueldo, cadena de caracteres con el salario del empleado.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_setSueldo(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL && validSueldo(sueldo) == 0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe un dato donde se va a buscar el salario, y se devolvera el mismo.
*\param this, espacio de memoria de tipo Employee.
*\param sueldo, es un puntero donde se guardara el salario.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/**\brief Valida que el salario ingresado sea solo numeros.
*\param sueldo, cadena de caracteres que se va a validar.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int validSueldo(char* sueldo)
{
    int retorno = -1;
    if(utn_isInt(sueldo) == -1)
    {
        printf("\nEl sueldo ingresado no es valido. Ingrese solo numeros.\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**\brief Recibe un id del empledo y se guarda.
*\param this, espacio de memoria de tipo Employee.
*\param id, cadena de caracteres con el id del empleado.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_setId(Employee* this, char* id)
{
    int retorno = -1;
    static int siguienteId = -1; //lo almaceno en la memoria de forma estatica(automaticamente)
    int aux;
    if(this != NULL && validId(id) == 0)
    {
        aux = atoi(id);
        if(aux == -1)
        {
            siguienteId++;
            this->id = siguienteId;
            retorno = 0;
        }else if(aux > siguienteId)
        {
            siguienteId = aux;
            this->id = siguienteId;
            retorno = 0;
        }
    }
    return retorno;
}

/**\brief Recibe un dato donde se busca el id y se devuelve el mismo.
*\param this, espacio de memoria de tipo Employee.
*\param id, puntero en donde se va a guardar el id.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/**\brief Valida que el id sea solo numeros.
*\param id, cadena que se va a validar.
*\return retorna un 0 si salio todo bien o retorna -1 si hay un error.
*/

int validId(char* id)
{
    int retorno = -1;
    if(utn_isIntConGuiones(id) == -1)
    {
        printf("\nEl id ingresado es invalido. Ingrese solo numeros\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**\brief Compara dos nombres y los ordena.
*\param thisUno, dato que se va a comparar.
*\param thisDps, dato que se va a comparar.
*\return retorna un 1 si salio todo bien o retorna -1 si hay un error.
*/

int employee_ordenarNombre(void* thisUno,void* thisDos)
{
    char nombreUno[1050];
    char nombreDos[1050];
    int retorno = 0;
    employee_getNombre((Employee*)thisUno,nombreUno);
    employee_getNombre((Employee*)thisDos,nombreDos);
    if(strcmp(nombreUno,nombreDos) > 0)
    {
        retorno = 1;

    }else if(strcmp(nombreUno,nombreDos) < 0)
    {
        retorno = -1;
    }
    return retorno;
}

/**\brief Compara id del empleado y los ordena.
*\param auxUno, dato que se va a comparar.
*\param auxDos, dato que se va a comparar.
*\return retorna un 1 si salio todo bien o retorna -1 si hay un error.
*/
int employee_ordenarId(void* auxUno,void* auxDos)
{
    int idUno;
    int idDos;
    int retorno = 0;
    employee_getId(auxUno,&idUno);
    employee_getId(auxDos,&idDos);
    if(idUno > idDos)
    {
        retorno = 1;
    }
    else if(idUno < idDos)
    {
        retorno = -1;
    }
    return retorno;
}

/**\brief Compara las horas trabajadas del empleado y lo ordena.
*\param auxUno, dato que se va a comparar.
*\param auxDos, dato que se va a comparar.
*\return retorna un 1 si salio todo bien o retorna -1 si hay un error.
*/
int employee_ordenarHoras(void* auxUno,void* auxDos)
{
    int horaUno;
    int horaDos;
    int retorno = 0;
    employee_getHorasTrabajadas(auxUno,&horaUno);
    employee_getHorasTrabajadas(auxUno,&horaDos);
    if(horaUno > horaDos)
    {
        retorno = 1;
    }
    else if(horaUno < horaDos)
    {
        retorno = -1;
    }
    return retorno;
}

/**\brief Compara el salario del empleado y lo ordena.
*\param auxUno, dato que se va a comparar.
*\param auxDos, dato que se va a comparar.
*\return retorna un 1 si salio todo bien o retorna -1 si hay un error.
*/
int employee_ordenarSalario(void* auxUno,void* auxDos)
{
    int sueldoUno;
    int sueldoDos;
    int retorno = 0;
    employee_getSueldo(auxUno,&sueldoUno);
    employee_getSueldo(auxDos,&sueldoDos);
    if(sueldoUno > sueldoDos)
    {
        retorno = 1;
    }
    else if(sueldoUno < sueldoDos)
    {
        retorno = -1;
    }
    return retorno;
}

/**\brief ordena los datos de los empleados
*\param pArrayListEmployee, va a ser donde se guardara.
*\return retorna un 1 si salio todo bien o retorna -1 si hay un error.
*/
int employee_ordenarLista(LinkedList* pArrayListEmployee)
{
    int option;
    int retorno = 0;
    if(pArrayListEmployee != NULL)
    {
        printf("\n1.Ordenar id del empleado de forma ascendente.\n2.Ordenar el id del empleado de forma descendente.\n3.Ordenar nombre de los empleados de forma ascendente.\n4.Ordenar nombre de los empleados de forma descendente.\n5.Ordenar horas trabajadas por el empleado de forma ascendente.\n6. Ordenar horas trabajadas por el empleado de forma descendente.\n7. Ordenar sueldo de los empleados en forma ascendente.\n8. Ordenar sueldo de los empleados de forma descendente.\n9.Salir.\n\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1:
                    ll_sort(pArrayListEmployee,employee_ordenarId,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 2:
                    ll_sort(pArrayListEmployee,employee_ordenarId,0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 3:
                    ll_sort(pArrayListEmployee,employee_ordenarNombre,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 4:
                    ll_sort(pArrayListEmployee,employee_ordenarNombre,0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 5:
                    ll_sort(pArrayListEmployee,employee_ordenarId,1);
                    ll_sort(pArrayListEmployee,employee_ordenarHoras,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 6:
                    ll_sort(pArrayListEmployee,employee_ordenarId,1);
                    ll_sort(pArrayListEmployee,employee_ordenarHoras,0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 7:
                    printf("Aguarde, se estan ordenando los datos...");
                    ll_sort(pArrayListEmployee,employee_ordenarId,1);
                    ll_sort(pArrayListEmployee,employee_ordenarSalario,1);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 8:
                    printf("Aguarde, se estan ordenando los datos...");
                    ll_sort(pArrayListEmployee,employee_ordenarId,1);
                    ll_sort(pArrayListEmployee,employee_ordenarSalario,0);
                    controller_ListEmployee(pArrayListEmployee);
                    break;
            case 9:
                    break;
            default:
                    printf("\nOpcion invalida.\n");
                    break;
        }
        retorno = 1;
    }
    return retorno;
}

/** \brief Agrega un nuevo empleado.
*\param pArrayLinkedList va a recibir el array en donde se van a cargar los datos del empleado.
*\return retorna 0 si salio todo bien, -1 si hay un error.
*/
int employee_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxiliar;
    char auxNombre[1024];
    char auxId[1024] = "-1";
    int auxHoras;
    int auxSueldo;
    char horas[1024];
    char sueldo[1024];
    int retorno = -1;
    if(utn_getNombre(auxNombre,"\nIngrese nombre del empleado: \n","\nError. Re: \n") == 0 &&
        utn_getEnteroSinLimites(&auxHoras,5,"\nIngrese las horas trabajadas: \n","\nError, Re: \n") == 0 &&
        utn_getEnteroSinLimites(&auxSueldo,5,"\nIngrese el salario: \n","\nError, Re: \n") == 0)
    {
        itoa(auxHoras,horas,10); //convierto en int
        itoa(auxSueldo,sueldo,10);
        auxiliar = employee_newParametros(auxId,auxNombre,horas,sueldo);
        if(auxiliar != NULL)
        {
            ll_add(pArrayListEmployee, auxiliar);
        }
        retorno = 0;
    }
    return retorno;
}

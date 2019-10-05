#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
#define OCUPADO 0
#define LIBRE 1
#define TAM_MAX 51
#define TAM_MAXd 31

struct{
int id;
char name[TAM_MAX];
char lastName[TAM_MAX];
float salary;
int sector;
int isEmpty;
}typedef eEmployee;

typedef struct{
int id;
char descripcion[TAM_MAXd];
}eSector;


int menu();
int menuModify(eEmployee list[], int index, eSector sector[], int lenS);
int menuInformes();
void initEmployees(eEmployee list[], int len);
int searchFree(eEmployee list[], int len);
void sectors(eSector sector[]);
void listSectors(eSector sector[], int len);
int addEmployee(eEmployee list[], int len, eSector sector[], int lenS, int *increment);
int findEmployeeById(eEmployee list[], int len, int idEmp);
void getSector(eSector sector[], int len, int idS, char string[]);
void showEmployee(eEmployee list, eSector sector[], int lenS);
int validEmployee(eEmployee list[], int len);
int modifyEmployee(eEmployee list[], int len, int *idEmp, eSector sector[], int lenS);
int removeEmployee(eEmployee list[], int len, int idEmp, eSector sector[], int lenS);
void printEmployees(eEmployee list[], int len, eSector sector[], int lenS);
void sortEmployees(eEmployee list[], int len, int option);
float totalSalary(eEmployee list[], int len);
int qtyEmployees(eEmployee list[], int len);
float promedioSalary(eEmployee list[], int len);
void higherSalary(eEmployee list[], int len, float promedio);

#endif // ARRAYEMPLOYEES_H_INCLUDED

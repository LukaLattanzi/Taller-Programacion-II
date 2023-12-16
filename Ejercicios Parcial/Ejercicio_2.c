#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SUELDO_MIN 500

struct Sueldos
{
    char fecha[6]; // DDMMAA
    double monto;
};

struct Empleado
{
    char nombre[25];
    int legajo;
    struct Sueldos sueldosMensuales[12];
    double sueldoProm;
};

void asignarSueldo(struct Empleado *empleado, double sueldo);
void calculaProm(struct Empleado *empleado);

int main(void)
{
    struct Empleado empleado1;
    strcpy(empleado1.nombre, "Luka Lattanzi");
    double sueldo = SUELDO_MIN;
    asignarSueldo(&empleado1, sueldo);

    for (int i = 0; i < 12; i++)
    {
        printf("El empleado %s tiene un sueldo de: %.2lf Pesos en el mes %i\n", empleado1.nombre, empleado1.sueldosMensuales[i].monto, i + 1);
    }
    
    calculaProm(&empleado1);
    printf("El empleado %s tiene un sueldo promedio de: %.2lf Pesos\n", empleado1.nombre, empleado1.sueldoProm);
    return EXIT_SUCCESS;
}

void asignarSueldo(struct Empleado *empleado, double sueldo) // Asigna el sueldo al empleado
{
    for (int i = 0; i < 12; i++)
    {
        empleado->sueldosMensuales[i].monto = sueldo * (i + 1);
    }
}

void calculaProm(struct Empleado *empleado) // Calcula el sueldo promedio del empleado
{
    double promedio = 0;
    for (int i = 0; i < 12; i++)
    {
        promedio += empleado->sueldosMensuales[i].monto;
    }
    empleado->sueldoProm = promedio / 12;
}

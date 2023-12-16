// Escribir una funcion que tome como argumento un entero positivo entre 1 y 7 y retorne un puntero a cadena con el nombre del dıa de la semana correspondiente al argumento. Probar dicha funcion.

#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // EXIT_SUCCESS

char *nombreDia(int dia);

int main(void)
{
    int numeroDia;
    do
    {
        printf("Ingrese Un Numero Entre 1 Y 7: ");
        scanf("%d", &numeroDia);
    } while (numeroDia < 1 || numeroDia > 7);
    printf("El Dia De La Semana Es: %s\n", nombreDia(numeroDia));
    return EXIT_SUCCESS;
}

char *nombreDia(int numeroDia)
{
    char *nombreDia;
    switch (numeroDia)
    {
    case 1:
        nombreDia = "Lunes";
        break;
    case 2:
        nombreDia = "Martes";
        break;
    case 3:
        nombreDia = "Miercoles";
        break;
    case 4:
        nombreDia = "Jueves";
        break;
    case 5:
        nombreDia = "Viernes";
        break;
    case 6:
        nombreDia = "Sabado";
        break;
    case 7:
        nombreDia = "Domingo";
        break;
    default:
        nombreDia = "Dia Invalido";
        break;
    }
    return nombreDia;
}
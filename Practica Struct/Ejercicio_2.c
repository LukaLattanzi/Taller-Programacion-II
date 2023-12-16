#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_ELEMENTOS 3

typedef struct tiempo // Estructura para guardar la fecha y hora de última modificación de un archivo
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo; // Tiempo es un alias para struct tiempo

typedef struct // Estructura para guardar el nombre y la fecha y hora de última modificación de un archivo
{
    char *nombre;
    Tiempo ultima_mod;
} Archivo; // Archivo es un alias para struct

int compara_tiempos(Tiempo *t1, Tiempo *t2); // Compara dos tiempos de última modificación
void ordena_alfa(Archivo *lista, int n); // Ordena los archivos alfabéticamente
void ordena_temporal(Archivo *lista, int n); // Ordena los archivos por tiempo de última modificación

int main()
{
    // Crea un arreglo de archivos
    Archivo archivos[CANT_ELEMENTOS];

    archivos[1].nombre = "archivo-C.txt";
    archivos[1].ultima_mod.anio = 2023;
    archivos[1].ultima_mod.mes = 10;
    archivos[1].ultima_mod.dia = 6;
    archivos[1].ultima_mod.hora = 0;
    archivos[1].ultima_mod.minuto = 0;
    archivos[1].ultima_mod.segundo = 0;

    archivos[2].nombre = "archivo-A.txt";
    archivos[2].ultima_mod.anio = 2023;
    archivos[2].ultima_mod.mes = 10;
    archivos[2].ultima_mod.dia = 5;
    archivos[2].ultima_mod.hora = 0;
    archivos[2].ultima_mod.minuto = 0;
    archivos[2].ultima_mod.segundo = 0;

    archivos[0].nombre = "archivo-B.txt";
    archivos[0].ultima_mod.anio = 2023;
    archivos[0].ultima_mod.mes = 10;
    archivos[0].ultima_mod.dia = 7;
    archivos[0].ultima_mod.hora = 0;
    archivos[0].ultima_mod.minuto = 0;
    archivos[0].ultima_mod.segundo = 0;

    printf("╔ ═ ═ ═ ═ ═ Archivos Orden Alfabetico ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    ordena_alfa(archivos, CANT_ELEMENTOS);
    for (int i = 0; i < CANT_ELEMENTOS; i++)
    {
        printf("%s\n", archivos[i].nombre);
    }
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    printf("╔ ═ ═ ═ ═ ═ Archivos Orden Ultima Modificacion ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╗\n");
    ordena_temporal(archivos, CANT_ELEMENTOS);
    for (int i = 0; i < CANT_ELEMENTOS; i++)
    {
        printf("%s\n", archivos[i].nombre);
    }
    printf("╚ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ═ ╝\n");

    return 0;
}

int compara_tiempos(Tiempo *t1, Tiempo *t2)
{
    // Compara los tiempos de última modificación
    if (t1->anio < t2->anio)
        return 1;
    else if (t1->anio > t2->anio)
        return -1;
    if (t1->mes < t2->mes)
        return 1;
    else if (t1->mes > t2->mes)
        return -1;
    if (t1->dia < t2->dia)
        return 1;
    else if (t1->dia > t2->dia)
        return -1;
    if (t1->hora < t2->hora)
        return 1;
    else if (t1->hora > t2->hora)
        return -1;
    if (t1->minuto < t2->minuto)
        return 1;
    else if (t1->minuto > t2->minuto)
        return -1;
    if (t1->segundo < t2->segundo)
        return 1;
    else if (t1->segundo > t2->segundo)
        return -1;
    return 0; // Los tiempos son iguales
}

void ordena_alfa(Archivo *lista, int n)
{
    // Ordena los archivos alfabéticamente usando strcmp
    int i, j;
    Archivo temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(lista[i].nombre, lista[j].nombre) > 0)
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void ordena_temporal(Archivo *lista, int n)
{
    // Ordena los archivos por tiempo de última modificación usando compara_tiempos
    int i, j;
    Archivo temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (compara_tiempos(&lista[i].ultima_mod, &lista[j].ultima_mod) == 1)
            {
                temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}



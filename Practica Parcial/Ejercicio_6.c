// Definir una funcion int **CrearMatriz(int columnas, int filas) que dadas las dimensiones de una matriz  cree una matriz de esas dimensiones y complete cada elemento de la misma con i + j, donde i es la fila del elemento y j la columna. Ej: CrearMatriz(3, 2) -> {{0, 1, 2}, {1, 2, 3}}

#include <stdio.h>
#include <stdlib.h>

int **CrearMatriz(int columnas, int filas);

int main(void)
{
    int columnas = 5;
    int filas = 5;
    int **matriz = CrearMatriz(columnas, filas);
    for (int i = 0; i < filas; i++)
    {
        printf("{");
        for (int j = 0; j < columnas; j++)
        {
            printf("%d", matriz[i][j]);
            if (j < columnas - 1)
            {
                printf(", ");
            }
        }
        printf("}\n");
    }
    for (int i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    return EXIT_SUCCESS;
}

int **CrearMatriz(int columnas, int filas)
{
    int **matriz = (int **)malloc(sizeof(int *) * filas);
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = i + j;
        }
    }
    return matriz;
}
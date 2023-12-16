#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT_FILAS_MAS 1
#define CANT_COLUMNAS_MAS 1

// Definir funcion int **expandir(int **matriz, int filas, int columnas); que construya otra matriz con una fila mas y una columna mas, completando los valores nuevos de la matriz con 0.

int **expandir(int **matriz, int filas, int columnas)
{
    int **matrizexpandida = (int **)malloc(sizeof(int *) * (filas + CANT_FILAS_MAS));
    for (int i = 0; i < filas + CANT_FILAS_MAS; i++)
    {
        matrizexpandida[i] = (int *)malloc(sizeof(int) * (columnas + CANT_COLUMNAS_MAS));
        for (int j = 0; j < columnas + CANT_COLUMNAS_MAS; j++)
        {
            if (i < filas && j < columnas)
            {
                matrizexpandida[i][j] = matriz[i][j];
            }
            else
            {
                matrizexpandida[i][j] = 0;
            }
        }
    }
    return matrizexpandida;
}

void imprimirMatriz(int **matriz, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("[%i]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("----------------------------------------\n");
    int filas, columnas;
    printf("Ingrese La Cantidad De Filas: ");
    scanf("%d", &filas);
    printf("Ingrese La Cantidad De Columnas: ");
    scanf("%d", &columnas);
    printf("----------------------------------------\n");
    int **matriz = (int **)malloc(sizeof(int *) * filas);
    for (int i = 0; i < filas; i++)
    {
        matriz[i] = (int *)malloc(sizeof(int) * columnas);
        for (int j = 0; j < columnas; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
    printf("----------------------------------------\n");
    printf("Matriz Original:\n");
    imprimirMatriz(matriz, filas, columnas);
    printf("----------------------------------------\n");
    printf("----------------------------------------\n");
    printf("Matriz Expandida:\n");
    int **matrizexpandida = expandir(matriz, filas, columnas);
    imprimirMatriz(matrizexpandida, filas + CANT_FILAS_MAS, columnas + CANT_COLUMNAS_MAS);
    printf("----------------------------------------\n");
    for (int i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    for (int i = 0; i < filas + CANT_FILAS_MAS; i++)
    {
        free(matrizexpandida[i]);
    }
    free(matrizexpandida);
    return EXIT_SUCCESS;
}
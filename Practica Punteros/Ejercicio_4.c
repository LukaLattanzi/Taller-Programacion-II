// Escriba un programa que cree la transpuesta de una matriz.

#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // rand(), srand()
#include <unistd.h> // getpid(), sleep()

#define NUM_MAX 20 // Numero maximo para la matriz

void generarMatriz(int renglones, int columnas, int matriz[renglones][columnas])
{
    for (int i = 0; i < renglones; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            int numeroRandom = rand() % (NUM_MAX + 1);
            matriz[i][j] = numeroRandom;
        }
    }
}

void imprimirMatriz(int renglones, int columnas, int matriz[renglones][columnas])
{
    for (int i = 0; i < renglones; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("[%3i]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int renglones, columnas;
    printf("Teclea el numero de renglones: ");
    scanf("%d", &renglones);
    printf("Teclea el numero de columnas: ");
    scanf("%d", &columnas);
    printf("MATRIZ ORIGINAL\n");
    int matrizOriginal[renglones][columnas];
    srand(getpid());
    generarMatriz(renglones, columnas, matrizOriginal);
    imprimirMatriz(renglones, columnas, matrizOriginal);
    printf("MATRIZ TRANSPUESTA\n");
    int matrizTranspuesta[columnas][renglones];
    for (int i = 0; i < columnas; i++)
    {
        for (int j = 0; j < renglones; j++)
        {
            matrizTranspuesta[i][j] = matrizOriginal[j][i];
        }
    }
    imprimirMatriz(columnas, renglones, matrizTranspuesta);
    return 0;
}
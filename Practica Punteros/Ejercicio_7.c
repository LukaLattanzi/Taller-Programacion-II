// Escriba un programa que realiza la suma de dos matrices de N x N.

#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // rand(), srand()
#include <unistd.h> // getpid(), sleep()

#define N 5
#define NUM_MAX 20

void generarMatriz(int n, int matriz[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int numeroAleatorio = rand() % (NUM_MAX + 1);
            matriz[i][j] = numeroAleatorio;
        }
    }
}

void imprimirMatriz(int n, int matriz[n][n])
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%3i]", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(void)
{
    srand(getpid());
    printf("Generando matriz A...\n");
    sleep(1);
    int matrizA[N][N];
    generarMatriz(N, matrizA);
    imprimirMatriz(N, matrizA);
    sleep(1);
    printf("Generando matriz B...\n");
    sleep(1);
    int matrizB[N][N];
    generarMatriz(N, matrizB);
    imprimirMatriz(N, matrizB);
    sleep(1);
    printf("Sumando matrices...\n");
    sleep(1);
    int matrizC[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    imprimirMatriz(N, matrizC);
    return 0;
}
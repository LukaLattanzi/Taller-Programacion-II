// Escriba un programa que genere la matriz identidad de tamaño N x N.

#include <stdio.h>

void generarMatrizIdentidad(int n, int matriz[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                matriz[i][j] = 1;
            }
            else
            {
                matriz[i][j] = 0;
            }
        }
    }
}

void imprimirMatriz(int n, int matriz[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[%d]", matriz[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int N;
    printf("Ingrese Un Numero \"N\" Para La Matriz Identidad (N x N): ");
    scanf("%d", &N);
    int matriz[N][N];
    generarMatrizIdentidad(N, matriz);
    printf("Matriz Identidad de tamaño %d x %d:\n", N, N);
    imprimirMatriz(N, matriz);
    return 0;
}

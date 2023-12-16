#include <stdio.h>
#include <stdlib.h>

// Estructura para representar una arista
struct Arista
{
    int origen, destino, peso; // vertice origen, vertice destino, peso de la arista
};

// Estructura para representar un grafo
struct Grafo
{
    int V, E;               // numero de vertices, numero de aristas
    struct Arista *aristas; // Array de struct Arista
    int **matriz_costos;    // Matriz bidimensional de Costos
};

// Funcion para crear un grafo con V vertices y E aristas
struct Grafo *crearGrafo(int V, int E)
{
    // Inicializar el grafo
    struct Grafo *grafo = (struct Grafo *)malloc(sizeof(struct Grafo));
    grafo->V = V;
    grafo->E = E;
    grafo->aristas = (struct Arista *)malloc(E * sizeof(struct Arista));

    // Inicializar la matriz de costos
    grafo->matriz_costos = (int **)calloc(V, sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        grafo->matriz_costos[i] = (int *)calloc(V, sizeof(int));
    }

    return grafo;
}

// Funcion de comparacion para qsort, compara aristas por peso
int compararAristas(const void *a, const void *b)
{
    return ((struct Arista *)a)->peso - ((struct Arista *)b)->peso; // Devuelve un entero negativo si el primer elemento es menor que el segundo, cero si son iguales y un entero positivo si el primero es mayor que el segundo.
}

// Algoritmo de Kruskal para encontrar el arbol de expansion minima
void kruskal(struct Grafo *grafo)
{
    // Ordenar las aristas por peso de menor a mayor
    qsort(grafo->aristas, grafo->E, sizeof(struct Arista), compararAristas); // qsort(array, numero de elementos, tamaño de cada elemento, funcion de comparacion)

    // Conjuntos disjuntos para realizar uniones y comprobaciones de ciclos
    int *conjuntos = (int *)malloc(grafo->V * sizeof(int)); // Array de enteros [0, V-1]
    for (int i = 0; i < grafo->V; i++)
    {
        conjuntos[i] = i; // [0, 1, 2, ..., V-1]
    }

    printf("\n- - - - Arbol Expansion Minima Kruskal - - - -\n");

    // Iterar sobre todas las aristas ordenadas por peso
    for (int i = 0; i < grafo->E; i++)
    {

        int origen = grafo->aristas[i].origen;   // Vertice origen de la arista actual
        int destino = grafo->aristas[i].destino; // Vertice destino de la arista actual

        // Encontrar el conjunto al que pertenece el vertice de origen
        while (conjuntos[origen] != origen)
        {
            origen = conjuntos[origen];
        }

        // Encontrar el conjunto al que pertenece el vertice de destino
        while (conjuntos[destino] != destino)
        {
            destino = conjuntos[destino];
        }

        // Si los conjuntos son diferentes, no hay ciclo, agregar arista al arbol
        if (origen != destino)
        {
            printf("> Arista %d -> Vertice Origen %d | Vertice Destino %d | Peso: %d\n", i + 1, grafo->aristas[i].origen, grafo->aristas[i].destino, grafo->aristas[i].peso);
            conjuntos[origen] = destino;
        }
    }

    free(conjuntos);
}

int main(void)
{
    printf("- - - - Algortimo De Kruskal - - - -\n");
    int V, E;

    do
    {
        printf("> Ingrese El Numero De Vertices Del Grafo -> ");
        scanf("%d", &V);
        if (V <= 0)
        {
            printf("> El Numero De Vertices Debe Ser Mayor Que 0\n");
        }
    } while (V <= 0);

    do
    {
        printf("> Ingrese El Numero De Aristas Del Grafo -> ");
        scanf("%d", &E);
        if (E <= 0)
        {
            printf("> El Numero De Aristas Debe Ser Mayor Que 0\n");
        }
    } while (E <= 0);

    struct Grafo *grafo = crearGrafo(V, E);
    printf("> Se Aconseja Introducir Las Aristas Que Conectan Al Vertice 0 Primero, Seguido Por Aquellas Que Conectan Al Vertice Siguiente, Y Asi Sucesivamente Hasta El Vertice V-1. Prestar Atencion Para Evitar Ingresar La Misma Arista En Sentido Opuesto, Si Introduces Una Arista Del Vertice 1 Al 2, No Agregues La Arista Del 2 Al 1.\n");

    for (int i = 0; i < E; ++i)
    {
        printf("> Ingrese Los Datos De La Arista %d | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> ", i + 1);
        scanf("%d %d %d", &grafo->aristas[i].origen, &grafo->aristas[i].destino, &grafo->aristas[i].peso);

        if (!(grafo->aristas[i].origen >= 0 && grafo->aristas[i].origen < V) || !(grafo->aristas[i].destino >= 0 && grafo->aristas[i].destino < V))
        {
            printf("> Vertice No Valido En La Arista %d\n", i + 1);

            free(grafo->aristas);
            for (int j = 0; j < V; j++)
            {
                free(grafo->matriz_costos[j]);
            }
            free(grafo->matriz_costos);
            free(grafo);

            exit(EXIT_FAILURE);
        }

        if (grafo->aristas[i].peso <= 0)
        {
            printf("> El Peso De La Arista %d Debe Ser Mayor Que 0\n", i + 1);

            free(grafo->aristas);
            for (int j = 0; j < V; j++)
            {
                free(grafo->matriz_costos[j]);
            }
            free(grafo->matriz_costos);
            free(grafo);

            exit(EXIT_FAILURE);
        }

        grafo->matriz_costos[grafo->aristas[i].origen][grafo->aristas[i].destino] = grafo->aristas[i].peso;
        grafo->matriz_costos[grafo->aristas[i].destino][grafo->aristas[i].origen] = grafo->aristas[i].peso;
    }

    printf("\n- - - - Matriz De Costos - - - -\n");

    printf("  ");

    for (int i = 0; i < V; i++)
    {
        printf("%d ", i);
    }

    printf("\n");

    for (int i = 0; i < V; i++)
    {
        printf("%d ", i);
        for (int j = 0; j < V; j++)
        {
            printf("%d ", grafo->matriz_costos[i][j]);
        }
        printf("\n");
    }

    kruskal(grafo);

    free(grafo->aristas);
    for (int i = 0; i < V; i++)
    {
        free(grafo->matriz_costos[i]);
    }
    free(grafo->matriz_costos);
    free(grafo);

    return EXIT_SUCCESS;
}

/*

Grafo De Prueba:

                      ┏━━━┓
          ┏━━━━━━━━━━━┃ 0 ┃━━━━┓
        2 ┃           ┗━━━┛    ┃
          ┃             ┃ 5    ┃
        ┏━━━┓    5    ┏━━━┓    ┃
   ┏━━━━┃ 1 ┃━━━━━━━━━┃ 2 ┃    ┃
   ┃    ┗━━━┛         ┗━━━┛    ┃ 6
   ┃      ┃             ┃      ┃
   ┃      ┃             ┃ 4    ┃
   ┃      ┃ 2           ┃      ┃
   ┃      ┃           ┏━━━┓    ┃
   ┃      ┗━━━━━━━━━━━┃ 4 ┃━━━━┛
   ┃                  ┗━━━┛
   ┃ 3                  ┃
   ┃                    ┃ 4
 ┏━━━┓                  ┃
 ┃ 3 ┃━━━━━━━━━━━━━━━━━━┛
 ┗━━━┛

Inputs Para El Grafo De Prueba:

> Ingrese El Numero De Vertices Del Grafo -> 5
> Ingrese El Numero De Aristas Del Grafo -> 8
> Ingrese Los Datos De La Arista 1 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 0 1 2
> Ingrese Los Datos De La Arista 2 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 0 2 5
> Ingrese Los Datos De La Arista 3 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 0 4 6
> Ingrese Los Datos De La Arista 4 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 1 3 3
> Ingrese Los Datos De La Arista 5 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 1 2 5
> Ingrese Los Datos De La Arista 6 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 1 4 2
> Ingrese Los Datos De La Arista 7 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 2 4 4
> Ingrese Los Datos De La Arista 8 | Vertice Origen, Vertice Destino Y Peso (Ejemplo: 1 2 5) -> 3 4 4

Resultados:

- - - - Matriz De Costos - - - -
  0 1 2 3 4
0 0 2 5 0 6
1 2 0 5 3 2
2 5 5 0 0 4
3 0 3 0 0 4
4 6 2 4 4 0

- - - - Arbol Expansion Minima Kruskal - - - -
> Arista 1 -> Vertice Origen 1 | Vertice Destino 4 | Peso: 2
> Arista 2 -> Vertice Origen 0 | Vertice Destino 1 | Peso: 2
> Arista 3 -> Vertice Origen 1 | Vertice Destino 3 | Peso: 3
> Arista 5 -> Vertice Origen 2 | Vertice Destino 4 | Peso: 4

                      ┏━━━┓
          ┏━━━━━━━━━━━┃ 0 ┃
        2 ┃           ┗━━━┛
          ┃
        ┏━━━┓         ┏━━━┓
   ┏━━━━┃ 1 ┃         ┃ 2 ┃
   ┃    ┗━━━┛         ┗━━━┛
   ┃      ┃             ┃
   ┃      ┃             ┃ 4
   ┃      ┃             ┃
   ┃      ┃    2      ┏━━━┓
   ┃      ┗━━━━━━━━━━━┃ 4 ┃
   ┃                  ┗━━━┛
   ┃ 3
   ┃
 ┏━━━┓
 ┃ 3 ┃
 ┗━━━┛

*/
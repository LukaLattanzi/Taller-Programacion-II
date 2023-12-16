#include <stdio.h>
#include <stdlib.h>

struct nodo
{ // Estructura de un nodo de la pila
    int valorNodo;
    struct nodo *siguienteNodo;
};

void cargarNodos(struct nodo **pilaNodos);
void eliminarNodos(struct nodo **pilaNodos);
void listarNodos(struct nodo **pilaNodos);
void vaciarPila(struct nodo **pilaNodos);
void topPila(struct nodo **pilaNodos);
void bottomPila(struct nodo **pilaNodos);

int main(void)
{
    int opcion;
    struct nodo *pilaNodos = NULL; // Puntero a la pila de nodos (inicialmente vacia)
    do
    {
        printf("---- ---- MANEJO DE LA PILA ---- ----\n");
        printf("0. Terminar La Ejecucion\n");
        printf("1. Ingresar Elementos\n");
        printf("2. Eliminar Elementos\n");
        printf("3. Listar Elementos\n");
        printf("4. Vaciar La Pila\n");
        printf("5. Elemento Top De La Pila\n");
        printf("6. Elemento Bottom De La Pila\n");
        printf("---- ---- ---- ---- ---- ---- ---- ----\n");
        printf("Ingrese Una Opcion -> ");
        scanf("%d", &opcion);
        switch (opcion) // Segun la opción ingresada por el usuario
        {
        case 0: // Terminar la ejecucion
            printf("---- ---- ---- ---- ---- ----\nTerminando La Ejecucion...\n---- ---- ---- ---- ---- ----\n");
            break;
        case 1: // Ingresar elementos
            cargarNodos(&pilaNodos);
            break;
        case 2: // Eliminar elementos
            if (pilaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Pila Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                eliminarNodos(&pilaNodos);
            break;
        case 3: // Listar elementos
            if (pilaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Pila Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                listarNodos(&pilaNodos);
            break;
        case 4: // Vaciar la pila
            if (pilaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Pila Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                vaciarPila(&pilaNodos);
            break;
        case 5: // Elemento top de la pila
            if (pilaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Pila Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                topPila(&pilaNodos);
            break;
        case 6: // Elemento bottom de la pila
            if (pilaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Pila Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                bottomPila(&pilaNodos);
            break;
        default: // Opcion invalida
            printf("---- ---- ---- ---- ---- ----\nOpcion Invalida\n---- ---- ---- ---- ---- ----\n");
            break;
        }
    } while (opcion != 0);    // Repite mientras la opcion ingresada sea distinta de cero
    while (pilaNodos != NULL) // Mientras la pila no este vacia
    {
        struct nodo *nodoAuxiliar = pilaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la pila
        pilaNodos = pilaNodos->siguienteNodo;  // Apunta la pila al siguiente nodo
        free(nodoAuxiliar);                    // Libera la memoria del nodo auxiliar
    }
    return EXIT_SUCCESS; // Termina el programa
}

void cargarNodos(struct nodo **pilaNodos)
{
    printf("---- ---- CARGA NODOS EN LA PILA ---- ----\n");
    int cantidadNodos, valorNodo; // Variable auxiliar para la carga de datos
    printf("Ingrese El Numero De Nodos A Cargar -> ");
    scanf("%d", &cantidadNodos);
    for (int i = 0; i < cantidadNodos; i++)
    {
        struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo)); // Crea un nuevo nodo y reserva memoria para el
        printf("Ingrese El Valor Numerico Del Nodo %i: ", i + 1);
        scanf("%d", &valorNodo);
        nuevoNodo->valorNodo = valorNodo;      // Asigna el valor al nodo
        nuevoNodo->siguienteNodo = *pilaNodos; // Asigna el puntero al siguiente nodo
        *pilaNodos = nuevoNodo;                // Asigna el puntero a la pila al nuevo nodo
    }
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void eliminarNodos(struct nodo **pilaNodos)
{
    printf("---- ---- DESCARGA NODOS EN LA PILA ---- ----\n");
    int cantidadNodos, numNodosEnPila; // Variable auxiliar para la carga de datos
    printf("Ingrese El Numero De Nodos A Eliminar -> ");
    scanf("%d", &cantidadNodos);
    struct nodo *temp = *pilaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la pila
    while (temp != NULL)            // Cuenta la cantidad de nodos en la pila
    {
        numNodosEnPila++;
        temp = temp->siguienteNodo;
    }
    if (cantidadNodos > numNodosEnPila) // Si la cantidad de nodos a eliminar es mayor a la cantidad de nodos en la pila
    {
        printf("Se Ingreso Mas Nodos A Eliminar Que Los Existentes, Se eliminaran Todos Los Nodos\n");
        cantidadNodos = numNodosEnPila;
    }
    for (int i = 0; i < cantidadNodos; i++) // Elimina los nodos
    {
        struct nodo *nodoAuxiliar = *pilaNodos;
        *pilaNodos = nodoAuxiliar->siguienteNodo;
        free(nodoAuxiliar);
    }
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void listarNodos(struct nodo **pilaNodos)
{
    printf("---- ---- LISTA NODOS EN LA PILA ---- ----\n");
    struct nodo *nodoAuxiliar = *pilaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la pila
    while (nodoAuxiliar != NULL)            // Mientras el nodo auxiliar no sea nulo
    {
        printf("| %d |", nodoAuxiliar->valorNodo);  // Muestra el valor del nodo
        nodoAuxiliar = nodoAuxiliar->siguienteNodo; // Apunta el nodo auxiliar al siguiente nodo
        printf("\n");
    }
    printf("---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void vaciarPila(struct nodo **pilaNodos)
{
    printf("---- ---- VACIAR LA PILA ---- ----\n");
    while (*pilaNodos != NULL) // Mientras la pila no este vacía
    {
        struct nodo *nodoAuxiliar = *pilaNodos;   // Crea un nodo auxiliar y lo apunta al primer nodo de la pila
        *pilaNodos = nodoAuxiliar->siguienteNodo; // Apunta la pila al siguiente nodo
        free(nodoAuxiliar);                       // Libera la memoria del nodo auxiliar
    }
    printf("Pila Vaciada\n");
    printf("---- ---- ---- ---- ---- ---- ----\n");
}

void topPila(struct nodo **pilaNodos)
{
    printf("---- ---- ELEMENTO TOP DE LA PILA ---- ----\n");
    printf("El Elemento Top De La Pila Es -> | %d |\n", (*pilaNodos)->valorNodo);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void bottomPila(struct nodo **pilaNodos)
{
    printf("---- ---- ELEMENTO BOTTOM DE LA PILA ---- ----\n");
    struct nodo *nodoAuxiliar = *pilaNodos;     // Crea un nodo auxiliar y lo apunta al primer nodo de la pila
    while (nodoAuxiliar->siguienteNodo != NULL) // Mientras el nodo auxiliar no sea nulo
    {
        nodoAuxiliar = nodoAuxiliar->siguienteNodo; // Apunta el nodo auxiliar al siguiente nodo
    }
    printf("El Elemento Bottom De La Pila Es -> | %d |\n", nodoAuxiliar->valorNodo);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}
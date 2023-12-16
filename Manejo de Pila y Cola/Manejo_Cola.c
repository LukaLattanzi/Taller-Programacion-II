#include <stdio.h>
#include <stdlib.h>

struct nodo
{ // Estructura de un nodo de la cola
    int valorNodo;
    struct nodo *siguienteNodo;
};

void encolarNodos(struct nodo **colaNodos);
void desencolarNodos(struct nodo **colaNodos);
void listarNodos(struct nodo **colaNodos);
void vaciarCola(struct nodo **colaNodos);
void frenteCola(struct nodo **colaNodos);
void finalCola(struct nodo **colaNodos);

int main(void)
{
    int opcion;
    struct nodo *colaNodos = NULL; // Puntero a la cola de nodos
    do
    {
        printf("---- ---- MANEJO DE LA COLA ---- ----\n");
        printf("0. Terminar La Ejecucion\n");
        printf("1. Encolar Elementos\n");
        printf("2. Desencolar Elementos\n");
        printf("3. Listar Elementos\n");
        printf("4. Vaciar La Cola\n");
        printf("5. Elemento Front De La Cola\n");
        printf("6. Elemento Rear De La Cola\n");
        printf("---- ---- ---- ---- ---- ---- ---- ----\n");
        printf("Ingrese Una Opcion -> ");
        scanf("%d", &opcion);
        switch (opcion) // Segun la opcion ingresada por el usuario
        {
        case 0: // Terminar la ejecucion
            printf("---- ---- ---- ---- ---- ----\nTerminando La Ejecucion...\n---- ---- ---- ---- ---- ----\n");
            break;
        case 1: // Encolar elementos
            encolarNodos(&colaNodos);
            break;
        case 2: // Desencolar elementos
            if (colaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Cola Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                desencolarNodos(&colaNodos);
            break;
        case 3: // Listar elementos
            if (colaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Cola Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                listarNodos(&colaNodos);
            break;
        case 4: // Vaciar la cola
            if (colaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Cola Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                vaciarCola(&colaNodos);
            break;
        case 5: // Elemento front de la cola
            if (colaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Cola Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                frenteCola(&colaNodos);
            break;
        case 6: // Elemento rear de la cola
            if (colaNodos == NULL)
                printf("---- ---- ---- ---- ---- ----\nLa Cola Esta Vacia\n---- ---- ---- ---- ---- ----\n");
            else
                finalCola(&colaNodos);
            break;
        default: // Opcion invalida
            printf("---- ---- ---- ---- ---- ----\nOpcion Invalida\n---- ---- ---- ---- ---- ----\n");
            break;
        }
    } while (opcion != 0);    // Repite mientras la opcion ingresada sea distinta de cero

    while (colaNodos != NULL) // Mientras la cola no este vacia
    {
        struct nodo *nodoAuxiliar = colaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
        colaNodos = colaNodos->siguienteNodo;  // Apunta la cola al siguiente nodo
        free(nodoAuxiliar);                    // Libera la memoria del nodo auxiliar
    }

    return EXIT_SUCCESS; // Termina el programa
}

void encolarNodos(struct nodo **colaNodos)
{
    printf("---- ---- ENCOLAR NODOS EN LA COLA ---- ----\n");
    int cantidadNodos, valorNodo; // Variable auxiliar para la carga de datos
    printf("Ingrese El Numero De Nodos A Encolar -> ");
    scanf("%d", &cantidadNodos);
    for (int i = 0; i < cantidadNodos; i++)
    {
        struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo)); // Crea un nuevo nodo y reserva memoria para el
        printf("Ingrese El Valor Numerico Del Nodo %i: ", i + 1);
        scanf("%d", &valorNodo);
        nuevoNodo->valorNodo = valorNodo; // Asigna el valor al nodo
        nuevoNodo->siguienteNodo = NULL;  // El nuevo nodo apunta a NULL, ya que es el ultimo en la cola
        if (*colaNodos == NULL)           // Si la cola está vacia
        {
            *colaNodos = nuevoNodo; // El nuevo nodo es el unico nodo en la cola
        }
        else
        {
            struct nodo *temp = *colaNodos;     // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
            while (temp->siguienteNodo != NULL) // Recorre la cola hasta el ultimo nodo
            {
                temp = temp->siguienteNodo;
            }
            temp->siguienteNodo = nuevoNodo; // El ultimo nodo apunta al nuevo nodo
        }
    }
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void desencolarNodos(struct nodo **colaNodos)
{
    printf("---- ---- DESENCOLAR NODOS EN LA COLA ---- ----\n");
    int cantidadNodos, numNodosEnCola = 0; // Variable auxiliar para la carga de datos
    printf("Ingrese El Numero De Nodos A Desencolar -> ");
    scanf("%d", &cantidadNodos);
    struct nodo *temp = *colaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
    while (temp != NULL)            // Cuenta la cantidad de nodos en la cola
    {
        numNodosEnCola++;
        temp = temp->siguienteNodo;
    }
    if (cantidadNodos > numNodosEnCola) // Si la cantidad de nodos a desencolar es mayor a la cantidad de nodos en la cola
    {
        printf("Se Ingreso Mas Nodos A Desencolar Que Los Existentes, Se Desencolaran Todos Los Nodos\n");
        cantidadNodos = numNodosEnCola;
    }
    for (int i = 0; i < cantidadNodos; i++) // Desencola los nodos
    {
        struct nodo *nodoAuxiliar = *colaNodos;
        *colaNodos = nodoAuxiliar->siguienteNodo;
        free(nodoAuxiliar);
    }
    printf("---- ---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void listarNodos(struct nodo **colaNodos)
{
    printf("---- ---- LISTA NODOS EN LA COLA ---- ----\n");
    struct nodo *nodoAuxiliar = *colaNodos; // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
    while (nodoAuxiliar != NULL)            // Mientras el nodo auxiliar no sea nulo
    {
        printf("| %d |", nodoAuxiliar->valorNodo);  // Muestra el valor del nodo
        nodoAuxiliar = nodoAuxiliar->siguienteNodo; // Apunta el nodo auxiliar al siguiente nodo
    }
    printf("\n---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void vaciarCola(struct nodo **colaNodos)
{
    printf("---- ---- VACIAR LA COLA ---- ----\n");
    while (*colaNodos != NULL) // Mientras la cola no esté vacia
    {
        struct nodo *nodoAuxiliar = *colaNodos;   // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
        *colaNodos = nodoAuxiliar->siguienteNodo; // Apunta la cola al siguiente nodo
        free(nodoAuxiliar);                       // Libera la memoria del nodo auxiliar
    }
    printf("Cola Vaciada\n");
    printf("---- ---- ---- ---- ---- ---- ----\n");
}

void frenteCola(struct nodo **colaNodos)
{
    printf("---- ---- ELEMENTO FRONT DE LA COLA ---- ----\n");
    printf("El Elemento Front De La Cola Es -> | %d |\n", (*colaNodos)->valorNodo);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

void finalCola(struct nodo **colaNodos)
{
    printf("---- ---- ELEMENTO REAR DE LA COLA ---- ----\n");
    struct nodo *nodoAuxiliar = *colaNodos;     // Crea un nodo auxiliar y lo apunta al primer nodo de la cola
    while (nodoAuxiliar->siguienteNodo != NULL) // Mientras el nodo auxiliar no sea nulo
    {
        nodoAuxiliar = nodoAuxiliar->siguienteNodo; // Apunta el nodo auxiliar al siguiente nodo
    }
    printf("El Elemento Rear De La Cola Es -> | %d |\n", nodoAuxiliar->valorNodo);
    printf("---- ---- ---- ---- ---- ---- ---- ---- ----\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define NUM_CASILLAS 25   // Número de casillas del diccionario
#define VACIO "VACIO"     // Valor para indicar que una casilla está vacía
#define BORRADO "BORRADO" // Valor para indicar que una casilla está borrada

typedef char **DICCIONARIO;

// Protipo de funciones
DICCIONARIO CrearDiccionario();
void InsertarClave(char *clave, DICCIONARIO tabla);
int LocalizaPosicion(char *clave, DICCIONARIO tabla);
int HashSimple(char *clave);
void ImprimirDiccionario(DICCIONARIO tabla);
int CalcularLongitudMaxima(DICCIONARIO tabla);
int EsMiembro(char *clave, DICCIONARIO tabla);
void SuprimirClave(char *clave, DICCIONARIO tabla);
void DestruirTablaHash(DICCIONARIO tabla);

// Función para crear un diccionario
DICCIONARIO CrearDiccionario()
{
    DICCIONARIO tabla = (char **)malloc(NUM_CASILLAS * sizeof(char *)); // Crea un array usando memoria dinámica

    for (int i = 0; i < NUM_CASILLAS; i++)
    {
        tabla[i] = VACIO; // Inicializa cada elemento del array con VACIO
    }

    return tabla;
}

// Función para insertar una clave en el diccionario
void InsertarClave(char *clave, DICCIONARIO tabla)
{
    int indice = LocalizaPosicion(clave, tabla);

    if (tabla[indice] == VACIO || tabla[indice] == BORRADO) // Si la posición está vacía o contiene un elemento borrado
    {
        tabla[indice] = strdup(clave); // Inserta la clave en la posición
    }
    else // Si la posición contiene una clave
    {
        printf("La Clave Ya Existe En El Diccionario\n");
    }
}

// Función para buscar la posición de una clave en el diccionario
int LocalizaPosicion(char *clave, DICCIONARIO tabla)
{
    int indice = HashSimple(clave);

    while (tabla[indice] != VACIO && strcmp(tabla[indice], clave) != 0) // Mientras la posición no esté vacía y la clave no sea igual a la clave buscada
    {
        indice = (indice + 1) % NUM_CASILLAS; // Calcula la siguiente posición
    }

    return indice;
}

// Función para calcular la posición de una clave en el diccionario
int HashSimple(char *clave)
{
    int suma = 0;

    while (*clave) // Recorre la clave
    {
        suma += *clave++; // Suma los códigos ASCII de los caracteres de la clave
    }

    return suma % NUM_CASILLAS;
}

// Función para imprimir el contenido del diccionario
void ImprimirDiccionario(DICCIONARIO tabla)
{
    int longitudMaxima = CalcularLongitudMaxima(tabla); // Calcula la longitud máxima de las claves

    printf("━ ━ ━ ━ ━ Contenido Del Diccionario ━ ━ ━ ━ ━\n");
    printf("● Indice ● ━ ━ ━ ━ ━ ● %-*s ●\n", longitudMaxima, "Clave");

    for (int i = 0; i < NUM_CASILLAS; i++)
    {
        if (tabla[i] == VACIO) // Si la posición está vacía
        {
            printf("● %6d ● ━ ━ ━ ━ ━ ● %-*s ●\n", i + 1, longitudMaxima, VACIO);
        }
        else if (tabla[i] == BORRADO) // Si la posición está borrada
        {
            printf("● %6d ● ━ ━ ━ ━ ━ ● %-*s ●\n", i + 1, longitudMaxima, BORRADO);
        }
        else // Si la posición contiene una clave
        {
            printf("● %6d ● ━ ━ ━ ━ ━ ● %-*s ●\n", i + 1, longitudMaxima, tabla[i]);
        }
    }

    printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━\n");
}

// Función para calcular la longitud máxima de las claves
int CalcularLongitudMaxima(DICCIONARIO tabla)
{
    int longitudMaxima = 0;

    for (int i = 0; i < NUM_CASILLAS; i++)
    {
        if (tabla[i] != NULL && strlen(tabla[i]) > longitudMaxima) // Si la posición no está vacía y la longitud de la clave es mayor a la longitud máxima
        {
            longitudMaxima = strlen(tabla[i]); // Actualiza la longitud máxima
        }
    }

    return longitudMaxima;
}

// Función para verificar si una clave está en el diccionario
int EsMiembro(char *clave, DICCIONARIO tabla)
{
    int indice = LocalizaPosicion(clave, tabla);

    return tabla[indice] != VACIO && strcmp(tabla[indice], clave) == 0; // Devuelve 1 si la posición no está vacía y la clave es igual a la clave buscada, 0 en caso contrario
}

// Función para eliminar una clave del diccionario
void SuprimirClave(char *clave, DICCIONARIO tabla)
{
    int indice = LocalizaPosicion(clave, tabla);

    if (tabla[indice] != VACIO) // Si la posición no está vacía
    {
        free(tabla[indice]);     // Libera la memoria de la clave
        tabla[indice] = BORRADO; // Marca la posición como borrada
    }
    else
    {
        printf("La Clave No Existe En El Diccionario\n");
    }
}

// Función para destruir un diccionario
void DestruirTablaHash(DICCIONARIO tabla)
{
    for (int i = 0; i < NUM_CASILLAS; i++)
    {
        if (tabla[i] != VACIO && tabla[i] != BORRADO)
        {
            free(tabla[i]); // Libera la memoria de la clave
        }
    }

    free(tabla); // Libera la memoria del array
}

int main(void)
{
    DICCIONARIO diccionario = CrearDiccionario(); // Crear un diccionario

    // Insertar algunas claves en el diccionario (las claves son títulos de videojuegos)
    InsertarClave("Call Of Duty Black Ops 2", diccionario);
    InsertarClave("Bloodborne", diccionario);
    InsertarClave("Grand Theft Auto Vice City", diccionario);
    InsertarClave("Metal Gear Solid 2", diccionario);
    InsertarClave("Silent Hill 2", diccionario);
    InsertarClave("The Last Of Us", diccionario);
    InsertarClave("Red Dead Redemption 2", diccionario);
    InsertarClave("Fallout New Vegas", diccionario);
    InsertarClave("Outlast", diccionario);
    InsertarClave("Resident Evil 4", diccionario);

    // Imprimir el contenido del diccionario
    ImprimirDiccionario(diccionario);
    sleep(2);

    // Verificar si ciertas claves son miembros del diccionario
    printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━\n");
    printf("¿\"Silent Hill 2\" Es Miembro? %s\n", EsMiembro("Silent Hill 2", diccionario) ? "Sí" : "No");
    printf("¿\"Destiny 2\" Es Miembro? %s\n", EsMiembro("Destiny 2", diccionario) ? "Sí" : "No");
    printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━\n");
    sleep(2);

    // Eliminar una clave y verificar si aún es miembro
    printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━\n");
    SuprimirClave("Outlast", diccionario);
    printf("¿\"Outlast\" Es Miembro Despues De Eliminarlo? %s\n", EsMiembro("Outlast", diccionario) ? "Sí" : "No");
    printf("━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━ ━\n");
    sleep(2);

    // Imprimir el contenido del diccionario
    ImprimirDiccionario(diccionario);
    sleep(2);

    // Liberar la memoria asignada para el diccionario
    DestruirTablaHash(diccionario);

    return EXIT_SUCCESS;
}
// Crear programa que lea un numero determinado de reales introducidos por teclado, los almacene en un vector para luego mostrarlos en orden inverso. Para recorrer el array debera usar aritmetica de punteros en lugar de indices del array.

#include <stdio.h> // printf(), scanf()

int main(void)
{
    int cantidadNumeros;
    printf("Ingrese La Cantidad De Numeros A Almacenar En El Vector: ");
    scanf("%d", &cantidadNumeros);
    int arrayElementos[cantidadNumeros];
    int *arrayPuntero = arrayElementos; // El puntero apunta al primer elemento del array
    for (int i = 0; i < cantidadNumeros; i++)
    {
        printf("Ingrese El Valor Del Elemento[%d]: ", i);
        scanf("%d", arrayPuntero + i); // El puntero se desplaza a la siguiente posicion del array
    }
    for (int j = cantidadNumeros - 1; j >= 0; j--)
    {
        printf("El Valor Del Elemento[%d]: %d\n", j, *(arrayPuntero + j));
    }
    return 0;
}

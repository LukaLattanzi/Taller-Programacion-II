#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *digitos2char(int numeroADescomponer, int *Digitos);

int main(void)
{
    int numero;
    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    int digitos;
    char *cadena = digitos2char(numero, &digitos);
    printf("El numero ingresado es: %s y la cantidad de digitos es: %i\n", cadena, digitos);
    
    free(cadena);
    return EXIT_SUCCESS;
}

char *digitos2char(int numeroADescomponer, int *Digitos) // Devuelve un puntero a char con el numero ingresado y la cantidad de digitos
{
    int digitos = 0;              // Cantidad de digitos del numero ingresado
    int aux = numeroADescomponer; // Variable auxiliar para no modificar el numero ingresado

    while (aux > 0)               // Calculo la cantidad de digitos del numero ingresado
    {
        aux /= 10; // Divido el numero por 10 para ir eliminando los digitos
        digitos++; // Cuento la cantidad de digitos
    }

    char *cadena = (char *)malloc(sizeof(char) * (digitos + 1)); // Reservo memoria para la cadena de caracteres (digitos + 1 para el '\0')

    if (cadena == NULL)
    {
        perror("Error al asignar memoria");
        exit(1);
    };

    aux = numeroADescomponer;

    for (int i = digitos - 1; i >= 0; i--) // Recorro la cadena de caracteres de atras hacia adelante
    {
        cadena[i] = (aux % 10) + '0'; // Usa el resto de la division para obtener el digito y le suma el valor ASCII de '0' para obtener el caracter
        aux /= 10;
    }
    
    cadena[digitos] = '\0'; // Agrego el caracter nulo al final de la cadena
    *Digitos = digitos;
    return cadena;
}

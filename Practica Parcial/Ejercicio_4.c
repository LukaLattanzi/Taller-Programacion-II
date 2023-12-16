// Definir una funcion char *eco (char *cadena) que dada una cadena devuelva otra cadena con los mismos caracteres, pero con el ultimo caracter repetido 5 veces. Ej: "hola" -> "holaaaaa"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *eco(char *cadena);

int main(void)
{
    char *cadenaOriginal = "Hola"; //
    char *cadenaEco = eco(cadenaOriginal);
    printf("La Cadena Original: %s\n", cadenaOriginal);
    printf("La Cadena Eco: %s\n", cadenaEco);
    free(cadenaEco);
    return EXIT_SUCCESS;
}

char *eco(char *cadena)
{
    char *cadenaEco = (char *)malloc(sizeof(char) * (strlen(cadena) + 5)); // Memoria para la cadena eco (4 caracteres extra + 1 por el \0)
    strcpy(cadenaEco, cadena);                                             // Copio la cadena original en la cadena eco
    for (int i = 0; i < 4; i++)
    {
        cadenaEco[strlen(cadena) + i] = cadena[strlen(cadena) - 1]; // Copio el ultimo caracter de la cadena original 4 veces en la cadena eco
    }
    cadenaEco[strlen(cadena) + 4] = '\0'; // Agrego el \0 al final de la cadena eco
    return cadenaEco;
}

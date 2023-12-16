// Definir una funcion void elimSFinales(char *cadena) que dada una cadena elimine las letras 's' que estan al final de una palabra. Ej: "Los rosarinos hablamos sin eses" -> "Lo rosarino hablamo sin ese"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void elimSFinales(char *cadena);

int main(void)
{
    char *cadenaOriginal = "Los rosarinos hablamos sin eses";
    printf("La Cadena Original: %s\n", cadenaOriginal);
    elimSFinales(cadenaOriginal);
    return EXIT_SUCCESS;
}

void elimSFinales(char *cadena) // Definir una funcion void elimSFinales(char *cadena) que dada una cadena elimine las letras 's' que estan al final de una palabra. Ej: "Los rosarinos hablamos sin eses" -> "Lo rosarino hablamo sin ese"
{
    char *cadenaSinS = (char *)malloc(sizeof(char) * (strlen(cadena) + 1));
    int i = 0;
    int j = 0;
    while (cadena[i] != '\0') // Recorro la cadena de caracteres
    {
        if (cadena[i] == 's' && (cadena[i + 1] == ' ' || cadena[i + 1] == '\0')) // Si el caracter es una 's' y el siguiente es un espacio o el final de la cadena
        {
            i++;
        }
        else
        {
            cadenaSinS[j] = cadena[i]; // Copio el caracter en la nueva cadena
            i++;
            j++;
        }
    }
    cadenaSinS[j] = '\0';
    printf("La Cadena Sin S: %s\n", cadenaSinS);
    free(cadenaSinS);
}
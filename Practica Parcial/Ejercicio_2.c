#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A) Defina una estructura que permita almacenar la siguiente información: i) dirección IP ii) mascara de red

struct red
{
    int ip[4];
    int mascara[4];
};

// B) Crear una función que tome un puntero a dicha estructura y que devuelva una cadena con el número de red. Ej: IP: 192.168.146.222 Mask: 255.255.255.0 Salida: 192.168.146.0

char *numeroDeRed(struct red *red)
{
    char *numerodered = (char *)malloc(sizeof(char) * 16);
    sprintf(numerodered, "%d.%d.%d.%d", red->ip[0] & red->mascara[0], red->ip[1] & red->mascara[1], red->ip[2] & red->mascara[2], red->ip[3] & red->mascara[3]);
    return numerodered;
}

int main()
{
    struct red *redUno = (struct red *)malloc(sizeof(struct red));
    struct red *redDos = (struct red *)malloc(sizeof(struct red));
    redUno->ip[0] = 192;
    redUno->ip[1] = 168;
    redUno->ip[2] = 146;
    redUno->ip[3] = 222;
    redUno->mascara[0] = 255;
    redUno->mascara[1] = 255;
    redUno->mascara[2] = 255;
    redUno->mascara[3] = 0;
    redDos->ip[0] = 187;
    redDos->ip[1] = 143;
    redDos->ip[2] = 122;
    redDos->ip[3] = 24;
    redDos->mascara[0] = 125;
    redDos->mascara[1] = 255;
    redDos->mascara[2] = 15;
    redDos->mascara[3] = 155;
    char *numerodereduno = numeroDeRed(redUno);
    char *numerodereddos = numeroDeRed(redDos);
    printf("%s\n", numerodereduno);
    printf("%s\n", numerodereddos);
    free(numerodereduno);
    free(numerodereddos);
    free(redUno);
    free(redDos);
    return EXIT_SUCCESS;
}
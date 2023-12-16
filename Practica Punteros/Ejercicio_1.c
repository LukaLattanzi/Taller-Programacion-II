#include <stdio.h>  // printf(), scanf()
#include <stdlib.h> // EXIT_SUCCESS

typedef enum
{
    MAYUSCULAS,
    MINUSCULAS
} may_min;

int strLargo(const char *origen);                             // Cantidad de caracteres.
int strVacio(const char *origen);                             // Retorna 1 si tiene al menos un caracter, 0 en otro caso.
void strCopia(char *destino, const char *origen);             // Copia el contenido de origen en destino.
char *reverse(char *string);                                  // Retorna una cadena que es string invertida.
void strIzq(char *destino, const char *origen);               // Saca blancos a la izquierda.
void strDer(char *destino, const char *origen);               // Saca blancos a la derecha.
void strAmbos(char *destino, const char *origen);             // Saca blancos a ambos lados.
void strMayMin(char *destino, const char *origen, may_min m); // Convierte a mayusculas o minusculas.
int main()
{
    char *text1 = " Sera Cierto ?? ";
    int largo = strLargo(text1) + 1;
    char *result = (char *)malloc(largo);
    char *reves;
    if (result == NULL)
        return -1;
    printf("la cadena: ");
    puts(text1);
    printf("Se encunetra: %s\n", (strVacio(text1) ? "No vacia" : "Vacia"));
    printf("Largo: %d\n", strLargo(text1));
    strCopia(result, text1);
    printf("Copia: [%s]\n", result);
    strIzq(result, text1);
    printf("Sin blancos a la Izquierda: ");
    puts(result);
    strDer(result, text1);
    printf("Der : [%s]\n", result);
    strAmbos(result, text1);
    printf("Ambos: [%s]\n", result);
    strMayMin(result, text1, MAYUSCULAS);
    printf("Mayusculas: [%s]\n", result);
    strMayMin(result, text1, MINUSCULAS);
    printf("Minusculas: [%s]\n", result);
    reves = reverse(text1);
    printf("Reversa: [%s]\n", reves);
    return 0;
}

int strLargo(const char *origen)
{
    int largo = 0;
    while (*origen++)
        largo++;
    return largo;
}

int strVacio(const char *origen)
{
    return *origen == '\0';
}

void strCopia(char *destino, const char *origen)
{
    while (*origen)
        *destino++ = *origen++;
    *destino = '\0';
}

char *reverse(char *string)
{
    char *reves = string;
    char *fin = string;
    char temp;
    while (*fin)
        fin++;
    fin--;
    while (string < fin)
    {
        temp = *string;
        *string++ = *fin;
        *fin-- = temp;
    }
    return reves;
}

void strIzq(char *destino, const char *origen)
{
    while (*origen == ' ')
        origen++;
    while (*origen)
        *destino++ = *origen++;
    *destino = '\0';
}

void strDer(char *destino, const char *origen)
{
    int largo = strLargo(origen);
    while (origen[largo - 1] == ' ')
        largo--;
    for (int i = 0; i < largo; i++)
        *destino++ = *origen++;
    *destino = '\0';
}

void strAmbos(char *destino, const char *origen)
{
    strIzq(destino, origen);
    strDer(destino, destino);
}

void strMayMin(char *destino, const char *origen, may_min m)
{
    while (*origen)
    {
        if (m == MAYUSCULAS)
        {
            if (*origen >= 'a' && *origen <= 'z')
                *destino++ = *origen++ - 32;
            else
                *destino++ = *origen++;
        }
        else
        {
            if (*origen >= 'A' && *origen <= 'Z')
                *destino++ = *origen++ + 32;
            else
                *destino++ = *origen++;
        }
    }
    *destino = '\0';
}

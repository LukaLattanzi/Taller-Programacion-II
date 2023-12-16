#include <stdio.h> // printf(), scanf()

int main(void)
{
    int i = 5, j[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char x = 'a', pal[] = "texto en c";
    int *pi;
    char *pc;
    printf("---------------------------------------------\n");
    // Mostrar la direccion de "i" y su valor.
    printf("Por variable: 'i' Valor: %d Direccion %p\n", i, &i);
    printf("---------------------------------------------\n");
    // Mostrar los mismos valores a traves del puntero "pi".
    pi = &i;                                                       // pi apunta a la direccion de memoria de i.
    printf("Por puntero: 'pi' Valor: %d Direccion %p\n", *pi, pi); // *pi accede al valor de la direccion de memoria a la que apunta pi. pi accede a la direccion de memoria a la que apunta pi.
    printf("---------------------------------------------\n");
    // Recorrer el vector "j" mostrando para cada elemento, su direccion y valor.
    for (int i = 0; i < 10; i++)
    {
        printf("Por variable: 'j[%d]' Valor: %d Direccion %p\n", i, j[i], &j[i]);
    }
    printf("---------------------------------------------\n");
    // Recorrer el vector accediendo a traves del puntero "pi" y usando algebra de punteros.
    pi = j; // pi apunta a la direccion de memoria de j.
    for (int i = 0; i < 10; i++)
    {
        printf("Por puntero: 'pi[%d]' Valor: %d Direccion %p\n", i, *(pi + i), pi + i); // *(pi + i) accede al valor de la direccion de memoria a la que apunta pi + i. pi + i accede a la direccion de memoria a la que apunta pi + i.
    }
    printf("---------------------------------------------\n");
    // Repita lo mismo con las variables char, el arreglo y el puntero.
    printf("Por variable: 'x' Valor: %c Direccion %p\n", x, &x);
    printf("---------------------------------------------\n");
    pc = &x;                                                       // pc apunta a la direccion de memoria de x.
    printf("Por puntero: 'pc' Valor: %c Direccion %p\n", *pc, pc); // *pc accede al valor de la direccion de memoria a la que apunta pc. pc accede a la direccion de memoria a la que apunta pc.
    printf("---------------------------------------------\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Por variable: 'pal[%d]' Valor: %c Direccion %p\n", i, pal[i], &pal[i]);
    }
    printf("---------------------------------------------\n");
    pc = pal; // pc apunta a la direccion de memoria de pal.
    for (int i = 0; i < 10; i++)
    {
        printf("Por puntero: 'pc[%d]' Valor: %c Direccion %p\n", i, *(pc + i), pc + i); // *(pc + i) accede al valor de la direccion de memoria a la que apunta pc + i. pc + i accede a la direccion de memoria a la que apunta pc + i.
    }
    printf("---------------------------------------------\n");
    // Finalmente muestre la direccion donde se almacenan ambos punteros.
    printf("Direccion de 'pi': %p\n", &pi);
    printf("Direccion de 'pc': %p\n", &pc);
    printf("---------------------------------------------\n");
    return 0;
}
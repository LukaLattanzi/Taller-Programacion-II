#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura Tiempo
typedef struct tiempo
{
    int anio, mes, dia, hora, minuto, segundo;
} Tiempo;

// Función Para Comparar Tiempos
int compara_tiempos(Tiempo *t1, Tiempo *t2);

// Función Para Imprimir Tiempo, Formato: "dia/mes/anio hora:minuto:segundo"
void imprime_tiempo(Tiempo t);

int main()
{
    // Crear Dos Estructuras Tiempo
    Tiempo tiempo1 = {2023, 9, 18, 23, 0, 0};
    Tiempo tiempo2 = {2023, 9, 18, 12, 0, 0};

    // Llamar A La Función Para Comparar Tiempos
    int resultado = compara_tiempos(&tiempo1, &tiempo2);

    // Imprimir El Resultado
    if (resultado == 1)
    {
        printf("Tiempo 1 ( ");
        imprime_tiempo(tiempo1);
        printf(" ) Es Anterior A Tiempo 2 ( ");
        imprime_tiempo(tiempo2);
        printf(" )\n");
    }
    else if (resultado == 0)
    {
        printf("Tiempo 1 ( ");
        imprime_tiempo(tiempo1);
        printf(" ) Es Igual A Tiempo 2 ( ");
        imprime_tiempo(tiempo2);
        printf(" )\n");
    }
    else
    {
        printf("Tiempo 1 ( ");
        imprime_tiempo(tiempo1);
        printf(" ) Es Posterior A Tiempo 2 ( ");
        imprime_tiempo(tiempo2);
        printf(" )\n");
    }

    // Finalizar El Programa Correctamente
    return EXIT_SUCCESS;
}

int compara_tiempos(Tiempo *t1, Tiempo *t2)
{
    if (t1->anio < t2->anio)
    {
        return 1;
    }
    else if (t1->anio > t2->anio)
    {
        return -1;
    }
    else
    {
        // Los años son iguales, compara el mes
        if (t1->mes < t2->mes)
        {
            return 1;
        }
        else if (t1->mes > t2->mes)
        {
            return -1;
        }
        else
        {
            // Los meses son iguales, compara el día
            if (t1->dia < t2->dia)
            {
                return 1;
            }
            else if (t1->dia > t2->dia)
            {
                return -1;
            }
            else
            {
                // Los días son iguales, compara la hora
                if (t1->hora < t2->hora)
                {
                    return 1;
                }
                else if (t1->hora > t2->hora)
                {
                    return -1;
                }
                else
                {
                    // Las horas son iguales, compara el minuto
                    if (t1->minuto < t2->minuto)
                    {
                        return 1;
                    }
                    else if (t1->minuto > t2->minuto)
                    {
                        return -1;
                    }
                    else
                    {
                        // Los minutos son iguales, compara el segundo
                        if (t1->segundo < t2->segundo)
                        {
                            return 1;
                        }
                        else if (t1->segundo > t2->segundo)
                        {
                            return -1;
                        }
                        else
                        {
                            // Si todos los campos son iguales, retorna 0
                            return 0;
                        }
                    }
                }
            }
        }
    }
}

void imprime_tiempo(Tiempo t)
{
    printf("%d/%d/%d %d:%d:%d", t.dia, t.mes, t.anio, t.hora, t.minuto, t.segundo);
}
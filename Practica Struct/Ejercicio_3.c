#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int n;                // grado maximo del polinomio
    double *coeficientes; // arreglo de coeficientes
} Polinomio;

Polinomio *creaPolinomio(int orden);                              /* crea y retorna un nuevo Polinomio */
void setCoef(int n, double c, Polinomio *p);                      /* asigna el n_ésimo coeficiente del Polinomio */
double getCoef(int n, Polinomio *p);                              /* retorna el n_ésimo coeficiente del Polinomio */
double especializa(double x, Polinomio *p);                       /* calcula el polinomio en x usando: ((...((c[n]*x+c[n-1])*x+c[n-2])*x+ ...+c[1]*x)+c[0]) */
Polinomio *sum(Polinomio *p1, Polinomio *p2);                     /* suma dos Polinomios retorna un nuevo Polinomio con el resultado */
Polinomio *mult(Polinomio *p1, Polinomio *p2);                    /* multiplica dos Polinomios y retorna un nuevo Polinomio con el resultado */
Polinomio *deriv(Polinomio *p);                                   /* deriva un Polinomio retornando un nuevo Polinomio con el resultado */
void destruyePolinomio(Polinomio *p);                             /* libera la memoria asociada con el polinomio */
double ceropol(double a, double b, double epsilon, Polinomio *p); /* busque por el método de bisección un cero de un polinomio dentro de un intervalo [a,b], con una precisión dada por épsilon y lo retorne*/

int main(){
    Polinomio *p1 = creaPolinomio(3);
    Polinomio *p2 = creaPolinomio(3);
    setCoef(0, 1, p1);
    setCoef(1, 2, p1);
    setCoef(2, 3, p1);
    setCoef(3, 4, p1);
    setCoef(0, 1, p2);
    setCoef(1, 2, p2);
    setCoef(2, 3, p2);
    setCoef(3, 4, p2);
    Polinomio *p3 = sum(p1, p2);
    Polinomio *p4 = mult(p1, p2);
    Polinomio *p5 = deriv(p1);
    printf("p1(2) = %lf\n", especializa(2, p1));
    printf("p2(2) = %lf\n", especializa(2, p2));
    printf("p3(2) = %lf\n", especializa(2, p3));
    printf("p4(2) = %lf\n", especializa(2, p4));
    printf("p5(2) = %lf\n", especializa(2, p5));
    printf("ceropol(0, 1, 0.0001, p1) = %lf\n", ceropol(0, 1, 0.0001, p1));
    destruyePolinomio(p1);
    destruyePolinomio(p2);
    destruyePolinomio(p3);
    destruyePolinomio(p4);
    destruyePolinomio(p5);
    return 0;
};

Polinomio *creaPolinomio(int orden)
{
    Polinomio *p = (Polinomio *)malloc(sizeof(Polinomio));
    p->n = orden;
    p->coeficientes = (double *)malloc(sizeof(double) * (orden + 1));
    return p;
};

void setCoef(int n, double c, Polinomio *p)
{
    p->coeficientes[n] = c;
};

double getCoef(int n, Polinomio *p)
{
    return p->coeficientes[n];
};

double especializa(double x, Polinomio *p)
{
    double resultado = 0;
    for (int i = 0; i <= p->n; i++)
    {
        resultado = resultado * x + p->coeficientes[i];
    };
    return resultado;
};

Polinomio *sum(Polinomio *p1, Polinomio *p2)
{
    Polinomio *p3 = creaPolinomio(p1->n);
    for (int i = 0; i <= p1->n; i++)
    {
        p3->coeficientes[i] = p1->coeficientes[i] + p2->coeficientes[i];
    };
    return p3;
};

Polinomio *mult(Polinomio *p1, Polinomio *p2)
{
    Polinomio *p3 = creaPolinomio(p1->n + p2->n);
    for (int i = 0; i <= p1->n; i++)
    {
        for (int j = 0; j <= p2->n; j++)
        {
            p3->coeficientes[i + j] += p1->coeficientes[i] * p2->coeficientes[j];
        };
    };
    return p3;
};

Polinomio *deriv(Polinomio *p)
{
    Polinomio *p2 = creaPolinomio(p->n - 1);
    for (int i = 0; i <= p->n - 1; i++)
    {
        p2->coeficientes[i] = p->coeficientes[i + 1] * (i + 1);
    };
    return p2;
};

void destruyePolinomio(Polinomio *p)
{
    free(p->coeficientes);
    free(p);
};

double ceropol(double a, double b, double epsilon, Polinomio *p)
{
    double c = (a + b) / 2;
    if (b - a < epsilon)
    {
        return c;
    }
    else if (especializa(a, p) * especializa(c, p) < 0)
    {
        return ceropol(a, c, epsilon, p);
    }
    else
    {
        return ceropol(c, b, epsilon, p);
    };
};
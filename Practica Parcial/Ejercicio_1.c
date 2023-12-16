#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct alumno
{
    char nombre[20];
    char carrera[20]; // Tener En Cuenta Que Las Carreras Son: AUS - TUC - TUQ
};

struct alumno *Nomina[50];

// A) Permitir El Ingreso De Alumnos A La Nomina

void ingresarAlumno(int i)
{
    struct alumno *alumno = (struct alumno *)malloc(sizeof(struct alumno));
    printf("------------------------------------\n");
    printf("Ingrese El Nombre Del Alumno (NombreApellido): ");
    scanf("%s", alumno->nombre);
    do
    {
        printf("Ingrese La Carrera Del Alumno (AUS - TUC - TUQ): ");
        scanf("%s", alumno->carrera);
        if (strcmp(alumno->carrera, "AUS") != 0 && strcmp(alumno->carrera, "TUC") != 0 && strcmp(alumno->carrera, "TUQ") != 0)
        {
            printf("Carrera No Valida. Ingrese AUS - TUC - TUQ.\n");
        }
    } while (strcmp(alumno->carrera, "AUS") != 0 && strcmp(alumno->carrera, "TUC") != 0 && strcmp(alumno->carrera, "TUQ") != 0);
    printf("------------------------------------\n");
    Nomina[i] = alumno;
}

// B) Listar A Los Alumnos Por La Carrera Ingresada

void listarAlumnosPorCarrera(char carrera[20])
{
    printf("------------------------------------\n");
    printf("Alumnos De La Carrera %s\n", carrera);
    for (int i = 0; i < 50; i++)
    {
        if (Nomina[i] != NULL)
        {
            if (strcmp(Nomina[i]->carrera, carrera) == 0)
            {
                printf("- %s\n", Nomina[i]->nombre);
            }
        }
    }
    printf("------------------------------------\n");
}

// C) Dar el numero de alumnos por carrera

void numeroDeAlumnosPorCarrera(char carrera[20])
{
    int contador = 0;
    for (int i = 0; i < 50; i++)
    {
        if (Nomina[i] != NULL)
        {
            if (strcmp(Nomina[i]->carrera, carrera) == 0)
            {
                contador++;
            }
        }
    }
    printf("------------------------------------\n");
    printf("El Numero De Alumnos En La Carrera %s Es De: %d\n", carrera, contador);
    printf("------------------------------------\n");
}

// D) Buscar un alumno determinado por el nombre y mostrar sus datos

void buscarAlumnoPorNombre(char nombre[20])
{
    for (int i = 0; i < 50; i++)
    {
        if (Nomina[i] != NULL)
        {
            if (strcmp(Nomina[i]->nombre, nombre) == 0)
            {
                printf("------------------------------------\n");
                printf("Nombre Del Alumno: %s\n", Nomina[i]->nombre);
                printf("Carrera Del Alumno: %s\n", Nomina[i]->carrera);
                printf("------------------------------------\n");
            }
        }
    }
}

int main()
{
    int opcion;
    int i = 0;
    char carrera[20];
    char nombre[20];
    do
    {
        printf("------------------------------------\n");
        printf("1) Ingresar Alumno\n");
        printf("2) Listar Alumnos Por Carrera\n");
        printf("3) Numero De Alumnos Por Carrera\n");
        printf("4) Buscar Alumno Por Nombre\n");
        printf("5) Salir\n");
        printf("------------------------------------\n");
        printf("Ingrese Una Opcion: ");
        scanf("%d", &opcion);
        switch (opcion)
        {
        case 1:
            ingresarAlumno(i);
            i++;
            break;
        case 2:
            printf("------------------------------------\n");
            do
            {
                printf("Ingrese La Carrera Del Alumno (AUS - TUC - TUQ): ");
                scanf("%s", carrera);
                if (strcmp(carrera, "AUS") != 0 && strcmp(carrera, "TUC") != 0 && strcmp(carrera, "TUQ") != 0)
                {
                    printf("Carrera No Valida. Ingrese AUS - TUC - TUQ.\n");
                }
            } while (strcmp(carrera, "AUS") != 0 && strcmp(carrera, "TUC") != 0 && strcmp(carrera, "TUQ") != 0);
            listarAlumnosPorCarrera(carrera);
            break;
        case 3:
            printf("------------------------------------\n");
            do
            {
                printf("Ingrese La Carrera (AUS - TUC - TUQ): ");
                scanf("%s", carrera);
                if (strcmp(carrera, "AUS") != 0 && strcmp(carrera, "TUC") != 0 && strcmp(carrera, "TUQ") != 0)
                {
                    printf("Carrera No Valida. Ingrese AUS - TUC - TUQ.\n");
                }
            } while (strcmp(carrera, "AUS") != 0 && strcmp(carrera, "TUC") != 0 && strcmp(carrera, "TUQ") != 0);
            numeroDeAlumnosPorCarrera(carrera);
            break;
        case 4:
            printf("------------------------------------\n");
            printf("Ingrese El Nombre Del Alumno: ");
            scanf("%s", nombre);
            buscarAlumnoPorNombre(nombre);
            break;
        case 5:
            printf("------------------------------------\n");
            printf("Finalizando Programa...\n");
            break;
        default:
            printf("------------------------------------\n");
            printf("Opcion Invalida\n");
            break;
        }
    } while (opcion != 5);
    return EXIT_SUCCESS;
}
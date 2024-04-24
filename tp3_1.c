#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#define FILA 5
#define COLUMNA 12
int main(int argc, char const *argv[])
{
    int suma = 0, vMax = 0, vMin = 50001, anioMax, mesMax, anioMin, mesMin;
    int matriz[FILA][COLUMNA];
    int promAnio[FILA];
    srand(time(NULL));
    for (int i = 0; i < FILA; i++)
    {
        printf("|");
        for (int j = 0; j < COLUMNA; j++)
        {
            matriz[FILA][COLUMNA] = rand()%(10000 - 50000 + 1) + 10000;
            printf(" %i ", matriz[FILA][COLUMNA]);
            suma = matriz[FILA][COLUMNA] + suma;
            if(matriz[FILA][COLUMNA] > vMax){
                vMax = matriz[FILA][COLUMNA];
                anioMax = i;
                mesMax = j;
            }
                if(matriz[FILA][COLUMNA] < vMin){
                vMin = matriz[FILA][COLUMNA];
                anioMin = i;
                mesMin = j;
            }
        }
        promAnio[i]= suma / 12;
        printf(" |\n");
        suma = 0;
    }
    printf("\n/********** PROMEDIO POR ANIO **************/\n");
    for (int i = 0; i < FILA; i++)
    {
        printf("ANIO %d: %i\n", i+1, promAnio[i]);
    }
    printf("\n/************ VALORES NOTABLES **************/\n");
    printf("Valor Maximo: %i - Anio: %i - Mes: %i \n", vMax, anioMax +1, mesMax+1);
    printf("Valor Minimo: %i - Anio: %i - Mes: %i \n", vMin, anioMin +1, mesMin +1);
    return 0;
}
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#define TAMA 5 //Modificacion del Punto 5

int main(int argc, char const *argv[])
{
    char **v;
    int cantNombres;
    printf("Ingresar la cantidad de Nombres que va a introducir: \n"); //Modificacion del Punto 5
    scanf("%d", &cantNombres);//Modificacion del Punto 5
    v =(char **)malloc(cantNombres * sizeof(char *));
    char buff[100];
    for (int i = 0; i < cantNombres; i++)//Modificacion del Punto 5
    {
        printf("ingrese la palabra %d: ", i+1);
        gets(buff);
        v[i] = (char *)malloc(sizeof(char)*(strlen(buff)+1));
        strcpy(v[i], buff);
    }
    for (int i = 0; i < cantNombres; i++)//Modificacion del Punto 5
    {
        printf("\n Palabra %d: %s", i+1, v[i]);
    }
    for (int i = 0; i < cantNombres; i++)//Modificacion del Punto 5
    {
        free(v[i]);
    }
    free(v);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
struct Producto {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
 }typedef Producto;

 struct Cliente {
 int ClienteID; // Numerado en el ciclo iterativo
 char *NombreCliente; // Ingresado por usuario
 int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
 Producto *Productos; //El tamaño de este arreglo depende de la variable
 // "CantidadProductosAPedir"
 }typedef clientes;
float costoProducto(Producto Productos);
int main(int argc, char const *argv[])
{
    float suma = 0;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    int cliente;
    do
    {
        printf("Ingresar la Cantidad de clientes a visitar (MAX 5): ");
        scanf("%d", &cliente);
    } while (cliente > 5 || cliente <= 0);
    clientes *cl;
    cl = (clientes *)malloc(cliente * sizeof(clientes));

    for (int i = 0; i < cliente; i++)
    {
        cl[i].NombreCliente = (char *)malloc(25 * sizeof(char));
        printf("/-----------ALTA CLIENTE-----------/\n");
        cl[i].ClienteID = i+1;
        printf("Ingresar nombre del cliente: ");
        fflush(stdin);
        gets(cl[i].NombreCliente);
        cl[i].CantidadProductosAPedir = rand()%(1-5+1)+1;
        cl[i].Productos = (Producto *)malloc(cl[i].CantidadProductosAPedir * sizeof(Producto));
        printf("\nNombre de Cliente: %s \nID: %d \nCantidad de Productos a Pedir: %d ", cl[i].NombreCliente, cl[i].ClienteID, cl[i].CantidadProductosAPedir);
        printf("\n\n/-----------PRODUCTOS DEL CLIENTE DE ID : %d-----------/\n",cl[i].ClienteID);
        for (int j = 0; j < cl[i].CantidadProductosAPedir; j++)
        {
            cl[i].Productos[j].Cantidad = rand()%(1-10+1)+1;
            cl[i].Productos[j].TipoProducto = TiposProductos[rand()%(0 - 4 + 1)+0];
            cl[i].Productos[j].PrecioUnitario = rand()%(10-100+1)+10;
            float pagar = costoProducto(cl[i].Productos[j]);
            suma = suma + pagar;
            cl[i].Productos[j].ProductoID = j +1;
            printf("\nID del producto: %d \nCantidad del Producto: %d \nTipo de Producto: %s \nPrecio del producto:$ %.2f\nCosto Total del producto:$ %.2f\n",cl[i].Productos[j].ProductoID, cl[i].Productos[j].Cantidad, cl[i].Productos[j].TipoProducto, cl[i].Productos[j].PrecioUnitario, pagar);
        }
        printf("\n\nTOTAL A PAGAR POR EL CLIENTE: $ %.2f\n", suma);
    }
    for (int i = 0; i < cliente; i++)
    {
        for (int j = 0; j < cl[j].CantidadProductosAPedir; j++)
        {
            free(cl[i].Productos);
        }
        free(cl[i].NombreCliente);
    }
    free(cl);
    return 0;
}
float costoProducto(Producto Productos){
    float resultado;
    resultado = Productos.Cantidad * Productos.PrecioUnitario;
    return resultado;
}
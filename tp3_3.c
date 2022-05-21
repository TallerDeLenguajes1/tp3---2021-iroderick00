#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define longitud 5

char *tiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

typedef struct producto{
    int productoID; //numerado en ciclo iterativo
    int cantidad; //entre 1 y 10
    char *tipoProducto; //algun valor del arreglo tiposProductos
    float precioUnitario; //entre 10 y 100
}producto;

typedef struct cliente{
    int clienteID; //numerado en el ciclo iterativo
    char *nombreCliente; //ingresado por el usuario
    int cantidadProductosAPedir; //aleatorio entre 1 y 5
    producto *productos; //el tamaño de este arreglo depende de la variable anterior
}cliente;

cliente * cargarClientes(cliente *,int);
int calcularCosto(producto);
void mostrarProducto(producto);
void mostrarClientes(cliente *,int);

void main(){
    cliente *listado;
    int numeroDeClientes;
    srand(time(NULL));

    printf("\nIngrese la cantidad de clientes que desea cargar: ");
    scanf("%d", &numeroDeClientes);
    listado=cargarClientes(listado,numeroDeClientes);
    mostrarClientes(listado,numeroDeClientes);
    
    fflush(stdin);
    getchar();
}

cliente * cargarClientes(cliente *listado,int numeroDeClientes){
    char *buff=(char*)malloc(30*sizeof(char));
    int random;
    listado=(cliente *)malloc(numeroDeClientes*sizeof(cliente));
    for (int i = 0; i < numeroDeClientes; i++)
    {
        (listado+i)->clienteID=i+1;
        fflush(stdin);
        printf("\nIngrese el nombre del usuario numero %d: ",i+1);
        gets(buff);
        (listado+i)->nombreCliente=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy((listado+i)->nombreCliente,buff);
        (listado+i)->cantidadProductosAPedir=rand()%5+1;
        (listado+i)->productos=(producto *)malloc((listado+i)->cantidadProductosAPedir*sizeof(producto));//unu
        for (int j = 0; j<(listado+i)->cantidadProductosAPedir; j++)
        {
            (((listado+i)->productos)+j)->productoID=j+1;
            (((listado+i)->productos)+j)->cantidad=rand()%10+1;
            random=rand()%5;
            (((listado+i)->productos)+j)->tipoProducto=(char *)malloc((strlen(tiposProductos[random])+1)*sizeof(char));//unu
            strcpy((((listado+i)->productos)+j)->tipoProducto,tiposProductos[random]);
            (((listado+i)->productos)+j)->precioUnitario=rand()%91+10;
        }
    }
    return listado;
}

int calcularCosto(producto producto){
    int total;
    total=producto.cantidad*producto.precioUnitario;
    return total;
}

void mostrarProducto(producto producto){
    printf("\n\nProducto con ID: %d. %s",producto.productoID,producto.tipoProducto);
    printf("\nCantidad encargada de este producto: %d",producto.cantidad);
    printf("\nPrecio unitario: %d",producto.precioUnitario);
}

void mostrarClientes(cliente *listado, int numeroDeClientes){
    int total=0;
    printf("\n--------------------LISTADO DE CLIENTES--------------------\n");
    for (int i = 0; i < numeroDeClientes; i++)
    {
        printf("\nCLIENTE NUMERO %d",(listado+i)->clienteID);
        printf("\nNOMBRE: %s",(listado+i)->nombreCliente);
        printf("\nEN SU ORDEN TIENE %d PRODUCTOS",(listado+i)->cantidadProductosAPedir);
        for (int j = 0; j < (listado+i)->cantidadProductosAPedir; j++)
        {
            mostrarProducto(*(((listado+i)->productos)+j));
            total+=calcularCosto(*(((listado+i)->productos)+j));
        }
        printf("\nEL TOTAL A PAGAR POR ESTE CLIENTE ES: %d",total);
    }
    printf("\n--------------------FIN DE LISTADO--------------------\n");
}
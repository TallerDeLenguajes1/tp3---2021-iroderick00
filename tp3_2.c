#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define longitud 5

int main(){
    char *buff, *vector[longitud];
    buff=(char*)malloc(100*sizeof(char));
    for (int i = 0; i < longitud; i++)
    {
        printf("Ingrese la cadena de caracteres %d: ",i+1);
        gets(buff);
        *(vector+i)=(char*)malloc((strlen(buff)+1)*sizeof(char));
        strcpy(*(vector+i),buff);
    }
    free(buff);
    system("cls");
    for (int j = 0; j < longitud; j++)
    {
        puts(*(vector+j));
        free(*(vector+j));
    }
    getchar();
    return 0;
}
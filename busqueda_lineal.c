// Escribe aquí la implementación de los ejercicios de búsqueda lineal simple
#include<stdio.h>
#include<stdlib.h>

int simple_lineal_search(int *A, int n, int x){
    int k = x; // k es nuestra variable auxiliar.
    int i = 0; // i es un contador para iterar en el arreglo completo.
    for (i = 0; i < n; i++){
        if(A[i] == k){ //Si el valor en la posicion A[i] es igual a k (la llave), se retorna el indice en que se encontro primero
            return i;
        }
        i++;
    }
    return -1;
}


int main(){
   int tam, x; // La variable tam se refiere al tamano del arreglo, x es la llave
    int *ap;
    //Usando memoria dinamica, almacenamos el arreglo
    printf("Ingrese el tamano del arreglo: ");
    scanf("%i", &tam); //Solicitamos al usuario el tamano del arreglo
    if(tam > 0){ //Comprobamos casos especiales con entradas erroneas
        ap = (int*)malloc(tam);
        for (int i = 0; i < tam; i++){
        scanf("%i", &ap[i]);
        }
        printf("Numero a buscar: ");
        scanf("%i", &x);
        int var1 = simple_lineal_search(ap, tam, x);
        if(ap[var1] == x){
            printf("El valor fue encontrado en el indice %i.\n", var1); //mostramos en pantalla el resultado de la busqueda
        }
        else{
        printf("El valor NO fue encontrado."); //Si no fue encontrado, se le hace saber al usuario.
        }
        //Liberamos la memoria reservada para el arreglo en memoria dinamica
        free(ap);
    }
    else{
        printf("El tamano del arreglo debe ser mayor a cero\n"); //Consecuencia de casos especiales de entradas erroneas.
    }
    return 0;
}// Escribe aquí la implementación de los ejercicios de búsqueda lineal.

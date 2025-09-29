// Escribe aquí la implementación de los ejercicios de búsqueda lineal recursiva
#include<stdio.h>
#include<stdlib.h>
int recursive_lineal_search(int *A, int n, int x){
    if(n == 0){
        return -1; //Caso base
    }
    else if (A[n - 1] == x){
        return n - 1; //Retornamos el ultimo elemento del arreglo, si es que cumple la condicion.
    }
    recursive_lineal_search(A, n-1, x); //Aplicamos recursion para el elemento penultimo del arreglo.
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
        scanf("%i", &ap[i]); //Se guarda el arreglo introducido por el usuario.
        }
        printf("Numero a buscar: ");
        scanf("%i", &x);
        int var1 = recursive_lineal_search(ap, tam, x);
        if(ap[var1] == x){
            printf("El valor fue encontrado en el indice %i.\n", var1); //mostramos en pantalla el resultado de la busqueda
        }
        else{
        printf("El valor NO fue encontrado."); //Si no fue encontrado, se le hace saber al usuario.
        }
    
    }
    else{
        printf("El tamano del arreglo debe ser mayor a cero\n"); //Consecuencia de casos especiales de entradas erroneas.
    }
    return 0;
}
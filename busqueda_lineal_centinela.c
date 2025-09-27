// Escribe aquí la implementación de los ejercicios de búsqueda lineal con centinela
#include<stdio.h>
#include<stdlib.h>
int sentinel_lineal_search(int *A, int n, int x){
    int tmp = A[n-1]; //Guardamos el ultimo valor del arreglo en una variable temporal.
    A[n-1] = x; // Cambiamos el valor guardado en A[n-1] por nuestra llave (que funge como centinela)
    int i = 0; //Inicializamos nuestro contador
    while (A[i] != x){ //Si el valor en A[i] no es igual a nuestro sentinela, agregamos uno al contador.
        i++; 
    }
    A[n-1] = tmp; //Regresamos el valor almacenado en la variable temporal a su posicion correspondiente en el arreglo.
    if(i < n || A[n-1] == x){ /*Comprobamos dos cosas: 1. Que el valor del indice sea menor al tamano del arreglo (lo que significa que termino antes),
        2. Si el valor de la última posicion es igual a nuestra llave, entonces el valor se encontraba dentro del arreglo.
        Si no se cumple alguna de estas condiciones, significa que el valor x que buscabamos nunca estuvo en el arreglo, pero nos sirvio para detener el while*/
        return i;
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
        scanf("%i", &ap[i]); //Se guarda el arreglo introducido por el usuario.
        }
        printf("Numero a buscar: ");
        scanf("%i", &x);
        int var1 = sentinel_lineal_search(ap, tam, x);
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
}

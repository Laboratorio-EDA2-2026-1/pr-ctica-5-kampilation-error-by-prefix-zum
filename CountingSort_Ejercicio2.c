#include <stdio.h>

typedef enum { ROJO, BLANCO, AZUL } Color; //Usamos un enum para cada color

//Función para imprimir el arreglo
void imprimirArreglo(Color A[], int n){
    for (int i = 0; i < n; i++) {
        switch (A[i]) {
            case ROJO:   printf("Rojo ");   break;
            case BLANCO: printf("Blanco "); break;
            case AZUL:   printf("Azul ");   break;
        }
    }
    printf("\n");
}

Color examine(Color A[], int i){ //Para verificar el elemento i en A
    return A[i];
}

void swap(Color A[], int i, int j){ //Intercambia el elemento i por j y j por i en A
    Color temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

//
void sort(Color A[], int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;

    //El bucle se ejecuta mientras haya elementos desconocidos (mid <= high)
    while (mid <= high) {
        //Usamos examine para verificar el color del elemento 
        switch (examine(A, mid)) {
            case ROJO:
                //Si es rojo, lo mandamos al principio
                swap(A, low, mid);
                low++;
                mid++;
                break;

            case BLANCO:
                //Si es blanco, está en la sección correcta y no hacemos nada
                mid++;
                break;

            case AZUL:
                //Si es azul, lo mandamos al final
                swap(A, mid, high);
                high--;
                //No movemos mid para que el elemento en high sea procesado en la siguiente iteracion
                break;
        }
    }
}

int main(){
    int n;
    printf("Ingrese el tamaño del arreglo: "); //Solicitamos el tamaño
    scanf("%i", &n);
    Color arr[n]; //Creamos el arreglo del tamaño solicitado

    printf("1) Rojo, 2) Blanco, 3) Azul\n");

    for(int i = 0; i < n; i++){ //Solicitamos el arreglo al usuario
        printf("Color del elemento %i: ", i+1);
        int k = 0;
        scanf("%i", &k);
        switch(k) {
            case 1: arr[i] = ROJO;   break;
            case 2: arr[i] = BLANCO; break;
            case 3: arr[i] = AZUL;   break;
        }
    }

    n = sizeof(arr) / sizeof(arr[0]); //Tamaño del arreglo con tamaño de sus elementos

    printf("Arreglo original: "); //Imprimimos el arreglo original
    imprimirArreglo(arr, n);

    sort(arr, n);

    printf("Arreglo ordenado: "); //Imprimimos el arreglo ordenado
    imprimirArreglo(arr, n);

    return 0;
}
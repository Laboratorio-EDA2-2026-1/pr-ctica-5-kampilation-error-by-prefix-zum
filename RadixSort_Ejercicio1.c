// Escribe aquí la implementación del ejercicio de Radix Sort.

#include <stdio.h>
#include <stdlib.h>

void countingSortByDigit(int arr[], int exp, int n){
    int output[n]; //Creamos un arreglo de salida
    int count[10] = {0}; //Creamos nuestro arreglo C

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++; //Contamos las frecuencias de ese digito para cada numero

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1]; //Hacemos una suma de prefijos en el arreglo C

    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;    //obtenemos el digito buscado para cada numero
        output[count[digit] - 1] = arr[i]; //Agregamos a output en el indice del elemento digit del arreglo count -1, el elemento del arreglo original
        count[digit]--; //Restamos una frecuencia de ese elemento
    }

    for (int i = 0; i < n; i++) { //Pasamos todos los elementos del arreglo de salida al original, para mantener las modificaciones.
        arr[i] = output[i];
}
}

void radixSort(int arr[], int n) {
    int maxVal = -1; //inicializamos una variable con -1 para obtener el maximo valor del arreglo ingresado

    for(int i = 0; i < n; i++) //Obtenemos el maximo
        if(arr[i] > maxVal) maxVal = arr[i];

    for (int exp = 1; maxVal / exp > 0; exp *= 10) //Para cada digito del numero mas grande, se realiza un counting sort, llevando cuenta del digito en el que vamos
        countingSortByDigit(arr, exp, n);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66}; //arreglo de ejemplo
    int n = 8; //tamaño del arreglo de ejemplo
    radixSort(arr, n); // llamada a la funcion de ordenamiento

    for(int i = 0; i < n; i++) //Impresion del arreglo ordenado
        printf("%i ", arr[i]);

    return 0;
}
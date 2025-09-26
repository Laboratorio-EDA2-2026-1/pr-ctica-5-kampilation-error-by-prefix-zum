// Escribe aquí la implementación de los ejercicios de Counting Sort.
#include<stdio.h>
#include<stdlib.h>

char* leerCadena(int *n){
    int bufferi = 30, incremento = 5;
    char *cadena = malloc(bufferi);
    int capacidad = bufferi;
    int longitud = 0;
    char c;

    while((c = getchar()) != '\n'){
        if(longitud+1 >= capacidad){
            capacidad += incremento;
            char *temp = realloc(cadena, capacidad);
            cadena = temp;
        }
        cadena[longitud++] = c;
    }

    cadena[longitud] = '\0';
    *n = longitud;

    return cadena;
}

void countSort(char inputArray[], int N) {

    //Busqueda del maximo elemento
    int M = 0;
    for (int i = 0; i < N; i++)
        if (inputArray[i] > M)
            M = inputArray[i];
    
    //Inicializar todo en 0 (el minimo valor)
    int* countArray = (int*)calloc(M + 1, sizeof(int));

    //Conteo de frecuencias en el auxiliar
    for (int i = 0; i < N; i++)
        countArray[inputArray[i]]++;
    
    //Suma de prefijos para todo el arreglo
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    
    // Creating outputArray[] from countArray[] array
    char* outputArray = (char*)malloc(N * sizeof(char));
    for (int i = N - 1; i >= 0; i--) {
        outputArray[countArray[inputArray[i]] - 1] = inputArray[i];
        countArray[inputArray[i]]--;
    }
    
    // Copying sorted elements back to inputArray[]
    for (int i = 0; i < N; i++){
        inputArray[i] = outputArray[i];
        printf("%c", outputArray[i]);
    }
    
    
    // Freeing dynamically allocated memory
    free(countArray);
    free(outputArray);
}


int main(){
    int n = 0;
    char *s = leerCadena(&n);
    char arns[n];

    for(int i = 0; i < n; i++){
        arns[i] = s[i]; 
    }
    
    countSort(arns, n);
    return 0;
}
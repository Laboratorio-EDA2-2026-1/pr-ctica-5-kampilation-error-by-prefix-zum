// Escribe aquí la implementación de los ejercicios de Counting Sort.
#include<stdio.h>
#include<stdlib.h>

char* leerCadena(int *n){ //Funcion que lee un string de manera dinamica
    int bufferi = 5, incremento = 5; //el buffer es el tamaño inicial del arreglo dinamico, el incremento, la cantidad de caracteres que se le asignaran al llenar los solicitados
    char *cadena = malloc(bufferi); //se crea el arreglo dinamico de caracteres
    int capacidad = bufferi; // la capacidad se inicializa en el tamaño inicial
    int longitud = 0; //La longitud de la cadena empieza en 0
    char c;

    while((c = getchar()) != '\n'){ //Cada vez que leamos un caracter, mientras no sea un salto de linea se realizara
        if(longitud+1 >= capacidad){ //Si se excedió el tamaño del arreglo dinámico:
            capacidad += incremento; //A la capacidad se le suma el incremento
            char *temp = realloc(cadena, capacidad); //Se usa un arreglo dinamico secundario para solicitar más memoria
            cadena = temp; //Se asigna el arreglo secundario al original
        }
        cadena[longitud++] = c; //Se agrega el caracter a la cadena
    }

    cadena[longitud] = '\0'; //Se asigna el caracter vacio
    *n = longitud; //Regresamos n para poder usarlo en el countingSort

    return cadena; //Regresamos la cadena
}

void countSort(char arr[], int N) {

    //Busqueda del maximo elemento
    int M = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] > M)
            M = arr[i];
    
    //Inicializar todo en 0 (el minimo valor)
    int* C = (int*)calloc(M + 1, sizeof(int));

    //Conteo de frecuencias en el auxiliar
    for (int i = 0; i < N; i++)
        C[arr[i]]++;
    
    //Suma de prefijos para todo el arreglo
    for (int i = 1; i <= M; i++)
        C[i] += C[i - 1];
    
    // Crea el arreglo de salida a partir del de entrada
    char* out = (char*)malloc(N * sizeof(char));
    for (int i = N - 1; i >= 0; i--) {
        out[C[arr[i]] - 1] = arr[i];
        C[arr[i]]--;
    }
    
    //Imprime el arreglo de salida
    for (int i = 0; i < N; i++){
        printf("%c", out[i]);
    }

    free(C); //Libera la memoria dinámica
    free(out);
}


int main(){
    int n = 0; //Tamaño del arreglo inicial
    char *s = leerCadena(&n); //Arreglo dinamico para cadenas de cualquier tamaño
    char arns[n];

    for(int i = 0; i < n; i++){ //Convierte el arreglo dinamico en estatico
        arns[i] = s[i]; 
    }
    
    countSort(arns, n); //Llama a la funcion countSort para ordenar el arreglo
    return 0;
}
// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
#include<stdio.h>
#include<stdlib.h>

int binary_search(int *Array, int key, int left, int right){
    //Planteamos el caso base
    if(left <= right){ //Si esto se cumple, entonces el tamaño del arreglo es diferente de uno
        //Hacemos la funcion piso, tal cual como se vio en clase:
        //El piso es nuestro valor medio
        int floor = left + (right - left) / 2; //Este es el valor del medio
        if (Array[floor] == key){ //Si la llave que buscamos esta justo en el medio, entonces ya no hay que pensarle nada.
            return floor;
        }
        if (Array[floor] > key){ //Si esta condicion se cumple, entonces encontramos la cota superior, no nos interesa esa parte.
            return binary_search(Array, key, left, floor-1 ); //La recursion solo se aplica a la mitad izquierda del arreglo.
        }
        if (Array[floor] < key){
            return binary_search(Array, key, floor + 1, right); //La recursion solo se aplica a la mitad derecha del arreglo.
        }
    }
    return -1; // Significa que el valor no fue encontrado
}


int main(){
    int x;
    int size;
    printf("\nIngrese el tamano del arreglo: ");
    scanf("%i", &size);
    if(size > 0){
        //Reservamos el espacio para el arreglo usando memoria dinamica
        int *ap;
        ap = (int*)malloc(sizeof(int) * size);
        printf("\n Ingrese el arreglo: \n");
        for (int i = 0; i < size; i++){
            scanf("%i", &ap[i]);
        }
        printf("\n Ingrese el valor a buscar: \t");
        scanf("%i", &x);
    //Ejecutamos la busqueda binaria recursiva
    int var = binary_search(ap, x, 0, size - 1);
        if(var == -1){
            printf("\nEl valor %i no se encuentra en el arreglo.", x);
        }
        else{
            printf("\nEl valor %i se encuentra en el arreglo en la posicion %i", x, var);
        }
        //Liberamos la memoria reservada para el arreglo en memoria dinamica
        free(ap);
    }
    else {
        printf("\nEl tamano del arreglo no es valido. \n");
    }
    
    return 0;
}

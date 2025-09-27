// Escribe aqui la implementación de los ejercicios de búsqueda binaria.
#include<stdio.h>
#include<stdlib.h>

void aprox_binary_search(int *B, double x, int k){
    int i = 0; //Usamos un contador
    double left = 0.00; //Definimos left y right en la funcion porque lo vamos a implementar de manera operativa.
    double right = 1.00; //El ejercicio dice que x pertenece al intervalo [0,1)

    for (i = 0; i < k; i++){
        //Obtenemos el valor medio mediante la funcion piso.
        double mid = left + (right - left)/ 2.00;
        if(x < mid){ //Cota superior. Si se cumple, hablamos de la mitad izq del intervalo.
            B[i] = 0; //Ponemos el cero solicitado en la posicion del bit.
            printf("[%i]. Intervalo = [%.6f , %.6f), medio = %.6f , Valor impreso: [%i]\n", i+1, left, right, mid, B[i]);
            /*Mostramos en pantalla la informacion tal cual el ejemplo de ejecucion. 
            Posteriormente, se mostrara el arreglo completo en la funcion main.*/ 

            right = mid; //Tratamos de acotar aun mas convirtiendo el intervalo a [left, mid).
        }
        else if(x >= mid){ //Cota inferior. Si se cumple, hablamos de la mitad der del intervalo.
            B[i] = 1; //Ponemos el uno solicitado en la posicion del bit.
            printf("[%i]. Intervalo = [%.6f , %.6f), medio = %.6f , Valor impreso: [%i]\n", i+1, left, right, mid, B[i]);
            left = mid; //Tratamos de acotar aun mas convirtiendo el intervalo a [mid, right).
        }
    }
}


int main(){
    double x; //El valor a aproximar
    int k; //El numero de iteraciones a realizar
    printf("\nIngrese el numero de pasos para aproximar el arreglo: ");
    scanf("%i", &k);

    if(k > 0){
        //Reservamos el espacio para el arreglo usando memoria dinamica
        int *ap;
        ap = (int*)malloc(sizeof(int) * k);
        printf("\n Ingrese el valor a aproximar: \t");
        scanf("%lf", &x);

        if(x >= 0.00 && x < 1.00){
            //Ejecutamos la busqueda binaria recursiva
            aprox_binary_search(ap, x, k);  
            //Mostramos el arreglo en pantalla.
            int a = 0;

            printf("\no.o.o|Aproximacion de 'x' en terminos de bits|o.o.o");
            printf("\n 0.");

            while(a < k){ //Mostramos todos los elementos del arreglo que representa al binario de la aproximacion de 'x'.
                printf("%i", ap[a]);
                a++;
            }      
        }
        else{ printf("\nEl valor de x no pertenece al intervalo 0 <= x < 1\n");} //Caso en que la 'x' ingresada sea igual o mayor a 1.
        //Liberamos la memoria reservada para el arreglo en memoria dinamica
        free(ap);
    }
    else{
        printf("\nEl numero de pasos no es valido. Debe ser al menos uno\n");
    }
    
    return 0;
}
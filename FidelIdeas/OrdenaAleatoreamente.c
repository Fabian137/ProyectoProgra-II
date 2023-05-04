#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct Lugar{
    int clave;

}; 

int generardatos(struct Lugar *A, int n);
int aleatorio(int min, int max); 


int main(){
    struct Lugar *ayuda;
    ayuda=(struct Lugar *) malloc(16 * sizeof(struct Lugar)); 
    


    int i, n; 
    n = 16;

    srand(getpid());

    generardatos(ayuda, n);

    printf("\n\nArreglo Original: \n"); 

    for(i=0; i < n; i++){

        printf("El dato %d es : %d \n\n", i, ayuda[i].clave);

    } 


    for(i=0; i < n; i++){
        int indicealeatorio, temporal; 
        indicealeatorio = aleatorio (0, n-1); 

        temporal = ayuda[i].clave;
        ayuda[i].clave = ayuda[indicealeatorio].clave;
        ayuda[indicealeatorio].clave = temporal; 

    }

    printf("\n\nArreglo mezclado\n");

      for(i=0; i < n; i++){

        printf("\n El dato %d es : %d \n\n", i, ayuda[i].clave);

    } 

    return 0; 
}

int generardatos(struct Lugar *A, int n){
    int i;
    for(i=0; i < n; i++){
        A[i].clave = i;
    }
    return 0; 
}

int aleatorio(int min, int max){

return min + rand()/ (RAND_MAX/ (max - min + 1 ) + 1);

}
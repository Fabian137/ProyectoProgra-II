# include <stdio.h>
#include <stdlib.h>
struct Lugar{
    int NumRand, clave;

}; 

int generardatos(struct Lugar *A, int n);


int main(){
    struct Lugar *ayuda;
    ayuda=(struct Lugar *) malloc(16 * sizeof(struct Lugar)); 



    int k1, k2, aux, n, lista[20]; 
    n = 16;

    generardatos(ayuda, n);

    for(k1=0; k1<n; k1++){
        printf("El dato generado %d es : %d ", ayuda[k1].clave, ayuda[k1].NumRand);
    }
    

    for(k1=0; k1<n; k1++){
        for(k2=0; k2<n; k2++){
            if(ayuda[k1].NumRand> ayuda[k2].NumRand){
                aux= ayuda[k1].NumRand;
                ayuda[k1].NumRand= ayuda[k2].NumRand;
                ayuda[k2].NumRand= aux;
            }

        }     
    }

 for(k1=0; k1<n; k1++){
        printf("Los dato ordenados son: \n\n");
        printf("%d", ayuda[k1].NumRand);
    }
    


    return 0; 
}

int generardatos(struct Lugar *A, int n){
    int i;
    for(i=0; i < n; i++){
        A[i].clave = i; 

        A[i].NumRand = rand()%200; 

    }

    return 0; 
}
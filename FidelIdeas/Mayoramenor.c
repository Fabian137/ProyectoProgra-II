# include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Lugar{
    int NumRand, clave, NumOrder;

}; 

int generardatos(struct Lugar *A, int n);
int identificadorClave(int n, int iden, struct Lugar *a);


int main(){
    struct Lugar *ayuda;
    ayuda=(struct Lugar *) malloc(16 * sizeof(struct Lugar)); 
    FILE *archivo = fopen("valuesTeams.csv", "w");
    int ord;

    int k1, k2, aux, n, lista[20]; 
    n = 4;

    generardatos(ayuda, n);

    for(k1=0; k1<n; k1++){
        // printf("El dato generado %d es : %d \n\n", ayuda[k1].clave, ayuda[k1].NumRand);
    }
    

    for(k1=0; k1<n; k1++){
        //  ayuda[k1].NumOrder = k1;
        // fprintf(archivo, "%d, %d, \n", ayuda[k1].NumOrder, ayuda[k1].clave);
        for(k2=0; k2<n; k2++){
            if(ayuda[k1].NumRand> ayuda[k2].NumRand){
                aux= ayuda[k1].NumRand;
                ayuda[k1].NumRand= ayuda[k2].NumRand;
                ayuda[k2].NumRand= aux;

            }

        }     
    }


    printf("Los datos ordenados son los siguientes: \n\n");
    printf("--------------------------------------------------\n\n");
        for(k1=0; k1<n; k1++){
            // printf("El dato numero %d es: ", ayuda[k1].clave);
            printf("%d", ayuda[k1].NumRand);
            printf ("\n\n");

            fprintf(archivo, "%d,\n", ayuda[k1].NumRand);
        }
    
    fclose(archivo);

    int id, j=0;
    FILE *arch2 = fopen("ID_Teams.csv", "w");
    archivo = fopen("valuesTeams.csv", "r");
    
    while (fscanf(archivo, "%d,", &ord) == 1) {
        // printf("Nombre: %s, Edad: %d, Peso: %.2lf\n",ord);
        
        id = identificadorClave(n, ord, ayuda);
        printf("\nClave %d -- %d\n", id, ord);
    }
    fclose(archivo);


    return 0; 
}

int generardatos(struct Lugar *A, int n){
    int i;
    FILE *arch3 = fopen("RawData.csv", "w");
    //Te falto la semilla para usar rand, por eso te genera siempre los mismoms numeros
    // srand(time(NULL)); Semilla
    srand(time(NULL)); //Al colocar la semilla dentro del for tratamos que el proceso tenga pocas probabilidades de repetir un número
    for(i=0; i < n; i++){
        A[i].clave = i+1; 
        A[i].NumRand = rand()%300; 

        printf("Clave: %d - - Num: %d\n", A[i].clave, A[i].NumRand);
        fprintf(arch3, "%d,%d,\n", A[i].clave, A[i].NumRand);
    }
    return 0; 
}

void ImpresionArrays(int ar){

}

int identificadorClave(int n, int iden, struct Lugar *a){
    int i;
    for (i = 0; i < n; i++){
        if (iden == a[i].NumRand){
             return i;
            
        }
    }
}
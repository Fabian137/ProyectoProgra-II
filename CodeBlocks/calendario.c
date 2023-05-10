#include <stdio.h>
#include <time.h>

void imprimirarreglo(int arr[], int tamaño){
    printf("Los valares lamacenados en j: \n\n"); 




}

void fechas(int init){
    int i, j[8], index=0;
     for (i = init; i <= 31; i += 7) {
        printf("Sabado %d de Marzo:  \n\n", i);
        printf("");
        printf("Domingo %d de Marzo: \n\n", i + 1);

        j[index] = i;
        j[index + 1] = i + 1;
        index += 2;

    }

    printf("\n\n");

    printf("\nValores almacenados en el arreglo j:\n");
    for (i = 0; i < index; i++) {
        printf("%d ", j[i]);
    }
    
}

int main(void) {
    int i, j[8];
 
//    printf("\nMarzo\n\n"); 
fechas(4);
printf("\n\n");
fechas(1);
printf("\n\n");
/*
    int index = 0;
    for (i = 4; i <= 31; i += 7) {
        printf("Sabado %d de Marzo:  \n\n", i);
        printf("Domingo %d de Marzo: \n\n", i + 1);

        j[index] = i;
        j[index + 1] = i + 1;
        index += 2;
    }
*/


    return 0;
}


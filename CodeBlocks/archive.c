#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct futbolTeams{
    char teamsName[20], D_Tecnico[20], Capitan[10];
    int clave, n_jugadores, goles, faltas, NumCampeon;

};

int aleatorio(int min, int max){
    return min + rand()/ (RAND_MAX/ (max - min + 1 ) + 1);
}

void imprime_cadena(char* cadena) {
    printf("La cadena es: %s\n", cadena);
}

void generararreglo(int n, int *arr){
    int i;
    for(i=0; i < n; i++){
        arr[i]= i;
    }
    
    for(i=0; i < n; i++){
        int temporal; 
        int indicealeatorio = aleatorio(0, n-1); 

        temporal = arr[i];
        arr[i] = arr[indicealeatorio];
        arr[indicealeatorio] = temporal; 

    }
    
}

int main() {
    FILE *archivo;
    struct futbolTeams *F;
    archivo = fopen("datos.txt", "r");
    // archivo = fopen("datos.csv", "r");
    int h=3, MAX_LENGTH=50;
    int i, c=0, j, n=16;
    int *arr;
    char teams[20], nombreCompleto[MAX_LENGTH], dtec[40];
    F = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
    arr = (int *) malloc(n * sizeof(int));

    generararreglo(n, arr);

    // fprintf(archivo, " NICEEstos son los nuevos datos que se van a incluir en el archivo.\n");
    // for (i = 0; i < n; i++){
        // if (fscanf(archivo, "%s,", nombre) != EOF){
            // c=arr[i];
            // strcpy(F[i].Capitan, nombre);
        // }
        // printf("\n %s \n", F[i].Capitan);
    // }

    while (fgets(nombreCompleto, MAX_LENGTH, archivo) != NULL) {
        // Hacer algo con el nombre completo leído
        c++;
        strcpy(F[c].Capitan, nombreCompleto);
        printf("Nombre completo: %s", nombreCompleto);
    }
        printf("\n %d \n", c);
        // printf("\n %s \n", F[0].Capitan);
        printf("\n %s \n", F[1].Capitan);
        printf("\n %s \n", F[2].Capitan);
        printf("\n %s \n", F[3].Capitan);

    fclose(archivo);
    return 0;
}

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>

struct futbolTeams{
    char teamsName[20], D_Tecnico[20], Capitan[10], MVP[10];
    int clave, n_jugadores, goles, faltas, ganadas, perdidas, numRand;
};

void leerDatos(struct futbolTeams *, int);
void generarDatos(struct futbolTeams *, int, int arr[8]);
void imprimirDatos(struct futbolTeams *, int);
void ordenar(struct futbolTeams *, int);
int busqueda_NRandomEquipo(struct futbolTeams *, int );
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int arr[8]);

int main(){
    struct futbolTeams *equipo;
    int max, numTeam = 0, i, n, indicealeatorio, temporal;
    equipo = (struct futbolTeams *) malloc(16 * sizeof(struct futbolTeams));
    n = 8; 
    int arr[8];
    // leerDatos(equipo, 3);

    generarDatos(equipo, n, arr);
    

    printf("\n\nArreglo ya mezclado: \n\n"); 
        for(i=0; i < n; i++){
            printf("%d\n", arr[i]);

    } 


    imprimirDatos(equipo, n);

    return 0;

}

void leerDatos(struct futbolTeams *F, int n){
    int i;
    for (i = 0; i < n; i++){
        printf("\nIngresa el nombre del equipo ");
        scanf("%s", F[i].teamsName);
        printf("\nIngresa el nombre del Director Tecnico ");
        scanf("%s", F[i].D_Tecnico);
        printf("\nIngresa el nombre del Capitan ");
        scanf("%s", F[i].Capitan);
    }
}

void generarDatos(struct futbolTeams *F, int n, int arr[8]){
    FILE *archivo;
    // char caracter;
    int i, c=0, j;
    char teams[20], equipo[20];

    archivo = fopen("data/teams.csv", "r");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    }
    /*
    */
    //srand(time(NULL));
            srand(time(NULL));

//-------------Fragmento que mezcla los datos ------------------------------
    generararreglo(n, arr);
//-------------Aqui termina----------------

    for (j = 0; j < n; j++){

        if (fscanf(archivo, "%s,", teams) != EOF){

            c=arr[j];

            strcpy(F[c].teamsName, teams);
        }
        
        F[j].n_jugadores = 11;
        F[j].goles = rand() % 5;
        // F[i].ganadas = rand() % 4;
        // F[i].perdidas = rand() % 4;
        F[j].faltas = rand() % 4;
        // F[i].clave = i +100;
        F[j].clave = j;
    }

    fclose(archivo);
    
}

void imprimirDatos(struct futbolTeams *F, int n){
    int i;
    FILE *archivo;
    archivo = fopen("ID_teams.csv", "w");

    for ( i = 0; i < n; i++){
        printf("\n\n\t\t---- %s ----", F[i].teamsName);
        printf("\n\t\tclave de equipo: %d", F[i].clave);
        printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
        printf("\n\tCapitan: %s", F[i].Capitan);
        printf("\n\tMVP: ...%s", F[i].MVP);
        printf("\n\tNumero de jugadores: %d", F[i].n_jugadores);

        printf("\n\tJuegos Totales: %d", F[i].perdidas + F[i].ganadas);
        printf("\n\t\tPerdidos: %d ----- Ganados: %d", F[i].perdidas, F[i].ganadas);
        printf("\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);
    
        fprintf(archivo, "%d,\n", F[i].clave);
    }
    fclose(archivo);
}

int aleatorio(int min, int max){

return min + rand()/ (RAND_MAX/ (max - min + 1 ) + 1);

}

void generararreglo(int n, int arr[8]){
    int i;
    for(i=0; i < n; i++){
        arr[i]= i;
    }
    
    for(i=0; i < n; i++){
        int temporal; 
        int indicealeatorio = aleatorio (0, n-1); 

        temporal = arr[i];
        arr[i] = arr[indicealeatorio];
        arr[indicealeatorio] = temporal; 

    }
    
}
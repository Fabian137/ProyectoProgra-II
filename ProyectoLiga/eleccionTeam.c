#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>

struct futbolTeams{
    char teamsName[20], D_Tecnico[20], Capitan[10], MVP[10];
    int clave, n_jugadores, goles, faltas, ganadas, perdidas, numRand, NumCampeon;
    /*
      clave -       para identificar el equipo sin usar el nombre. teamsName
    ! numRand -     No sé si se sigue necesitando . . .
    ! perdidas -    Tampoco estoy seguro si se necesite . . .
      NumCampeon -  Para tener un historial de campeones de la LIGA

    */
};

void generarDatos(struct futbolTeams *, int, int *);
void imprimirDatos(struct futbolTeams *, int);
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int *arr);

int filas_CSV();
// void enfrentamientos(struct futbolTeams *,  int);
void enfrentamientos(struct futbolTeams *);

int main(){
    struct futbolTeams *equipo;
    int i, indicealeatorio, temporal, n=4;
    equipo = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
    // n = 8; 
    // int arr[8];
    int *arr;
    arr = (int *) malloc(n * sizeof(int));

    generarDatos(equipo, n, arr);
        
    // printf("\n\nArreglo ya mezclado: \n\n"); 
    //     for(i=0; i < n; i++){
    //         printf("%d\n", arr[i]);

    // } 

    imprimirDatos(equipo, n);

    enfrentamientos(equipo);
/*
*/

    return 0;

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
        F[j].faltas = rand() % 4;
        F[j].clave = j;
    }

    fclose(archivo);
    
}

void imprimirDatos(struct futbolTeams *F, int n){
    int i;
    FILE *archivo_Infos;
    FILE *archivo_ids;
    archivo_Infos = fopen("ID_teams.txt", "w");
    archivo_ids = fopen("ID_teams.csv", "w");

    for ( i = 0; i < n; i++){
        /*
        printf("\n\n\t\t---- %s ----", F[i].teamsName);
        printf("\n\t\tclave de equipo: %d", F[i].clave);
        printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
        printf("\n\tCapitan: %s", F[i].Capitan);
        printf("\n\tMVP: ...%s", F[i].MVP);
        printf("\n\tNumero de jugadores: %d", F[i].n_jugadores);

        printf("\n\tJuegos Totales: %d", F[i].perdidas + F[i].ganadas);
        printf("\n\t\tPerdidos: %d ----- Ganados: %d", F[i].perdidas, F[i].ganadas);
        printf("\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);
        */
    
        fprintf(archivo_Infos, "%d, %d, %s  ------ G: %d -------- F: %d\n", F[i].clave, i, F[i].teamsName, F[i].goles, F[i].faltas);
        fprintf(archivo_ids, "%d, \n", F[i].clave);
    }
    fclose(archivo_Infos);
    fclose(archivo_ids);
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
        int indicealeatorio = aleatorio(0, n-1); 

        temporal = arr[i];
        arr[i] = arr[indicealeatorio];
        arr[indicealeatorio] = temporal; 

    }
    
}

int filas_CSV(){
    FILE *archivoIDS;
    archivoIDS = fopen("ID_teams.csv", "r");
    int id, i=0;

    
    while (fscanf(archivoIDS, "%d,", &id) != EOF){
        i++;
    }
    /*
    Con el while solo leo la cantidad de variables que existe, para asi saber el numero de filas y por ende número de interaciones que necesito. Para asi hacer los enfrentamientos
    */
    /*
    Este for es para guardar */



    return i;
    
}

void enfrentamientos(struct futbolTeams *F){
    FILE *archivoIDS;

    archivoIDS = fopen("ID_teams.csv", "r");
    int i, n, id, *id_team; 
    //id es para leer los datos del archivo y *id_team es un arreglo dinámico para guardar los datos de id 
    // id_team = (int *) malloc(n * sizeof(int));
    n = filas_CSV();
    id_team = (int *) malloc(n * sizeof(int));

    for (i = 0; i < n; i++){
        if(fscanf(archivoIDS, "%d,", &id) != EOF){
            printf("%d ----- %d - %d \n", id, i, i+1);
            id_team[i] = id;
        }
    }
    printf("\n\n");


    for (i = 0; i < n; i+=2){
        printf("%d -- %d \n", id_team[i], id_team[i+1]);
        printf("%s -- %s \n", F[id_team[i]].teamsName, F[id_team[i+1]].teamsName);


        if (F[id_team[i]].goles > F[id_team[i+1]].goles){
            // printf("hola-?");
            printf("\n\tGana el equipo de: ---%s\n", F[id_team[i]].teamsName);    
        }
        else if (F[id_team[i+1]].goles > F[id_team[i]].goles){
            printf("\n\tGana el equipo de: ---%s\n", F[id_team[i+1]].teamsName);    
        }
        else{
            if (F[id_team[i]].faltas > F[id_team[i+1]].faltas){
                printf("\n\tGana el equipo de: ---%s \n", F[id_team[i+1]].teamsName);
            }
            else if (F[id_team[i+1]].faltas > F[id_team[i]].faltas){
                printf("\n\tGana el equipo de: ---%s \n", F[id_team[i]].teamsName);
            }
            else{
                printf("\n\t %s\n", F[id_team[i]].teamsName);
            }
            
        }
        
        

        // else if(F[id_team[i+1]].goles >  F[id_team[i]].goles){
        // printf("Gana el equipo de: ---%s", F[id_team[i+1]].goles);
        
        // }
        
        // else{
        //     if(F[id_team[i]].faltas > F[id_team[i+1]].faltas || F[id_team[i+1]].faltas > F[id_team[i]].faltas){
            
        // }
        
        
        }
    }

// }
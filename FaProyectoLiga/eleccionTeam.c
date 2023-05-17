#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct futbolTeams{
    char teamsName[20], D_Tecnico[40], Capitan[40];
    int clave, n_jugadores, goles, faltas, NumCampeon;

};

void generarDatos(struct futbolTeams *, int, int, int);
void imprimirDatos(struct futbolTeams *, int);
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int *arr);

int filas_CSV();
void Array_ids(int *, int);
void escrituraArchivos_Partidos(struct futbolTeams *,int *, int); 
void iteraciones(struct futbolTeams *F, int *arr, int n, char* ); 
void enfrentamientos(struct futbolTeams *);
void fechas(struct futbolTeams *, int *, int, int, int, int);



int main(){

    struct futbolTeams *equipo;

    int i, indicealeatorio, temporal, n=16;

    equipo = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
   
    int root = time(NULL);

    generarDatos(equipo, n, 1, root);

    imprimirDatos(equipo, n);

    enfrentamientos(equipo);

    free(equipo);

    return 0;

}

void generarDatos(struct futbolTeams *F, int n, int modo, int root){

    srand(root);
    FILE *archivo;
    FILE *archNombres;
    FILE *archDTec;
    
    int i, c=0, a=-1, k=-1, j, MAX_LENGTH=40;
    int *arr;
    char teams[20], nombre[MAX_LENGTH], dtec[40];

    arr = (int *) malloc(n * sizeof(int));

    archivo = fopen("data/teams.txt", "r");
    archNombres = fopen("data/nombres.txt", "r");
    archDTec = fopen("data/Dtecnico.txt", "r");

    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    }
    if(archNombres == NULL){
        printf("Error al abrir archNombres\n");
    }
    if(archDTec == NULL){
        printf("Error al abrir archDTec\n");
    }


    if (modo == 1){
//-------------Fragmento que mezcla los datos ------------------------------
        generararreglo(n, arr);
        
//----------------------Aqui termina----------------------------------------
        for (j = 0; j < n; j++){
                c=arr[j];

            if (fscanf(archivo, "%s", teams) != EOF){
                    strcpy(F[c].teamsName, teams);
            }
            F[j].clave = j;
        }

        while (fgets(nombre, MAX_LENGTH, archNombres) != NULL) {
            a++;
            strcpy(F[a].Capitan, nombre);
            // printf("Nombre completo: %s", nombre);
        }
        while (fgets(nombre, MAX_LENGTH, archDTec) != NULL) {
            k++;
            strcpy(F[k].D_Tecnico, nombre);
            // printf("Nombre completo: %s", nombre);
        }
    }
    for (i = 0; i < n; i++){
        F[i].n_jugadores = 11;
        F[i].goles = rand() % 6;
        F[i].faltas = rand() % 4;

    }


    free(arr); 

    fclose(archivo);
    fclose(archNombres);
    fclose(archDTec);
    
}

void imprimirDatos(struct futbolTeams *F, int n){
    int i;
    FILE *archivo_Infos;
    FILE *archivo_ids;
    archivo_Infos = fopen("ID_teams.txt", "w");
    archivo_ids = fopen("ID_teams.csv", "w");

    for ( i = 0; i < n; i++){   
        
        printf("\n\n\t\t---- %s ----", F[i].teamsName);
        printf("\n\t\tclave de equipo: %d", F[i].clave);
        printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
        printf("\n\tCapitan: %s", F[i].Capitan);
       
        printf("\n\tNumero de jugadores: %d", F[i].n_jugadores);

        printf("\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);
        
    
        fprintf(archivo_Infos, "%d, %d, %s  ---- G: %d ---- F: %d\n", F[i].clave, i, F[i].teamsName, F[i].goles, F[i].faltas);
        fprintf(archivo_ids, "%d, \n", F[i].clave);
    }
    fclose(archivo_Infos);
    fclose(archivo_ids);
}

int aleatorio(int min, int max){
    return min + rand()/ (RAND_MAX/ (max - min + 1 ) + 1);
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

int filas_CSV(){
    FILE *archivoIDS;
    archivoIDS = fopen("ID_teams.csv", "r");
    int id, i=0;
    
    while (fscanf(archivoIDS, "%d,", &id) != EOF){
        i++;
    }

    fclose(archivoIDS); 
    return i;
    
}

void Array_ids(int *arr, int n){
    FILE *archivoIDS;
    int id, i;
    archivoIDS = fopen("ID_teams.csv", "r");

    for (i = 0; i < n; i++){

        if(fscanf(archivoIDS, "%d,", &id) != EOF){
            
            arr[i] = id;
            
        }
    }
    printf("\n\n");
    
    fclose(archivoIDS);

}

void iteraciones(struct futbolTeams *F, int *arr, int n, char* cadena){
    FILE *archivoPartidos;
    int i, id;

    archivoPartidos = fopen(cadena, "w");
    
    for ( i = 0; i < n; i++){
        id = arr[i];
        fprintf(archivoPartidos, "\n %d ---- %s -- G:%d -- F:%d", F[id].clave, F[id].teamsName, F[id].goles, F[id].faltas);
    }

}

void escrituraArchivos_Partidos(struct futbolTeams *F, int *arr, int n){
    FILE *archivoPartidos;
    archivoPartidos = fopen("Partidos/General_matches.txt", "w");
   
    char *cadena;
        cadena = (char *) malloc(25 * sizeof(char));
        

    
    switch (n){
        case 16:
            cadena = "Partidos/Seleccion.txt";
            fprintf(archivoPartidos, "\nFilas: %d\n", n);
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            fechas(F, arr, 16, 4, 3, 31);
        break;

        case 8:
            cadena = "Partidos/Octavos.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            fechas(F, arr, 8, 1, 4, 9);
        break;

        case 4:
            cadena= "Partidos/cuartos.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            fechas(F, arr, 4, 15, 4, 16);
        break;

        case 2:
            cadena = "Partidos/semifinales.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            fechas(F, arr, 2, 22, 4, 22);
            //fechas(F, 4, arr, 2, );
        break;

        /*
        case 1:
            cadena = "Partidos/finales.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            //fechas(F, 4, arr, 1, );
        break;
        */

        default:
        break;
    }
    


}

void enfrentamientos(struct futbolTeams *F){
    FILE *archivoIDS;
    FILE *history;

    int i, n, id, *id_team; 
    float pi=3.14159265359;

    int root;
 
    while (n != 2){
        n = filas_CSV();
        id_team = (int *) malloc(n * sizeof(int));

        printf("\n FILAS:%d", n);        

        Array_ids(id_team, n);

        archivoIDS = fopen("ID_teams.csv", "w");
        
        escrituraArchivos_Partidos(F, id_team, n);

        for (i = 0; i < n; i+=2){
            
            if (F[id_team[i]].goles > F[id_team[i+1]].goles){
                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave);  

            }
            else if (F[id_team[i+1]].goles > F[id_team[i]].goles){
                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i+1]].teamsName, F[id_team[i+1]].clave, F[id_team[i+1]].goles, F[id_team[i+1]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i+1]].clave); 
            }
            else{
                if (F[id_team[i]].faltas > F[id_team[i+1]].faltas){
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i+1]].teamsName, F[id_team[i+1]].clave, F[id_team[i+1]].goles, F[id_team[i+1]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i+1]].clave);
                }
                else if (F[id_team[i+1]].faltas > F[id_team[i]].faltas){
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave);
                      
                }
                else{
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave); 
                }
            }
        }

            root = (time(NULL) + (n*pi)) * (id_team[n-1]*id_team[n-1]);
            generarDatos(F, n, 0, root);

        fclose(archivoIDS);
    }


        n = filas_CSV();
        id_team = (int *) malloc(n * sizeof(int));
        Array_ids(id_team, n);
        printf("\n\n\n\n\t\t\t %s \n\n\n", F[id_team[0]].teamsName);

        history = fopen("Partidos/campeones.txt", "a");

            
            fprintf(history, "\n--------------------\n \t %s", F[id_team[0]].teamsName);
            // iteraciones(F, arr, n, cadena);
            //fechas(F, 4, arr, 1, );
        
}

void fechas(struct futbolTeams *F, int *ids, int n, int init, int month, int end){
    /*
    struct futbolTeams *F = equipo. Arreglo dinámico de estructuras
    int *ids = Arreglo dinámico de claves que existen en ID_teams para buscar los equipos
    int n = Para identificar en que ronda estamos
    int init = En que día inicia el for (sábado)
    int month = Para saber en qué mes estoy. Y asi imprimirlo en con ayuda de un switch
    int end = hasta que dia va a llegar el for ()

    En conjunto para poder usar sólo un for y que cambie segun el CASE desde el que lo 
    estamos llamando.
        */
    FILE *archivoIDS;
    archivoIDS = fopen("ID_teams.csv", "r");

    printf("\n desde fechas: %d\n", n);

    int i, j[8], index=0, z=-2;

    int *dias;

    dias = (int *) malloc(n * sizeof(int));

    for (i = init; i <= end; i += 7) {
        // j[index] = i;
        // j[index + 1] = i + 1;
        // index += 2;

        // init == end ? 
        if (init != end){
            dias[index] = i;
            dias[index + 1] = i + 1;
            index += 2;
        }
        else{
            dias[index] = i;
            index += 2;
        
        }
    
        
    }

    for (i = 0; i < index; i++) {
        z+=2;
        switch (month){
            case 3:
                printf("\n\t\t%d de marzo de 2023\n", dias[i]);
                printf("\n\t %s \t --VS-- \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
            break;

            case 4:
                if(dias[i] > 31){
                    printf("\n /_");
                    // Asi evitamos esa especie de fecha que se genera extra 
                }
                else{
                    // printf("\n ---/_");
                    printf("\n\t\t %d de abril de 2023\n", dias[i]);
                    printf("\n\t %s \t --VS-- \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
                }
            break;
        default:
            break;
        }
    }


}
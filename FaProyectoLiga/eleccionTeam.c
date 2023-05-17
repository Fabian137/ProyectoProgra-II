#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// #include "FuncionesPrototipos.h"

struct futbolTeams{
    char teamsName[20], D_Tecnico[40], Capitan[40];
    int clave, n_jugadores, goles, faltas, NumCampeon, ganadas;

};


void generarDatos(struct futbolTeams *, int, int, int);
void imprimirDatos(struct futbolTeams *, int, int, int);
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int *arr);

int filas_CSV(char* c);
void Array_ids(int *, int);
void escrituraArchivos_Partidos(struct futbolTeams *,int *, int); 
void iteraciones(struct futbolTeams *F, int *arr, int n, char* ); 
void enfrentamientos(struct futbolTeams *);
void fechas(struct futbolTeams *, int *, int, int, int, int);
int maxChampion(struct futbolTeams *F);

void composer(struct futbolTeams *F);
int menu(struct futbolTeams *F);
void caratula();


void caratula();
int menu();



int main(){
    struct futbolTeams *equipo;
    int i, opcion, n;
    char respuesta;

    printf("\n--%d--\n",n);

    do{
        n=16;
            printf("\n--%d--\n",n);
    int root = time(NULL);

<<<<<<< HEAD
    equipo = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
=======
    //caratula(); 


    generarDatos(equipo, n, 1, root);
>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258

    generarDatos(equipo, n, 1, root);
        printf("\n--%d--\n",n);

    enfrentamientos(equipo);

    // composer(equipo);
    // opcion = menu(equipo);

    printf("\nOtra ligaa [S/N]\n ");
	scanf(" %c", &respuesta);
    } while(respuesta == 's' || respuesta == 'S');
    
    free(equipo);

    //menu();


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
            // F[j].NumCampeon = 0;
            F[j].ganadas = 0;
            F[j].clave = j;
        }

        while (fgets(nombre, MAX_LENGTH, archNombres) != NULL) {
            a++;
            strcpy(F[a].Capitan, nombre);
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

void imprimirDatos(struct futbolTeams *F,int init, int n, int modo){
    int i;
    FILE *archivo_Infos;
    FILE *archivo_ids;
    archivo_Infos = fopen("data/ID_teams.txt", "w");
    archivo_ids = fopen("data/ID_teams.csv", "w");

    for ( i = init; i < n; i++){   
        if (modo == 1){
            
        printf("\n\n\t\t---- %s ----", F[i].teamsName);
<<<<<<< HEAD
        printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
=======
        printf("\n\n\t\tclave de equipo: %d", F[i].clave);
        printf("\n\n\tDirector Tecnico: %s", F[i].D_Tecnico);
>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258
        printf("\n\tCapitan: %s", F[i].Capitan);
       
        printf("\n\tNumero de jugadores: %d", F[i].n_jugadores);

        printf("\n\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);
        
        // fprintf(archivo_Infos, "%d, %d, %s  ---- G: %d ---- F: %d\n", F[i].clave, i, F[i].teamsName, F[i].goles, F[i].faltas);
        fprintf(archivo_Infos, "%s - %d\n", F[i].teamsName, F[i].clave);
        fprintf(archivo_ids, "%d, \n", F[i].clave);
        }
        printf("\n\t\tclave del equipo: %s - %d", F[i].teamsName, F[i].clave);
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

int filas_CSV(char* cadena){
    FILE *archivo;
    archivo = fopen(cadena, "r");
    int id, i=0;
    
    while (fscanf(archivo, "%d,", &id) != EOF){
        i++;
    }

    fclose(archivo); 
    return i;
    
}

void Array_ids(int *arr, int n){
    FILE *archivoIDS;
    int id, i;
    archivoIDS = fopen("data/ID_teams.csv", "r");

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
<<<<<<< HEAD
        cadena = (char *) malloc(25 * sizeof(char));
=======
        cadena = (char *) malloc(40 * sizeof(char));
        

>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258
    
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
<<<<<<< HEAD
            fechas(F, arr, 2, 22, 4, 22);
        break;
=======
            fechas(F, arr, 2, 22, 4, 23);
            //fechas(F, 4, arr, 2, );
        break;

        case 1:
            cadena = "Partidos/finales.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            //fechas(F, 4, arr, 1, );
        break;
        
        /*
        */

>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258
        default:
        break;
    }
    


}

void enfrentamientos(struct futbolTeams *F){
    FILE *archivoIDS;
    FILE *history;

    int i, n=16, id, *id_team; 
    float pi=3.14159265359;
        printf("\n--%d--\n",n);
    int root;
    char string[] = "data/ID_teams.csv";
    while (n != 2){
        n = filas_CSV(string);
        id_team = (int *) malloc(n * sizeof(int));

        printf("\n FILAS:%d", n);        
    printf("\n--%d--\n",n);
        Array_ids(id_team, n);

        archivoIDS = fopen("data/ID_teams.csv", "w");
        
        escrituraArchivos_Partidos(F, id_team, n);

        for (i = 0; i < n; i+=2){
            
            if (F[id_team[i]].goles > F[id_team[i+1]].goles){
                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave);  
                F[id_team[i]].ganadas++;

            }
            else if (F[id_team[i+1]].goles > F[id_team[i]].goles){
                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i+1]].teamsName, F[id_team[i+1]].clave, F[id_team[i+1]].goles, F[id_team[i+1]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i+1]].clave); 
                F[id_team[i+1]].ganadas++;
            }
            else{
                if (F[id_team[i]].faltas > F[id_team[i+1]].faltas){
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i+1]].teamsName, F[id_team[i+1]].clave, F[id_team[i+1]].goles, F[id_team[i+1]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i+1]].clave);
                    F[id_team[i+1]].ganadas++;
                }
                else if (F[id_team[i+1]].faltas > F[id_team[i]].faltas){
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave);
                    F[id_team[i]].ganadas++;
                      
                }
                else{
                    printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                    fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave); 
                    F[id_team[i]].ganadas++;
                }
            }
        }

            root = (time(NULL) + (n*pi)) * (id_team[n-1]*id_team[n-1]);
            generarDatos(F, n, 0, root);

        fclose(archivoIDS);
    }


        n = filas_CSV(string);
        id_team = (int *) malloc(n * sizeof(int));
        Array_ids(id_team, n);
        printf("\n\n\n\n\t\t\t %s \n\n\n", F[id_team[0]].teamsName);

        history = fopen("Partidos/campeones.csv", "a");

            
            fprintf(history, "%s,\n", F[id_team[0]].teamsName);
            F[id_team[0]].NumCampeon++;
            // printf("\n %s -- %d\n", F[id_team[0]].teamsName, F[id_team[0]].NumCampeon);
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
    archivoIDS = fopen("data/ID_teams.csv", "r");

    printf("\n desde fechas: %d\n", n);

    int i, j[8], index=0, z=-2;

    int *dias;

    dias = (int *) malloc(n * sizeof(int));

    for (i = init; i <= end; i += 7) {
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
<<<<<<< HEAD
                if(dias[i] > 31){
                    printf("\n");
=======
                if(dias[i] ==23){
                    printf("\n /_");
>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258
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

int maxChampion(struct futbolTeams *F){
    int i, n=16;
    int max = 0;
    // char cadena[30] = "Partidos/campeones.csv";
    // n = filas_CSV("Partidos/campeones.csv");
    /*

    char string[10];
    FILE *archivo;
    archivo = fopen("Partidos/campeones.csv", "r");

    while (fscanf(archivo, "%s,", string) != EOF){
        n++;
    }

    */
    // return i;
    

    for (i = 0; i < n; i++) {
        if (F[i].NumCampeon > max) {
            max = F[i].NumCampeon;
        }
    }
    // fclose(archivo); 
   return max;
    
}

int idenficadorEquipo(struct futbolTeams *F, int n, int clave){
    int i;
    for (i = 0; i < n; i++){
        if (clave == F[i].clave){
            return i;
        }
    }
}

void caratula(){
    printf("\n\n\t\t\t \033[38;5;31m \033[1m--------- || PROYECTO || --------- \n \t\t\t\t   -Liga de fútbol- \033[1m \033[0m\n");
    // printf("\n\n\t\t\t  \033[38;5;31mTexto en rojo\033[0m\n \n \t\t\t-Liga de fútbol");
    printf("\n\n\t\t Pogramación II");
    printf("\n\t\t Profesora: Alma López Blanco");

    printf("\n\n\t Integrantes");
    printf("\n\t - Beltrán Isidro Carlos Fabián - 423127045");
    printf("\n\t - Veizaga Pinto Frida          - 423490440");
    printf("\n\t - Díaz Valdez Gilberto Fidel   - 320324280");
    printf("\n\t - Pablo Cesar Tapia Becerril   - 423089662");

    


}

<<<<<<< HEAD
void composer(struct futbolTeams *F){
    int opcion, teamID, id, MAX_LENGTH = 10;
    char respuesta, campeon[MAX_LENGTH];


    FILE *arch;
    do{

        opcion = menu(F);
        // while(opcion!=7){
        switch (opcion){
        case 1:
            printf("\n\nIngresa la clave del equipo que deseas ver: \n");
            imprimirDatos(F, 0, 16, 0);
            printf("\n");
            scanf("%d", &id);
            teamID = idenficadorEquipo(F, 16, id);
            imprimirDatos(F,teamID-1, teamID, 1);
            break;

        case 2:
            imprimirDatos(F, 0, 16, 1);
            break;
        
        case 3:
            arch = fopen("Partidos/campeones.csv", "w");
            fclose(arch);
            break;

        case 4:
            arch = fopen("Partidos/campeones.csv", "r");
            while (fgets(campeon, MAX_LENGTH, arch) != NULL) {
                printf("\nCampeones: %s\n", campeon);
            }
        break;


        default:
            break;
        }

    printf("\nHacer otra consulta/operacion [S/N]\n ");
	scanf(" %c", &respuesta);
    } while(respuesta == 's' || respuesta == 'S');
    // }
    fclose(arch);

}

int menu(struct futbolTeams *F){
int opcion;

    printf("\n\n\t -- Elige una opcion si quieres hacer una consulta --");
    // printf("\n\n\t 1) El equipo con mayor número de campeonatos");
    printf("\n\n\t 1) Información detallada de un equipo");
    printf("\n\n\t 2) Información detallada de todos los equipos");
    // printf("\n\n\t 4) Partidos ganados de un equipo");
    printf("\n\n\t 3) Reiniciar Historial de campeones");
    printf("\n\n\t 4) Mostrar Historial de campeones\n");
    
    printf("\n\tOpcion: ");
    scanf("%d", &opcion);
=======
void caratula(){
    printf("\n\n\t\t\t \033[38;5;31m \033[1m--------- || PROYECTO || --------- \n \t\t\t\t   -Liga de fútbol- \033[1m \033[0m\n");
    // printf("\n\n\t\t\t  \033[38;5;31mTexto en rojo\033[0m\n \n \t\t\t-Liga de fútbol");
    printf("\n\n\t\t Pogramación II");
    printf("\n\t\t Profesora: Alma López Blanco");

    printf("\n\n\t Integrantes");
    printf("\n\t - Beltrán Isidro Carlos Fabián");
    printf("\n\t - Veizaga Pinto Frida");
    printf("\n\t - Díaz Valdez Gilberto Fidel");

    


}

int menu(){

int opcion;

while(opcion!=5){


    printf("\n\n\t Elige una opcion si quieres una consulta: ");
    printf("\n\n\t 1) El equipo con mayor número de campeonatos");
    printf("\n\n\t 2) Información detallada de un equipo");
    printf("\n\n\t 3) Información detallada de todos los equipos");
    printf("\n\n\t 4) Partidos ganados");
    printf("\n\n\t 5) Salir");

    scanf("\n\n%d", &opcion);
                
       switch (opcion){
   case 1:
    printf("\n\nLO que se que tenga que hacer en la opcion 1");
    break;
   case 2:
    printf("\n\nLO que se que tenga que hacer en la opcion 2");
    break;
    case 3:
    printf("\n\nLO que se que tenga que hacer en la opcion 3");
    break;
    case 4:
    printf("\n\nLO que se que tenga que hacer en la opcion 4");
    break;
    case 5:
    printf("\n\nSe acaba el programa cuando digitas 5");
    break;


   default:
    break;
   }


}
>>>>>>> d012763820cd8bc3e2988cb729818ebe8d017258
    return opcion; 
}
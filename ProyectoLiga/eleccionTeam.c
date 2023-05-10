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

void generarDatos(struct futbolTeams *, int, int /* , int *  */);
void imprimirDatos(struct futbolTeams *, int);
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int *arr);

int filas_CSV();
// void enfrentamientos(struct futbolTeams *,  int);
void Array_ids(int *, int);
void escrituraArchivos_Partidos(struct futbolTeams *,int *, int); //Funciona mas de estructura pero mando a llamar iteraciones para no repetir los ciclo for y escribir
void iteraciones(struct futbolTeams *F, int *arr, int n, char* ); //Imprime el valor de la clave y nombre para ir viendo "Octavos", "Cuartos", etc
void enfrentamientos(struct futbolTeams *);
void fechas(struct futbolTeams *, int init, int *);



int main(){
    struct futbolTeams *equipo;
    int i, indicealeatorio, temporal, n=16;
    equipo = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
    // n = 8; 
    // int arr[8];

    generarDatos(equipo, n, 1 /*, arr */);

    imprimirDatos(equipo, n);

    enfrentamientos(equipo);
    // enfrentamientos(equipo);
    // enfrentamientos(equipo);
    // enfrentamientos(equipo);
/*
*/
free(equipo);
// free(arr); 

    return 0;

}

//Se me ocurre pasar un tercer o cuarto parametro (0 o 1) para indicar a la función si generar el arreglo o no. Que en cuyo caso sólo se genera una vez que es al comienzo de los enfrentamientos

void generarDatos(struct futbolTeams *F, int n, int modo /* ,int *arr*/){
    FILE *archivo;
    int i, c=0, j;
    int *arr;
    char teams[20];

    arr = (int *) malloc(n * sizeof(int));

    archivo = fopen("data/teams.txt", "r");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    }

    srand(time(NULL));

//-------------Fragmento que mezcla los datos ------------------------------
    if (modo == 1){
        generararreglo(n, arr);
    }
    
//-------------Aqui termina----------------

    for (j = 0; j < n; j++){
        if (modo == 1){
        
        if (fscanf(archivo, "%s", teams) != EOF){

            c=arr[j];

            strcpy(F[c].teamsName, teams);
        }
        }
        
        F[j].n_jugadores = 11;
        F[j].goles = rand() % 5;
        F[j].faltas = rand() % 4;

/*Con estas condiciones pretendo que cuando vuelva a llamar a la funcion
no cambie de claves a los equipos nuevamente*/
        if (F[j].clave = j){
        F[j].clave = j;
        }
        else{
            F[j].clave = j;
        }
        
    }

    free(arr); 
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
    /*
    Con el while solo leo la cantidad de variables que existe, para asi saber el numero de filas y por ende número de interaciones que necesito. Para asi hacer los enfrentamientos
    */
    /*
    Este for es para guardar */


    fclose(archivoIDS); 
    return i;
    
}

/* Función para guardar las claves de ID_teams.csv en un arreglo
dinámico*/
void Array_ids(int *arr, int n){
    FILE *archivoIDS;
    int id, i;
    archivoIDS = fopen("ID_teams.csv", "r");

        for (i = 0; i < n; i++){
        if(fscanf(archivoIDS, "%d,", &id) != EOF){
            //printf("%d ----- %d - %d \n", id, i, i+1);
            arr[i] = id;

            // printf("\n %d", arr[i]);
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
    // char cadena[] = "Hola mundo";
    char *cadena;
        cadena = (char *) malloc(25 * sizeof(char));
    
    
    switch (n){
        case 16:
         cadena = "Partidos/Seleccion.txt";
            fprintf(archivoPartidos, "\nFilas: %d\n", n);
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
        break;

        case 8:
        cadena = "Partidos/Octavos.txt";
        fprintf(archivoPartidos, "\n--------------------\n");
        iteraciones(F, arr, n, cadena);
        break;

        case 4:
        cadena= "Partidos/cuartos.txt";
        fprintf(archivoPartidos, "\n--------------------\n");
        iteraciones(F, arr, n, cadena);
        break;

        case 2:
        cadena = "Partidos/semifinales.txt";
        fprintf(archivoPartidos, "\n--------------------\n");
        iteraciones(F, arr, n, cadena);
        break;

        case 1:
        cadena = "Partidos/finales.txt";
        fprintf(archivoPartidos, "\n--------------------\n");
        iteraciones(F, arr, n, cadena);
        break;

        default:
        break;
    }
    


}

void enfrentamientos(struct futbolTeams *F){
    FILE *archivoIDS;

    int i, n, id, *id_team;
    //id es para leer los datos del archivo y *id_team es un arreglo dinámico para guardar los datos de id 
    // id_team = (int *) malloc(n * sizeof(int));
    do{
    
        n = filas_CSV();

        id_team = (int *) malloc(n * sizeof(int));

        printf("\n FILAS:%d", n);        

        Array_ids(id_team, n);
        // fechas(F, 4, id_team);

        escrituraArchivos_Partidos(F, id_team, n);
        archivoIDS = fopen("ID_teams.csv", "w");
        
        for (i = 0; i < n; i+=2){

            generarDatos(F, n, 0);

            //Mando a llamar generarDatos para que por cada ronda genere nuevos datos pero no los modifica

            
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


        fclose(archivoIDS);
    } while (n !=1);
}

void fechas(struct futbolTeams *F, int init, int *ids){
    FILE *archivoIDS;
    archivoIDS = fopen("ID_teams.csv", "r");

    int i, j[8], index=0, z=-2;

    //Este for crea el calendario
    for (i = init; i <= 31; i += 7) {
        j[index] = i;
        j[index + 1] = i + 1;
        index += 2;

    }

    printf("\n\n");

    printf("\nValores almacenados en el arreglo j:\n");
    for (i = 0; i < index; i++) {
        z+=2;
        printf("\n\t\t%d de marzo de 2023\n", j[i]);
        printf("\n\t %s \t --VS--  \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
        //printf
    }
    
}
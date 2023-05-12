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

void generarDatos(struct futbolTeams *, int, int, int/* , int *  */);
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
void fechas(struct futbolTeams *, int *, int, int, int, int);



int main(){
    struct futbolTeams *equipo;
    int i, indicealeatorio, temporal, n=16;
    equipo = (struct futbolTeams *) malloc(n * sizeof(struct futbolTeams));
    // n = 8; 
    // int arr[8];
    int root = time(NULL);
    generarDatos(equipo, n, 1, root /*, arr */);

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

void generarDatos(struct futbolTeams *F, int n, int modo, int root /* ,int *arr*/){
    srand(root);
    FILE *archivo;
    int i, c=0, j;
    int *arr;
    char teams[20];

    arr = (int *) malloc(n * sizeof(int));

    archivo = fopen("data/teams.txt", "r");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    }


//-------------Fragmento que mezcla los datos ------------------------------
    if (modo == 1){
        generararreglo(n, arr);
        printf("\nEntro al if -- genera arreglo\n");
    }
    
//-------------Aqui termina----------------

    // srand(time(NULL));
    for (j = 0; j < n; j++){
        if (modo == 1){
        
        //    printf("\nEntro al if 2 -- Asigna claves y nombres\n");
            if (fscanf(archivo, "%s", teams) != EOF){
                c=arr[j];
                strcpy(F[c].teamsName, teams);
            }
            F[j].clave = j;
        }
        
        F[j].n_jugadores = 11;
         F[j].goles = rand() % 6;
        // F[j].goles = random() % 6;
         F[j].faltas = rand() % 4;
        // F[j].faltas = random() % 4;

       // printf("\n%d-- %d - %d\n", F[j].clave, F[j].goles, F[j].faltas);

/*Con estas condiciones pretendo que cuando vuelva a llamar a la funcion
no cambie de claves a los equipos nuevamente*/

        // if (F[j].clave = j){
        // F[j].clave = j;
        // }
        // else{
        //     F[j].clave = j;
        // }
        
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
            printf("\n Hi");
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

        case 1:
            cadena = "Partidos/finales.txt";
            fprintf(archivoPartidos, "\n--------------------\n");
            iteraciones(F, arr, n, cadena);
            //fechas(F, 4, arr, 1, );
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
    n=16;
    int root;
    // do{
    while (n != 1){
        n = filas_CSV();
        id_team = (int *) malloc(n * sizeof(int));

        printf("\n FILAS:%d", n);        

        Array_ids(id_team, n);

        archivoIDS = fopen("ID_teams.csv", "w");

        // fechas(F, 4, id_team);

        
        
            //Mando a llamar generarDatos para que por cada ronda genere nuevos datos pero no los modifica
        // generarDatos(F, n, 0, root);
        escrituraArchivos_Partidos(F, id_team, n);

        for (i = 0; i < n; i+=2){
            
            if (F[id_team[i]].goles > F[id_team[i+1]].goles){

                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i]].teamsName, F[id_team[i]].clave, F[id_team[i]].goles, F[id_team[i]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i]].clave);  
                // generarDatos(F[id_team[i]], n, 0);
            }
            else if (F[id_team[i+1]].goles > F[id_team[i]].goles){
                printf("\n\tGana el equipo de: ---%s : %d  G:%d - F:%d \n", F[id_team[i+1]].teamsName, F[id_team[i+1]].clave, F[id_team[i+1]].goles, F[id_team[i+1]].faltas);
                fprintf(archivoIDS, "%d,\n", F[id_team[i+1]].clave);  
                // generarDatos(F[id_team[i]], n, 0);
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
        root = time(NULL) + (n/2 + n*n);
        generarDatos(F, n, 0, root);


        fclose(archivoIDS);
    }
    // } while (n !=1);
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

        dias[index] = i;
        dias[index + 1] = i + 1;
        index += 2;
    }

    for (i = 0; i < index; i++) {
        z+=2;
        switch (month){
            case 3:
            /* code */
                printf("\n\t\t%d de marzo de 2023\n", dias[i]);
                printf("\n\t %s \t --VS--  \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
            break;

            case 4:
                printf("\n\t\t%d de abril de 2023\n", dias[i]);
                printf("\n\t %s \t --VS--  \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
            break;
        default:
            break;
        }
        //printf
    }

/*
    switch (n){
    
        case 16:

        for (i = init; i <= 31; i += 7) {
        j[index] = i;
        j[index + 1] = i + 1;
        index += 2;

    }

    printf("\n\n");

        for (i = 0; i < index; i++) {
        z+=2;
        printf("\n\t\t%d de marzo de 2023\n", j[i]);
        printf("\n\t %s \t --VS--  \t %s \t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
        //printf
    }
        break;

        case 8:
        printf("EL caso cuando son 8 equipos\n\n");
        break;

        case 4:
        printf("EL caso cuando son 4 equipos\n\n");
        break;

        case 2:
        printf("EL caso cuando son 2 equipos\n\n");
        break;

        case 1:
        printf("EL caso cuando son 1 equipos\n\n");
        break;
    
    default:
    break;
    
    }
*/



}
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

//-----------------------Prototipo de Funciones------------------------

void generarDatos(struct futbolTeams *, int  , int *); 
void imprimirDatos(struct futbolTeams *, int);

void generararreglo(int , int *);
int aleatorio(int , int );

int filas_CSV();
void enfrentamientos(struct futbolTeams *);
void fechas(struct futbolTeams *, int, int, int *);

int reviso();
void generarDatosNo2(struct futbolTeams *, int  , int *); 

//---------------------------------------------------------------------



int main(){
    //Variables a usar en main 
    struct futbolTeams *equipo; 
    int i; 
    int indicealeatorio; 
    int temporal; 
    int n = 16; 
    int *arr;
    int a;  
   
     

//Haremos la estructura futbolTeams conocida en main como "equipo" un arreglo dinamico

equipo =(struct futbolTeams *) malloc(n * sizeof(struct futbolTeams)); 

//Haremos el arreglo "arr" de tipo de memoria dinamica 

arr = (int *) malloc( n * sizeof(int));



generarDatos(equipo, n, arr); 

imprimirDatos(equipo, n);

enfrentamientos(equipo);

n = reviso(); 

generarDatosNo2(equipo, n, arr);

imprimirDatos(equipo, n);



printf("\n\nEL nuevo numero de equipos resxtantes es: %d ", n);


  free(equipo); 
  free(arr); 
    return 0;
}



void generarDatos(struct futbolTeams *E, int n, int arr[n]){
//Declaramos un archivo para poder utilizarlos
FILE *archivo; 
int i, c = 0, j; 

char equipo[20]; 
//Se vincula la variable "archivo" de tipo FILE con el archivo que queremos abrir
//Se pone la r porque solo funcionara para leer los datos del archivo teams.txt
archivo = fopen("data/teams.txt", "r"); 

if(archivo==NULL){
    printf("Error al abrir el archivo\n");
}

  //Para hacer el numero y randomizar las posiciones donde se guardaran los equipos
  srand(time(NULL));

  generararreglo(n, arr);

for(j = 0; j < n; j++){
  
  if(fscanf(archivo, "%s", equipo) != EOF){

    c=arr[j];

    strcpy(E[c].teamsName, equipo);

  }
        E[j].n_jugadores = 11;
        E[j].goles = rand() % 5;
        E[j].faltas = rand() % 4;
        E[j].clave = j;


}
fclose(archivo); 


}

void imprimirDatos(struct futbolTeams *F, int n){
  int i; 
//SE DECLARARN ESTOS ARCHIVOS QUE SERAN EN LOS QUE SE ALMACENARAN LAS SIGUIENTES COSAS: 
  FILE *archivo_info;
//LOS DATOS DE LOS EQUIPOS, JUEGOS GANADOS, PERDIDOS, IDS, EMPAREJAMIENTO ETC.
  FILE *archivo_ids; 
//SOLO SE GUARDARAN LOS IDS DE LOS EQUIPOS
//SE VINCULAN LOS ARCHUVOS DECLARADOS CON LOS QUE GUARDARAN LOS DATOS
  archivo_info = fopen("ID_teams.txt", "w"),  
  archivo_ids = fopen("ID_teams.cvs", "w");
  
for(i = 0; i < n ; i++){

  printf("\n\n\t\t---- %s ----", F[i].teamsName); 
  printf("\n\n\t\tClave de equipo: %d", F[i].clave);
  printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
  printf("\n\tCapitan: %s", F[i].Capitan); 
  printf("\n\tMVP: %s", F[i].MVP);
  printf("\n\tNumero de Jugadores: %d", F[i].n_jugadores);
  printf("\n\tJuegos Totales: %d", F[i].perdidas + F[i].ganadas);
  printf("\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);

  fprintf(archivo_info, "ID: %d - I: %d, %s -----G: %d -----F:%d \n",F[i].clave, i, F[i].teamsName,F[i].goles,F[i].faltas);
  fprintf(archivo_ids, "%d\n", F[i].clave);
}

fclose(archivo_ids);
fclose(archivo_info);

}

void generararreglo(int n, int arr[n]){
int i; 
for(i = 0; i < n; i++ ){
  arr[i] = i; 
}

for(i = 0; i < n; i++){
        int temporal; 
        int indicealeatorio = aleatorio(0, n-1); 

        temporal = arr[i];
        arr[i] = arr[indicealeatorio];
        arr[indicealeatorio] = temporal; 
}
}

int aleatorio(int min, int max){
  return min + rand()/ (RAND_MAX/ (max - min + 1 ) + 1);
}

int filas_CSV(){
  FILE *archivo_id; 
  archivo_id = fopen("ID_teams.csv", "r"); 

  int i = 0, id; 

while(fscanf(archivo_id, "%d,", &id) != EOF){
  i++; 

}



fclose(archivo_id);
return i;
}

void fechas(struct futbolTeams *F, int dia, int lenght, int ids[lenght]){
  FILE *archivo_id;
   archivo_id = fopen("ID_teams.cvs", "+r");
int i, j[8], index = 0, z= -2;

for(i = dia; i <=31; i+=7){

  j[index]= i; 
  j[index + 1] = i + 1;
  index+=2;   
}

printf("\n\n");

for(i = 0; i< index; i++){
 z+=2;
printf("\n\t\t %d de Marzo de 2023\n", j[i]);
printf("\n\t %s \t---VS---\t %s\t\n\n", F[ids[z]].teamsName, F[ids[z+1]].teamsName);
}

}

void enfrentamientos(struct futbolTeams *F){

FILE *archivos_ids;
FILE *archivo_ganadores;
archivos_ids = fopen("ID_teams.cvs", "r+");
archivo_ganadores = fopen("EquiposGanadores.cvs", "w");

int i, n, id, *id_team;

n=  filas_CSV();
id_team = (int *) malloc(n * sizeof(int));

for(i = 0; i < n; i++){

  if(fscanf(archivos_ids, "%d,", &id)!= EOF){

    id_team[i] = id;
    printf("\n %d", id_team[i]);
  }
}
    printf("\n\n");

    printf("El calendario es: \n\n");
    fechas(F, 4, n, id_team);

printf("\n\nEL resultado de los endrentamientos de la primera ronda son: \n\n");

for(i = 0; i < n; i+=2){
  if(F[id_team[i]].goles > F[id_team[i+1]].goles){
    printf("\n\tGana el equipo de: ---%s\n", F[id_team[i]].teamsName);
    fprintf(archivos_ids, "%s,\n",F[id_team[i]].teamsName ); 
  }else if(F[id_team[i+1]].goles > F[id_team[i]].goles){
      printf("\n\tGana el equipo de: ---%s\n", F[id_team[i+1]].teamsName);
      fprintf(archivo_ganadores, "%s,\n",F[id_team[i+1]].teamsName );
    }else{
      if(F[id_team[i]].faltas > F[id_team[i+1]].faltas){
        printf("\n\tGana el equipo de: ---%s \n", F[id_team[i+1]].teamsName);
        fprintf(archivo_ganadores, "%s,\n",F[id_team[i+1]].teamsName );

      }else if(F[id_team[i+1]].faltas > F[id_team[i]].faltas){
          printf("\n\tGana el equipo de: ---%s \n", F[id_team[i]].teamsName);
          fprintf(archivo_ganadores, "%s,\n",F[id_team[i]].teamsName );
        }else{
          printf("\n\tGana el equipo de: ---%s \n", F[id_team[i]].teamsName);
          fprintf(archivo_ganadores, "%s,\n",F[id_team[i]].teamsName );
        }
      }
  }




fclose(archivo_ganadores);
fclose(archivos_ids);
}


int reviso(){
FILE *archivo_equipos;
archivo_equipos = fopen("EquiposGanadores.cvs", "r"); 

int i = 0; 
char equipos[20]; 
while(fscanf(archivo_equipos, "%s,", equipos) != EOF){
  i++;
}
fclose(archivo_equipos);
return i;
}

void generarDatosNo2(struct futbolTeams *E, int n , int arr[n]){

FILE *archivo; 
int i, c = 0, j; 

char equipo[20]; 
//Se vincula la variable "archivo" de tipo FILE con el archivo que queremos abrir
//Se pone la r porque solo funcionara para leer los datos del archivo teams.txt
archivo = fopen("EquiposGanadores.cvs", "r"); 

if(archivo==NULL){
    printf("Error al abrir el archivo\n");
}

  //Para hacer el numero y randomizar las posiciones donde se guardaran los equipos
  srand(time(NULL));

  generararreglo(n, arr);

for(j = 0; j < n; j++){
  
  if(fscanf(archivo, "%s", equipo) != EOF){

    c=arr[j];

    strcpy(E[c].teamsName, equipo);

  }
        E[j].n_jugadores = 11;
        E[j].goles = rand() % 5;
        E[j].faltas = rand() % 4;
        E[j].clave = j;


}
fclose(archivo); 





}


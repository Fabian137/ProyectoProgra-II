#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <time.h>

struct futbolTeams{
    char teamsName[20], D_Tecnico[20], Capitan[10], MVP[10];
    int clave, n_jugadores, goles, faltas, ganadas, perdidas, numRand;
};

void leerDatos(struct futbolTeams *, int);
void generarDatos(struct futbolTeams *, int);
void imprimirDatos(struct futbolTeams *, int);
void ordenar(struct futbolTeams *, int);
int busqueda_NRandomEquipo(struct futbolTeams *, int );
int idenficadorEquipo(struct futbolTeams *, int , int);

int main(){
    struct futbolTeams *equipo;
    int max, numTeam = 0;
    equipo = (struct futbolTeams *) malloc(16 * sizeof(struct futbolTeams));

    // leerDatos(equipo, 3);
 
    generarDatos(equipo, 3);
    max = busqueda_NRandomEquipo(equipo, 16);
    numTeam = idenficadorEquipo(equipo, 16, max);
    printf("\n\t %d -- %d -- %s", max, numTeam, equipo[numTeam].teamsName);
    imprimirDatos(equipo, 3);

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

void generarDatos(struct futbolTeams *F, int n){
    FILE *archivo;
    // char caracter;
    int i, c=0;
    char teams[20], equipo[20];

    archivo = fopen("data/teams.csv", "r");
    
    if (archivo == NULL) {
        printf("Error al abrir el archivo\n");
    }
    /*
    */
    srand(time(NULL)); //
    for (i = 0; i < n; i++){

        if (fscanf(archivo, "%s,", teams) != EOF){
            strcpy(F[i].teamsName, teams);
        }
        
        F[i].n_jugadores = 11;
        F[i].goles = rand() % 5;
        F[i].numRand= rand() % 200;
        // F[i].ganadas = rand() % 4;
        // F[i].perdidas = rand() % 4;
        F[i].faltas = rand() % 4;
        // F[i].clave = i +100;
        F[i].clave = i;
    }

    fclose(archivo);
    
}

void imprimirDatos(struct futbolTeams *F, int n){
    int i;
    for ( i = 0; i < n; i++){
        printf("\n\n\t\t---- %s ----", F[i].teamsName);
        printf("\n\t\tclave de equipo: %d", F[i].clave);
        printf("\n\t\tNUMEROOO: %d", F[i].numRand);
        printf("\n\tDirector Tecnico: %s", F[i].D_Tecnico);
        printf("\n\tCapitan: %s", F[i].Capitan);
        printf("\n\tMVP: ...%s", F[i].MVP);
        printf("\n\tNumero de jugadores: %d", F[i].n_jugadores);

        printf("\n\tJuegos Totales: %d", F[i].perdidas + F[i].ganadas);
        printf("\n\t\tPerdidos: %d ----- Ganados: %d", F[i].perdidas, F[i].ganadas);
        printf("\n\t\tGoles: %d ----- Faltas: %d \n", F[i].goles, F[i].faltas);
    }
    
}

int busqueda_NRandomEquipo(struct futbolTeams *F, int n){
   int i;
   int max = 0;
   for (i = 0; i < n; i++) {
      if (F[i].numRand > max) {
         max = F[i].numRand;
      }
   }
   return max;
}

int idenficadorEquipo(struct futbolTeams *F, int n, int maxNum){
    int i;
    for (i = 0; i < n; i++){
        if (maxNum == F[i].numRand){
            return i;
        }
    }
}

void ordenar(struct futbolTeams *F, int n){


}
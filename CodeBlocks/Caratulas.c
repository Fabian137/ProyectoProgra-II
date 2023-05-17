#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>



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

void menu(){

    printf("\n\n\t Opciones \n\t Puedes consultar:");
    printf("\n\n\t 1) El equipo con mayor número de campeonatos");
    printf("\n\n\t 2) Información detallada de un equipo");
    printf("\n\n\t 3) Información detallada de todos los equipos");
    printf("\n\n\t 4) Partidos ganados");
}

void contexto(){

    printf("\n\n\n\t Algo con lo que me va a ayudar Frida");
}

int main(){
    caratula();

    printf("\n\n");


    return 0;
}
#include <stdio.h>

void imprime_cadena(char* cadena) {
    printf("La cadena es: %s\n", cadena);
}


int main() {
    FILE *archivo;
    archivo = fopen("dat/datos.txt", "w");
    int h=3;
    // fprintf(archivo, " NICEEstos son los nuevos datos que se van a incluir en el archivo.\n");
    
    fclose(archivo);
do
{
    archivo = fopen("datos.txt", "w");
    printf("\n -- %d\n", h);
    h--;
    switch (h){
        case 3:
        fprintf(archivo, "\n 3\n");
        /* code */
        break;
        case 2:
        fprintf(archivo, "\n 2\n");
        /* code */
        break;
        case 1:
        fprintf(archivo, "\n 1\n");
        /* code */
        break;
    
        default:
        break;
    }

} while (h!=0);


    fclose(archivo);
    
    char cadena[] = "Hola mundo";
    imprime_cadena(cadena);
    return 0;
}

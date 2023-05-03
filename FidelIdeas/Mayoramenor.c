# include <stdio.h>

int main(){
    int k1, k2, aux, n, lista[10]; 
    n = 5;
    for(k1=0; k1<n; k1++){
        printf("Dame el dato %d:  ", k1+1);
        scanf("%d", &lista[k1]);
    }

    for(k1=0; k1<n; k1++){
        for(k2=0; k2<n; k2++){
            if(lista[k1]> lista[k2]){
                aux= lista[k1];
                lista[k1]= lista[k2];
                lista[k2]= aux;
            }

        }     
    }

    printf("\n\nLos datos ordenados son: ");
    for(k1=0; k1<n; k1++){
        printf("%d, ", lista[k1]);
        
    }

    return 0; 
}
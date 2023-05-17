void generarDatos(struct futbolTeams *, int, int, int);
void imprimirDatos(struct futbolTeams *, int);
int idenficadorEquipo(struct futbolTeams *, int , int);
int aleatorio(int min, int max);
void generararreglo(int numeroequipos, int *arr);

int filas_CSV(char c[30]);
void Array_ids(int *, int);
void escrituraArchivos_Partidos(struct futbolTeams *,int *, int); 
void iteraciones(struct futbolTeams *F, int *arr, int n, char* ); 
void enfrentamientos(struct futbolTeams *);
void fechas(struct futbolTeams *, int *, int, int, int, int);
int maxChampion(struct futbolTeams *F);
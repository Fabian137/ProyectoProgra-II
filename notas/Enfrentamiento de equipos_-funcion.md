Ya que tenemos una función "generadorDatos", ésta nos ayuda asignar a los indices de equipo un nombre, además de ésto genera la clave y datos extras. En este caso nos interesa lo datos de goles en el pardido, tal vez faltas, (y otras ...?)

NOTA: Lo más apropiado para la propuesta es quitar "partidosGanados" del generaror de datos

Entonces la función "recibirá" dos equipos (la clave), los buscará para finalmente comparar los goles de los dos equipos y ver qué gana
		if(F[clave1].goles > F[clave2].goles ){
		F[clave1].partidosGanados++;
		}

Asi se vería el código para asignar quien gana, algo asi.

# Asignación de partidos
Este tema es de los que más tendríamos que analizar por el momento si queremos que el programa sea "reactivo" y que se pueda adaptar bien a más equipos, por ende hay que diseñar correctamente el algoritmo.
. . .
. . .

La función podría iterar por la cantidad de equipos y por cada iteración (cada equipo) se le dará un número aleatorio y después se compará el orden y nos regresará los dos equipos con número más grande
Usariamos el algoritmo de ordenamiento dos veces, quitando al primer equipo seleccionado en la segunda vez

# Cambio de planes :)
Al final la estructura de enfrentamiento será igual a la que se siguen en los torneos, por ejemplo el mundial, se organzian 4 equipos, se enfrentan 2 y después 2 y quienes ganes de éstos se enfrentan, asi pues avanzando en la categoria o acercandose a la final.

Cada equipo tendrá un puntaje y un número de faltas, cada falta suma 10 o más puntos y en caso de quedar en empate el equipo con mayor puntaje de falta es el que se queda. El puntaje en función del número de faltas creo que se tendría que reinciar por cada ronda.
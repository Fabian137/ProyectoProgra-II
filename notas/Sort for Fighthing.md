                                                                                                                                                                                                                                                                            Ordenamiento para peleas 

Con el uso del algoritmo Bubble Sort se ordenan los números random de mayor a menor y posteriormente lo guardamos en un archivo "valuesTeam.csv" ya ordenados

Después volvemos a abrir ese mismo archivo para leerlo y creamos otro para guardar las claves asociadas al número random que está leyendo.
Asi que recorremos este archivo "valuesTeam.csv" y por cada iteración que leamos el valor random que hay, vamos a llamar a la función IdentificadorClave. La cual encontrará la clave asociada al número random que le pasamos como parametro y lo guardara en el nuevo archivo "ID_Teams.csv"

Entonces para tratar de tener la escencia del funcionamiento:
	Usamos 3 archivos
	
- Uno para guardar los datos random generados y la clave asociada
- Otro para guardar los datos ordenados
- Y el último que toma los numeros ordenados y busca su clave asociada con el primer archivo
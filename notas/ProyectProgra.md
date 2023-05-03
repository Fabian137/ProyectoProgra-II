
Lo que llevamos del proyecto:
	- Lee los nombres de los equipos
	- El nombre del Director Técnico
	- Nombre del Capitan 

Una idea es que los nombres de los equipos los tome aleatoriamente de un archivo, tal vez junto con los nombres de los jugadores (si es que ponemos todos), junto con el nombre del capitán y tal vez del Director técnico. Asi que un primer paso para esto sería aprender a guardar en variables partes de un archivo.

Entonces tendremos un arreglo dinámico de estructuras para los equipos...

La función de generar datos entonces sí podrá generar gran parte de los datos requieridos. Supongo que recorro el archivo csv y por cada iteración asigno el pais (nombre de equipo) a la variable que le corresponde en la estructura


# Requisitos que leí jem
Los equipos generados con las estadisticas (o sin ellas) lo tenemos que guardar en un segundo archivo y al hacer los juegos y demás se tienen que actualizar segun surgan los resultados

# Análisis

Para saber como vamos a construir el código será necesario partir de pensar como se debe de construir o mejor dicho estructurar como se organizará la liga y apartir de este razonamiento, construirlo, comenzar a pensar en cómo se puede generar una liga solo con 8 equipos, para que partiendo de esto, si es posible generar un programa lo suficientemente modular como para que el usuario pueda elegir el número de equipos que jugarán. 

Dentro del ánalisis sobre como organizar la liga de 8 equipos partimos de tomar como inspiración el mundial de futbol, en donde todos los equipos son divididos en 2 grupos y en cada grupo de equipos todos tendrán que jugar contra todos los equipos para posteriormenente dividir cada grupo a la mitad en base de los que tengan mejor puntuación

[[Enfrentamiento de equipos_-funcion]]


# Ejecución de la Liga en ***Codespace***


Presionamos el botón de **code** 
![Ejemplo de las "rondas"](imgsReadme/SS_20230524_2256.jpg)

Nos mostrará dos opciones: **Local** y **Codespaces**
![Ejemplo de las "rondas"](imgsReadme/SS_20230524_2302.jpg)

Seleccionamos **Codespaces** y hacemos click en el espacio *musical guide (O el que esté ahi)*. 

![Ejemplo de las "rondas"](imgsReadme/SS_20230524_2357.jpg)

Si no aparece creamos un *codespace*. ***Create codespace on master***

![Ejemplo de las "rondas"](imgsReadme/SS_20230525_0002.jpg)

Nos abrirá un espacio parecido a este 

![Ejemplo de las "rondas"](imgsReadme/SS_20230525_0005.jpg)

- Entramos a la carpeta donde se encuentra el proyecto (Liga) \
```cd Liga/```

- Copilamos el código (proyecto.c). \
```gcc proyecto.c -o proyecto``` \
***Nota: Si no compila tendremos que instalar alguna extensión como C/C++***
- Ejecutamos 
```./proyecto```

## Estructura 
Dentro de la carpeta ***Liga*** están ***data*** y ***Partidos***.
- ***data*** tiene archivos que usa el programa para ejecutarse
- ***Partidos*** contiene archivos donde se encuentran las rondas que se dieron en la liga ejecutada

- El archivo a nivel de Liga ***(campeonse.csv)*** nos muestra el historial de campeones que ha existido
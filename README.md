<!-- # Cómandos básicos GIT -->
<h1 align="center"> Cómandos básicos GIT </h1>

## Creación de un repositorio 
<!-- <p> -->
Para tener un repositorio donde subir nuestro código. <br>
    ### **1.** Creamos el repositorio, ya sea privado o público <br>
    ### **2.** En donde tengamos nuestro código: VS Code, CodesSpaces o nuestra computadora local<br>
        **2.1** Tenemos que inicializar el repositorio en el directorio donde se encuentre nuestro trabajo<br>
        ```git init```<br>
        **2.2** Posteriormente **"enlazamos"** lo que tenemos en local a nuestro repositorio para que se suba ahí<br>
        ``` git remote add origin URL```<br>
     ## **3.** Damos seguimientos a los archivos que tengamos y los que queremos subir<br>
            ``` git add .``` Da seguimiento a todos los archivos<br>
            ``` git add nombre_Archivo ``` Da seguimiento al archivo o carpeta especificado. <br>
            Nota: Poner también la extensión del archivo<br>
     ## **4.** Si queremos ver cómo vamos podemos hacer un `git status` y nos mostrará si hay archivos sin seguimiento, modificados, eliminados<br>
                y en que rama nos encontramos, etc.<br>
     ## **5.** **commit** de nuestros archivos trackeados (con seguimiento)<br>
            ```git commit -m "Descripcion del commit"```<br>
     ## **6.** Subir nuestros cambios<br>
            ``` git push origin Nombre-de-la-Rama```<br>

<!-- </p> -->

# Cómandos básicos GIT
<!-- <h1 align="center"> Cómandos básicos GIT </h1> -->

## Creación de un repositorio
Para tener un repositorio donde subir nuestro código.

### 1. Creamos el repositorio, ya sea privado o público 
### 2. En donde tengamos nuestro código: VS Code, CodesSpaces o nuestra computadora local
* 2.1 Tenemos que inicializar el repositorio en el directorio donde se encuentre nuestro trabajo
``` git init```
* **2.2** Posteriormente **"enlazamos"** lo que tenemos en local a nuestro repositorio para que se suba ahí 
```git remote add origin URL```
### 3. Damos seguimientos a los archivos que tengamos y los que queremos subir
```git add .``` Da seguimiento a todos los archivos \
```git add nombre_Archivo ``` Da seguimiento al archivo o carpeta especificado. 

***Nota: Poner también la extensión del archivo***  

### 4. Status de nuestro repo en local
Si queremos ver cómo vamos podemos hacer un `git status` y nos mostrará si hay archivos sin seguimiento, modificados, eliminados y en que rama nos encontramos, etc.
### 5. **Commit** de nuestros archivos trackeados (con seguimiento)
```git commit -m "Descripcion del commit"``` La bandera **-m** agrega el mensaje del commit \
```git commit -am "Descripcion del commit"``` Asi con la bandera **-am** da seguimiento a los archivos y agregamos el mensaje del commit
### **6.** Subir nuestros cambios
``` git push origin NOMBRE-RAMA```


## Clonación

### 1. Clonar un repositorio
```git clone URL``` nos clona el proyecto desde la rama ***default*** (master o main)

### 2. Clonar una rama especifica
```git clone -b NOMBRE-RAMA --single-branch URL ``` Nos clona la rama que especifiquemos del repositorio

## "Actualizar un proyecto"
Si trabajamos en colaborativo y un colaborador subión sus cambios al repositorio y nosotros en nuestro ordenador no tenemos esos cambios.
### 1. Verificar
Primero revisemos si estamos en la rama donde deseamos. Para ver las ramas existentes en nuestro ordenador usamos ``git branch``
* 1.1 Si la rama que queremos clonar no existe la podemos crear ``git branch NOMBRE-RAMA``
* 1.2 Si queremos movernos a otra rama ``git checkout NOMBRE-RAMA``

### 2. Actualizar cambios
Para actualizar los cambios que existen en el repositorio a nuestro ordenador usamos ``git pull origin NOMBRE-RAMA``


Listo : ) \
Por el momento es todo . . . ?
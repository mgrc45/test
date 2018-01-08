# Lenguaje C

Para usar lenguaje C desde la terminal de linux necesitaremos preparar nuestro entorno de desarrollo.

## Compilador 

GCC es un compilador integrado del proyecto GNU para C, C++, Objective C y Fortran; es capaz de recibir un programa fuente en cualquiera de estos lenguajes y generar un programa ejecutable binario en el lenguaje de la máquina donde ha de correr.

La sigla GCC significa "GNU Compiler Collection". Originalmente significaba "GNU C Compiler"; todavía se usa  GCC para designar una compilación en C. G++ refiere a una compilación en C++. 

### Verificamos

Verificamos que tengamos instalado el compilador

```sh
gcc --version
```

En caso contrario lo podemos instalar desde el repositorio

```sh
apt-get install build-essential
```

## Compilar

Para compilar nuestro primer programa solo debemos crear un archivo con un codigo simple de prueba.

```c
/* Circulo.c: calcula el área de un círculo.
   Ejemplo para mostrar etapas de compilación.
*/
#define PI 3.1416

main()
{
  float area, radio;

  radio = 10;
  area = PI * (radio * radio);
  printf("Circulo.\n");
  printf("%s%f\n\n", "Area de circulo radio 10: ", area);

}
```

Y desde terminal escribir la siguiente linea

```bash
gcc main.c -o main.out
```

De forma predeterminada genera un archivo compilado "a.out" pero podemos definir otro nombre de salida con la opcion "-o".

## Librerias

De forma prederterminada "GNU Compiler Collection" instala una serie de librerias como stdio.h, stdlib.h, strings.h, complex.h y time.h entre otras. Estas se encuentran ubicadas en la ruta.

```zsh
/usr/include/
```

Y puede consultarse las rutas asociadas de busqueda usando 

```sh
gcc --verbose
ld --verbose
```

o de forma mas especifica

```sh
 gcc -m64 -Xlinker --verbose  2>/dev/null | grep SEARCH | sed 's/SEARCH_DIR("=\?\([^"]\+\)"); */\1\n/g'  | grep -vE '^$'
```

Sin embargo existen librerias propietarias como conio.h de Borland, o que unicamente se encuentran para windows por lo que existen proyectos que tratan de implementar estas librerias dentro de linux. Como son [conio4linux](https://sourceforge.net/projects/conio4linux/) o [ncurses](https://www.gnu.org/software/ncurses/).


En caso de contar con las librerias se pueden llamar de manera simple unicamente por su nombre

```sh
gcc -lfoo main.c -o main.exe
```


```sh
apt-get install libncurses5-dev libncursesw5-dev
gcc -lcurses main.c -o main.exe
```

Para compilar 



```sh
apt-get install build-essential
```

Librerias como conio.h y stdio.h son privativas de Borland, sin embargo existen proyectos que tratan de implementar estas librerias dentro de linux. Como son [conio4linux](https://sourceforge.net/projects/conio4linux/) o [ncurses](https://www.gnu.org/software/ncurses/). Tambien existen espacios de trabajo que instalan estas librerias como son 
[wine](https://github.com/wine-mirror/wine/blob/master/include/msvcrt/conio.h) o [MinGW](https://sourceforge.net/p/mingw/mingw-org-wsl/ci/b4fe285fd979fae8364d3c70056584aaacd95e8b/tree/mingwrt/include/conio.h). Este ultimo me parece el mas completo y se instala de la siguiente forma.

```
apt-get install mingw-w64
```


## Vinculador
ld - Es el nombre del vinculador de GNU, para leer las bibliotecas que estan ligadas ldconfig -v. 
La ruta predeterminada de busqueda de librerias para gcc y g++ es:

```
/usr/include/
```

En caso de poseer alguna copia local de la libreria se puede encontrar con el comando find

```
find / -name conio.h
```

En mi caso se encontro en las siguientes rutas

```
/usr/share/mingw-w64/include/conio.h
/usr/i686-w64-mingw32/include/conio.h
/usr/x86_64-w64-mingw32/include/conio.h
```

Por lo que para ejecutarlo de manera temporal puedo declarar la ruta completa

```
gcc main.c -o main.exe -L /usr/x86_64-w64-mingw32/include/
```

Si desea compilar archivos ejecutables en windows desde linux, esto es conocido como "Cross Compile".

```
sudo apt-get install mingw-w64

# C
i686-w64-mingw32-gcc hello.c -o hello32.exe      # 32-bit
x86_64-w64-mingw32-gcc hello.c -o hello64.exe    # 64-bit
 
# C++
i686-w64-mingw32-g++ hello.cc -o hello32.exe     # 32-bit
x86_64-w64-mingw32-g++ hello.cc -o hello64.exe   # 64-bit
```

Fuentes:
https://iie.fing.edu.uy/~vagonbar/gcc-make/gcc.htm
https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#Link-Options
https://stackoverflow.com/questions/9922949/how-to-print-the-ldlinker-search-path
https://arrayfire.com/cross-compile-to-windows-from-linux/



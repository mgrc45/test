# Lenguaje C/C++

Para usar lenguaje C o C++ en un entorno linux sin necesidad de utilizar un IDE (Entorno de Desarrollo Integrado) necesitaremos preparar nuestra distribución. En este manual encontraras las bases para compilar código fuente, vincular librerías y ejecutar binarios desde la terminal de linux.

### Compilador 

GCC es un compilador integrado del proyecto GNU para C, C++, Objective C y Fortran; es capaz de recibir un programa fuente en cualquiera de estos lenguajes y generar un programa ejecutable binario en el lenguaje de la máquina donde ha de correr.

La sigla GCC significa "GNU Compiler Collection", aun que originalmente significaba "GNU C Compiler" por lo que todavía se usa GCC para designar una compilación en C y G++ para una compilación en C++.

### Verificamos

Verificamos que tengamos instalado el compilador

```sh
gcc --version
g++ --version
```

En caso contrario lo podemos instalar desde el repositorio

```sh
apt-get install build-essential
```

Este paquete instala gcc y g++ en la última versión estable para su distribución de linux.

## Compilar

Para compilar nuestro primer programa solo debemos crear un archivo con un código simple de prueba

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

Y desde terminal escribir la siguiente línea

```sh
gcc main.c -o main.out
```

De forma predeterminada genera un compilado "a.out" pero podemos definir otro nombre de salida con la opción "-o"

## Ejecutar

Para ejecutar desde la terminal escriba la siguiente línea

```sh
./main.out
```

## Librerías

"GNU Compiler Collection" instala una serie de librerías como stdio.h, stdlib.h, strings.h, complex.h y time.h estas se encuentran en la ruta `/usr/include/`. Para consultar las rutas de búsqueda asociadas a un compilador escriba

```sh
gcc --verbose
g++ --verbose
ld --verbose
```

O para mostrar solo las rutas puede filtrar con grep y sed

```sh
gcc -m64 -Xlinker --verbose  2>/dev/null | grep SEARCH | sed 's/SEARCH_DIR("=\?\([^"]\+\)"); */\1\n/g'  | grep -vE '^$'
```

Sin embargo, existen librerías propietarias como "conio.h" de Borland o que únicamente se encuentran para windows por lo que existen proyectos que tratan de implementar estas librerías dentro de linux como son [conio4linux](https://sourceforge.net/projects/conio4linux/) o [ncurses](https://www.gnu.org/software/ncurses/).

```sh
apt-get install libncurses5-dev libncursesw5-dev
gcc -lncurses main.c -o main.out
```

### Cross Compile

Compilar archivos ejecutables en windows desde un entorno linux, es posible con proyectos como [MinGW](https://sourceforge.net/p/mingw/mingw-org-wsl/ci/b4fe285fd979fae8364d3c70056584aaacd95e8b/tree/mingwrt/include/conio.h) y son usados por diversas aplicaciones como [wine](https://github.com/wine-mirror/wine/blob/master/include/msvcrt/conio.h), [codeblocks](www.codeblocks.org/downloads) y [metasploit](https://www.metasploit.com/download).

```sh
sudo apt-get install mingw-w64

# C
i686-w64-mingw32-gcc hello.c -o hello32.exe      # 32-bit
x86_64-w64-mingw32-gcc hello.c -o hello64.exe    # 64-bit
 
# C++
i686-w64-mingw32-g++ hello.cc -o hello32.exe     # 32-bit
x86_64-w64-mingw32-g++ hello.cc -o hello64.exe   # 64-bit
```

## Incluir librerías
Puede incluir de manera manual alguna librería al momento de realizar una compilación

```sh
gcc main.c -o main.exe -I /usr/x86_64-w64-mingw32/include/
```

### Fuentes

* [El compilador GCC](https://iie.fing.edu.uy/~vagonbar/gcc-make/gcc.htm)
* [Options for Linking](https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html#Link-Options)
* [How to print the linker search path](https://stackoverflow.com/questions/9922949/how-to-print-the-ldlinker-search-path)
* [Cross Compile to Windows From Linux](https://arrayfire.com/cross-compile-to-windows-from-linux/)

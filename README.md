# Programacion

Un programa es un conjunto de instrucciones que el ordenador puede interpretar y ejecutar para realizar una tarea especifica. Se codifica usando algun lenguaje de programación y con la ayuda de un compilador se traduce a lenguaje maquina. A esta traduccion se le conoce como binario o simplemente ejecutable.

´´´
De acuerdo a Bohm y Jacopini un programa puede ser escrito usando únicamente 3 estructuras (Secuencial, Selectiva y Repetitiva). Ademas de poseer solo un punto de entrada y uno de salida. Sin bucles infinitos y con almenos un camino hasta el final. A esto se le conoce como el teorema de "Bohm y Jacopini".
´´´

Un lenguaje de programación es un conjunto de simbolos ordenados por reglas sintacticas y semanticas; que componen un lenguaje formal entendible para el ser humano. Mientras mas cercano al lenguaje natural se dice que es de mayor nivel. 

De acuerdo a esta clasificacion tenemos
- Lenguajes de alto nivel: VB, C, C#, PHP, Java
- Lenguaje de medio nivel: Ensamblador (MOV 1AX,4CH)
- Lenguaje de bajo nivel: Binario, tambien llamado lenguaje maquina (10101001)


Utilizando un lenguaje de programación podemos escribir un codigo que sera la fuente de nuestro programa, mejor conocido como **codigo fuente**.

El compilador es el encargado de traducir el codigo fuente pasando por un codigo objeto o directamente a lenguaje maquina. Para realizar esta tarea se encarga de enlazar librerias y analizar el codigo fuente para asegurarse de que cumpla con las reglas del lenguaje de programacion.
- Analisis Léxico: Valida que el conjunto de símbolos o instrucciones correspondan al lenguaje.
- Analisis Sintáctico: Valida las reglas para combinar de forma correcta las instrucciones.
- Analisis Semántico: Valida el significado de cada linea del codigo fuente.

Interprete
Existen lenguajes de programacion que no son compilados sino leidos e interpretados directamente desde el codigo fuente. Por lo que no generan un ejecutable. Esto resta velocidad en cuanto a ejecucion, sin embargo es util para ser ejecutado en diferentes plataformas como es el caso de Java que es interpretado por la maquina virtual de java (JVM).

La programacion para su estudio fue clasificada en 
- Programación estructurada: Esta incluye el uso de diseño descendente (top-down), la division de problemas complejos en varios simples y el uso de estructuras basicas (secuenciales, selectivas y repetitivas).
- Programación modular: Consta de varias secciones que interactuan através de llamadas a procedimientos ó funciones. Y su mayor ventaja es la reutilizacion de codigo y la facilidad para depurar el mismo. Ya que se puede modificar un modulo sin afectar a otros.
- Programacón orientada a objetos: Consiste en la utilizacion de estructuras de codigo, las cuales poseen propiedades y atributos; por lo cual reciben el nombre de objetos.

El objetivo original de la programacion consiste en la automatizacion de tareas, siendo la tarea del programador la abstraccion, resolucion y representacion de una solucion en un lenguaje de programacion. Es de este proceso que surge la algoritmia, que es la ciencia y arte de solucionar problemas.

La algoritmia consiste en la resolucion de problemas por metodos no triviales, es decir resolver un problema de la manera mas eficiente posible. Ya sea usando el menor numero de recursos o el menor tiempo computacional.

## Buenas practicas

Existen un conjunto de reglas no escritas que facilitan el trabajo a los programadores.



2.2 Metodología para la solución de problemas
	La programación se reduce a la ciencia y arte de solucionar problemas
	Análisis del problema
Se debe considerar la aplicación de requerimientos de entrada, salida y procesamiento.
Cuando se analiza un problema se busca nombres y verbos dentro de la declaración del problema.
Los nombres a menudo suelen sugerir información de entrada y salida.
Y los verbos sugieren pasos del procedimiento.
	Diseño del algoritmo
Determinar los pasos o instrucciones que deban llevarse a cabo y el orden lógico de su ejecución para dar una eficiente solución al problema.	
Pare ello se pueden utilizar las siguientes herramientas:
A)Algoritmo
B)Diagrama de Flujo
C)Pseudo código
Codificación
	Implica la escritura real de l programa en un lenguaje formal de programación
	Compilación y ejecución
Antes de que el programa sea traducido al lenguaje de maquina (compilado)debe ser verificado para evitar ciertos errores.
Error de Sintaxis: violación a las reglas del lenguaje de programación.
Error de escritura: Ocurre cuando se intenta mezclar tipos de datos diferentes
Error de Vinculo: ocurre cuando una rutina requerida no puede ser localizada
Después de ser compilado el programa suelen ocurrir algunos errores mas, como son:
1.- Error lógico: La lógica estuvo mal planteada y por ello el programa no hace lo que el usuario quiere.
2.- Error de tiempo de ejecución: El programa intenta resolver una operación ilegal 
(ejemplo: una division entre cero)
	


Prueba y depuración
Siempre hay unos cuantos errores en el programa (no realiza lo esperado), quitar los errores (Depurar) es comúnmente lo que consume mas tiempo al programador.
Los pasos básicos de depuración son :
*Darse cuenta que tiene un error
*Localizar y determinar la causa del error
*Corregir el error
Las 4 cosas para depurar su programa son :
A) Verificación o prueba de escritorio
B) Compilación y vinculación del programa
C) Ejecución
D) Depuración 
	Documentación
	Debe incluir
	1.- Descripción del problema
		2.- El algoritmo 
	3.- Listado de programa con comentarios
		4.- Muestra datos de entrada y salida
	5.- Resultados de la verificación y la depuración
	6.- Instrucciones para el usuario
3.1 Estructura de un programa (En turbo C++)
	#include<stdio.h>    Cabecera 
void main (void) Función
{
const float pi = 3.1416 ; Constante
float resulatado; Variable
resultado = pi * 5; Proceso
printf(“%f”,resultado); Proceso
}
Cabecera
En la primera línea del código en este caso es el nombre de la librería que le dice a la computadora como ejecutar las ordenes.
Programa principal
Aquí se escribe el nombre de el bloque de ordenes (función)que se va a ejecutar siempre la primera será “main” o en español “principal”.
“void main (void)” por que no manda nada ni recibe nada.
{}
Toda la cabecera va a comenzar con la apertura de una llave y el cierre de esta para delimitar la función
	

Declaración de variables y constantes
Una constante: “const tipo_dato nombre =  dato;”
Una variable: “tipo_dato nombre;”


	Procesos
Aqui se incluyen todos los calculos y demas operaciones del programa.
3.2 Tipos de Datos

Numéricos: Enteros y Enteros Reales
	Alfabéticos: Símbolos
	Alfanuméricos: Números y símbolos	

	Clasificación
		Carácter A
		Cadena “mi_nombre_es_miguel”
		Reales 3.1416
		Lógicos not, or, and
Constantes: Son aquellos espacios en memoria que una vez definidos no seran modificados durante la ejecucion del programa.
Variables: Son aquellos espacios en memoria que pueden ser modificados durante la ejecucion del programa.

Reglas: El primer carácter debe de ser una letra o el símbolo ”_” no se admiten caracteres especiales.
		Ejemplos de declaraciones validas:
			int x,numero,otro_numero;
		float factorial,resultado;
			char respuesta;
		Reglas de alcance:
Variable local: Es la que esta dentro de una función y cuando esta termina la variable desaparece.
Variable global: Es la que esta fuera de todas las funciones.
	Operadores 
Turbo C es rico en operadores incorporados, un operador es un símbolo que le dice al compilador que realice manipulaciones matemáticas o lógicas especificas, existen operadores:
Aritméticos:
+ Suma
- Resta
* Multiplicación
/ División 
% Residuo de la división
++ Incremento X++ ó ++X es equivalente a X=X+1
-- Decremento X- - ó - -X es equivalente a X=X-1
Lógicos o sobre bits:
	¦¦ OR
	&& AND
	¡ NOT
Relacionales o de comparación:
= = Igual
¡= Diferente
> Mayor que 
< Menor que
<= Menor o igual que
>= Mayor o igual que
		Operadores de Asignación 
		= Asignación simple
		+= Asignación de adición compuesta X+=3 ó X=X+3
		-= Asignación de sustracción compuesta Y-=2 ó Y=Y-2
	*= Asignación de multiplicación compuesta X*=Y ó X=X*Y
	/= Asignación de división compuesta Y/=4 ó Y=Y/4
	%= Asignación de modulo compuesto Y%=X ó Y=Y%X
3.3 Instrucciones básicas 
	Entrada / Salida 
	Printf: Se usa para mostrar algun valor en pantalla.
	Scanf: Se usa para asignar un dato a una variable.
	Asignación x=5;
3.4 Instrucciones de control
	Secuenciales
Una instrucción se ejecuta una después de otra en el orden establecido.
	Selectivas o de desicion 
Bifurca o altera el orden de ejecución de las instrucciones al comparar operándos.
		Simple: Bifurca cuando es verdadero
		Doble: Bifurca con dos alternativas
		Múltiple: Bifurca con varias alternativas
	Repetitivas
	Ejecuta instrucciones un cierto numero de veces
3.5 Programación modular
En este caso se divide un gran programa en varios subprogramas llamados modulos ó sum rutinas, los cuales son de gran utilidad para crear progrmas demasiado complejos, dividiendo su dificultad.
3.6 Estructura de datos
	Concepto
Arreglos: Colección de variables de un mismo tipo que se denominan por un nombre comun.
Sus principales tipos son:     Unidimensional o Vector
Bidimensional o Matriz
N dimensional o Multidimensional
	Registro
	Archivos
		Texto
		Binario
	Punteros
3.7 Búsqueda y ordenamientos
	Pila
	Colas
	Bujías
	Ligas
4.1 Aplicación del análisis y diseño de sistemas de información.

 

## Glosario

**Instrucción**: Conjunto de datos insertados en una secuencia estructurada que el procesador interpreta y ejecuta.
**Programa**: Conjunto de instrucciones, escritas para realizar una tarea especifica.
**Lenguaje de programación**: Conjunto de reglas gramaticales que permiten formar un programa.
**Codigo fuente**: Instrucciones escritas en un lenguaje de programación y por lo tanto legible por un humano.
**Codigo objeto**: Contiene las instrucciones de alto nivel traducidas al lenguaje de maquina (por lo regular la extencion en .obj).



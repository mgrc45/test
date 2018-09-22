# Teoria de números

## Números primos

Los números primos son aquellos que solo pueden ser divididos de manera exacta por si mismos y por la unidad. Se puede decir que un número primo tiene como factor unicamente a la unidad y a si mismo.

> El número 1 sólo tiene un divisor, por eso no lo consideramos primo. La unidad no esta considerada como un número primo ni compuesto.

Para obtener los números primos se utiliza el siguiente algoritmo trivial

```c++
#include<iostream>

using namespace std;

int is_prime(int n)
{
 if (n<2) return false;
 for (int i = 2; i < n; i++)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 for (int cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Sin embargo este algoritmo tiene una complejidad muy alta **n^2**

### Formas de aproximación a los números primos

Otras maneras de atacar el problema de los numeros primos son:

* Teorema de divisibilidad de un numero
* Probar todos los números
* Criba de eratóstenes
* Teoria de números
* Raiz de N

## Números compuestos

Los números compuestos tienen varios factores ademas del uno y de si mismo. Otra forma de expresar los números compuestos es como productos de potencias de números primos, a dicha expresión se le llama descomposición de un número en factores primos.

> Podemos decir que si un número **N** no es dividido por un número primo, entonces es un número primo.

Ejemplo: **N**=12, **Raiz de N**=3.46=>4

| d \| N | d * k = N | |
| --- | --- | --- |
| 1 \| 12 | 1 * 12 = 12 | |
| 2 \| 12 | 2 * 6 = 12 | |
| 3 \| 12 | 3 * 4 = 12 | |
| 4 \| 12 | 4 * 3 = 12 | Repetido |
| 3 \| 12 | 6 * 2 = 12 | Repetido |

**Propiedad de la factorización: Efecto espejo**

Al realizar la factorización de un número **N** en sus factores **d** y **k** llega un punto en que sus operaciones resultan repetidas intercambiando el valor de **k** por **d**. Este punto es alcanzado cuando se llega a la **raiz de N** motivo por el cual podemos usar esta propiedad de la factorización como limite para evitar duplicar operaciones.

```c++
#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n)
{
 if (n<2) return false;
 int r = sqrt(n);
 for (int i=2; i <= r; i++)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 for (int cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Este algoritmo tiene una complejidad menor **Raiz de N**

Otra propiedad que podemos aprovechar para simplificar los numeros primos es la **paridad de una función** la cual indica que el producto de dos funciones impares es una función par. Misma se puede aplicar a la teoria de números.

Ejemplo:

| 1 + 1 | 2 |
|---|---|
| 3 + 3 | 6 |
| 5 + 5 | 10 |

```c++
#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n)
{
 if (n<2) return false;
 if (n==2) return true;
 
 //Valido pares
 //if (n%2==0) return false;
 if (n&1==0) return false;
 
 int r = sqrt(n);
 for (int i=3; i <= r; i+=2)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 for (int cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Este algoritmo tiene una complejidad algo menor que la anterior

### Criba de eratóstenes

Este metodo consiste en eliminar duplicados.
 1. Crea un arreglo de bits "primos[0..n]" e inicie todos los valores en true
 2. Llene con false los valores que no son primos

```c++
#include<iostream>

using namespace std;
 
void criba(int n)
{
 int p,i;
 bool primos[n+1] = {1,1};
 
 //Actualiza todos los multiplos
 for (p=2; p<=n; p++)
   if (primos[p] == false)
     for (i=p+p; i<=n; i+=p) primos[i] = true;
 
 //Imprime los numeros primos
 for (p=0; p<=n; p++)
   if (primos[p] == false) cout<<p<<" ";
} 

int main()
{
  int n = 100;
  criba(n);
  return 0;
}
```
Este algoritmo tiene una complejidad de **N log N** para ser creada y **constante** para ser consultada

Sin embargo aun tiene posibilidad de ser optimizado, cuando examinamos el segundo ciclo que actualiza los multiplos, encontramos repeticiones al momento de incrementar el contador **i** con la formula **i=i+p** como se muestra en el siguiente ejemlo. Por lo cual cambiando la formula a **i=i+2p** se evitan operaciones inecesarias.

Ejemplo:

* **2**: 4,6,8,10,12,14,16,18,20
* **3**: 6,9,12,15,18,21
* **5**: 10,15,20

```c++
#include<iostream>
#include<cmath> 

using namespace std;
 
void criba(int n)
{
 int p,i,i2;
 bool primos[n+1] = {1,1};
 
 //Actualiza todos los multiplos
 for (p=2; p<=n; p++)
   if (primos[p] == false) {
     i2=(p==2)?2:2*p;
     for (i=p*p; i<=n; i+=i2) primos[i] = true;
   }
 
 //Imprime los numeros primos
 for (p=0; p<=n; p++)
   if (primos[p] == false) cout<<p<<" ";
} 

int main()
{
  int n = 100;
  criba(n);
  return 0;
}
```
Este algoritmo tiene una complejidad algo menor de de **N log N** para ser creada y **constante** para ser consultada

**Factorización de primos**

La criba tambien puede ser usada para descomponer un numero en sus divisores exactos, aprovechando la tabla ya generada.

```c++
#include<iostream>
#include<cmath> 

using namespace std;
 
void criba(int n, bool fact)
{
 int p,i,i2;
 int primos[n+1] = {0};
 
 //Actualiza todos los multiplos
 for (p=2; p<=n; p++)
   if (primos[p] == 0) {
     i2=(p==2)?2:2*p;
     for (i=p*p; i<=n; i+=i2) primos[i] = p;
   }
 
 if (fact==1)
 {//Factoriza "n"
   while(primos[n]>0) {
     cout<<n<<" "<<primos[n]<<endl;
     n=n/primos[n];
   }
   cout<<n<<" "<<1<<endl;
 }
 else
 {//Imprime los numeros primos
   for (p=2; p<=n; p++)
     if (primos[p] == 0) cout<<p<<" ";
 }
} 

int main()
{
  int n = 12;
  criba(n,1);
  return 0;
}
```
Esta version puede determinar los numeros primos que factorizan a un numero **N**

## Glosario
* **Múltiplos**: Números que contienen a otros exactamente.
* **Factores**: Números que se multiplican para formar otro.


## Referencias
* [geeksforgeeks.org: Sieve of eratosthenes](https://www.geeksforgeeks.org/sieve-of-eratosthenes/)
* [dma.fi.upm.es: Aritmetica modular - Divisibilidad](http://www.dma.fi.upm.es/recursos/aplicaciones/matematica_discreta/web/aritmetica_modular/divisibilidad.html)
* [maribellopezmozo.webnode.es: Teoría de números](https://maribellopezmozo.webnode.es/sexto-grado/matematicas/teoria-de-numeros/)
* [es.slideshare.net: Múltiplos, Factores, Numeros primos y compuestos](https://es.slideshare.net/Crisalys/power-ponit-mltiplos-factores-nmeros-primos-y-compuestos)

## Autores
* [Angel González](https://github.com/mgrc45)
* [Luis Rodríguez](https://github.com/ChOmPsJr)

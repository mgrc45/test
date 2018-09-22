# Teoria de números

## Numeros primos

Los números primos son aquellos que solo pueden ser divididos de manera exacta por si mismos y por la unidad. Se puede decir que un número primo tiene como factor unicamente a la unidad y a si mismo.

> El número 1 sólo tiene un divisor, por eso no lo consideramos primo. La unidad no esta considerada como un número primo ni compuesto.

Para obtener los números primos se utiliza el siguiente algoritmo trivial

```c++
#include<iostream>

using namespace std;

int is_prime(int n)
{
 for (int i = n-1; i > 1; i--)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 int cnt,j;
 for (cnt = 2; cnt<100; cnt++)
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

Ejemplo: **N**=12, **Raiz de N*=3.46=>4

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
#include<math.h>

using namespace std;

int is_prime(int n)
{
 int r = sqrt(n);
 for (int i = 2; i <= r; i++)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 int cnt,j;
 cout<<"1"<<endl;
 for (cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Este algoritmo tiene una complejidad menor **Raiz de N**

Otra propiedad que podemos aprovechar para simplificar los numeros primos es.



```c++
#include<iostream>
#include<math.h>

using namespace std;

int is_prime(int n)
{
 int r = sqrt(n);
 for (int i = 2; i <= r; i++)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 int cnt,j;
 cout<<"1"<<endl;
 for (cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Este algoritmo tiene una complejidad menor **Raiz de N**

**Descomposición en sus valores primos**

Cualquier número entero positivo no primo **N** puede descomponerse en en factores primos.

| N | Factores |
|---|---|
| 12 | 2 * 2 * 3 |

### Criba de eratóstenes

Este metodo consiste en eliminar duplicados.
 1. Crea un arreglo de bits "primos[0..n]" e inicie todos los valores en true
 2. Llene con false los valores que no son primos

```c++
#include<iostream>

using namespace std; 
 
void SieveOfEratosthenes(int n) 
{
 bool primos[n+1];
 memset(primos, true, sizeof(primos));
 
 for (int p=2; p*p<=n; p++) 
   if (prime[p] == true) 
   {//Actualiza todos los multiplos de "p"
     for (int i=p*2; i<=n; i += p) prime[i] = false; 
   }
 
 //Imprime todos los numeros primos
 for (int p=2; p<=n; p++) 
   if (prime[p]) cout<<p<<" ";
} 

int main() 
{ 
  int n = 30;
  //Imprime los numeros primos menores o iguales a "n"
  SieveOfEratosthenes(n); 
  return 0; 
} 
```
Este algoritmo tiene una complejidad de **N log N** para ser creada y **constante** para ser consultada

## Glosario
**Múltiplos**: Números que contienen a otros exactamente.
**Factores**: Números que se multiplican para formar otro.


## Referencias
https://www.geeksforgeeks.org/sieve-of-eratosthenes/
https://maribellopezmozo.webnode.es/sexto-grado/matematicas/teoria-de-numeros/
https://es.slideshare.net/Crisalys/power-ponit-mltiplos-factores-nmeros-primos-y-compuestos

## Autores
* Angel Gonzalez
* Luis Rodriguez

Mínimo Común Múltiplo (MCM), Máximo Común Divisor (MCD), Greatest Common Divisor (GCD), Complemento

```c++
#include <iostream>
#include <algorithm>

int main()
{
  cout << std::__gcd(100,24);
  return 0;
}
```

Complemento de x > x
> Multiplicativa, conmutativa, asociativa, distributiva

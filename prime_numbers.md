# Numeros primos
Por definicion son aquellos que solo pueden ser divididos de manera exacta por si mismos y por la unidad.

Para obtener los numeros primos se utiliza el siguiente algoritmo trivial

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
 cout<<"1"<<endl;
 for (cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}
```
Sin embargo este algoritmo tiene una complejidad muy alta **n^2**

Otras maneras de atacar el problema de los numeros primos son:

* Teorema de divisibilidad de un numero
* Criba de eratóstenes
* Raiz de N
* Función Z
* Teoria de números

**Teoria de números**

Los números primos de un número N son menores a la **raiz de N**

| Expresión | Formula |
| --- | --- |
| d \| x | d * k = x |

Por ejemplo, en el caso de 12 su raiz es 3.46, como no es exacta validamos hasta su inmediato superior 4 ó hasta que la diferencia entre divisor y dividendo sea la unidad. Por que continuar solo nos llevaria a repetir operaciones.

| 1 \| 12 | 1 * 12 = 12 |
| --- | --- |
| 2 \| 12 | 2 * 6 = 12 |
| 3 \| 12 | 3 * 4 = 12 |

Complemento de x > x
> Multiplicativa, conmutativa, asociativa, distributiva


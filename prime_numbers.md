# Numeros primos
Los numeros primos son aquellos que solo pueden ser divididos de manera exacta por si mismos y por la unidad.

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

## Formas de aproximación a los numeros primos

Otras maneras de atacar el problema de los numeros primos son:

* Teorema de divisibilidad de un numero
* Criba de eratóstenes
* Raiz de N
* Función Z
* Teoria de números

### Teoria de números

Los números primos de un número **N** son menores a la **raiz de N**

| Expresión | Formula |
| --- | --- |
| d \| x | d * k = x |

Por lo que si continuamos buscando sus multiplos restando 1 a **x** y sumando 1 a **d** nos daremos cuenta que existira un limite en que la diferencia sea la unidad y de seguir calculando solo se repetiran operaciones. Por ejemplo cuando **x** sea 12 el limite es su raiz 3.46 en enteros es 3.

| 1 \| 12 | 1 * 12 = 12 |
| --- | --- |
| 2 \| 12 | 2 * 6 = 12 |
| 3 \| 12 | 3 * 4 = 12 |

Factorización / Descomposición de un número en factores primos.
Mínimo Común Múltiplo (MCM), Máximo Común Divisor (MCD), Greatest Common Divisor (GCD)

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



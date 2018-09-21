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

**Limite**

Los números primos de un número **N** son menores a la **raiz de N**. Esto debido a que si multiplicamos 2 numeros **a** y **b** que sean mayores a la **raiz de N** estos formaran un numero superior a **N**.

Ejemplo: **N**=12,**r**=Raiz de 12=3.46, {**a**,**b**} > 3.46

| a * b | resultado |
| --- | --- |
| 4 * 4 | 16 |
| 4 * 5 | 20 |

**Factorización**

Cualquier número entero positivo **N** puede descomponerse en sus multiplos, realizando una diferencia igual a ambos factores (**d** y **k**) hasta llegar a la **raiz de N**.

Ejemplo: **N**=12, **r**=Raiz de 12=3.46

| d \| N | d * k = N | |
| --- | --- | --- |
| 1 \| 12 | 1 * 12 = 12 | |
| 2 \| 12 | 2 * 6 = 12 | |
| 3 \| 12 | 3 * 4 = 12 | |
| 4 \| 12 | 4 * 3 = 12 | Repetido |
| 3 \| 12 | 6 * 2 = 12 | Repetido |

Si continuamos buscando sus multiplos restando 1 a **x** y sumando 1 a **d** nos daremos cuenta que existirá un limite **raiz de N** ó en que la diferencia sea la unidad, de seguir calculando solo se repetiran operaciones.

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
 1. Crea un arreglo hasta el numero indicado
 2. Tacha los multiplos con un arreglo de bits
Este algoritmo tiene una complejidad de **N log N** para ser creada y **constante** para ser consultada

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

## Exponenciación binaria

- a <sup>b</sup> mod **m**
- a <= 2 <sup>63</sup>
- b <= 2 <sup>9180</sup>

### Divide y venceras

| a <sup>b</sup> = a <sup>b/2</sup> * a <sup>b/2</sup> |
|---|
| a <sup>b/2</sup> = a <sup>b/4</sup> * a <sup>b/4</sup> |
| ... |
| a <sup>2</sup> = a <sup>1</sup> * a <sup>1</sup> |
| a <sup>1</sup> = a <sup>1</sup> |

| 3 <sup>10</sup> = 3 <sup>5</sup> * 3 <sup>5</sup> | 243 * 243 | 59049 |
|---|---|---|
| 3 <sup>5</sup> = 3 <sup>1</sup> * 3 <sup>4</sup> | 243 | |
| 3 <sup>4</sup> = 3 <sup>2</sup> * 3 <sup>2</sup> | 81 | |
| 3 <sup>2</sup> = 3 <sup>1</sup> * 3 <sup>1</sup> | 9 | |
| 3 <sup>1</sup> = 3 <sup>1</sup> | | |

### Propiedades de aritmetica modular

| Origen | Factorización | Uso |
|---|---|---|
| ( a + b ) % m | [ (a % m) + (b % m) ] % m | Se aplica para sumas |
| ( a * b ) % m | [ (a % m) * (b % m) ] % m | Se aplica para exponentes |
| ( a - b ) % m | [ (a - b + m) ] % m | |
| ( a / b ) % m | [ (a % m) / ( b % m ) ] % m | Error: Esta relación no se cumple  |
|  a * b<sup>-1</sup> % m |  | Se usa euclides extendido |

#### Exponenciación binaria

| ( a * b ) % m | [ (a % m) * (b % m) ] % m |
|---|---|

| 3 <sup>10</sup> % 7 | [ (3 <sup>5</sup> % 7) * (3 <sup>5</sup> % 7) ] % 7 | [ 5 * 5 ] % 7 | 4 |
|---|---|---|---|
| 3 <sup>5</sup> % 7 | [ (3 <sup>4</sup> % 7) * (3 <sup>1</sup> % 7) ] % 7 | [ 4 * 3 ] % 7 | 5 |
| 3 <sup>4</sup> % 7 | [ (3 <sup>2</sup> % 7) * (3 <sup>2</sup> % 7) ] % 7 | [ 2 * 2 ] % 7 | 4 |
| 3 <sup>2</sup> % 7 | [ (3 <sup>1</sup> % 7) * (3 <sup>1</sup> % 7) ] % 7 | [ 3 * 3 ] % 7 | 2 |
| 3 <sup>1</sup> % 7 | 3 <sup>1</sup> % 7 | | 3 |

```c++
typedef long long int lli;

lli expBinnaria(lli a, lli b, lli m)
{
  if (b==1) return a % m;
  if (b%2==0) {
    n = expBinaria( a, b/2, m ) % m;
    return (n*n) % m;
  }
  else {
    n = expBinaria( a, b-1, m ) % m;
    return (n*a%m) % m;
  }
}
```

#### Multiplicación binaria

| 3 * 10 | ( 3 * 5 ) + ( 3 * 5 ) | 15 + 15 | 30 |
|---|---|---|---|
| 3 * 5 | ( 3 * 4 ) + ( 3 * 1 ) | 12 + 3 | 15 |
| 3 * 4 | ( 3 * 2 ) + ( 3 * 2 ) | 6 + 6 | 12 |
| 3 * 2 | ( 3 * 1 ) + ( 3 * 1 ) | 3 + 3 | 6 |
| 3 * 1 | | | 3 |

| ( a + b ) % m | [ (a % m) + (b % m) ] % m |
|---|---|

| 3 x 10 % 7 | [ ( 3 * 5 ) % 7 + ( 3 * 5 ) % 7 ] % 7 | 15 % 7 + 15 % 7  | 4 |
|---|---|---|---|
| 3 x 10 % 7 | ( 3 * 5 ) % 7 + ( 3 * 5 ) % 7 | | 1 |
| 3 x 5 % 7 | ( 3 * 4 ) % 7 + ( 3 * 1 ) % 7 | | 2 |
| 3 x 4 % 7 | ( 3 * 2 ) % 7 + ( 3 * 2 ) % 7 | | 5 |
| 3 x 2 % 7 | ( 3 * 1 ) % 7 + ( 3 * 1 ) % 7 | 3 + 3 | 6 |
| 3 x 1 % 7 | ( 3 * 1 ) % 7 | | 3 |

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

* Teorema de Euler
* Pequeño teorema de Fermat
* Criterio de Euler
* Teorema de Lagrange
* Aritmética de saturación

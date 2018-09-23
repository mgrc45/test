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

# Guia rapida: Lenguaje C

## Cuerpo del programa

```c++
#include <iostream>
using namespace std;

int main(void)
{

 return 0;
}
```
## Comentarios
```c++
//Un comentario de una linea

/* Tambien puede realizar
 comentarios multilinea */
```

## Constantes

```c++
#define PI 3.1416
const double pi = 3.1416;
```

## Variables

Tipos de dato primitivos
```c++
bool a = true;
char b = 'c';
int c = 32767;
long d = 2147483647;
float e = 3.4*10^8;
double f = 1.7*10^308;
```

```c++
string g = "Hola mundo!";
char h = {'H','o','l','a'};
enum persona {string nombre, int edad, bool generoM};
```

## Entrada/Salida

```c++
char v;
scanf("Teclee un caracter %c",&v);
scanf("Teclee una cadena %s",&v);

printf("Escriba su nombre\n");

printf("Cal 1\tCal 2\tCal 3\n");
printf("8.5\t7.2\t10\n");
printf("8.6\t7.6\t9.3\n");

printf("Beep \a");

cout<< "El promedio es 8.3";
```

## Ciclos

```c++
for(int cnt=0; cnt<6; cnt++) 
  printf("%d\n",cnt);
```

```c++
int cnt = 0;
while (cnt < 5)
{
 cout<<cnt<<"\n";
 cnt++;
}
```

```c++
int cnt = 0;
do
{
 cout<<cnt<<"\n";
 cnt++;
} while (cnt < 5);
```

## Desiciones

```c++
int a=5,b=10;
if (a > b) 
  printf("A es mayor que B");
else 
  printf("B es mayor que A");
```

Condicion ternaria

```c++
int a=5,b=10;
int c = (a > b)? a: b;
```

## Desiciones multiples

```c++
int Opc,a=10,b=5;
printf("Elija una opcion\n");
printf("1) Suma\n");
printf("2) Resta\n");
printf("3) Multiplicacion\n");
printf("4) Division\n");
printf("5) Modulo\n");
printf("Otro) Salida\n");
scanf("%d",&Opc);

switch (Opc)
{
 case 1:
  printf("Suma %d\n",a+b);
 break;
 case 2:
  printf("Resta %d\n",a-b);
 break;
 case 3:
  printf("Multiplicacion %d\n",a*b);
 break;
 case 4:
  printf("Division %d\n",a/b);
 break;
 case 4:
  printf("Modulo %d\n",a%b);
 break;
 default:printf("Salida\n");
}
```





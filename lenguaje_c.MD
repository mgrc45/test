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

Constantes literales

```c++
#define PI 3.1416
const double pi = 3.1416;
```

```c++
#include <climits>
#include <iostream>
using namespace std;

int main(void)
{
 int a = INT_MAX;
 int b = INT_MIN;
 return 0;
}
```

Constantes simbolicas

```c++
const area = base * altura;
```

## Variables

Tipos de datos primitivos
```c++
bool a = true;
char b = 'c';
char b1 = 64; //ASCII 64 = @
int c = 32767;
int c1 = 0B101010; //Binario
int c2 = 0xfc; //Hexadecimal
long d = 2147483647;
float e = 3.4*10^8;
double f = 1.7*10^308;
```

```c++
string g = "Hola mundo!";
char h = {'H','o','l','a'};
enum Dias {Domingo,Lunes,Martes,Miercoles,Jueves,Viernes,Sabado};
```

Locales y globales

```c++
#include <iostream>

int global = 5;

int main(void)
{
 int local = 10;
 return 0;
}
```

## Entrada/Salida

```c++
char chr;
cin>>chr;
scanf("Teclee un caracter %c",&chr);

string cad;
cin>>str;
scanf("Teclee una cadena %s",&cad);

cout<<"Hola mundo!";

cout<<"Cal 1\tCal 2\tCal 3\n";
cout<<"8.5\t7.2\t10\n";
cout<<"8.6\t7.6\t9.3\n";
cout<<"Beep \a";

printf("Caracter: %c",chr);
printf("Cadena: %s",str);

printf("Entero: %d",1);
printf("Flotante: %4.2f",3.1416);
printf("Flotante sin ceros: %g",1.25000);
printf("Flotante con presicion: %4.2f",3.1416);
```

## Ciclos

```c++
for(int cnt=0; cnt<6; cnt++) 
 cout<<cnt<<"\n";
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

## Desicion

```c++
int a=5,b=10;
if (a > b) 
  cout<<"A es mayor que B";
else 
  cout<<"B es mayor que A";
```

Condicion ternaria

```c++
int a=5,b=10;
int c = (a > b)? a: b;
```

## Desicion multiple

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

## Apuntadores

Solo algunos lenguajes de programacion pueden interactuar con los bloques de memoria tal es el caso de lenguaje C y C++

```c++
int a=5;
cout<<a;//Muestra el valor en memoria
cout<<&a;//Muestra la direccion en memoria
```

Un puntero es una variable que almacena una direccion en memoria

```c++
int a = 5;
int * aPointer;

aPointer = &a;//Asignamos la direccion de "a"
*aPointer = 10;//Asignamos un nuevo valor

cout<<a; //Imprime "10"
```

## Referencias

Es una variable que apunta hacia otra variable, por lo que si la primera cambia la segunda tambien

```c++
int a;
int &aRef;

a = 5;

cout<<"a: "<<a<<"\n";
cout<<"aRef: "<<aRef<<"\n";

aRef = 10;

cout<<"a: "<<a<<"\n";
cout<<"aRef: "<<aRef<<"\n";
```

## Funciones

```c++
#include <iostream>

//Definimos la cabecera de la función
int Potencias(int, int &, int &); 

int main()
{
 int numero,cuadrado,cubo;
 cout<<"Ingresa un número positivo: ";
 cin>>numero;
 Potencias(numero, cuadrado, cubo);
 cout<<"Numero: "<<numero<<"\n";
 cout<<"Cuadrado: "<<cuadrado<<"\n";
 cout<<"Cubo: "<<cubo<<"\n";
}

//Paso por valor: numero
//Paso por referencias: rCuadrado, rCubo
int Potencias(int numero, int &rCuadrado, int &rCubo)
{
 rCuadrado = numero*numero;
 rCubo = numero*numero*numero;
}
```




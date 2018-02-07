# Guía rápida: Lenguaje C

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

Constantes simbólicas

```c++
const int area = base * altura;
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
float e = 3.4*100000000;
double f = 1.7*10^308;
```

```c++
string g = "Hola mundo!";
char h[] = {'H','o','l','a'};
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
#include <iostream>
using namespace std;

int main(void)
{
 char chr;
 cout<<"Teclea un caracter: ";
 cin>>chr;

 string str;
 cout<<"Teclea una cadena: ";
 cin>>str;
 cout<<"\n";

 cout<<"Caracter: "<<chr<<"\n";
 cout<<"Cadena: "<<str<<"\n";
 cout<<"\n";

 cout<<"Cal 1\tCal 2\tCal 3\n";
 cout<<"8.5\t7.2\t10\n";
 cout<<"8.6\t7.6\t9.3\n";
 cout<<"\n";

 cout<<"Beep \a"<<"\n";

 return 0;
}
```

```c++
#include <stdio.h>

int main(void)
{
 char chr;
 printf("Teclee un caracter: ");
 scanf("%c",&chr);

 char str[80];
 printf("Teclee una cadena: ");
 scanf("%s",&str);
 printf("\n");

 printf("Caracter: %c\n",chr);
 printf("Cadena: %s\n",str);
 printf("\n");

 printf("Entero: %d\n",1);
 printf("Flotante: %4.2f\n",3.1416);
 printf("Flotante sin ceros: %g\n",1.25000);
 printf("Flotante con presicion: %4.2f\n",3.1416);

 return 0;
}
```

## Ciclos

```c++
for(int cnt=0; cnt<5; cnt++) 
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

## Decisión

```c++
int a=5,b=10;
if (a > b) 
  cout<<"A es mayor que B\n";
else 
  cout<<"B es mayor que A\n";
```

Condicion ternaria

```c++
int a=5,b=10;
int c = (a > b)? a: b;
```

## Decisión múltiple

```c++
int opc,a=10,b=5;
cout<<"Elija una opcion\n";
cout<<"1) Suma\n";
cout<<"2) Resta\n";
cout<<"3) Multiplicacion\n";
cout<<"4) Division\n";
cout<<"5) Modulo\n";
cout<<"Otro) Salida\n";
cin<<opc;

switch(opc)
{
 case 1:
  cout<<"Suma "<<(a+b);
 break;
 case 2:
  cout<<"Resta "<<(a-b);
 break;
 case 3:
  cout<<"Multiplicacion "<<(a*b);
 break;
 case 4:
  cout<<"Division "<<(a/b);
 break;
 case 5:
  cout<<"Modulo "<<(a%b);
 break;
 default:
  cout<<"Salida";
}
```

## Apuntadores

Solo algunos lenguajes de programación pueden interactuar con los bloques de memoria tal es el caso de lenguaje C y C++

```c++
int a=5;
cout<<a<<"\n"; //Muestra el valor en memoria
cout<<&a<<"\n"; //Muestra la direccion en memoria
```

Un puntero es una variable que almacena una dirección en memoria

```c++
int a = 5;
int * aPointer;

aPointer = &a; //Asignamos la direccion de "a"
*aPointer = 10; //Asignamos un nuevo valor

cout<<a; //Imprime "10"
```

## Referencias

Es una variable que apunta hacia otra variable, por lo que si la primera cambia la segunda también

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

## Operador Modulo

Con la ayuda de este operador obtenemos el residuo de dos numeros

```c++
#include<iostream>
using namespace std;

int main(void)
{
 int i,c[] = {5,6,7,8,9,10};
 cout<<"Residuo de m=5 c={5,6,7,8,9,10}\n";
 for(i=0;i<6;i++) cout<<c[i]%5<<" ";
 cout<<"\n";
 return 0;
}
```

## Operadores de bits

```c++
#include<stdio.h>
using namespace std;

int main(void)
{
 int i,j;

 //Desplazamiento a la izq
 i = 2  ;  // 000010 = 2 (Dec)
 i = i<<2; // 001000 = 8 (Dec) 
 printf("4 con desplazamiento de 2 bits izq = %d\n\n",i);

 //Desplazamiento a la der
 i = 8;    // 001000 = 8 (Dec)
 i = i>>1; // 000100 = 4 (Dec)
 printf("8 con desplazamiento de 1 bit der = %d\n\n",i);

 //Operador & (AND)
 i = 5;   // 0101 = 5 (Dec)
 j = 3;   // 0011 = 3 (Dec)
 //i & j  == 0001 = 1 (Dec)
 printf("5 AND 3 = %d\n\n",i&j);

 //Operador | (OR)
 i = 5;   // 0101 = 5 (Dec)
 j = 3;   // 0011 = 3 (Dec)
 //i | j  == 0111 = 7 (Dec)
 printf("5 AND 3 = %d\n\n",i|j);

 //Operador ^ (XOR)
 i = 5;   // 0101 = 5 (Dec)
 j = 3;   // 0011 = 3 (Dec)
 //i ^ j  == 0110 = 6 (Dec)
 printf("5 XOR 3 = %d\n\n",i^j);

 return 0;
}
```

## Funciones

```c++
#include <iostream>

//Definimos la cabecera de la función
int Potencias(int, int &, int &); 

int main(void)
{
 int numero,cuadrado,cubo;

 cout<<"Ingresa un número positivo: ";
 cin>>numero;

 Potencias(numero, cuadrado, cubo);

 cout<<"Numero: "<<numero<<"\n";
 cout<<"Cuadrado: "<<cuadrado<<"\n";
 cout<<"Cubo: "<<cubo<<"\n";

 return 0;
}

//Paso por valor: numero
//Paso por referencias: rCuadrado, rCubo
int Potencias(int numero, int &rCuadrado, int &rCubo)
{
 rCuadrado = numero*numero;
 rCubo = numero*numero*numero;
}
```

## Clases

```c++
#include <iostream>

class Estudiante
{
 public:
  Estudiante(); //Constructor
  ~Estudiante(); //Destructor
 private:
  int vCod; //Código del estudiante
};

//Definimos al constructor
Estudiante::Estudiante()
{
 cout<<"LLamando al constructor.\n";
 vCod = 108;
}

//Definimos el destructor
Estudiante::~Estudiante()
{
 cout<<"LLamando al destructor.\n";
}

int main(void)
{
 cout<<"Estudiante Alvaro...\n";
 Estudiante Alvaro;

 cout<<"Estudiante *pSid = new Estudiante...\n";
 Estudiante *pSid = new Estudiante();

 cout<<"delete pSid...\n";
 delete pSid;

 cout<<"Terminando la demostración...\n";

 return 0;
}
```



# Guia rapida: Lenguaje C

## Cuerpo del programa

```c
#include <stdio.h>

int main(void)
{

 return 0;
}
```

## Entrada/Salida

```c
char v;
scanf("%c",&v);

printf("Tecle algo");
```

## Ciclos

Ciclo for

```c
for(int c=0; c<6; c++) 
  printf("%d\n",c);
```

## Desiciones

```c
int a=5,b=10;
if (a > b) 
  printf("A es mayor que B");
else 
  printf("B es mayor que A");
```

## Desiciones multiples

```c
int Opc,a=10,b=5;
printf("Elija una opcion\n");
printf("1) Suma\n");
printf("2) Resta\n");
printf("3) Multiplicacion\n");
printf("4) Division\n");
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
 default:printf("Salida\n");
}
```





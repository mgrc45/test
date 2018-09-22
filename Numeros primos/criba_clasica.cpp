//Criba de eratostenes
//Este codigo crea un arreglo de números primos, marcando con 1 los números no primos

#include<iostream>
#include<cmath> 

using namespace std;
 
void criba(int n)
{
 int p,i,i2;
 bool primos[n+1] = {1,1};
 
 //Actualiza todos los multiplos
 for (p=2; p<=n; p++)
   if (primos[p] == false) {
     i2=(p==2)?2:2*p;
     for (i=p*p; i<=n; i+=i2) primos[i] = true;
   }
 
 //Imprime los numeros primos
 for (p=0; p<=n; p++)
   if (primos[p] == false) cout<<p<<" ";
} 

int main()
{
  int n = 100;
  criba(n);
  return 0;
}

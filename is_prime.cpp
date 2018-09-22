// Este codigo valida si un número es primo con la funcion "is_prime"

#include<iostream>
#include<cmath>

using namespace std;

int is_prime(int n)
{
 if (n<2) return false;
 if (n==2) return true;
 
 //Valido pares
 //if (n%2==0) return false;
 if (n&1==0) return false;
 
 int r = sqrt(n);
 for (int i=3; i <= r; i+=2)
  if (n%i==0) return false;
 return true;
}

int main ()
{
 for (int cnt = 2; cnt<100; cnt++)
   if (is_prime(cnt)) cout<<cnt<<endl;
}

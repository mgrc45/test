//Factorización de números primos usando la Criba

#include<iostream>
#include<cmath> 

using namespace std;
 
void criba(int n, bool fact)
{
 int p,i,i2;
 int primos[n+1] = {0};
 
 //Actualiza todos los multiplos
 for (p=2; p<=n; p++)
   if (primos[p] == 0) {
     i2=(p==2)?2:2*p;
     for (i=p*p; i<=n; i+=i2) primos[i] = p;
   }
 
 if (fact==1)
 {//Factoriza "n"
   while(primos[n]>0) {
     cout<<n<<" "<<primos[n]<<endl;
     n=n/primos[n];
   }
   cout<<n<<" "<<1<<endl;
 }
 else
 {//Imprime los numeros primos
   for (p=2; p<=n; p++)
     if (primos[p] == 0) cout<<p<<" ";
 }
} 

int main()
{
  int n = 12;
  criba(n,1);
  return 0;
}

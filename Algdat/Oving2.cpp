#include <stdio.h>
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

double Kall(double x, double n);
double Kall2(double x, int n);
double pow(double x, double n);

int main()
{
  double x=1.001, n=5000;
  clock_t start, slutt;
  double tid1, tid2;

  start = clock();
  double tall = Kall(x, n);
  slutt = clock();
  tid1 =((double) (slutt - start))/CLOCKS_PER_SEC;

  start = clock();
  double tall2 = Kall2(x, n);
  slutt = clock();
  tid2 = ((double) (slutt - start))/CLOCKS_PER_SEC;

  double tall3 = pow(x, n);

  cout << "Kall1: "<< tall << ", tid: " << tid1 <<  "\nTall2: " << tall2 << ", tid: " << tid2 << "\nTall3: " << tall3  << "\n" <<  endl;
  return 0;
}

double Kall(double x, double n)
{
  if(n==0){
    return 1;
  }
  else{
    return x*Kall(x, (n-1));
  }      
}

double Kall2(double x, int n)
{
  if(n==0){
    return 1;
  }
  else if(n % 2 == 0){
    return Kall2((x*x), (n/2));
  }
  else{
    return x*Kall2((x*x), ((n-1)/2));
  }
}







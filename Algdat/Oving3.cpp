#include <stdio.h>
#include <iostream>
#include <stdlib.h>

class Tabell
{
  int lengde;
  int tabell[lengde];
  public:
  Tabell(int);
  void lagTabell(){
    for(int i = 0; i<lengde; i++){
      tabell[i]=rand();
    }
  }
};

Tabell::Tabell(int lengde){
  lengde = lengde;
}


int main()
{
  int lengde = 10;
  Tabell tabellen(lengde);
  tabellen.lagTabell();
  
}
/*

void shellsort(int n, int t[n])
{
  int s = n/2;
  while(s>0){
    for(int i = s; i < n; i++){
      int j = i;
      int flytt = t[i];
      while(j>=s && flytt<t[j-s]){
	t[j]=t[j-s];
	j -= s;
      }
      t[j] = flytt;
    }
    s=(s==2)?1:s/2.2;
  }
}
*/   







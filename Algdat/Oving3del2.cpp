#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Tabell
{
  int lengde;
  int *tabell;
  public:
  Tabell(int);
  void lagTabell(){
    tabell = (int *)malloc(lengde*sizeof(int));
    for(int i = 0; i<lengde; i++){
      tabell[i] = rand() % 10 + 1;
    }
  }

  void skrivUt(){
    for(int j = 0; j<lengde; j++){
      cout << tabell[j] << endl;
    }
  } 
  void shellsort(double d)
  {
    int n = lengde;
    int s = n/2;
    while(s>0){
      for(int i = s; i < n; i++){
	int j = i;
	int flytt = tabell[i];
	while(j>=s && flytt<tabell[j-s]){
	  tabell[j]=tabell[j-s];
	  j -= s;
	}
	tabell[j] = flytt;
      }
      s=(s>1 && s<d) ? 1 : s/d;
    }
  }

  int getTall(int i){
    return tabell[i];
  }
};

Tabell::Tabell(int lengden){
  lengde = lengden;
}


int main()
{
  srand(time(NULL));
  double delingstall;
  double tid;
  for(int i = 100000; i<1500000; i+=100000){
    int lengde =i;
    Tabell tabellen(lengde);
    clock_t start, slutt;
    tabellen.lagTabell();
    start = clock();
    tabellen.shellsort(12.2);
    slutt = clock();
    tid = ((double) (slutt - start))/CLOCKS_PER_SEC;
    cout << "Tiden med datamengden " << i << ": " << tid << endl;
  
  for(int j = 0; j<lengde-2; j++){
    int en = tabellen.getTall(j+1);
    int to = tabellen.getTall(j);
    if(!(en>=to)){
      cout << "Tabellen er ikke riktig sortert! :O" << endl;
    }
  }
  }
  return 0;
}






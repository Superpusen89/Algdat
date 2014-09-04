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
  double lavesteTid = 10;
  double delingstall;
  double tid;
  int lengde =100000;
  Tabell tabellen(lengde);
  clock_t start, slutt;
  tabellen.lagTabell();
  // tabellen.skrivUt();
  for(double i = 2; i<20; i+=0.1){
  start = clock();
  tabellen.shellsort(i);
  slutt = clock();
  tid = ((double) (slutt - start))/CLOCKS_PER_SEC;
  if(tid<lavesteTid){
    lavesteTid = tid;
    delingstall = i;
  }
  // cout << "Tiden: " << tid  << "  Delingstall: " << i <<  endl;
  } 
  cout << "Laveste tid: " << lavesteTid << "\nDelingstall: " << delingstall << endl;
  // tabellen.skrivUt();
  for(int i = 0; i<lengde-2; i++){
    int en = tabellen.getTall(i+1);
    int to = tabellen.getTall(i);
    if(!(en>=to)){
      cout << "Tabellen er ikke riktig sortert! :O" << endl;
    }
  }
  return 0;
}






#include <iostream>
#include <ctime>
using namespace std;
int main()
{
  srand(time(NULL));
  
  int HHp,HHk, MMp,MMk,nr;
 
  scanf("%d:%d",&HHp,&MMp);
  scanf("%d:%d",&HHk,&MMk);
 
  cin>>nr;
 
  int poczatek = HHp*60+MMp;
  int koniec = HHk*60+MMk;
  int tab[6];
 
  for (int i=0;i<6;i++) {
      tab[i]=0;
    }
 
  int los;
  
  for(int i=0; i<50000; i++){
      los=(rand()%(koniec-poczatek))+poczatek;
      tab[Grazyna(los/60,los%60)]++;
    }
  
  float wynik=(float)tab[nr]/50000;

 
  printf("%1.2f",wynik);

  
  return 0;
}
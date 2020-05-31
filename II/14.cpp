#include <iostream>
#include <math.h>

using namespace std;


double objetosc(double wysokosc){
  double suma=0;
  double postep=0;
  while(wysokosc>postep){
      suma+=(pow(butelka(postep),2)+pow(butelka(postep+0.01),2))/2*0.001;
      postep+=0.001;
    }
  return  suma*M_PI;
}






int main()
{


  int x,y,z,n;
  double wypelnienie,miejsce;

  cin>>x>>y>>z;
  cin>>wypelnienie;
  cin>>n;

  double butelki[n];

  for(int i=0; i<n; i++){
      cin>>butelki[i];
    }


  miejsce=(x*y*z)*(1-wypelnienie);
 int i=0;
  for(; i<n; i++){
      if(miejsce<0){
          cout<<i;
          break;
        }
      miejsce-=objetosc(butelki[i]);
    }
  if(i==n){
      cout<<"NIE";
    }


  return 0;
}
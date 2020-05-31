#include <iostream>

using namespace std;


int haszuj(int tab[],int size){  
  int h=0;
  for(int i=0; i<size;i++){
      h+=tab[i];
    }
  return h;
}


int main()
{
  int dlugosc_ciagu,dlugosc_wzorca;
  cin>>dlugosc_ciagu;
  int ciag[dlugosc_ciagu];

  for(int i=0; i<dlugosc_ciagu; i++){
      cin>>ciag[i];
    }

  cin>>dlugosc_wzorca;

  int wzorzec[dlugosc_wzorca];
  for(int i=0; i<dlugosc_wzorca; i++){
      cin>>wzorzec[i];
    }
  

  int sum=0,licznik=0;
  int tabpom[dlugosc_wzorca];
  int sumy[2];


  bool esc=true;  //sprawdza czy wzorzec odpowiada ciagu
  int haszwzorca = haszuj(wzorzec,dlugosc_wzorca);
  for(int i=0; i<dlugosc_ciagu-dlugosc_wzorca+1; i++){  //glowna petla
      for(int j=0; j<dlugosc_wzorca; j++){              //zapamietuje sekwecje znakow dlugosci wzorca
          tabpom[j]=ciag[i+j];
        }
      if(haszuj(tabpom,dlugosc_wzorca)==haszwzorca){    //jesli hasz wzorca pasuje do haszu podciagu 
          esc=true;
          for(int j=0; j<dlugosc_wzorca; j++){          //sprawdza czy podciag jest rowny wzorcowi
              if(tabpom[j]!=wzorzec[j]){
                  esc=false;                            //jesli nie ecs==fales aby dalej nie wchodzic 
                  break;
                }
            }

          if(esc){                                      //jesli wzorzec jest odpowiedni  
              sumy[licznik]=i;                          // zapamietuje odleglosc wzorca
              licznik++;                                //inkremetacja aby sprawdzic tylko dwa pierwsze powturzenia
              i+=dlugosc_wzorca;                        //przeskakuje o dlugosc wzorca
              i--;                                      //zeby nie przeskoczylo za daleko 
            }


        }
      if(licznik==2){                                  //jesli znalazlo dwa pierwsze wystapienia wychodzi z petli 
          break;
        }
    }

  int a,b,c;              //wartosci pomocnicze
  a=sumy[0];              //miejsce pierwszego wzorca
  b=sumy[1];              //miejsce drugiego wzorca
  c=a;
  while(b<dlugosc_ciagu){      //chodzi do ostatniego wystapienia ciagu
     c=a;
     a=b;   
     b=a+c;                   //zapamietuje sume wystapienie dwuch ostatnich wystapien
    }

  cout<<b-dlugosc_ciagu;      //suma ostatnich wystapien - dlugosc ciagu


  return 0;
}
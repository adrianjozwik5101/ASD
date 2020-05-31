#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Element
{
    int klucz;
    string napis;
    Element *ojciec, *lewy, *prawy;
    Element(){}
    Element(int k, string n){
        klucz=k;
        napis=n;
        lewy=prawy=NULL;
    }
};


Element *korzen = NULL;


void wstaw(int k, string s)
{

  Element *w = new Element(k,s); // towrzy wezel do wstawienia


  Element * p = korzen;

  if(p==NULL)           //jesli drzewo puste to wstawia do korzenia
    korzen = w;
  else
    while(true){        //zdiała do poki nie wstawi na odpowiednie miejsce
      if(k < p->klucz)          //jesli klucz nowego wezla jast mnjejszy, to schodzimy w lewo
      {
        if(p->lewy!=NULL)       //jesli lewy syn istneje to przechodzimy do niefo
            p=p->lewy;
        else {                  //jesli nie istnieje to
          p->lewy = w;          //przypisujemy nowy wezel w jego miejsce
          break;                //konczymy dzialenie petli
        }
      }
      else                      //to samo tylko w prawa strone
      {
        if(p->prawy!=NULL)
            p=p->prawy;
        else{
          p->prawy = w;
          break;
        }
      }
    }

  w->ojciec  = p;           //do dodanego wezla dopisujemy wskaznik na jego ojca
}




list<Element*> sciezka;     //zapamietuje sciezke do danego wezla
Element * szukaj(int k)
{
  Element *p=korzen;
  sciezka.push_back(p);     //zaczynamy od korzenia
  while(p!=NULL && p->klucz != k){   //dopuki element istnieje i nie jest rowny poszukiwanemu
    if(k<p->klucz)          //jesli poszukiwany jest mniejszy
        p=p->lewy;          //idz w lewo
    else                    //jesli wiekszy
        p=p->prawy;         //idz w prawo


    sciezka.push_back(p);   //zapamietuje elementy po ktorych przechodzi
  }
  if(p==NULL)               //jesli nie znalazlo poszukiwanego elementu
      sciezka.clear();      //wyczysc sciezke

  return p;                 //zwraca znaleziony element, lub NULL jesli nie znaleziono
}




Element* min(Element *k){
    if(k)
        while (k->lewy!=NULL){  //idzie w lewo dopuki cos jest,  skrajenie lewy element jest najmniejszy
            k=k->lewy;
        }
    return k;
}

Element* nastepnik(Element *p){

    if(p!=NULL){            //jesli prawy istnieje, to nastepnikiem jest min od prawego
        if(p->prawy!=NULL) return min(p->prawy);    //, to nastepnikiem jest minimum od prawego
        else{                           //jesli nie istnieje
            while (p->ojciec->prawy==p) { //idziemy dopoki jestsmy prawym synem
                p=p->ojciec;
            }
        }
    }
    return p;  //zwracamy ojca lewego syna
}


void usun(int k){
    Element *X=korzen;
    while(X && X->klucz!=k){        //szukamy wezłą do usuniecia po kluczy, tak jak funkcja szukaj
        if(k<X->klucz)
            X=X->lewy;
        else
            X=X->prawy;
    }                               //


    Element *Y, *Z;

    if(X!=NULL){        //jesli dany wezel istnieje
        if(X->lewy==NULL || X->prawy==NULL)        //jesli nie posiada lub posiada jednego syna
            Y=X;                                   //zapamietujemy ten wezel
        else
            Y=nastepnik(X);                        //jesli pososiada obu zapamietujemy jego nastepnika

        if(Y->lewy!=NULL)                           //zapamietujemy lewego jesli istnieje
            Z=Y->lewy;
        else                                        //jesli nie to prawego lub NULL
            Z=Y->prawy;

        if(Z!=NULL) Z->ojciec = Y->ojciec;          //jesli syn Y istnieje to zastepujemy nim Y(ojca)


        if(Y->ojciec==NULL)                              //jesli nieistnieje ojciec Y
            korzen =Z;                                   // to korzen =Z
        else if(Y==Y->ojciec->lewy)                     //jesli istnieje to sprawdzamy czy Y jest lewym synem
            Y->ojciec->lewy =Z;                         //jesli tak to zastepujemy do Z
        else Y->ojciec->prawy=Z;                        //jesli nie to prawego syna zastepujemy Z

        if(Y!=X){                                       //w miejsce usuwanego zapisujemy nowy
            X->klucz=Y->klucz;
            X->napis=Y->napis;
        }
    delete Y;
    }
}



int main()
{

    int n,m,k;
     string s;
     cin>>n>>m;

     int klucze[m];



      for(int i=0; i<n;i++){
          cin>>k>>s;
          wstaw(k,s);
      }

      for(int i=0; i<m;i++)
          cin>>klucze[i];



      for(int i=0; i<m; i++){
          if(szukaj(klucze[i])==NULL){  //szukamy danego wezla i zapamietujemy sciezke do niego
                  cout<<"NIE\n";        //jesli nie istnieje
                  continue;
          }
          for(list<Element*>::iterator it= (--sciezka.end()); it!=(--sciezka.begin()); it--){   //przechodzimy po sciezce do szuanego wezla
              cout<<(*it)->napis;       //wypisujemy elementy
              usun((*it)->klucz);       //usuwamy uzyte wezly
          }
          sciezka.clear();              //czyscimy liste sciezek do nastepnych wyszukiwan
        cout<<endl;

      }

     // cout<<"Hello word!";
    return 0;
}
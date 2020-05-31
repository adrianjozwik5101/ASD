#include <iostream>
#include <list>
using namespace std;


struct Element{
  Element *dzieci[26];     //26 bo tyle liter alfabetu
  bool slowo;              //czy w danym miejscu się kończy jakieś słowo
  Element(){
    for(int i=0; i<26; i++){
        dzieci[i]=NULL;
      }
    slowo=false;
  }
};



void wstaw(string klucz, Element *root){
  Element *r=root;      
  for(int i=0; i<klucz.length(); i++){    //idzie po kazdym znaku klucza
      if(!r->dzieci[(klucz[i]-'a')])      //sprawdza czy istnieje 'Element' w miejscu danej litery ('a'-'a'=0 'b'-'a'-1 odpowiedni index tablicy
        r->dzieci[(klucz[i]-'a')]= new Element();     //jesli nie istnieje tworzy nowy element, oznacza to jakąśe litere 
      r=r->dzieci[(klucz[i]-'a')];          //przechodzi do tej 'litery'
    }
  r->slowo=true;          //po przejsciu ustawia ze w danym wezle konczy sie slowo
}



void pisz(Element *root, list<char> *listaznakow){

  Element *r =root;
                                          //zaczyna od przekazanego wezla
  if(r->slowo){                           //jesli r->slowo== true oznacza ze tu konczy sie jakies slowo, czyli je wypisuje
      for(auto it = listaznakow->begin(); it!=listaznakow->end(); it++){
        cout<<*it;
        }
      cout<<endl;
    }

  for(int i=0; i<26; i++){              //przechodzi po alfabecie
      if(r->dzieci[i]){                 //jesli ktoras litera istnieje
          listaznakow->push_back((char)i+'a');    //dodaje ja do listy znakow
          pisz(r->dzieci[i],listaznakow);         //rekurecyjnie wywoluje funkcje, z przekazaniem wezla z tablicy w ktorym istnieje litera
        }
    }

  listaznakow->pop_back();            //przy wyjsciu z rekurecji o poziom usuwa element dodany na tym poziomie  
}



bool szukaj(string klucz, Element* root, list<char> *znaki){
  Element * r= root;

  for(int i=0; i< klucz.length(); i++){   //przechodzi po kluczu 
      if(r->dzieci[(klucz[i]-'a')]){      //jesli istnieje dana litera w wezle
        r=r->dzieci[(klucz[i]-'a')];      //to przechodzimy dalej
        znaki->push_back(klucz[i]);       // i zapamietujemy ta litere
        }
      else                                //jesli nie ma litery
        return false;                     // zwraacamy false co oznacza ze nie ma danego klucza
    }
        
                                          //jak znalzalo caly klucz
  pisz(r,znaki);                          // wypisuje wszystki mozliwe wyrazy ktorych poczatkiem jest przekazany klucz
                                          //przekazujemy wskaznik do wezla na ktorym sie zakanczyla petla
                                          // i liste znakow zapisanych przechodzac po kluczu(klucz)
  return true;    

}



int main()
{


    Element *root = new Element;

    list<char> *znaki = new list<char>;       //przechowuje kolejne litery wyrazwo


    int n;
    cin>>n;

    char Z;
    string tytul;

    for(int i=0; i<n; i++){
        cin>>Z;
        if(Z=='A'){
            cin>>tytul;
            wstaw(tytul,root);
          }
        else {
            cin>>tytul;
            znaki->clear();     //czysci liste przed kolejnym wywoaleniem szukania
            if(!szukaj(tytul,root,znaki))       //jesli znajdzie wyraz wypisuje je
              cout<<"-\n";                      //gdy nie znajdzie wypisze '-'
          }
      }

    return 0;
}
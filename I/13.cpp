#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct produkt{
    unsigned int ilosc;
    unsigned int cena;
};

struct klient
{
    unsigned int id;
    unsigned int kwota;
    unsigned int ktory_dodany;
    bool operator < (const klient &x)const
          {
            return (kwota!=x.kwota)?kwota<x.kwota:ktory_dodany>x.ktory_dodany;
          }
};


klient *klienci;
unsigned int liczba_klientow = 0;
unsigned int ile_dodanych=0;
unsigned int k;
klient temp;

unsigned int kolejnosc_dodawania=0;


bool empty(){
    if(ile_dodanych==0)
        return true;
    else
        return false;
}


void push(klient dodaj){
    dodaj.ktory_dodany=kolejnosc_dodawania++;   //do zachowania stabilnosci
    klienci[ile_dodanych]=dodaj;
    k=ile_dodanych++;
    while(k>0&&klienci[(k-1)/2]<klienci[k]){
        swap(klienci[((k-1)/2)],klienci[k]);
        k=((k-1)/2);
    }
}

void pop(){
    klienci[0]=klienci[ile_dodanych-1];
    ile_dodanych--;
    k=0;
    unsigned int j=((2*k)+1);
    while(j<ile_dodanych){
        if(j<ile_dodanych && klienci[j]<klienci[j+1]) j++;
        if(klienci[j]< klienci[k]) return;
        swap(klienci[k],klienci[j]);
        k=j;
        j= (2*k)+1;
    }
}

int main()
{

//WCZYTYWANIE
    unsigned int liczba_produktow;
    cin>>liczba_produktow>>liczba_klientow;
    unsigned int n=liczba_klientow;
    klienci= new klient[liczba_klientow];
    produkt produkty[liczba_produktow];
    list<unsigned int> chce_kupic[liczba_klientow];
    list<unsigned int> kupil[liczba_klientow];
    klient klient_pomocniczy;
    unsigned int ile_chce_kupic;
    unsigned int pom;

    for(unsigned int i=0 ; i<liczba_produktow; ++i)
        cin>>produkty[i].ilosc>>produkty[i].cena;

    for(unsigned int i=0; i<n; ++i){
        klient_pomocniczy.id=i;
        cin>>klient_pomocniczy.kwota;
        push(klient_pomocniczy);
        cin>>ile_chce_kupic;
        for(unsigned int j=0; j < ile_chce_kupic; j++){
            cin>>pom;
            chce_kupic[i].push_back(pom);
        }
    }

klient k_pom;

//SYMULOWANIE KOLEJKI
while(!empty()){
    k_pom = klienci[0];
    pop();
    while(!chce_kupic[k_pom.id].empty()){
        if(produkty[chce_kupic[k_pom.id].front()].ilosc>0&&produkty[chce_kupic[k_pom.id].front()].cena<=k_pom.kwota){   //sprawdza czy sa dostepne produkty ktore klijent chce kupic (front - pierwszy z listy) i czy ma wystarcajaca ilosc pieniedzy
            kupil[k_pom.id].push_back(chce_kupic[k_pom.id].front());                //zapisuje na liste co kupil
            k_pom.kwota-=produkty[chce_kupic[k_pom.id].front()].cena;               //odejmuje z portfela cene zakupionego produktu
            produkty[chce_kupic[k_pom.id].front()].ilosc--;                         //zdejmuje jedna sztuke z polki
            chce_kupic[k_pom.id].pop_front();                                       //usuwam z listy zakupow
            break;                                                                  //jesli kupil to wychodze z petli chodzacej po liscie zakupow
        }
        else{
            chce_kupic[k_pom.id].pop_front();                                       //jesli nie moze kupic(brak w sklepie lub zamalo pieniedzy) to usuwam z listy zakupow
        }
    }
    if(!chce_kupic[k_pom.id].empty()&&k_pom.kwota>0)                                //jesli lista zakopow pusta lub nie nie pieniedzy to nie wchodzi do kolejki
        push(k_pom);
}

//WYPISANIE WYNIKOW
    for(unsigned int i=0; i<liczba_klientow; i++){
        if(kupil[i].empty()){
            cout<<"-\n";
            continue;
        }
        for(list<unsigned int>::iterator it = kupil[i].begin(); it != kupil[i].end(); it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
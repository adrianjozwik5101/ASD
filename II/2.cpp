#include <iostream>
#include <vector>

using namespace std;

const int MAXINT = 1147483647;

struct krawedz
{
    int poczatek, koniec;
    float waga;
};

float *d;

bool Bellman_Ford(int v, int ile_w, int ile_krawedzi, vector<krawedz> krawedzie){
    for(int i=0; i<ile_w; i++){
        d[i]=MAXINT;            //ustawiamy wszystkie odleglosci na nieskonczonosc
    }
    d[v]=0;                     //odleglosc wierzcholka poczatkowego na 0

    for(int i=0 ; i<=ile_w; i++){
        for(vector<krawedz>::iterator it= krawedzie.begin(); it!=krawedzie.end(); it++){        //przechodzimy po wszystkich krawedzich
            if(d[it->poczatek]!=MAXINT && d[it->koniec]>d[it->poczatek]+it->waga){              //jesli do wierzcholka poczatkowego jest już jakas droga i odleglosc do jego sasiada tą drogą będzie mniejsza
                d[it->koniec]=d[it->poczatek]+it->waga;                                         //to w wierzcholku na koncu krawedzi zmieniamy odleglosc (odleglosc wierzcholka i poczatku krawdzi + waga krawdzi)


                if(i==ile_w)                                                                    //jesli przy ostatnim obrocie glownej petli odnajdzie droge krotsz od tych do tej pory zapisanych to oznacza ze wykryto cykl ujemy(i==liczbie_wierzcholkow, wykonuje sie raz wiecej niz jest wierzcholkow)
                    return false;                                                               // zwroc false

            }

        }
    }

    return true; //nie znaleziono cyklu ujemnego zwroc true
}


int main()
{

    int ile_k, ile_w,a,b;
    float droga,czas,zarobek,suma=0;
    vector<krawedz> krawedzie;      //tworze wektory krawedzi
    vector<krawedz> krawedzie2;


    cin>>ile_w>>ile_k;
    krawedzie.resize(ile_k*2);
    krawedzie2.resize(ile_k*2);

    d= new float[ile_w];

    for(int i=0; i<ile_k*2; i++){
        cin>>a>>b;
        cin>>droga>>czas>>zarobek;
        krawedzie[i].poczatek=a;                                //w pierwszym normalny graf 
        krawedzie[i].koniec=b;
        krawedzie[i].waga=droga*49+czas*18-zarobek*100;

        krawedzie2[i].poczatek=b;
        krawedzie2[i].koniec=a;
        krawedzie2[i].waga=droga*49+czas*18-zarobek*100;        //w drugim odwrotny ktory umozliwia wyznaczenie dlugosci wszystkich drug do jednego punktu 

        cin>>droga>>czas>>zarobek;
        krawedzie[++i].poczatek=b;
        krawedzie[i].koniec=a;
        krawedzie[i].waga=droga*49+czas*18-zarobek*100;

        krawedzie2[i].poczatek=a;
        krawedzie2[i].koniec=b;
        krawedzie2[i].waga=droga*49+czas*18-zarobek*100;
    }


    int ile_s;
    cin>>ile_s;
    int sklepy[ile_s];

    for(int i=0; i<ile_s; i++){
        cin>>sklepy[i];
    }

    if(Bellman_Ford(0,ile_w, ile_k,krawedzie)){     //jezeli nie wykryto cyklu ulemnego 

        for(int i=0; i<ile_s; ++i)                  //sumuje odleglosci z punktu 0 do sklepow
                suma+=d[sklepy[i]];

        Bellman_Ford(0,ile_w,ile_k,krawedzie2);     //wywoluje dla odwrotnego grafu 
            for(int i=0;i<ile_s; ++i){
                suma+=d[sklepy[i]];                 //sumuje dlugosci ze sklepow do punktu 0    
            }

            suma=suma/(ile_s*100);                  //wyliczam srednia (liczba sklepow *100, bo przy wczytywaniu przyjalem np. 18 zamiast 0.18
            printf("%.3f", suma);                   //wypisuje do 3 miejsc po przecinuk 

    }
    else
        cout<<"DO DOMU!";                           //jezeli wykryto cykl ujemny 


    return 0;
}
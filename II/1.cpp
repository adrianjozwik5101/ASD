#include <iostream>
#include <vector>

using namespace std;

const int MAXINT = 1147483647;

struct krawedz{
    int nastepny;
    float wartosc;
};

float *odleglosci;  //tablica w ktorej przchowuje odleglosci

bool *odwiedzony;   //tablica przechowuje informacje ktory wierzcholek zostal odwiedzony

void dijkstra(int v, int &l_wierzcholkow, vector<krawedz> *sasiedzi){   //algorytm dijkstra pobiera(v- od ktorego wierzcholka sprawdzac, ile jest wierzcholkow w grafie, listay sasiectwa)
    int i,j;
    for(i =0 ; i<l_wierzcholkow; ++i){      //ustawia wszystkie odleglosi na nieskonczonosc i wszystkie wieszcholki nie odwiedzone
        odwiedzony[i]=false;
        odleglosci[i]=MAXINT;
    }

    odleglosci[v]=0;  //uswawia odleglosc 0 dla wierzcholka od ktorego szukamy
    int najbli=-1;
    int najblizej=MAXINT;

    for(i =0 ; i<l_wierzcholkow ; ++i){
        najblizej=MAXINT;
        if(i==0) najbli=v;  //przy pierwszym obrocie zawsze v bo jeszcze nie odwiedzony
        else
            for(j=0; j<l_wierzcholkow; ++j){
                if(!odwiedzony[j] && odleglosci[j]<najblizej){
                    najblizej=odleglosci[j];
                    najbli=j;               //zapamietuje ktory nie odwiedzonywiechcholek jest najblizej v i zapamietuje jego odleglosc
                }
            }

        odwiedzony[najbli]=true;        //ustawia dany wierzcholek na odwiedzony

        for(vector<krawedz>::iterator it= sasiedzi[najbli].begin(); it!= sasiedzi[najbli].end(); ++it){     //przechodzi po sasiadach danego wierzcholka
            if(odleglosci[it->nastepny]>odleglosci[najbli]+it->wartosc){            //sprawdza czy tędy nie jest bliżej
                odleglosci[it->nastepny]=odleglosci[najbli]+it->wartosc;            //jesli tak to przypisuje mu ta odleglosc(dlugosc do odwiedzonego wierzcholka + dlogosc krawedzi do sasiada)
            }
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    int l_wierzcholkow,l_krawedzi,l_sklepow;
    int a,b,i;
    float suma;
    float droga,czas;
    krawedz pom_k;
    cin>>l_wierzcholkow>>l_krawedzi;
    vector<krawedz> *sasiedzi;      //tworze dwa grafy
    vector<krawedz> *sasiedzi2;
    sasiedzi = new vector<krawedz>[l_wierzcholkow];
    sasiedzi2 = new vector<krawedz>[l_wierzcholkow];

    odleglosci = new float[l_wierzcholkow]; //inicjuje tablice z dlugosciami
    odwiedzony = new bool[l_wierzcholkow];

    for(i =0; i<l_krawedzi; ++i){
        cin>>a>>b;
        cin>>droga>>czas;
        pom_k.nastepny=b;
        pom_k.wartosc=droga*49+czas*18;
        sasiedzi[a].push_back(pom_k);   //pierwszy graf normalny

        pom_k.nastepny=a;
        sasiedzi2[b].push_back(pom_k);     //drugi skierowany w odwrotna strone


        cin>>droga>>czas;
        pom_k.nastepny=a;
        pom_k.wartosc=droga*49+czas*18;
        sasiedzi[b].push_back(pom_k);

        pom_k.nastepny=b;
        sasiedzi2[a].push_back(pom_k);
    }

    cin>>l_sklepow;
    int sklepy[l_sklepow];

    dijkstra(0, l_wierzcholkow, sasiedzi);      //przechodze pierwszy graf od wierzcholka 0

    for(i =0; i<l_sklepow; ++i){
        cin>>sklepy[i];
        suma+=odleglosci[sklepy[i]];            //sumuje wszystkie odleglosci od 0 do sklepow
    }

    dijkstra(0,l_wierzcholkow, sasiedzi2);      //przechodze graf odwrotny dzieki czemu mam wyczone odleglosci od wszystkich wierzcholkow do wierzcholka 0


     for(i =0; i<l_sklepow; ++i){
         suma+=odleglosci[sklepy[i]];           //sumuje odleglosci od sklepow do wieszcholka 0
     }

     suma=suma/(l_sklepow*100);                 //sume dziele na liczbe sklepow(wyliczam srednia)
     printf("%.3f", suma);                      //wyswietlam do trzech miejsc po przecinuk

    return 0;
}
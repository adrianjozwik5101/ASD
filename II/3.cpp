#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> korzenie, ran;

int Find(int v){ //zwraca reprezentantat do ktorego jest podpiety v
    if(v==korzenie[v])
        return v;
    return korzenie[v] = Find(korzenie[v]);
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){       //jesli a i b naleza do innych poddrzew to polacz je
        if(ran[a]<ran[b])
            swap(a,b);
        korzenie[b]=a; //przypisuje nastepnika
        if(ran[a]==ran[b])
            ran[a]++;
    }
}

struct krawedz
{
    int u,v,waga;
    bool operator < (krawedz const& k){
        return waga<k.waga;
    }
};




int main()
{


    int V,E;    // V-liczba krawedzi, E-liczba wierzcholkow
    vector<krawedz> krawedzie;
    int wynik=0;
    cin>>V>>E;
    krawedzie.resize(E);
    bool ktore_odwiedzi[V];
    for(int i=0; i<V; i++){
        cin>>ktore_odwiedzi[i];
    }

    int u,v,waga;

    for(int i=0; i<E; i++){
        cin>>u>>v>>waga;
        if(ktore_odwiedzi[v]==1 && ktore_odwiedzi[u]==1){
            krawedzie[i].u=u;
            krawedzie[i].v=v;
            krawedzie[i].waga=waga;

        }

    }

    //algortym Kruskala

    korzenie.resize(V);
    ran.resize(V);

    for(int i=0; i<V; i++){
        korzenie[i]=i;     //ustawia karzdy wierzcholek jako swoj korze, na poczatku sa drzewa jedno elementowe
        ran[i]=-1;         //zapamietuje polaczenia miedzy elementami
    }


    sort(krawedzie.begin(), krawedzie.end()); //sortuje krawedzi wedlug wagi rosnaco


        for(vector<krawedz>::iterator it=krawedzie.begin();it!=krawedzie.end();it++){ //przechodzi po wszystkich krawedziach
            if(Find(it->u)!=Find(it->v)){   //sprawdza czy wierzcholki nie naleza do tego samego drzewaw
                wynik+=it->waga;            //sumuje dlugosc dolaczanych krawedzi
                Union(it->u,it->v);         //laczy wierzcholki na pomoca danej krawedzi
            }
        }




   cout <<wynik;
    return 0;
}
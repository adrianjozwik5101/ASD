#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
unsigned int ile_skrzy;
vector<int> wyniki;

struct Node{
    int numer;
    Node *ojciec;
    vector<int> dzieci;
    bool odwiedzony=false;
    unsigned int liczba_dzieci=0;
};


void preorder(Node *v, int ktore_bez, Node *tab){
    if(ktore_bez>1){
        if(ile_skrzy<=(v->liczba_dzieci)+1){
            wyniki.push_back(v->numer);
            ktore_bez=0;
        }
        else if(ktore_bez>3){
            wyniki.push_back(v->numer);
            ktore_bez=0;
        }

    }
    ktore_bez++;

    for(vector<int>::iterator it=v->dzieci.begin(); it!=v->dzieci.end(); it++)
        preorder(&tab[*it],ktore_bez,tab);
   // cout<<v->numer<<" ";
}


int main()
{

    int ilosc;
    int b,j;


    cin>>ilosc;
    cin>>ile_skrzy;

    Node *tab= new Node[ilosc];



        tab[0].numer=1;
    for(int i=0; i<ilosc-1; i++){
       cin>>b;
       cin>>j;
       tab[j-1].numer=j;
       tab[b-1].dzieci.push_back(j-1);
       tab[b-1].liczba_dzieci++;

    }

    int ktore=4;
    Node korzen = tab[0];


    preorder(&korzen,ktore,tab);
    sort(wyniki.begin(),wyniki.end());
    for(vector<int>::iterator it=wyniki.begin(); it!=wyniki.end(); it++)
        cout<<*it<<" ";


    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int ile=0;
vector<int> tab_kalorie;

bool sortowanie(int a, int b){
    return a>b;
}


void funkcja(int& kalorie, int ktora, int suma){
    for(unsigned int i=ktora; i<tab_kalorie.size(); ++i){
        suma+=tab_kalorie[i];
        if(suma<kalorie){
            funkcja(kalorie,i+1,suma);
        }
        else if(suma==kalorie){
            ile++;
        }
    suma-=tab_kalorie[i];
    }
}



int main()
{
    std::ios_base::sync_with_stdio(0);

    short liczba_testow;
    int liczba_potraw;
    int pozadane;
    int pom;


    cin>>liczba_testow;
    for(short i=0; i<liczba_testow; ++i){
        cin>>liczba_potraw;

        for(int j= 0;j<liczba_potraw; ++j){
            cin>>pom;
            tab_kalorie.push_back(pom);
        }
        cin>>pozadane;
        sort(tab_kalorie.begin(),tab_kalorie.end(),sortowanie);
        funkcja(pozadane, 0, 0);
        cout<<ile<<"\n";
        tab_kalorie.clear();
        ile=0;
    }

    return 0;
}
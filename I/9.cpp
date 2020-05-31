#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    short liczba_zestawy_danych;
    int liczba_programow;
    int pier_min;
    int kolejne_min;
    int suma=0;

    vector <int> poczatki;
    vector <int> konce;
    vector <int>::iterator poczatek;
    vector <int>::iterator koniec;

    cin>>liczba_zestawy_danych;

    for(short i=0;i<liczba_zestawy_danych;i++){
        suma=0;
        poczatki.clear();
        konce.clear();
        cin>>liczba_programow>>pier_min>>kolejne_min;
        poczatki.resize(liczba_programow); //ustawia wielkosc vektora 
        konce.resize(liczba_programow);
        for(vector<int>::iterator it=poczatki.begin(), itt=konce.begin(); it != poczatki.end();++it, ++itt){
            cin>>*it;
            cin>>*itt;
            suma=suma+(*itt-(*it))*kolejne_min+pier_min;            //wyliczam sume pesymistyczna(wszystkie programy na oddzielnych TV)
        }
        sort(poczatki.begin(),poczatki.end());
        sort(konce.begin(),konce.end());
                                                                                                //przechodze po koncach od tylu, aby wybierac najkorzystniejszy program do TV
        for(vector<int>::iterator koniec=konce.end()-2; koniec != konce.begin()-1;--koniec){    //-2 żeby nie sprawdzało dla najwiekszego konca bo i tak nie ma dalej poczatkow, -1 aby działało dla pierwszego elementu (warunek != pierwszyElement)
            if(*koniec<*(poczatki.end()-1)){        //if aby sprawdzało upper_bound nie wyszukauje gdy nie ma nic wiekszego
            poczatek=upper_bound(poczatki.begin(),poczatki.end(),*koniec); //wyszukiwanie binarne
            if(*koniec<*poczatek){                          
                if((*poczatek-*koniec)*kolejne_min<pier_min){
                    suma-=pier_min-((*poczatek-*koniec)*kolejne_min);
                    poczatki.erase(poczatek);           //usuwa uzyty poczatek, aby ponownie nie podlaczyc do tego samego
                }
            }
        }
        }

        cout<<suma<<"\n";
    }
    return 0;
}
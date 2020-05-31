#include <iostream>
#include <vector>
#include <string>

using namespace std;


int haszowanie(string napis){

    int k=0;
    for(int i=0; i<napis.length();i++){
        k+=(int)napis[i];
    }
    return k%10000;
}




int main()
{


    int wielkosc_tab=10000;
    vector<pair<string,string>> tab[wielkosc_tab];

    pair<string,string> para_pom;
    string nazwa;

    bool znalazlo=false;
    int n,hash;
    char Z;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>Z;
        if(Z=='A'){                                     //dodanie elementow
            cin>>para_pom.first>>para_pom.second;
            tab[haszowanie(para_pom.first)].push_back(para_pom);      //wrzucam w miejsce tablicy wyznaczone przez haszowanie
        }
        else{
            cin>>nazwa;                           //pobieram nazwe ktora szukam
            hash=haszowanie(nazwa);               //haszowanie wyznacza miejsce w tablicy
            znalazlo=false;
            if(tab[hash].empty())                 //jesli tablica pod tym indexem jest pusta oznacza ze elementu nie ma
                cout<<"-\n";
            else{
                for(auto it=tab[hash].begin(); it!= tab[hash].end(); it++){       //przeszukuje liste znajdujaca sie pod danym indexem tablicy
                    if(nazwa==it->first){                                         //jesli znaleziona dana nazwe, wypisuje jej lokalizacja
                        cout<<it->second<<endl;
                        znalazlo=true;                                            //oznaczam ze znaleziono
                        break;
                    }
                }
                if(!znalazlo)
                    cout<<"-\n";                                                  //jesli nie znaleziono

            }

        }
    }



    return 0;
}
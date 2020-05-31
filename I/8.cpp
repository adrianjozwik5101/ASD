#include <iostream>
#include <vector>

using namespace std;


struct drzewo
{
    unsigned int wartosc;
    drzewo *l_syn=NULL, *p_syn=NULL;
};

unsigned int licznikkkk=0;
unsigned int dlugosc_lampek;

void przejdz(drzewo *v, vector<unsigned int> &vec)
{
    vector<unsigned int> l,p;
    if(v->l_syn!=NULL){
        przejdz(v->l_syn,l);                    //w lewa galez przekazuje vector l
    }

    if(v->p_syn!=NULL){
        przejdz(v->p_syn,p);                   //w prawa galez przekazuje vector p
    }

    for(vector<unsigned int>::iterator itl=l.begin(); itl!= l.end(); itl++){            //porownuje sumy wszystkie elementy z l ze wszystkimi elemetami z p
        for(vector<unsigned int>::iterator itp=p.begin(); itp!= p.end(); itp++){
            if(((*itl)+(*itp))==dlugosc_lampek) licznikkkk++;
        }
    }

        while(!l.empty()){
            if((l.back())==dlugosc_lampek)      //jesli sciezka w dol == dlugosc to iteruj licznik
                licznikkkk++;
            if((l.back()+v->wartosc)==dlugosc_lampek&& v->wartosc!=0)       //jesli sciezka w dol + wartos w gore == dlugosc to iteruj licznik
                licznikkkk++;
            else if((l.back()+v->wartosc)<dlugosc_lampek)                   //jesli krotrze od lampek to podaj dlugosc scierzki w gore
                vec.push_back(l.back()+v->wartosc);
            l.pop_back();
        }
        while(!p.empty()){                                                  //to samo co wyzej tylko dla lewych galezi
            if((p.back())==dlugosc_lampek)
                licznikkkk++;
            if((p.back()+v->wartosc)==dlugosc_lampek&& v->wartosc!=0)
                licznikkkk++;
            else if((p.back()+v->wartosc)<dlugosc_lampek)
                vec.push_back(p.back()+v->wartosc);
            p.pop_back();
        }
        vec.push_back(v->wartosc);                                          //do vectora dokladam dlugosc galezi z aktualnego wezla

    return;
}


int main()
{
    unsigned int ilosc_testow;
    unsigned int ilosc_galezi;
    drzewo *choinka;
    drzewo *korzen;

    vector<unsigned int> l;

    cin>>ilosc_testow;

    for(unsigned int i=0; i<ilosc_testow; i++){
        cin>>ilosc_galezi>>dlugosc_lampek;
        choinka = new drzewo[ilosc_galezi+1];
        choinka[0].wartosc=0;                   //tworze korzen
        for(unsigned int j=1; j<ilosc_galezi+1; j++){
            cin>>choinka[j].wartosc;               //przypisuje wartosci do kolejnych elementow
            }

        for(unsigned int i =0; i<ilosc_galezi+1;i++){
            if((i*2+1)<ilosc_galezi+1){                 //sprawdza czy jest typle podgalezi
                choinka[i].l_syn=&choinka[i*2+1];       //lewy syn (2*i+1)

            }
            if((i*2+2)<ilosc_galezi+1){
                    choinka[i].p_syn=&choinka[i*2+2];   //prawy syn (2*i+2)
                }
        }

        korzen = &choinka[0];

        przejdz(korzen,l);          //przy pierwszym wywolaniu ten vector l nie potrzebny

        delete []choinka;

        cout<<licznikkkk<<"\n";
        licznikkkk=0;
    }

    return 0;
}
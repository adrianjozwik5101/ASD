#include <iostream>

using namespace std;

class Kubelek
{
    short rozmiar=0;
    double *obecny;         //wskaznik na tablice "kolejnych butelek "
    short index;
    unsigned int ile=6;
 public:
    double **tab = new double*[ile];  //tablica przechowujaca wskazniki na pierwsze elementy skrzynek
    void add(double* nowy){         //przyjmuje wskaznik na pierwszy element skrzynki
        if(rozmiar==ile){           // sprawdza czy nie przekracza rozmiaru tablicy jesli tak to
           ile=ile*2;
           double **tab2 = new double*[ile];        //tworzy nowa dwa razy wieksza
           for(int i=0; i<ile/2; i++){              //przepisuje jej wartosci
               tab2[i]=tab[i];
           }
           delete tab;                               //usuwa stara
           tab=tab2;                                //przypina do starej nazyw
        }
        tab[rozmiar++]=nowy;
    }
    //insertionsort
    void sort(int ost_element){         //ost_element- pod ostatnim elementem jest suma stanów wszystkich butelek
        for(short i=1; i<rozmiar; i++){
            obecny=tab[i];
            index=i;
            while(index>0 && obecny[ost_element]>tab[index-1][ost_element]){  //porównujemy ostatni element bo tam jest ukryta suma
                tab[index]=tab[index-1];
                index--;
            }
            tab[index]=obecny;
        }
    }

    short size(){
        return rozmiar;
    }
};


int main()
{
    ios_base::sync_with_stdio(0);
    int liczba_skrzynek;
    int liczba_butelek;
    int pojemnosc_samolotu;
    int licznik=0;      //licznik do zliczania ilości wypisanych skrzynek

    cin>>liczba_skrzynek>>liczba_butelek>>pojemnosc_samolotu;
    double skrzynki[liczba_skrzynek][liczba_butelek+1];     //+1 bo tam zapisuje sume
    double suma=0;
    Kubelek *posortowane_sumy = new Kubelek[liczba_skrzynek]; //dynamiczna tablica kubełków
    Kubelek kubelek;                                            //kubelek pomocniczy
    for(int i=0;i<liczba_skrzynek; i++){                        //ladowanie danych do tablicy
        for(int j=0; j<liczba_butelek; j++){
            cin>>skrzynki[i][j];
            suma+=skrzynki[i][j];   //zlicznie sumy w skrzynce
        }
        skrzynki[i][liczba_butelek]=suma;      //na ostanim elemencie w i-tym wierszu zapamietuje sume
        suma=0;
    }
    //sortowanie kubelkowe
    for(int i=0; i<liczba_skrzynek; i++){       //przechodzę po nie posortowanej tablicy
        posortowane_sumy[(unsigned int)((liczba_skrzynek-1)*skrzynki[i][liczba_butelek]/liczba_butelek)].add(skrzynki[i]);  //i dodaje wskazniki pierwszych elementow "wiersza" do kubelków w nowej tablicy
    }

    for(int i=liczba_skrzynek-1; i>=0 && licznik!=pojemnosc_samolotu; i--){     //kręci się dopóki ilosci zestawów ktore mieszcza sie w samolocie lub nie nie przejdzie przez ilosc wszystkich skrzynek
        posortowane_sumy[i].sort(liczba_butelek);               //sortuje kubelki metodą zawartą w klasie Kubelek, przekazuje liczbę butelek żeby w sorcie odnosilo sie do ostatniego elementu tablicy czyli sumy
        for(int j=0;j<posortowane_sumy[i].size() && licznik!=pojemnosc_samolotu;j++){   //przechodzi po posortowanych kubelkach jesli kubelek.size()==0 przechodzi do nastepnego, dopuki licznik nie przekroczy pojemnisci samolotu
            for(int k=0; k<liczba_butelek; k++ ){               //przechodzi po kolejnych butelkach w skrzynce
                cout<<*(posortowane_sumy[i].tab[j]+k)<<" ";     //posortowane_sumy[i] idzie po kolejnych kubelkach, tab[j] - po kolejnych elementach/skchynkach w kubelku, +k - kolejne butelki w skrzynce
            }
            licznik++;                                          //zwiekszam licznik po wypisaniu skrzynki
            cout<<"\n";
        }
    }
    return 0;
}
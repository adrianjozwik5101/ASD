#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct samochod //struktura opisujaca liczbe obrotow kola i nazwe samochodu
{
    long int obroty;
    string nazwa;
    bool operator < (const samochod &x)const //operaor porownania wykorzystywan przez funkcje sort
      {
        return (obroty!=x.obroty)?obroty<x.obroty:nazwa<x.nazwa; //porównuje po liczbie obrotów, jesli jes taka sama wtedy po nazwie
      }
};

int main()
{
    ios_base::sync_with_stdio(0); //przyspiesza wczytywanie danych
    unsigned int n,d;
    double p;
    samochod gotowe[4];
    cin>>n;


    for(unsigned int i=0,k=0;i<n;i++){
        cin.ignore(100,'\n'); //ignorowanie znaku konca lini pozosawionego w buforze przez cin
        getline(cin,gotowe[k].nazwa);
        cin>>p>>d;
        gotowe[k].obroty=p/(3.141593*2.54*d)*100000;
        if(i>=3)
            sort(gotowe,gotowe+4);
        else
            k++;
        }
    sort(gotowe,gotowe+3);
    for(unsigned int i = 0; i < 3 ;i++){
        cout<<gotowe[i].nazwa<<endl;
        cout<<gotowe[i].obroty<<endl;
    }
    return 0;
}
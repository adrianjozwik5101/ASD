#include <iostream>

using namespace std;

struct osoba
{
    osoba() {}
    string kod;
    float s;
    int d,m;
};
int main()
{
    ios_base::sync_with_stdio(0);
    unsigned n;
    char k1, k2, k3;
    cin>>n;
    cin>>k1>>k2>>k3;
    osoba tab[n],tab2[n];
    for(unsigned int i=0;i<n;i++){
        cin>>tab[i].kod>>tab[i].s>>tab[i].d>>tab[i].m;
        cin>>tab2[i].kod>>tab2[i].s>>tab2[i].d>>tab2[i].m;
    }

    if(k1=='m' && k2=='s' && k3=='d' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.m > tab[indexpom -1].m)||
                   (indexpom > 0 && pom.m == tab[indexpom -1].m && pom.s > tab[indexpom -1].s)||
                   (indexpom > 0 && pom.m == tab[indexpom -1].m && pom.s == tab[indexpom -1].s && pom.d > tab[indexpom -1].d)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.m > tab2[indexpom -1].m)||
                   (indexpom > 0 && pom.m == tab2[indexpom -1].m && pom.s > tab2[indexpom -1].s)||
                   (indexpom > 0 && pom.m == tab2[indexpom -1].m && pom.s == tab2[indexpom -1].s && pom.d > tab2[indexpom -1].d)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    if(k1=='m' && k2=='d' && k3=='s' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.m > tab[indexpom -1].m)||
                   (indexpom > 0 && pom.m == tab[indexpom -1].m && pom.d > tab[indexpom -1].d)||
                   (indexpom > 0 && pom.m == tab[indexpom -1].m && pom.d == tab[indexpom -1].d && pom.s > tab[indexpom -1].s)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.m > tab2[indexpom -1].m)||
                   (indexpom > 0 && pom.m == tab2[indexpom -1].m && pom.d > tab2[indexpom -1].d)||
                   (indexpom > 0 && pom.m == tab2[indexpom -1].m && pom.d == tab2[indexpom -1].d && pom.s > tab2[indexpom -1].s)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    if(k1=='s' && k2=='m' && k3=='d' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.s > tab[indexpom -1].s)||
                   (indexpom > 0 && pom.s == tab[indexpom -1].s && pom.m > tab[indexpom -1].m)||
                   (indexpom > 0 && pom.s == tab[indexpom -1].s && pom.m == tab[indexpom -1].m && pom.d > tab[indexpom -1].d)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.s > tab2[indexpom -1].s)||
                   (indexpom > 0 && pom.s == tab2[indexpom -1].s && pom.m > tab2[indexpom -1].m)||
                   (indexpom > 0 && pom.s == tab2[indexpom -1].s && pom.m == tab2[indexpom -1].m && pom.d > tab2[indexpom -1].d)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    if(k1=='s' && k2=='d' && k3=='m' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.s > tab[indexpom -1].s)||
                   (indexpom > 0 && pom.s == tab[indexpom -1].s && pom.d > tab[indexpom -1].d)||
                   (indexpom > 0 && pom.s == tab[indexpom -1].s && pom.d == tab[indexpom -1].d && pom.m > tab[indexpom -1].m)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.s > tab2[indexpom -1].s)||
                   (indexpom > 0 && pom.s == tab2[indexpom -1].s && pom.d > tab2[indexpom -1].d)||
                   (indexpom > 0 && pom.s == tab2[indexpom -1].s && pom.d == tab2[indexpom -1].d && pom.m > tab2[indexpom -1].m)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    if(k1=='d' && k2=='m' && k3=='s' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.d > tab[indexpom -1].d)||
                   (indexpom > 0 && pom.d == tab[indexpom -1].d && pom.m > tab[indexpom -1].m)||
                   (indexpom > 0 && pom.d == tab[indexpom -1].d && pom.m == tab[indexpom -1].m && pom.s > tab[indexpom -1].s)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.d > tab2[indexpom -1].d)||
                   (indexpom > 0 && pom.d == tab2[indexpom -1].d && pom.m > tab2[indexpom -1].m)||
                   (indexpom > 0 && pom.d == tab2[indexpom -1].d && pom.m == tab2[indexpom -1].m && pom.s > tab2[indexpom -1].s)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    if(k1=='d' && k2=='s' && k3=='m' ){
        osoba pom;
        int indexpom;
        for(int i=1; i<n;i++){
            pom=tab[i];
            indexpom = i;
            while ((indexpom > 0 && pom.d > tab[indexpom -1].d)||
                   (indexpom > 0 && pom.d == tab[indexpom -1].d && pom.s > tab[indexpom -1].s)||
                   (indexpom > 0 && pom.d == tab[indexpom -1].d && pom.s == tab[indexpom -1].s && pom.m > tab[indexpom -1].m)){
                tab[indexpom]=tab[indexpom - 1];
                indexpom--;
            }
            tab[indexpom] = pom;
        }
        for(int i=1; i<n;i++){
            pom=tab2[i];
            indexpom = i;
            while ((indexpom > 0 && pom.d > tab2[indexpom -1].d)||
                   (indexpom > 0 && pom.d == tab2[indexpom -1].d && pom.s > tab2[indexpom -1].s)||
                   (indexpom > 0 && pom.d == tab2[indexpom -1].d && pom.s == tab2[indexpom -1].s && pom.m > tab2[indexpom -1].m)){
                tab2[indexpom]=tab2[indexpom - 1];
                indexpom--;
            }
            tab2[indexpom] = pom;
        }
    }

    for(unsigned int i=0;i<n;i++)
        cout<<tab[i].kod<<" "<<tab2[i].kod<<" ";

    return 0;
}
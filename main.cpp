#include <iostream>
#include<fstream>
using namespace std;
int st[41], n=27, ns, m;

struct role{
    char nume[41];
    int valoare;
    int town;
    int mafia;
    int townInvestigative;
    int townProtective;
    int townKilling;
    int townSupport;
    int neutralEvil;
    int neutralKilling;
}a[41];
ifstream f("date.txt");
ofstream g("text10.txt");
int nr_ord=1;
void afisare()
{
    int suma=0;
    int i;
    int mafie=0;
    int oras=0;
    int tInvest=0;
    int tProtective=0;
    int tKilling=0;
    int tSupport=0;
    int neutralEvil=0;
    int neutralKilling=0;
    for( i=1; i<=m; i++)
    {
        suma+=a[st[i]].valoare;
        mafie+=a[st[i]].mafia;
        tInvest+=a[st[i]].townInvestigative;
        tProtective+=a[st[i]].townProtective;
        tKilling+=a[st[i]].townKilling;
        tSupport+=a[st[i]].townSupport;
        neutralEvil+=a[st[i]].neutralEvil;
        neutralKilling+=a[st[i]].neutralKilling;
        oras+=a[st[i]].town;
    }
    if(suma==0&&oras>mafie&&tInvest>0&&tProtective>0&&tKilling>0&&tSupport>0&&mafie>1&&(neutralEvil>0||neutralKilling>0))
    {
        g<<nr_ord<<".";
        nr_ord++;
        for( i=1; i<=m; i++)
        g<<a[st[i]].nume<<" ";
        g<<endl;
    ns++;}
}

int valid(int k)
{
  if(k>1)
    if(st[k]<=st[k-1])
            return 0;
    return 1;
}

void bkt(int k)
{
    for(int i=1; i<=n; i++)
    {
        st[k]=i;
        if(valid(k)==1)
            if(k==m)
                afisare();
            else
                bkt(k+1);
    }
}
void citire()
{
    int i=1;//i max 27
    for(;i<=27;i++)
        f>>a[i].nume>>a[i].valoare>>a[i].town>>a[i].mafia>>a[i].townInvestigative>>a[i].townKilling>>a[i].townProtective>>a[i].townSupport>>a[i].neutralEvil>>a[i].neutralKilling;
//for(i=1;i<=27;i++)
  //  cout<<a[i].nume<<a[i].valoare<<a[i].mafia<<a[i].town<<a[i].townInvestigative<<a[i].townKilling<<a[i].townProtective<<a[i].townSupport<<a[i].neutralEvil<<a[i].neutralKilling;
}
int main()
{
    citire();
    cout<<"Numar de playeri:";
    cin>>m;
    bkt(1);
    g<<endl<<ns<<" solutii";
    return 0;
}

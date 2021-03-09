#include <iostream>
using namespace std;
/**
Se genereaza sol cu
SUBMULTIMI crescatoare
cu m val distincte
din multimea A={1,2,3,...n}
*/
int st[20], n, ns, m;

void afisare()
{
    for(int i=1; i<=m; i++)
        cout<<st[i]<<" ";
    cout<<endl;
    ns++;
}

int valid(int k)
{

    return 1;
}

void bkt(int k)
{
    for(int i=st[k-1]+1; i<=n; i++)
    {
        st[k]=i;
        if(k==m)
            afisare();
        else
            bkt(k+1);
    }
}

int main()
{
    cout << "n=";
    cin>>n;
    cout << "m=";
    cin>>m;
    bkt(1);
    cout<<endl<<ns<<" solutii";
    return 0;
}

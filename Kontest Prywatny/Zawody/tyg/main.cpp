#include <bits/stdc++.h>
using namespace std;
long long n,r,k,wynik,robe;
vector <pair<long long,long long >> tyg;
int main()
{
    scanf("%lld",&n);
    for(int i =0; i < n;++i)
    {
        scanf("%lld%lld",&r,&k);
        tyg.push_back({r,k});
    }
     sort(tyg.begin(),tyg.end());
    for(int i =0;i < n; i)
    {
        ++wynik;
        robe = tyg[i].first;
        while(robe*tyg[i].second > tyg[i].first) {
           // cout<< robe*tyg[i].second << " "<< tyg[i].first<<endl;
            if (i >= tyg.size())break;
            ++i;
        }
    }

    printf("%lld",wynik);
}
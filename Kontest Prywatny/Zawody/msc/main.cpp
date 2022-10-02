#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
uint_fast32_t a,b,k,tab[10001],sum=0,pocz,kon;
uint_fast64_t  wynik,obecny;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b>>k;
    for(int i =0;i <=10000;++i)
    {
        int r = i;
        sum =0;
        while(r)
        {
            sum+=r%10;
            r/=10;
        }
        tab[i] = sum;
    }
    pocz = b-k+1;
    kon =b;
    for(int i =pocz;i <=kon;++i)obecny+=tab[i/10000] + tab[i%10000];
    wynik = obecny;
    while(pocz >=a)
    {
        obecny -=tab[kon/10000] + tab[kon%10000];
        --kon;
        --pocz;
        obecny +=tab[pocz/10000] + tab[pocz%10000];
        wynik = max(wynik,obecny);
        if((kon%10000000) == 9999999|| kon == 999999 || kon == 99999|| kon == 9999)break;
    }
    cout<<wynik;
}
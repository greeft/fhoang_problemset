#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll mod = 1e9 + 7;
constexpr ll MAX_N =  1000001;
ll sil[MAX_N],sil_od[MAX_N],n,value;
ll fast_pow(ll a,ll p)
{
    ll val = 1;
    while(p)
    {
        if(p % 2)val *= a;
        val%= mod;
        a*=a;
        a%=mod;
        p>>=1;
    }
    return val;
}
ll dwu_n(ll x, ll y) {
    return (((sil[x] * sil_od[y])%mod) * sil_od[x - y])%mod;
}
int main()
{
    sil[0] =1;
    sil[1] =1;
    cin>>n;
    //cout<<dwu_n(4,2)<<endl;
    for(ll i = 2;i < MAX_N;++i)
    {
        sil[i] = sil[i - 1] * i;
        sil[i] %= mod;
    }
    sil_od[MAX_N - 1] = fast_pow(sil[MAX_N - 1],mod - 2);
    for(ll i = MAX_N - 2;i;--i)
    {
        sil_od[i] = sil_od[i + 1] * (i + 1);
        sil_od[i] %= mod;
    }
    sil_od[0] = 1;
    value = (2 * dwu_n((2 * n) - 1,n -1)) - n;
    value %= mod;
    printf("%lld", value);
}
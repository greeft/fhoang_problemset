#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll mod = 998244353;
//constexpr ll odw = ;
ll n,k,possibilites,dp[20001][20001],gomsiennica;
ll fast_powering(ll a,ll n)
{
    ll value = 1;
    while(n)
    {
        if(n%2)value*=a;
        value%=mod;
        a*=a;
        a%=mod;
        n>>=1;
    }
    return value;
}
int main()
{
    cout<<fast_powering(6, mod - 2);
    cin>>n>>k;
    possibilites = fast_powering(6, k);
    dp[0][0] = 1;
   // gomsiennica = 1 ;
    for(int i = 1;i<= k;++i)
    {
        gomsiennica = 0;
        for(int j = 1;j<=n; ++j)
        {
            dp[i][j] += gomsiennica;
        }
    }
}


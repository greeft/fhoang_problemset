#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll mod = 1e9 + 7;
constexpr ll MAX_N = 2005;
constexpr ll SIL_SIZE = MAX_N * MAX_N;
ll sil[SIL_SIZE],sil_od[SIL_SIZE],n,k,dp[MAX_N][MAX_N],value;
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
    cin>>n>>k;
    //cout<<dwu_n(4,2)<<endl;
    if(k == 1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(ll i = 2;i <= (( n + 1) * (k + 1));++i)
    {
        sil[i] = sil[i - 1] * i;
        sil[i] %= mod;
    }
    sil_od[(( n + 1) * (k + 1))] = fast_pow(sil[(( n + 1) * (k + 1))],mod - 2);
    for(ll i = ((( n + 1) * (k + 1))) - 1;i;--i)
    {
        sil_od[i] = sil_od[i + 1] * (i + 1);
        sil_od[i] %= mod;
    }
    sil_od[0] = 1;
    dp[0][1] = 1;
   // cout<<dwu_n(4,2)%mod<<endl;
   //dp[1][1] = 1;
    for(ll i = 0;i<=n;++i)
    {
        for(ll j = i; j <= n;++j)
        {
            //cout<<n<<endl;
            if(i)dp[i][j] += dp[i - 1][j];
            dp[i][j] %= mod;
            if(j!=i) dp[i][j] += dp[i][j - 1] * dwu_n((j * (k - 1) + i - 1),(k -2));
            dp[i][j] %= mod;
//            cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
        }
    }
    value = dp[n][n];
     value *= sil[n];
    value%=mod;
   // if(n == 1||k == 1)cout<<1<<endl;
   cout<<value;
}


#include <bits/stdc++.h>
using namespace std;
#define ll uint_fast64_t
constexpr ll mod = 998244353;
constexpr ll odw = 166374059;
ll n,k,dp[2][20001],gom,value,odw_k;
ll fast_power(ll a,ll n)
{
    ll val = 1;
    while(n)
    {
        if(n%2)val*=a;
        val%= mod;
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>n>>k;
    //cout<<mod * odw <<endl;
   // cout<<fast_power(6,mod - 2)<<endl;
    odw_k = fast_power(k,mod - 2);
    dp[0][0] = 1;
    for(ll i  = 1; i<=k;++i)
    {
        gom = 0;
        dp[i%2][0] = 0;
        for(ll j = 1; j <= min(i * 6,n);++j)
        {
            dp[i%2][j] = 0;
           // cout << "gasei: " << dp[(i-1)%2][j-1] << "\n";
            gom += (dp[(i - 1)%2][(j - 1)] * odw)%mod;
            gom %= mod;
            if(j >= 6)
            {
                gom += mod;
                gom -= (dp[(i - 1)%2][(j - 7)] * odw)%mod;
                gom %= mod;
            }
            //cout << i << " " << j << " " << gom << "\n";
            dp[i%2][(j)] += gom;
            dp[i%2][(j)] %= mod;
        }
        //cout<<dp[i%2][n]<<endl;
        if((6 * i) >= n)value += (dp[i%2][n]) %mod;
        value %=mod;
    }
   // if(value < 0)value+=mod;
    cout<<(value * odw_k)%mod;
}
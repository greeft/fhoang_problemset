#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll MAX_N = 1e6 + 1;
long long prime[MAX_N],n,dp[MAX_N],a[MAX_N],value;
int main()
{
    scanf("%lld",&n);
    for(int i = 1;i<=n;++i)scanf("%lld",&a[i]);
    for(ll i = 2; i * i <= n;++i)
    {
        if(prime[i])continue;
        for(ll j = i*i;j <=n;j+=i)if(!prime[j])prime[j]= i;
    }
    dp[1] += a[1];
    for(int i =2;i<=n;++i)
    {
        if(!prime[i])
        {
            dp[1] +=a[i];
            dp[i + i] -= a[i];
        }
        else if(!(i%2))
        {
            dp[i] += a[i];
            dp[i + 1] -= a[i];
        }
        else
        {
            dp[i - prime[i] + 1] += a[i];
            dp[i + prime[i] - 1] -= a[i];
        }
    }
    for(int i = 1;i<=n;++i)
    {
        dp[i]+=dp[i - 1];
        value = max(value, dp[i]);
    }
    printf("%lld",value);
}
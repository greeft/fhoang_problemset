#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll HASH = 1299709;
constexpr int MAX_N = 1e5 + 1;
ll n,q,x[MAX_N],a,b,c,d;
ll dp[MAX_N],dp_pot[MAX_N],multi_hash[MAX_N],sum,qua,xr,sum2,poly[MAX_N],power = 1,hash1,hash2;
unordered_map<ll,ll> scaller;
int main()
{
    scanf("%lld%lld",&n,&q);
    for(int i =1;i<=n;++i)
    {
        scanf("%d",&x[i]);
        scaller[x[i]] = 420;
        dp[i] = dp[i - 1] + x[i];
        dp_pot[i] = dp_pot[i - 1] + (x[i] * x[i]);
    }
    int scal = 0;
    for(auto& u :scaller)
    {
        power *= HASH;
        ++scal;
        poly[scal] = power;
        u.second = scal;
    }
    for(int i =1;i<=n;++i)
    {
        multi_hash[i] = multi_hash[i - 1] + x[i] * poly[scaller[x[i]]];
    }
    for(int h = 1; h<=q;++h)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        sum = (dp[b] - dp[a - 1]) - (dp[d] - dp[c - 1]);
        qua = (dp_pot[b] - dp_pot[a - 1]) - (dp_pot[d] - dp_pot[c - 1]);
        hash1 = multi_hash[b] - multi_hash[a - 1];
        hash2 = multi_hash[d] - multi_hash[c - 1];
        if(!sum)
        {
            printf("NIE\n");
            continue;
        }
        sum2 = qua / sum;
        b = (sum2 - sum)  >> 1;
        a = sum + b;
        hash1 -= a * poly[scaller[a]];
        hash2 -= b * poly[scaller[b]];
        if(hash1 == hash2&& a + b == sum2)
        {
            printf("TAK\n");
            continue;
        }
        else
            printf("NIE\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e6 + 1;

int n,m,c,a,b,k;
long long dp[MAX_N],prefix_sum[MAX_N],value,starting[MAX_N];

int main()
{
    scanf("%d%d%d",&n,&m,&c);
    for(int i = 1;i<=m;++i)
    {
        scanf("%d%d%d",&a,&b,&k);
        prefix_sum[a]+=k;
        starting[a] += k;
        prefix_sum[b + 1] -=k;
    }
    for(int i =1;i<=n;++i)
    {
        prefix_sum[i] +=prefix_sum[i - 1];
        //zero bierzemy z poprzednika
        dp[i] = max(c - prefix_sum[i],dp[i - 1] + c - starting[i]);
        value = max(dp[i],value);
    }
    cout<<value;
}
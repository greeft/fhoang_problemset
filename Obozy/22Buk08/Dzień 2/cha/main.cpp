#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5 + 1,MAX_V = 1e3 + 1;
long long n,v,p[MAX_N],a,b,dp1[MAX_N][MAX_V],dp2[MAX_N][MAX_V],profit[MAX_N],value;
vector<int>graph[MAX_N];
void dfs(int a,int b)
{
    pair<long long,long long> mx_dp2,mx2_dp2;
    for(auto u : graph[a])
    {
        if(u == b)continue;
        dfs(u,a);
    }
    for(int i = 1;i <=v;++i)
    {
        mx_dp2.first = 0;
        mx_dp2.second = 0;

        mx2_dp2.first = 0;
        mx2_dp2.second = 0;
        for(auto u : graph[a])
        {
            if(u == b)continue;
            dp1[a][i] = max(dp1[a][i],dp1[u][i]);
            dp1[a][i] = max(dp1[a][i],dp1[u][i - 1] + profit[a] - p[b]);
            if(mx_dp2.first < dp2[u][v])
            {
                mx2_dp2.first = mx_dp2.first;
                mx2_dp2.second = mx_dp2.second;
                mx_dp2.first = dp2[u][v];
                mx_dp2.second = u;
            }
            else if(mx2_dp2.first < dp2[u][v])
            {
                mx2_dp2.first = dp2[u][v];
                mx2_dp2.second = u;
            }

        }

    }
}
int main()
{
    scanf("%lld%lld",&n,&v);
    for(int i = 1;i<=n;++i)
    {
        scanf("%lld",&p[i]);
    }
    for(int i = 1;i< n;++i)
    {
        scanf("%llld%lld",&a,&b);
        profit[a] += p[b];
        profit[b] += p[a];
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

}
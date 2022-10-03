#include <bits/stdc++.h>
using namespace std;

int n,u,v,a,b,m,deep[100001],dp[100001][18];
vector <int> graph[100001];
void dfs(int a,int b)
{
    dp[a][0]=b;
    for(auto  u : graph[a])
    {
        if(u==b)continue;
        deep[u]=deep[a]+1;
        dfs(u,a);
    }
}
int lca(int a,int b)
{
    if(deep[a]<deep[b])swap(a,b);
    for(int k = 17; k>=0;k--)
    {
        if(deep[dp[a][k]]>=deep[b])a=dp[a][k];
    }
    if(a==b)return b;
    for(int k=17; k >=0;k--)
    {
        if(dp[a][k]!= dp[b][k])
        {
            a = dp[a][k];
            b = dp[b][k];
        }
    }
    return dp[b][0];

}
int main()
{
    scanf("%d",&n);
    for(int i =1; i < n;i++)
    {
        scanf("%d%d",&u,&v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,1);
    scanf("%d",&m);
    for(int i = 1;i <= 17;++i)
    {
        for(int j = 1;j <= n;++j)dp[j][i] = dp[dp[j][i-1]][i-1];
    }
    for(int i =0; i < m;i++)
    {
        scanf("%d%d",&a,&b);
        int l = lca(a,b);
        if((deep[a]+deep[b]-2*deep[l])%2)printf("TAK\n");
        else printf("NIE\n");
    }
}
#include <bits/stdc++.h>
using namespace std;

int n,m,k,unactive,a,b,value2,paired[4002],current,visited[4002],value;
vector <int> graph[4002];
bool not_possible[4002],if_active[4002];
bool match(int x)
{
    visited[x] = current;
    if(not_possible[x])return false;
    for(auto u : graph[x])
    {
        if(!paired[u])
        {
            //cout<<x<<" "<<u<<endl;
            paired[x] = u;
            paired[u] = x;
            return true;
        }
    }
    for(auto  u : graph[x])
    {
        if(paired[u] == x||visited[paired[u]] == current||not_possible[paired[u]])continue;
        if(match(paired[u]))
        {
            paired[x] = u;
            paired[u] = x;
            return true;
        }
    }
    not_possible[x] = true;
    return false;
}
int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i = 0; i < k;++i)
    {
        scanf("%d%d",&a,&b);
        if(a > m && b > m)continue;
        else if(a <=m && b <= m)continue;
        if(a > m)swap(a,b);
        if_active[a] = true;
        if_active[b] = true;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for(int i=1;i<=m;i++)
    {
        if(!if_active[i])continue;
        ++current;
        (match(i));
    }
    for(int i = 1; i <= m;++i)
    {
        if(!if_active[i])continue;
        if(paired[i])++value;
    }
    for(int i = m + 1; i <= n + m;++i)
    {
        if(!if_active[i])continue;
        if(paired[i])++value2;
    }
    for(int i = 1; i <=n+m;++i)
    {
        if(!if_active[i])unactive++;
    }
    printf("%d",  n + m - value2 - unactive);
}
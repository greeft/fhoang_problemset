#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e5 + 1;
int n,q,d,a,u,value,v,rep[MAX_N],spo[MAX_N],subtree_size[MAX_N],idx[MAX_N];
vector <int> graph[MAX_N];
int Find(int a)
{
    if(rep[a] == a)return a;
    else
    {
        rep[a] = Find(rep[a]);
        return rep[a];
    }
}
void Union(int a,int b)
{
    a = Find(a);
    b = Find(b);
    if(spo[a] < spo[b])swap(a,b);
    rep[b] = a;
    spo[a] += spo[b];
}
bool comp(int& a,int& b)
{
    if(subtree_size[a] > subtree_size[b])return true;
    return false;
}
int get_size(int a,int b)
{
    for(auto u : graph[a])
    {
        if(u == b)continue;
        get_size(u,a);
        subtree_size[a] += subtree_size[u];
    }
}
void new_iter(int a,int b)
{
    ++value;
    for(auto u : graph[a])
    {

    }

}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i =1;i<=n;++i)
    {
        rep[i] = i;
        spo[i] = 1;
    }
    for(int i =1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    get_size(1, -1);
    for(int i =1;i<=n;++i)sort(graph[i].begin(),graph[i].end(),comp);
    new_iter(1, -1);
}
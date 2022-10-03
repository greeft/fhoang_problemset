#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e6 + 1;
int n,a,b,m,essa,value;
vector <int> graph[MAX_N];
bitset <MAX_N> trasa;
bool dfs(int a,int b)
{
    bool if_already = 0;
    bool if_taken = 0;
    if(trasa[a])if_already = 1;
    for(auto u : graph[a])
    {
        if(u ==b)continue;
        if(if_already&&!(if_taken))
        {
            if(dfs(u,a))
            {
                ++value;
                if_taken = true;
            }
        }
        else if_already |= dfs(u,a);
    }
    if(!(if_taken)&&if_already)return 1;
    else return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i< n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    scanf("%d",&m);
    for(int i =1;i<=m;++i)
    {
        scanf("%d",&essa);
        trasa[essa] = true;
    }
    dfs(1,-1);
    printf("%d",value);
}
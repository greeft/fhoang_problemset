#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e5 + 1;
constexpr int pot_2 = 262143;
int n,a,b,m,q,deep[MAX_N],pre_order[MAX_N],post_order[MAX_N],value;
vector <int> graph[MAX_N];
vector <int> back[MAX_N];
vector <int> MST[(pot_2) << 1];
void dfs(int a,int b)
{
    ++value;
    pre_order[a] = value;
    for(auto u : graph[a])
    {
        if(u == b)continue;
        if(!deep[u])
        {
            deep[u] = deep[a] + 1;
            dfs(u,a);
        }
        else
        {
            if(deep[u] > deep[a])
            {
                back[a].emplace_back(u);
            }
        }
    }
    post_order[a] = value;
}
void build()
{
    for(int iter = pot_2; iter;--iter)
    {
        int pointer_1 = 0;
        int node_1 = iter <<1;
        int pointer_2 = 0;
        int node_2 = (iter <<1) + 1;
       // cout<<pointer_1<<" "<<node_1<<" "<<pointer_2<<" "<<node_2<<endl;
        while(pointer_1 < MST[node_1].size()||pointer_2 < MST[node_2].size())
        {
            if(pointer_1 == MST[node_1].size())
            {
                while(pointer_2 < MST[node_2].size())
                {
                    MST[iter].emplace_back(MST[node_2][pointer_2]);
                    ++pointer_2;
                }
            }
            else if(pointer_2 == MST[node_2].size())
            {
                while(pointer_1 < MST[node_1].size())
                {
                    MST[iter].emplace_back(MST[node_1][pointer_1]);
                    ++pointer_1;
                }
            }
            else
            {
                if(MST[node_1][pointer_1] > MST[node_2][pointer_2])
                {
                    MST[iter].emplace_back(MST[node_2][pointer_2]);
                    ++pointer_2;
                }
                else
                {
                    MST[iter].emplace_back(MST[node_1][pointer_1]);
                    ++pointer_1;
                }
            }
        }
    }
}
int query(int a,int s, int e,int x,int y, int k)
{

}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    scanf("%d",&m);
    for(int i = 1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    deep[1] = 1;
    dfs(1,-1);
    for(int i = 1;i<=n;++i) {
        for (auto u: back[i]) {
            MST[pre_order[u] + pot_2].emplace_back(deep[i]);
        }
    }
    build();

}
// taki rozek z powazna mina podchodzi do ciebie i mowi " za granie w warmsy na kontesie zeruje ci kontest" xDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD
#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2000001;
int n,a,b,odl[MAX_N],value;
vector<int> graph[200001];
queue <int> q;
int main()
{
    scanf("%d",&n);
    for(int i = 1; i<n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    for(int i = 1;i<=n;++i)odl[i]  = 1e9;
    for(int i = 1;i<=n;++i)
    {
        if(graph[i].size() == 1)
        {
            odl[i] = 0;
            q.push(i);
        }
    }

    while(!q.empty())
    {
        a = q.front();
        q.pop();
//        cout<<a<<" "<<odl[a]<<endl;
        for(auto u : graph[a])
        {
            if(odl[u] > odl[a] + 1)
            {
                odl[u] = odl[a] + 1;
                value = max(odl[u],value);
                q.push(u);
            }
        }
    }
    printf("%d",value);
}
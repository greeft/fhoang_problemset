#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,value,k;
vector <int> tunnels[4001];
bitset<4001> if_build;
priority_queue<pair<int,int>> pq;
priority_queue<pair<int,int>> ppq;
int main()
{
    scanf("%d%d%d",&m,&n,&k);
    for(int i = 1; i <=k;++i)
    {
        scanf("%d%d",&a,&b);
        tunnels[a].push_back(b);
        tunnels[b].push_back(a);
    }
    for(int i = 1; i <= n + m;++i)
    {
        pq.push({-tunnels[i].size(),i});
    }
    while(!pq.empty())
    {
        int q = pq.top().second;
        pq.pop();
        if(if_build[q])continue;
       // cout<<q<<" "<<endl;
        for(auto u : tunnels[q])
        {
            if(!if_build[u])
            {
                ppq.push({tunnels[u].size(),u});
            }
        }
        if(ppq.empty())
        {
            value++;
            if_build[q]= true;
        }
        else
        {
            //cout<<ppq.top().second<<endl;
            if_build[ppq.top().second]= true;
            if_build[q]= true;
            value++;
            while(!ppq.empty())ppq.pop();
        }
    }
    printf("%d",value);
}
#include <bits/stdc++.h>
using namespace std;

int n,a,b,subtree_size[1000001],centroid;
vector <int> graph[1000001],subtrees;
long long ans,houses;
bitset<1000001> if_centroid;
set<long long> first_sub,second_sub;
set<long long> :: iterator iter;
int get_size(int a,int b)
{
   int &v = subtree_size[a];
   v =1;
    for(auto u : graph[a])
    {
        if(if_centroid[u])continue;
        if(u==b)continue;
        v += get_size(u,a);
    }
    return v;
}
int Find_Centroid(int a,int b)
{
    for(auto u : graph[a])
    {
        if(if_centroid[u])continue;
        if(u == b)continue;
        if(subtree_size[u] * 2 > n)return Find_Centroid(u,a);
    }
    if_centroid[a] = true;
    return a;
}
void generate_cut(int a,int b,set<long long>& s)
{
    for(auto u : graph[a])
    {
        if(u == b)continue;
        if(if_centroid[u])continue;
        s.insert(subtree_size[u]);
        generate_cut(u,a,s);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    get_size(1,-1);
   centroid =  Find_Centroid(1,-1);
    get_size(centroid,-1);
    if(graph[centroid].size() >2) {
        for (auto u: graph[centroid]) {
            // cout<<subtree_size[u]<<endl;
            subtrees.push_back(subtree_size[u]);
        }
        houses++;
        sort(subtrees.begin(), subtrees.end(), greater<int>());
        ans += (subtrees[0] * (subtrees[0] - 1)) / 2;
        ans += (subtrees[1] * (subtrees[1] - 1)) / 2;
        for (int i = 2; i < subtrees.size(); ++i)houses += subtrees[i];
        ans += (houses * (houses - 1)) / 2;
        printf("%lld", ans);
    }
    else
    {
        generate_cut(graph[centroid][0],centroid,first_sub);
        first_sub.insert(subtree_size[graph[centroid][0]]);
        first_sub.insert(42000000);
        generate_cut(graph[centroid][1],centroid,second_sub);
        first_sub.insert(subtree_size[graph[centroid][1]]);
        second_sub.insert(42000000);
        ans = 1000000000000000;
        for(auto u : first_sub)
        {
            iter = second_sub.lower_bound(u);
            long long p = *iter;
            long long r = n - u - p;
            ans = min(ans,((u * (u -1))/2) + ((p * (p -1))/2) + ((r * (r -1))/2));
            if(iter == second_sub.begin())continue;
            --iter;
            p = *iter;
             r = n - u - p;
            ans = min(ans,((u * (u -1))/2) + ((p * (p -1))/2) + ((r * (r -1))/2));
        }
        printf("%lld",ans);
    }
}
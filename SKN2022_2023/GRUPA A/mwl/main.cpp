#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e5 + 1;
bool if_deleted[MAX_N];
int n,edges[MAX_N],value,cycle_size,v;
string graph[MAX_N],s,s2;
queue <int> q;
unordered_map<string,int> ver;
int main()
{
   cin>>n;
   if(n%2)
   {
       cout<<"-1";
       return 0;
   }
    for(int i = 1;i<=n;++i)
    {
        cin>>s>>s2;
        ver[s] = i;
        graph[i] = s2;
    }
    for(int i = 1; i<=n;++i)
    {
        ++edges[ver[graph[i]]];
        if(if_deleted[i])continue;
        if(i != ver[graph[i]]&&i == ver[graph[ver[graph[i]]]])
        {
            if_deleted[i] = true;
            if_deleted[ver[graph[i]]] = true;
        }
    }
   // for(int i = 1;i<=n;++i)if(if_deleted[i])cout<<i<<endl;
   for(int i = 1;i<=n;++i)if(!edges[i])q.push(i);
   while(!q.empty())
   {
       v = q.front();
      // cout<<v<<endl;
        q.pop();
       if(if_deleted[ver[graph[v]]])continue;
       if_deleted[v] = true;
       if_deleted[ver[graph[v]]] = true;
       ++value;
       //cout<<edges[ver[graph[ver[graph[v]]]]]<<endl;
       --edges[ver[graph[ver[graph[v]]]]];
       if(!edges[ver[graph[ver[graph[v]]]]])q.push(ver[graph[ver[graph[v]]]]);
   }
 //  cout<<"kys"<<endl;
   for(int i = 1;i<=n;++i)
   {
       if(if_deleted[i])continue;
       cycle_size = 1;
       v = ver[graph[i]];
       if_deleted[i] = true;
       while(!if_deleted[v])
       {
          // cout<<i<<" "<<v<<endl;
           if_deleted[v] = true;
          ++cycle_size;
           v = ver[graph[v]];
       }
       value += (cycle_size + 1) >> 1;
   }
   cout<<value<<endl;
}
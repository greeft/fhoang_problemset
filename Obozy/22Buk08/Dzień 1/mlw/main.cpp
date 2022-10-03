#include <bits/stdc++.h>
using namespace std;
#define ll uint_fast64_t
constexpr ll base = 1e6;
constexpr uint_fast32_t MAX = 100001;
int n,edges[MAX],value;
string s,t;
map <string,int> m;
map <ll,bool> if_match;
bool if_deleted[MAX],if_paired[MAX];
string graph[MAX];
queue <int> q;
int dfs(int a,int c,int length)
{
    if_deleted[a] = true;

        if (c == m[graph[a]])return length + 1;
        if(if_deleted[m[graph[a]]]||if_paired[m[graph[a]]])return length + 1;
        return dfs(m[graph[a]], c, length + 1);
    return length + 1;
}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin>>n;
        if(n%2)
        {
            printf("-1");
            return 0;
        }
        for(int i = 1;i<=n;++i)
        {
            cin>>s>>t;
            m[s] = i;
            graph[m[s]] = t;
        }
        for(int i = 1;i<=n;++i) {
                if(if_match[ll(m[graph[i]]) * base + ll(i)])
                {
                    if_deleted[i] = true;
                    if_deleted[m[graph[i]]] = true;
                    continue;
                }
                if_match[ll(i) * base + ll(m[graph[i]])] = true;
        }

    for(int i = 1;i<=n;++i)
    {
        if(if_deleted[i])continue;
            if(!if_deleted[m[graph[i]]])edges[m[graph[i]]]++;
    }
    for(int i = 1;i<=n;++i)if(!edges[i]&&!if_deleted[i])q.push(i);
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        if(if_paired[p]||if_deleted[p])continue;
        if(!if_paired[m[graph[p]]])
        {
            if_paired[p] = true;
            if_paired[m[graph[p]]] = true;
            ++value;
            --edges[m[graph[m[graph[p]]]]];
           if(!edges[m[graph[m[graph[p]]]]]) q.push(m[graph[m[graph[p]]]]);
        }

    }
    //cout<<value<<endl;
    for(int i = 1 ;i<=n;++i)
    {
        if(!if_deleted[i]&&!if_paired[i])
        {
            int h = dfs(i,i,0);
            // cout<<h<<endl;
            if(h%2)value+= (h>>1) +1;
            else value += (h>>1);
        }
    }
    cout<<value<<endl;
}

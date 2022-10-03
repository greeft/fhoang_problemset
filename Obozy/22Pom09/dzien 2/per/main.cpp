#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e5 * 5 + 1;
constexpr int N = 524287;
int tree[(N + 1)<<1],Q[MAX_N],n,k,tab[MAX_N],groups[MAX_N],wynik[MAX_N],val;
void add(int a,int val)
{
    a += N;
    tree[a] = val;
    while(a)
    {
        tree[a] =  min(tree[a << 1],tree[(a << 1) + 1]);
        a >>=1;
    }
}
//x - y wierzcholka
int query(int v,int x,int y,int p,int k)
{
    if(x > k||y < p)return 1e9;
    else if(p <= x && k >= y)
    {
        return tab[v];
    }
    return min(query(v << 1,x,(x + y) >> 1,p,k), query((v<<1)+1,((x + y )>> 1) + 1,y,p,k));
}
priority_queue<int> pq;
int main(){
    scanf("%d%d",&n,&k);
    for(int i = N + 1;i < (N << 1);++i)tree[i] = 1e9;
    for(int i =1;i<=n;++i)
    {
        scanf("%d",&tab[i]);
        Q[tab[i]] = i;
        tree[i + n] = tab[i];
    }
    for(int i = N;i;--i)tree[i] = min(tree[i << 1],tree[(i << 1) + 1]);
    for(int i = 1; i <= n;i+=k)
    {
        val = query(1,1,N,i,i + k);
        groups[i / k] = val;
        if(val == query(1,1,N,Q[val],min(n,Q[val] + k))&&val == query(1,1,N,Q[val],max(1,Q[val] - k)))
        {
            pq.push(-Q[val]);
        }
    }
    int iter = 0;
    while(!pq.empty())
    {
        ++iter;
        wynik[val] = iter;
        val = tab[-pq.top()];
        groups[val / k] =  query(1,1,N,(val / k) * k,min(n,Q[val] + k))
        add(Q[val],1e9);

    }
    for(int i =1;i<=n;++i)cout<<wynik[i]<<endl;
}
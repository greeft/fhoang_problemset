#include <bits/stdc++.h>
using namespace std;
const int N=262143;
int n,a,b,scaler=1,tree[(N+1)<<1];
vector<pair<int,int> > off;
map <int,int> scal;
void add(int w,int val)
{
    w+=N;
    while(w)
    {
        tree[w]=max(tree[w],val);
        w=>1;
    }
}
int query(int w,int p,int k,int x,int y) {
    //cout<<"hej jestem wierzcholkiem :"<<x<<" "<<y<<" "<<k<<endl;
    if (x > k || y < p) return 0;
    else if (p <= x && k >= y) {
        return tree[w];
    } else {
        return max(query(w <<1, p, k, x, (x + y) >> 1), query((w <<1) + 1, p, k, ((x + y) >> 1) + 1, y));
    }
}
bool comp(pair <int,int> a, pair<int,int> b)
{
    if(a.first> b.first)return 0;
    if(a.first<  b.first)return 1;
    if(a.second >  b.second)return 1;
    else return 0;
}
        int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a, &b);
        scal[a] = 2137;
        scal[b] = 2137;
        off.push_back({a, b});
    }
    for(auto u : scal)
    {
         scal[u.first]= scaler;
         ++scaler;
    }
    sort(off.begin(),off.end(),comp);
    for(int i =0;i < off.size();++i)
    {
        int k = scal[off[i].second];
        int q = query(1,k,N+1,1,N+1);
        //cout<<p<<" "<<k<<" "<<q<<endl;
        add(k,q+1);
    }
    printf("%d",tree[1]);
}
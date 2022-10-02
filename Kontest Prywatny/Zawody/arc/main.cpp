#include <bits/stdc++.h>
using namespace std;
int n,z,a,b,c,rep[100001],spojna[100001],hight[100001];
pair<int,int> Find(int a)
{
    pair <int,int> p;
    p.first = 0;
    p.second = 0;
    if(rep[a] == a)
    {
        p.first = a;
        return p;
    }
    else
    {
        p = Find(rep[a]);
        p.second +=hight[a];
       if(p.first != rep[a]) hight[a] = p.second;
        rep[a] = p.first;
        return p;
    }
}
void Union(int a, int b,int c)
{
    pair <int,int> p_a = Find(a);
    pair <int,int> p_b = Find(b);
    int help_c = p_b.second -  p_a .second;
    if(spojna[a] < spojna[b])
    {
        swap(a,b);
        help_c = - help_c;
        c= - c;
    }
    rep[b] = rep[a];
    hight[b] += c + help_c;
    spojna[a] += spojna[b];
}
int main()
{
    scanf("%d%d",&n,&z);
    for(int i = 1 ; i <=n;++i)
    {
        rep[i] = i;
        spojna[i] = 1;
    }
    for(int i =0;i < z;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(Find(a).first != Find(b).first)
        {
            printf("TAK\n");
            Union(a,b,-c);
        }
        else
        {
            if(hight[b] + c == hight[a])printf("TAK\n");
            else printf("NIE\n");
        }
    }
   // for(int i = 1; i<=n;++i)cout<<hight[i]<<" ";
}
#include <bits/stdc++.h>
using namespace std;

int n,z,a,b,c,rep[100001],hight[100001];
pair<int,int> Find(int a)
{
    pair<int,int> p;
    p.second = 0;
    if(rep[a] == a)
    {
        p.first = rep[a];
        return p;
    }
    else
    {
        p = Find(rep[a]);
        rep[a] = p.first;
        hight[a] += p.second;
        p.second = hight[a];
        return p;
    }
}
void Union(int a,int b,int c)
{
    pair<int,int> p_a = Find(a);
    pair<int,int> p_b = Find(b);
    int c_add =  - p_b.second  + p_a.second;
    rep[p_b.first] = p_a.first;
    hight[p_b.first] = c + c_add;
   // cout<<c_add<<" "<<p_a.first<<" "<<p_b.first<<"   es"<< hight[p_b.first]<<endl;
}
int main()
{
    scanf("%d%d",&n,&z);
    for(int i = 1;i <=n;++i)rep[i] = i;
    for(int h = 0; h < z;++h)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(Find(a).first == Find(b).first)
        {
            //cout<<hight[a]<<" "<<hight[b]<<endl;
            if(hight[a] + c == hight[b])printf("TAK\n");
            else printf("NIE\n");
        }
        else
        {
            printf("TAK\n");
            Union(a,b,c);
           // cout<<hight[b]<<endl;
        }
    }


}
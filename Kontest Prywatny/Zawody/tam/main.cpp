#include <bits/stdc++.h>
using namespace std;
int n,w[1000002],k[1000002];
priority_queue < pair<int,int> > pq,clone_pq;
int main()
{
    scanf("%d",&n);
    for(int i =1; i <= n+1;++i)
    {
        scanf("%d",&w[i]);
    }
    for(int i =1; i < n+1;++i)
    {
        scanf("%d",&k[i]);
    }
    for(int i =1; i <=n;++i)
    {
        int b = min(w[i],w[i+1])/k[i];
        ++b;
        pq.push({-b,i});
    }
    int pocz = 0;
    int kon =1000000;
    int mid = (pocz+kon)>>1;
    while(pocz!=mid&&kon!=mid)
    {
        clone_pq = pq;
        while(!clone_pq.empty())
        {
            if(mid > clone_pq.top().first)
            {
                pocz = mid;
                mid = (pocz+kon)>>1;;
                break;
            }
            else
            {

            }
        }
    }
}

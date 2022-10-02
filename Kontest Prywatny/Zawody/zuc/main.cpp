#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,k;
pair<int,int> dp[50001];
bitset<50001> zuczki;
vector<int> graph[50001];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i =1;i <n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    scanf("%d",&k);
    for(int i =0; i < k;++i)
    {
        scanf("%d",&a);
        zuczki[a] = true;
    }

}
#include <bits/stdc++.h>
using namespace std;
int n,l,first[1000001],last[1000001],tab[1000001],dp[1000001];
//vector <int> v;
int main()
{
    scanf("%d",&n);
    for(int i =1;i <= n;++i)
    {
        scanf("%d",&l);
        tab[i] = l;
        last[l] = i;
        if(!first[l])first[l]=i;
       // ++licz[l];
    }
    for(int i =1;i <= n;++i)
    {
        dp[i] = dp[i-1];
        if(last[tab[i]]==i) dp[i] = max(dp[i],dp[first[tab[i]]]+1);
    }
    printf("%d",dp[n]);
}
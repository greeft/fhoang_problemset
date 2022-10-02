#include <bits/stdc++.h>
using namespace std;

int n,dp[10010];
int main()
{
    dp[1] = 1;
    scanf("%d",&n);
    for(int i =2;i <=n;++i)
    {
        for(int j = 1; j < i;++j)dp[i]
      dp[i] +=dp[i];
    }
    cout<<dp[n];
}
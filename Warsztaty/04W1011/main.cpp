#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1002;
long long n,m,tab[MAX_N][MAX_N],dp[MAX_N][MAX_N][4],value;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
    {
        for(int j =1; j<=m;++j)scanf("%d",&tab[i][j]);
    }
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1; j<=m;++j)dp[i][j][0] = max(tab[i][j],max(dp[i - 1][j][0],dp[i][j - 1][0]));
    }
    for(int i = n;i;--i)
    {
        for(int j = 1; j<=m;++j)dp[i][j][1] = max(tab[i][j],max(dp[i + 1][j][1],dp[i][j - 1][1]));
    }
    for(int i = 1;i<=n;++i)
    {
        for(int j = n;j;--j)dp[i][j][2] = max(tab[i][j],max(dp[i][j +1][2],dp[i - 1][j][2]));
    }
    for(int i = n;i;--i)
    {
        for(int j = m;j;--j)dp[i][j][3] = max(tab[i][j],max(dp[i][j + 1][3],dp[i + 1][j][3]));
    }
    for(int i = 1;i<=n;++i)
    {
        for(int j = 1; j<=m;++j)value = max(value,tab[i][j] + max(max(dp[i - 1][j - 1][0],dp[i + 1][j - 1][1]),max(dp[i - 1][j + 1][2],dp[i + 1][j + 1][3])));
    }
    printf("%d",value);
}
#include <bits/stdc++.h>
using namespace std;


int n,m;
char tab[3001][3001],dp[3001][3001];
//vector <pair<pair<int,int>,pair<int,int>> v;
int main()
{
    cin>>n>>m;
    for(int i = 1; i<=n;++i)
    {
        for(int j = 1;j<=m;++j)
        {
            cin>>tab[i][j];
        }
    }
    for(int i = 1;i<=n;++)
    {
        for(int j = 1;j<=m;++j)
        {
                dp[i][j] = max(dp[i][j -1],dp[i - 1][j]);
                if(i > 2&&tab[i][j] == 'W' && tab[i - 1][j] == 'G'&&tab[i - 2][j] == 'R')
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j] + dp[i][j - 3] + 1);
                }
                if(j > 2&&tab[i][j] == 'W' && tab[i][j - 1] == 'G'&&tab[i - 2][j] == 'R')
                {
                     dp[i][j] = max(dp[i][j],dp[i][j - 1] + dp[i - 3][j] + 1);
                }
        }

    }
    printf("%d",dp[n][m]);
}

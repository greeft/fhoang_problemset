#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
int n,dp[2][30001];
char tab[30001];
inline void MOD(int& a)
{
    while(a > mod)
    {
        a -= mod;
    }
}
int main()
{
    scanf("%d\n",&n);
    for(int i = 1;i<=n;++i)
    {
        tab[i] = getchar();
    }
    dp[0][0] = 1;
    for(int i =1;i<=n;++i)
    {
        int local_min = min(i,n - i);
        if(!(i%2))
        {
            for(int j = 0; j <= local_min;j+=2)
            {
                //cout<<dp[i%2][j]<<" ";
                dp[i%2][j] = dp[(i -1) % 2][j + 1];
                MOD(dp[i%2][j]);
                if(tab[i] == '('&&j)dp[i%2][j] += dp[(i -1) % 2][j - 1];
                MOD(dp[i%2][j]);
            }
        }
        else
        {
            for(int j = 1; j <= local_min;j+=2)
            {
                //cout<<dp[i%2][j]<<" ";
                dp[i%2][j] = dp[(i -1) % 2][j + 1];
                MOD(dp[i%2][j]);
                if(tab[i] == '('&&j)dp[i%2][j] += dp[(i -1) % 2][j - 1];
                MOD(dp[i%2][j]);
            }
        }
        //   cout<<endl;
    }
    printf("%d",dp[n%2][0]);
}
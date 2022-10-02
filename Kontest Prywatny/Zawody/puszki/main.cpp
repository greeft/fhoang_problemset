#include <bits/stdc++.h>
using namespace std;
long long n,k,a,tab[502][502],dp[502][502],dp2[502][502],wynik;

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i =1;i  <=n;++i)
    {
        for(int j = 1; j <= n-i+1;++j)
        {
            scanf("%lld",&a);
            tab[i][j]=a;
        }
    }
   // cout<<endl;
    for(int i = n; i>0;--i)
    {
        for(int j =1; j<=n ;++j)
        {
           // cout<<tab[i][j]<<" ";
            dp[i][j] = tab[i][j]+ dp[i+1][j-1]+dp[i+1][j]-dp[i+2][j-1];
        }
        //cout<<endl;
    }
    /*/
    cout<<endl;
    for(int i =1;i  <=n;++i)
    {
        for(int j = 1; j <= n-i+1;++j)
        {
          cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    /*/
    for(long long i =1; i <=n;++i)
    {
        for(long long j =1; j <= k;++j)
        {
            for(long long ki =0;ki < i;++ki)
            {
                dp2[i][j] = max(dp2[i][j],dp2[ki][j-1] + dp[1][i] - dp[i-ki+1][min(i,ki)]);
            }
            wynik = max(wynik,dp2[i][j]);
        }
    }
    printf("%lld",wynik);
}
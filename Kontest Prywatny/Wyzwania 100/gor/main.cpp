#include <bits/stdc++.h>
using namespace std;
//pozycja,wysokosc,liczba szczytow, kierunek 0 w dol
int n,r,k,dp[42][22][22][4];

int main()
{
    scanf("%d%d%d",&n,&r,&k);
    dp[0][0][0][1]=1;
    for(int pozycja = 1; pozycja <=2*n;++pozycja)
    {
        for(int wysokosc = 0; wysokosc<=n;++wysokosc)
        {
            for(int liczba_szczytow =0; liczba_szczytow <=r;++liczba_szczytow)
            {
                 if(wysokosc)  dp[pozycja][wysokosc][liczba_szczytow][1]+=dp[pozycja-1][wysokosc-1][liczba_szczytow][0]+dp[pozycja-1][wysokosc-1][liczba_szczytow][1];
                if(wysokosc==k-1)
                {
                    dp[pozycja][wysokosc][liczba_szczytow][0]+=dp[pozycja-1][wysokosc+1][liczba_szczytow][0];
                    dp[pozycja][wysokosc][liczba_szczytow+1][0]+=dp[pozycja-1][wysokosc+1][liczba_szczytow][1];
                }
                else
                {
                    dp[pozycja][wysokosc][liczba_szczytow][0]+=dp[pozycja-1][wysokosc+1][liczba_szczytow][0]+dp[pozycja-1][wysokosc+1][liczba_szczytow][1];
                }
            }
        }
    }
    printf("%d",dp[2*n][0][r][0]);
}
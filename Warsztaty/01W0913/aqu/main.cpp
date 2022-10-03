#include <bits/stdc++.h>
#define ll long long
using namespace std;
constexpr int MAX_N =  (301) << 1;
int n,r,x,y,l,tab[MAX_N][MAX_N],shifted[MAX_N][MAX_N];
ll dp[MAX_N][MAX_N],value;
int main()
{
    scanf("%d%d",&n,&r);
    for(int i =1;i<=n;++i) {
        for (int j = 1; j <= n; ++j)
        {
            scanf("%d",&tab[i][j]);
            shifted[j + i][i - j + MAX_N] = tab[i][j];
        }
    }
    for(int i = 1;i< MAX_N;++i)
        {
        for(int j =1;j< MAX_N;++j)
        {
          //  cout<<tab[i][j]<<" ";
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + shifted[i][j];
        }
       // cout<<endl;
    }
    for(int h = 1; h<= r;++h)
    {
        scanf("%d%d%d",&x,&y,&l);
        int x_p = x - y + MAX_N;
        int y_p = x + y + 1;
        //dolny
       int x_d = min(x_p + l,MAX_N -1);
       int y_d = min(y_p + l, MAX_N - 1);
       //gorny
       int x_g = max(x_p - l,1);
       int y_g = max(x_p - l, 1);
       value = dp[y_d][x_d] - dp[y_d][x_g - 1] - dp[y_g - 1][x_d] + dp[y_g - 1][x_g - 1];
        printf("%lld\n",value);
    }



}
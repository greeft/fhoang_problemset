#include <bits/stdc++.h>
using namespace std;
int n,t,dp[302][302][200],x,y,z;

int main()
{
	scanf("%d",&n);
	for(int i = 1;i<=n;++i)
	{
		for(int j = 1;j <= n;++j)
		{
			scanf("%d",&dp[i][j][0]);
		}
	}
		for(int k = 1; k <= n;++k)
		{
			for(int i = 1;i<=n;++i)
			{
				for(int j = 1; j<= n;++j)
				{
						dp[i][j][k] = max(dp[i][j][k],  dp[i - 1][j][k - 1]);
						dp[i][j][k] = max(dp[i][j][k],  dp[i + 1][j][k - 1]);
						
						dp[i][j][k] = max(dp[i][j][k],  dp[i][j - 1][k - 1]);
						dp[i][j][k] = max(dp[i][j][k],  dp[i][j + 1][k - 1]);
				}
			}
		}
	scanf("%d",&t);
	for(int i = 1;i<=t;++i)	
	{
		scanf("%d%d%d",&x,&y,&z);
		printf("%d\n",dp[x][y][z]);
	}
}

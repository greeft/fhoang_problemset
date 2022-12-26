#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1000001;
char c;
int dp[MAX_N],n,how_manyw,value;

int main()
{
	scanf("%d\n",&n);
	for(int i = 1;i<=n;++i)
	{
		scanf("%c",&c);
		if(c == 'X')++dp[i];
		else how_manyw++;
		dp[i] += dp[i - 1];
	}
	value = 1e9;
	for(int i = 1;i<= (n >> 1);++i)
	{
		value = min(value,dp[i + (n >>1) -1] - dp[i -1]);
	}
	printf("%d",how_manyw + value);
}

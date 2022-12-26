#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
constexpr int MAX_N = 1e5 + 1;
int n,k,m,mask_he = 1,q,a,b,c;
ll p,cost[MAX_N][6],dp[MAX_N][1 << 6],value = 1e18;
vector <pair<int,ll>> graph[MAX_N]; 
vector <int> cities;
priority_queue<pair<long long, int >> pq;
void djikstra(int s,int v)
{
	for(int i = 1; i <=n;++i)cost[i][v] = 1e18;
	pq.push({0,s});
	while(!pq.empty())
	{
		p = -pq.top().ff;
		q = pq.top().ss;
		pq.pop();
		if(p < cost[q][v])
		{
			cost[q][v] = p;
			for(auto u : graph[q])pq.push({-(u.ss + cost[q][v]),u.ff});
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i = 1;i<=k;++i)
	{
		scanf("%d",&a);
		cities.emplace_back(a);
	}
	for(int i = 1; i <=m;++i)
	{
		scanf("%d%d%d",&a,&b,&c);	
		graph[a].emplace_back(b,c);
		graph[b].emplace_back(a,c);
	}
	
	for(int i = 1;i<=k;++i)
	{
		djikstra(cities[i],i);	
	}
	
	for(int i = 1; i <= k; ++i)
	{
		for(int a = 1; a <= n; ++a)
		{
			dp[a][mask_he] = cost[a][i];
		}
		mask_he <<=1;
	}
	for(int mask = 1; mask < (1 << (k + 1));++mask)
	{
		for(int a = 1; a <= n;++a)
		{
			if(__builtin_popcount(mask)  > 1)dp[a][mask] = 1e18;
			for(int submask = mask; submask; --submask)
			{
				if((mask | submask) == mask)
				{
					dp[a][mask] = min(dp[a][mask],dp[a][submask] + dp[a][mask - submask]);
				}
			}
			for(auto u : graph[a])pq.push({-(dp[a][mask] + u.ss),u.ff});
		} 	
		while(!pq.empty())
		{
			p = - pq.top().ff;
			q = pq.top().ss;
			pq.pop();
			if(p < dp[q][mask])
			{
				dp[q][mask] = p;
				for(auto u : graph[q])pq.push({-(p + u.ss),u.ff});
			}
		}
	} 
	for(int i = 1;i <=n;++i)value = min(value,dp[i][(1 << k) - 1]);
	printf("%lld",value);
}

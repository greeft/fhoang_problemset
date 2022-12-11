#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 301;
int n,m,k,a,b,val,edges[MAX_N];
queue <int> q;
int function(int k_l,bool* tab,int* edges_l)
{
	
	for(int i = 1;i <= n;++i)if(edges_l[i])q.push(i);
	while(!pq.empty())
	{
		int v = q.top();
		q.pop();
		for(auto u : graph[v])
		{
			--edges[u];		
			if(!edges[u])
			{
							
			}
		}
	
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);
		graph[a].emplace_back(b);
		edges[b]++;
	}	
	

}

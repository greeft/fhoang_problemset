#include <bits/stdc++.h>
#define ll long long 
using namespace std;
constexpr ll MAX_N = 1e6 + 2;
ll n,l[MAX_N],iter;
ll value,value2;
priority_queue <pair<ll,ll>> pq;
pair<ll,ll> p;
int main()
{
	scanf("%d",&n);
	for(int i= 1;i<=n;++i)
	{
		scanf("%d",&l[i]);
	}
	for(int i = 2;i <=n;++i)
	{
		if(!l[i])pq.push({l[i - 1] - l[i - 2], i - 1});
	}	
	for(int i = 1;i  <n;++i)
	{
		if(!l[i])pq.push({l[i + 1] - l[i + 2],i +1});
	}

	while(!pq.empty())
	{
		++iter;
		p = pq.top();
		pq.pop();
		//cout<<p.second<<endl;
		if(!l[p.second])continue;
		if(iter%2)value += l[p.second];
		else value2 += l[p.second];
		l[p.second] = 0;
		if(p.second + 1 <= n && l[p.second + 1])pq.push({l[p.second + 1] - l[p.second + 2], p.second+ 1});
		else if(p.second - 1 >= 1 && l[p.second -1])pq.push({l[p.second - 1] - l[p.second - 2],p.second - 1});
	}
	printf("%lld %lld",value,value2);
}

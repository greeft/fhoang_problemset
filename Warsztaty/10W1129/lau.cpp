#include <bits/stdc++.h>
using namespace std;
constexpr int N = 262143;
constexpr int MAX_N = 1e5 + 1;
int n,q,tree[(N + 1) << 1][2][27];
void push(int w,int l)
{
	tree[w << 1][0][l] += tree[w][1][l];
	tree[w << 1][1][l] += tree[w][1][l];
	tree[(w << 1) + 1][0][l] += tree[w][1][l];
	tree[(w << 1) + 1][1][l] += tree[w][1][l];
	tree[w][1][l] = 0;
}
// p wierz k wierz, x query y 
void add(int w,int l, int p,int k,int x,int y,int val)
{
	if(p > y || k < x)return;
	else if(x<=p && y<=k)
	{
		tree[w][0][l] += val;
		tree[w][1][l] += val;
		return;
	}
	if(w <= N)push(w,l);
	add(w << 1, l , p , (p + k) >> 1,x,y,val);
	add((w << 1) + 1, l , ((p + k) >> 1) + 1, x , y , val);
}
int query(int w,int l, int p,int k,int x,int y)
{
	if(p > y || k < x)return;
	else if(x<=p && y<=k)
	{
		return tree[w][0][l];
	}
	if(w <= N)push(w,l);
	return query(w << 1, l , p , (p + k) >> 1,x,y) + add((w << 1) + 1, l , ((p + k) >> 1) + 1, x , y);
}
int main()
{
	scanf("%d%d\n",&n,&q);
	for(int i = 1;i<=n;++i)
	{
	
	}

}

#include <bits/stdc++.h>
using namespace std;

int n,m,k,x,y,prefix_sum[20001][20001];
struct point{
    int x;
    int y;
};
vector <point> vertexes,points;
point p;
int main()
{
    vertexes.push_back({0,0});
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;++i)
    {
        scanf("%d%d",&p.x,&p.y);
        vertexes.emplace_back(p);
    }
    points.push_back({0,0});
    for(int i =1;i<=k;++i)
    {
        scanf("%d%d",&p.x,&p.y);
        points.emplace_back(p);
    }
    for(int i =1;i<=n;++i)
    {

    }
}
#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 4001;
int h,w,cost[MAX_N][MAX_N],x,y,value;
char tab[MAX_N][MAX_N];
deque <pair<int,int>> dq;
int main()
{
    cin>>h>>w;
    for(int i =1;i<=h;++i)
    {
        for(int j = 1; j <=w;++j){
            cin>>tab[i][j];
        }

    }
    for(int i =1; i <= h;++i)
    {
        for(int j = 1; j<= w;++j)cost[i][j] = 1e9;
    }
    dq.emplace_back(1,1);
    cost[1][1] = 1;
    while(!dq.empty())
    {
        x = dq.front().first;
        y = dq.front().second;
        cout<<x<<" "<<y<<" "<<cost[x][y]<<" "<<endl;
        dq.pop_front();
        if(tab[x][y] == '.')continue;
        value = max(value,cost[x][y]);
        // x - 1   y
        if((x - 1) && tab[x][y] == tab[x - 1][y] && cost[x - 1][y] > cost[x][y])
        {
            dq.push_front({x - 1,y});
            cost[x - 1][y] = cost[x][y];
        }
        else if((x - 1) && cost[x - 1][y] > cost[x][y] + 1)
        {
            dq.emplace_back(x - 1,y);
            cost[x - 1][y] = cost[x][y] + 1;
        }

        //x    y -1
        if((y - 1) && tab[x][y] == tab[x][y - 1] && cost[x][y - 1] > cost[x][y])
        {
            dq.push_front({x ,y - 1});
            cost[x][y - 1] = cost[x][y];
        }
        else if((y - 1) && cost[x][y - 1] > cost[x][y] + 1)
        {
            dq.emplace_back(x,y - 1);
            cost[x][y - 1] = cost[x][y] + 1;
        }
        // NA PRAWO
        if((x + 1) <= h && tab[x][y] == tab[x + 1][y] && cost[x + 1][y] > cost[x][y])
        {
            dq.emplace_back(x + 1,y);
            cost[x + 1][y] = cost[x][y] + 1;
        }
        //x    y -1
        if((y + 1) <= w && tab[x][y] == tab[x][y + 1] && cost[x][y + 1] > cost[x][y])
        {
            dq.push_front({x ,y + 1});
            cost[x][y] = cost[x][y + 1];
        }
        else if((y + 1) <= w && cost[x][y + 1] > cost[x][y] + 1)
        {
            dq.emplace_back(x,y + 1);
            cost[x][y + 1] = cost[x][y] + 1;
        }
    }
    cout<<value<<endl;
}
#include <bits/stdc++.h>
using namespace std;

int n,m,visited[101][101][2],x,y,direction,k,cycle_size,iteration;
char tab[101][101];
int main()
{
    cin>>n>>m;
    for(int i =1; i <=n;++i)
    {
        for(int j =1; j <=m;++j)
        {
            cin>>tab[i][j];
        }
    }
    cin>>x>>y>>k;
    while(!visited[x][y][0]||visited[x][y][1] !=direction&&k)
    {
      //  cout<<x<<" "<<y<<" "<<tab[x][y]<<endl;
        ++iteration;
        if(tab[x][y]=='F')
        {
            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(tab[x][y]=='R')
        {
            ++direction;
            if(direction ==4)direction = 0;

            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(tab[x][y]=='L')
        {
            --direction;
            if(direction ==-1)direction = 3;

            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(visited[x][y][0]&&visited[x][y][1] ==direction)
        {
            cycle_size = iteration - visited[x][y][0];
        }
        else
        {
            visited[x][y][0] = iteration;
            visited[x][y][1] = direction;
        }
        --k;
    }
    ++cycle_size;
    k%=cycle_size;
    while(k)
    {
        ++iteration;
        if(tab[x][y]=='F')
        {
            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(tab[x][y]=='R')
        {
            ++direction;
            if(direction ==4)direction = 0;

            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(tab[x][y]=='L')
        {
            --direction;
            if(direction ==-1)direction = 3;

            if(direction ==0)
            {
                if(y -1 == 0 )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction ==1)
            {
                if(x + 1 > m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction==2)
            {
                if(y + 1 == n )
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else
            {
                if(x - 1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        if(visited[x][y][0]&&visited[x][y][1] ==direction)
        {
            cycle_size = iteration - visited[x][y][0];
        }
        else
        {
            visited[x][y][0] = iteration;
            visited[x][y][1] = direction;
        }
        --k;
    }
    cout<<x<<" "<<y<<endl;

}
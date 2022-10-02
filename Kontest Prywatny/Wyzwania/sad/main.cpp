#include <bits/stdc++.h>
using namespace std;
int n,m,direction,visited[101][101][2],x,y,it,cycle_size;
long long k;
char c,tab[101][101];
int main()
{
    cin>>n>>m;
    for(int i =1; i <=n;++i)
    {
       for(int j =1; j<=m;++j)
       {
           cin>>tab[i][j];
       }
    }
    cin>>x>>y>>k;
    while(!visited[x][y][0]&&visited[x][y][1]==direction)
    {
        ++it;
        visited[x][y][0]=it;
        visited[x][y][0] = direction;
        if(tab[x][y] == 'F')
        {
            if(direction ==0)
            {
                if(y -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction == 1)
            {
                if(x + 1  < m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction == 2)
            {
                if(y + 1  < n)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else if(direction ==3)
            {
                if(x -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        else if(tab[x][y]=='R')
        {
            ++direction;
            direction%=4;
                if(direction ==0)
                {
                    if(y -1 == 0)
                    {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                    --y;
                }
                else if(direction == 1)
                {
                    if(x + 1  < m)
                    {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                    ++x;
                }
                else if(direction == 2)
                {
                    if(y + 1  < n)
                    {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                    ++y;
                }
                else if(direction ==3)
                {
                    if(x -1 == 0)
                    {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                    --x;
                }
        }
        else if(tab[x][y] == 'F')
        {
            --direction;
            if(direction < 0) direction= 3;
            if(direction ==0)
            {
                if(y -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction == 1)
            {
                if(x + 1  < m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction == 2)
            {
                if(y + 1  < n)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else if(direction ==3)
            {
                if(x -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
    }
    cycle_size = it - visited[x][y][0];
    k%=cycle_size;
    while(k--)
    {
        if(tab[x][y] == 'F')
        {
            if(direction ==0)
            {
                if(y -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction == 1)
            {
                if(x + 1  < m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction == 2)
            {
                if(y + 1  < n)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else if(direction ==3)
            {
                if(x -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        else if(tab[x][y]=='R')
        {
            ++direction;
            direction%=4;
            if(direction ==0)
            {
                if(y -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction == 1)
            {
                if(x + 1  < m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction == 2)
            {
                if(y + 1  < n)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else if(direction ==3)
            {
                if(x -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        else if(tab[x][y] == 'F')
        {
            --direction;
            if(direction < 0) direction= 3;
            if(direction ==0)
            {
                if(y -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --y;
            }
            else if(direction == 1)
            {
                if(x + 1  < m)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++x;
            }
            else if(direction == 2)
            {
                if(y + 1  < n)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                ++y;
            }
            else if(direction ==3)
            {
                if(x -1 == 0)
                {
                    cout<<x<<" "<<y<<endl;
                    return 0;
                }
                --x;
            }
        }
        //--k;
    }
    cout<<x<<" "<<y<<endl;
}
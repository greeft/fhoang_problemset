#include <bits/stdc++.h>
using namespace std;
int H,current_level = 1;
vector<vector<int>> tab = {{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0},{0,0,0,0,0,0,0}};
char desribtion[7][2][7];
vector <vector<vector<int>>> combinations[7];
void check()
{
    int colour[10] = {0,0,0,0,0,0,0,0,0};
    int y = 6;
    int x = 6;
    bool if_possible = true;
    for(int i = 1;i<=6;++i)
    {
        y = 6;
        if(desribtion[current_level][0][i] == '.')
        {
            while(y)if(tab[i][y])
                {
                    if_possible = false;
                    break;
                }
            if(!if_possible)break;
        }
        else
        {
            while(y&&!tab[i][y])
            {
                if(tab[i][y])
                {
                    if(colour[tab[i][y]])
                    {
                        if(colour[tab[i][y]] != desribtion[current_level][0][i])
                        {
                            if_possible = false;
                            return;
                        }
                    }
                    else
                    {
                        colour[tab[i][y]] = desribtion[current_level][0][i];
                        continue;
                    }
                }
                if(!if_possible)return;
                --y;
            }
        }
        if(!if_possible)return;
    }
    if(!if_possible)return;
    for(int i = 1;i<=6;++i)
    {
        x = 6;
        if(desribtion[current_level][0][i] == '.')
        {
            while(x)if(tab[x][i])
                {
                    if_possible = false;
                    break;
                }
            if(!if_possible)break;
        }
        else
        {
            while(x&&!tab[x][i])
            {
                if(tab[x][i])
                {
                    if(colour[tab[x][i]])
                    {
                        if(colour[tab[x][i]] != desribtion[current_level][0][i])
                        {
                            if_possible = false;
                            return;
                        }
                    }
                    else
                    {
                        colour[tab[x][i]] = desribtion[current_level][0][i];
                        continue;
                    }
                }
                if(!if_possible)return;
                --y;
            }
        }
        if(!if_possible)return;
    }
    if(!if_possible)return;
    combinations[current_level].push_back(tab);
}
void generate(int x,int y,int kloc)
{

    for(int i = x; i <=5;++i)
    {
        for(int j = 1; j<= 5;++j)
        {
            tab[i][j] = kloc;
            tab[i + 1][j] = kloc;
            tab[i][j + 1] = kloc;
            tab[i + 1][j + 1] = kloc;
            generate(i + 2,j + 2,kloc + 1);
            tab[i][j] = kloc;
            tab[i + 1][j] = 0;
            tab[i][j + 1] = 0;
            tab[i + 1][j + 1] = 0;
            generate(i + 2,j + 2,kloc);
        }
    }
    if(x > 1|| y > 1)
    {
        for(int i = 1; i<= 5;++i)
        {
            for(int j = y; j <= 5;++j)
            {
                tab[i][j] = kloc;
                tab[i + 1][j] = kloc;
                tab[i][j + 1] = kloc;
                tab[i + 1][j + 1] = kloc;
                generate(i + 2,j + 2,kloc + 1);
                tab[i][j] = kloc;
                tab[i + 1][j] = 0;
                tab[i][j + 1] = 0;
                tab[i + 1][j + 1] = 0;
                generate(i + 2,j + 2,kloc);
            }
        }
    }
}
int main()
{
    scanf("%d",&H);
    for(int f = 1;f<=H;++f)
    {
        for(int i = 1;i<=6;++i)
        {
            scanf("%d",desribtion[i][0][f]);
        }
        for(int i = 1;i<=6;++i)
        {
            scanf("%d",desribtion[i][1][f]);
        }
    }
    generate(1,1,1);
    printf("%d",combinations[1].size());
}
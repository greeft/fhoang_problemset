#include <bits/stdc++.h>
using namespace std;
int n,m,k,l,x ,y,x_current = 1,y_current = 1,delta_x,delta_y,alph;
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    char tab[n][m];
    scanf("%d%d",&x_current,&delta_y);
    for(int i = 1; i <k;++i)
    {
        scanf("%d%d",&x,&y);
        delta_x = x - x_current;
        delta_y = y- y_current;
        cout<<delta_x<<" "<<delta_y;
        while(delta_x&&delta_y)
        {
            if(delta_x&&delta_y)
            {
                tab[x_current][y_current] = char(alph + 'A');
                ++alph;
                alph%=26;
                if(delta_y > 0)
                {
                    ++y_current;
                    delta_y--;
                }
                 if(delta_y < 0)
                {
                    --y_current;
                    delta_y++;
                }

                if(delta_x > 0)
                {
                    ++x_current;
                    delta_x--;
                }
                if(delta_x < 0)
                {
                    --x_current;
                    delta_x++;
                }
            }
        }
    }
    for(int i = 1; i <=n;++i)
    {
        for(int j =1; j <=m;++j)
        {
            if(tab[i][j] == NULL)cout<<". ";
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

}
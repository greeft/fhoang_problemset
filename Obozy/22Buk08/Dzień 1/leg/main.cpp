
// zaleznosc punktow od linijek kodu w zadaniu to 2 ^ x
#include <bits/stdc++.h>
#define s short
using namespace std;
short h;
char tab[7][7][2];
s board[7][7],l_local[7][7],kloc_numer;
vector<pair<char[7][7],s>> combinations[7];
void f(s i_l,s j_l,s kloc[10])
{
    ++kloc_numer;
    for(int i = i_l;i<=5;++i)
    {
        for(int j =j_l;j<=5;++j)
        {
            if(board[i -1][j]||board[i - 1][j - 1]||board[i][ j -1])continue;
            for(int x = 1;x<=6;++x)
            {
                for(int y = 1;y<=6;++y)l_local[x][y] =board[x][y];
            }
        }
    }
}
int main()
{
    scanf("%d",&h);
    for(int hi = 1; hi <=h;++hi)
    {
        for(int i =1;i<=6;++i)
        {
            scanf("%d",&tab[hi][i][0]);
        }
        scanf("\n");
        for(int i =1;i<=6;++i)
        {
            scanf("%d",&tab[hi][i][1]);
        }
        scanf("\n");
    }

}
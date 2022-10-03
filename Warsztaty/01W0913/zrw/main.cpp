#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1e6 + 2;

int n,m,a,value;
char tab[MAX_N];
int main()
{
    cin>>n>>m;
    tab[0] = '0';
    tab[n + 1] = '0';
    for(int i =1;i<=n;++i)
    {
       cin>>tab[i];
        if(tab[i] != tab[i - 1])++value;
    }
    cout<<value<<endl;
    for(int h = 1;h<=m;++h)
    {
        cin>>a;
        if(a == 1)
        {
            if(tab[1] == '0')
            {
                if(tab[2] == '0')++value;
                else if(tab[2] == '1')--value;
                tab[1] = '1';
            }
            else
            {
                if(tab[2] == '0')value--;
                else if(tab[2] == '1')++value;
                tab[1] = '0';
            }
        }
        else if(a == n)
        {
            if(tab[n] == '0')
            {
                if(tab[n - 1] == '0')value+=2;
                tab[n] = '1';
            }
            else
            {
                if(tab[n -1] == '0')value-=2;
                tab[n] = '0';
            }
        }
        else
        {
            if(tab[a] == '1')
            {
                if(tab[a - 1] == tab[a + 1]&& tab[a - 1] == '1')value+=2;
                else if(tab[a - 1] == tab[a + 1]&& tab[a - 1] == '0')value-=2;
                tab[a] = '0';
            }
            else
            {
                if(tab[a - 1] == tab[a + 1]&& tab[a - 1] == '1')value-=2;
                else if(tab[a - 1] == tab[a + 1]&& tab[a - 1] == '0')value+=2;
                tab[a] = '1';
            }
        }
        cout<<value<<endl;
    }
}
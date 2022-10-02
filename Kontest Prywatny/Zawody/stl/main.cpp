#include <bits/stdc++.h>
using namespace std;
char c,tab[401][401];
int r,s,prefix[401][401],wynik, dluglosc,szerokosc;
int main()
{
    cin>>r>>s;
    for(int i =1; i <=r;++i)
    {
        for(int j =1; j<=s;++j)
        {
            cin>>c;
            tab[i][j] =c;
            if(c =='.')
            {
                prefix[i][j] = prefix[i][j-1]+1;
            }
        }
    }
    /*/
    for(int i =1;i <=r;++i)
    {
        for(int j =1; j <=s;++j)
        {
            cout<<prefix[i][j]<<" ";
        }
        cout<<endl;
    }
    /*/
    for(int i = 1; i <=r;++i)
    {
        for(int j =1;j <=s;++j)
        {
            int current_length=2137420;
            int local_ans = 0;
            for(int k = i; k;--k)
            {
                if(tab[k][j]=='X')break;
                current_length = min(current_length,prefix[k][j]);
               // cout<<current_length<<endl;
                local_ans = max(current_length * 2 + (i-k+1) * 2, local_ans);
            }
            wynik = max(wynik,local_ans);
        }
    }
    cout<<wynik-1<<endl;
}
#include <bits/stdc++.h>
using namespace std;
int n,w,k,value;
map<int,bool> x,y;
int main()
{
    cin>>n;
    for(int i =1;i<=n;++i)
    {
        cin>>w>>k;
        if(!x[w]&&!y[k])
        {
            ++value;
            x[w] = true;
            y[k] = true;
        }
    }
    printf("%d",value);

}
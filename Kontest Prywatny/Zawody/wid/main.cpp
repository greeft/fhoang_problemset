#include <bits/stdc++.h>
using namespace std;

long long n,tab[500001],value,pairs;
deque <pair<long long,long long>> dq;
int main()
{
    scanf("%lld",&n);

    for(int i = 1;i<=n;++i)
    {
        scanf("%lld",&tab[i]);
    }

    for(int i =1;i <=n;++i)
    {
        //cout<<value<<endl;
        pairs = 1;
        while(!dq.empty()&&dq.back().first < tab[i])
        {
            // cout<<i<<" "<<dq.back().first<<" "<<dq.back().second<<endl;
            value += dq.back().second;
            pairs+=dq.back().second;
            dq.pop_back();
        }
        if(dq.empty())
        {
            dq.push_back({tab[i],pairs});
            continue;
        }

            // cout<<i<<" "<<dq.back().first<<" "<<dq.back().second<<endl;
            value += dq.back().second;
            dq.push_back({tab[i],pairs});

    }
    printf("%lld",value);
}
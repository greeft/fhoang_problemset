/*/
 * Filip Hoang
 * Zadanie Równy podział
 * Złożoność O(n)
 */

#include <bits/stdc++.h>
using namespace std;
int n,pointer1=2,pointer2=3,pointer3=4;
long long prefix_sum[200001],wynik=9223372036854775807,localmin,localmax;
int main()
{
    scanf("%d",&n);
    for(int i =1;i <= n;++i)
    {
        scanf("%lld",&prefix_sum[i]);
        prefix_sum[i]+=prefix_sum[i-1];
        //cout<<prefix_sum[i]<<" ";
    }
    localmax =max(max(prefix_sum[pointer1-1], prefix_sum[pointer2-1] - prefix_sum[pointer1-1]),max( prefix_sum[pointer3-1] - prefix_sum[pointer2-1],prefix_sum[n] - prefix_sum[pointer3-1]));
    localmin = min(min(prefix_sum[pointer1-1], prefix_sum[pointer2-1] - prefix_sum[pointer1-1]),min( prefix_sum[pointer3-1] - prefix_sum[pointer2-1],prefix_sum[n] - prefix_sum[pointer3-1]));
    wynik = min(wynik,localmax - localmin);
    while(pointer3 <=n)
    {
        //cout<<pointer1<<" "<<pointer2<<" "<<pointer3<<endl;
        localmin = min(min(prefix_sum[pointer1-1], prefix_sum[pointer2-1] - prefix_sum[pointer1-1]),min( prefix_sum[pointer3-1] - prefix_sum[pointer2-1],prefix_sum[n] - prefix_sum[pointer3-1]));
        if(prefix_sum[pointer1-1] == localmin)
        {
            ++pointer1;
            if(pointer1 == pointer2)
            {
                ++pointer2;
                if(pointer2 == pointer3)++pointer3;
            }
        }
        else if(prefix_sum[pointer2-1] - prefix_sum[pointer1-1] == localmin)
        {
            ++pointer2;
            if(pointer2 == pointer3)++pointer3;
        }
        else
        {
            ++pointer3;
        }
        if(pointer3 >n)break;
        localmax =max(max(prefix_sum[pointer1-1], prefix_sum[pointer2-1] - prefix_sum[pointer1-1]),max( prefix_sum[pointer3-1] - prefix_sum[pointer2-1],prefix_sum[n] - prefix_sum[pointer3-1]));
        localmin = min(min(prefix_sum[pointer1-1], prefix_sum[pointer2-1] - prefix_sum[pointer1-1]),min( prefix_sum[pointer3-1] - prefix_sum[pointer2-1],prefix_sum[n] - prefix_sum[pointer3-1]));
       // cout<<pointer1<<" "<<pointer2<<" "<<pointer3<<":"<<endl;
        //cout<<prefix_sum[pointer1-1]<<" "<<prefix_sum[pointer2-1] - prefix_sum[pointer1-1]<<" "<<prefix_sum[pointer3-1] - prefix_sum[pointer2-1]<<" "<<prefix_sum[n] - prefix_sum[pointer3-1]<<endl;
        wynik = min(wynik,localmax - localmin);
    }
    printf("%lld",wynik);
}
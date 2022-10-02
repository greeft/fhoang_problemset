#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
uint_fast32_t n,a,value;
vector <pair<uint_fast32_t,uint_fast32_t>> v;
vector<uint_fast32_t> prime;
bitset<100001>if_prime;
int main()
{
    scanf("%d",&n);

    for(uint_fast32_t i = 2; i * i <= 100000;++i)
    {
        if(if_prime[i])continue;
        for(uint_fast32_t j = i*i;j <=100000;j+=i)if_prime[j]= true;
    }
    //cout<<"OK"<<endl;
    for(uint_fast32_t i =2; i<=100000;++i) {
        if (!if_prime[i]) {
            prime.push_back(i);
        }
    }

    for(uint_fast32_t i =0; i <n;++i)
    {
        scanf("%d",&a);
        value=0;
        uint_fast32_t  a1 = a;
        for(uint_fast32_t j =0; a  >= prime[j] *prime[j];++j)
        {
            //  if(a == prime[j])continue;
            if(a1%prime[j]==0)
            {
                while(a1%prime[j]==0)a1/=prime[j];
                value++;
            }
        }
        if(!if_prime[a1]&&a1!=a&&a1!=1)++value;
        v.emplace_back(value,a);
    }
    sort(v.begin(),v.end());
    for(uint_fast32_t i =0;i < v.size();++i)
    {
        printf("%d ",v[i].second);
    }
}
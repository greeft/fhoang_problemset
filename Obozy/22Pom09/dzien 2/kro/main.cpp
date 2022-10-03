#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr ll mod = 1e9 + 7;
ll q, x,y,fib[89],value;
vector <pair<ll,ll>> k[89];
int main()
{
    cin >> q;
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2;i <=90;++i)fib[i] = fib[i - 1] + fib[i - 2];
    k[1].emplace_back(1,2);
    for(int i = 1;i < 88;++i)
    {
       // cout<<i<<" "<<k[i].size()<<endl;
        for(auto u : k[i])
        {
            ll b = max(u.first,u.second);
            ll a = min(u.first,u.second);
            k[i + 1].emplace_back(b,a + b);
        }
        k[i + 1].emplace_back(fib[i + 2],fib[i + 2] + fib[i]);
    }
   // cout<<"AAAAAAAAAAAAAAAAAAAAAAA"<<endl;
    while(q) {
        --q;
        cin >> x >> y;
        if (x > y)swap(x, y);
        int current_k = 88;
        value = 0;
        //cout << endl;
        while (fib[current_k] > x || fib[current_k + 1] > y)--current_k;
        if (x == 1 && y == 1)current_k = 1;
        for (auto u: k[current_k]) {
            ll a = u.first;
            ll b = u.second;
            //cout<<a<<" "<<b<<endl;
            if (b <= y && a <= x) {
                value += (((y - b) / a) + 1)%mod;
            }
            swap(a, b);
            if (b <= y && a <= x) {
                value += (((y - b) / a) + 1)%mod;
            }
        }
        if(x ==1||y == 1)++value;
        if(x ==2&&y == 2)
        {
            current_k = 1;
            value = 4;
        }
        cout<<current_k<<" "<<value%mod<<endl;
    }
}
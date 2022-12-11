/*/
#include <bits/stdc++.h>
constexpr int MAX_N = 1e5 + 1;
int n,a,value;
std::map <int,int> tab;
std::vector<int> v;
int main() {
    std::cin>>n;
    for(int i = 0;i<n;++i){std::cin>>a;v.emplace_back(a),tab[a] = i;}
    std::sort(v.begin(),v.end());
    for(int i =0; i< n;++i)if(((i ^ tab[v[i]])&1))++value;
    std::cout<<(value >> 1);
}
/*/
#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 1;
constexpr void stasiek(int* tab[])
{
    *tab[1] = 1;
    for(int i = 1;i<=N;++i)
    {
        if(*tab[i])continue;
        for(int j = i * i; i < N;++j)
        {
            *tab[i] = 1;
        }
    }
}
int main()
{
    stasiek(constexpr int if_prime[MAX_N]);
}
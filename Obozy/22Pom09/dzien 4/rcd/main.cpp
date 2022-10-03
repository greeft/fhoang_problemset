#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2500001;
long long n,u,v,size[MAX_N],centroid,dp[MAX_N][3];
long long max_value;
vector <int> graph[MAX_N];
unordered_map<long long,long long> sizes;
int get_size(int a,int b)
{
    size[a]  = 1;
    for(auto u : graph[a])
    {
        if(u == b)continue;
        size[a] += get_size(u,a);
    }
    return size[a];
}
int get_centroid(int a,int b)
{
    for(auto u : graph[a])
    {
        if(u == b)continue;
        if(size[u] << 1> n)return get_centroid(u,a);
    }
    return a;
}
long long get_value(int a,int b)
{
     long long val;
    val = size[a] - 1;
    for(auto u : graph[a])
    {
        if(u == b)continue;
        val += get_value(u,a);
    }
    return val;
}
int main()
{
    scanf("%d",&n);
    for(int i =1;i<n;++i)
    {
        scanf("%d%d",&u,&v);
        graph[v].emplace_back(u);
        graph[u].emplace_back(v);
    }
    get_size(1,-1);
   centroid =  get_centroid(1,-1);
    get_size(centroid, - 1);
   // cout<<centroid<<endl;
    for(auto u : graph[centroid])
    {
        max_value += get_value(u,centroid);
        sizes[size[u]]++;
    }
    dp[0][0] = 1;
  //  ++max_value;
    for(auto u : sizes)
    {
        long long current_size = u.first;
        long long quantity = u.second;
        //  cout<<quantity<<" "<<current_size<<endl;
        // i 0 - czy wystapil w ogole
        //i 1 - ostatni ziutek dla ktorego wystepowal
        //ilosc obecnych ziutkow
        for(int i = 0; i <= n;++i) {

            if(dp[i][0])
            {
                if(dp[i][1] != current_size)
                {
                    dp[i][1] = current_size;
                    dp[i][2] = 0;
                    dp[i + current_size][0] = 1;
                    dp[i + current_size][1] = current_size;
                    dp[i + current_size][2] = dp[i][2] + 1;
                }
                if(dp[i][2] < quantity&&!(dp[i + current_size][0]))
                {
                    dp[i + current_size][0] = 1;
                    dp[i + current_size][1] = current_size;
                    dp[i + current_size][2] = dp[i][2] + 1;
                }
            }
        }
    }
   // for(int i = 0; i <= n;++i) cout<<i<<" "<<dp[i][0]<<" "<<dp[i][2]<<endl;
    long long a = (n - 1) >> 1;
    while(!dp[a][0])--a;
    long long b = n  - a + 1;
    ++a;
    //cout<<a<<" "<<b<<endl;
    max_value+= ( a * b) - a - 1;
  //  node = find_leave(1,-1);
   // calculate_min(node,-1,1);
    cout<<n - 1<<" "<<max_value<<endl;

}
#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 1501;
int n,a,b,m,k,size[MAX_N],bag[MAX_N][MAX_N][3],ans_bag[MAX_N][2];
vector <int> graph[MAX_N];
int get_size(int a,int b)
{
    ++size[a];
    for(auto u: graph[a])
    {
        if(u == b)continue;
        size[a] += get_size(u,a);
    }
    return size[a];
}
void count_dp(int a ,int b)
{
   // cout<<a<<":\n";
    int temp_bag[size[a] + 1][3];
    for(int i = 0;i<=size[a];++i)
    {
        temp_bag[size[a]][2] = 0;
        temp_bag[size[a]][1] = 0;
        temp_bag[size[a]][0] = 0;
    }
    temp_bag[size[a]][2] = graph[a].size() - 1;
    temp_bag[size[a]][1] = 0;
    temp_bag[size[a]][0] = 1;

    bag[a][size[a]][2] = graph[a].size() - 1;
    bag[a][size[a]][1] = 0;
    bag[a][size[a]][0] = 1;
    bag[a][0][0] = 1;
    for(auto u : graph[a]) {
        if (u == b)continue;
        count_dp(u, a);
        for (int i = 0; i <= size[a] - size[u]; ++i) {
            //  cout<<i<<endl;
           // cout << i << " " << u << " " << size[u] << endl;
            if (!bag[a][i][0])continue;
            for (int j = 1; j <= size[u]; ++j) {
                if (!bag[u][j][0])continue;
                if (!bag[a][i + j + 1][0]) {
                    temp_bag[i + j+ 1][0] = 1;
                    temp_bag[i + j+ 1][2] = bag[a][i][2] + 1;
                    temp_bag[i + j+ 1][1] = bag[a][i][1] + bag[u][j][1] + graph[a].size() - 1 - temp_bag[i + j+ 1][2];
                } else {
                    if (bag[a][i + j+ 1][1] > bag[a][i][1] + bag[u][j][1] - graph[a].size() + bag[a][i][2]) {
                        temp_bag[i + j+ 1][0] = 1;
                        temp_bag[i + j+ 1][2] = bag[a][i][2] + 1;
                        temp_bag[i + j+ 1][1] = bag[a][i][1] + bag[u][j][1] + graph[a].size() - 1 - temp_bag[i + j+ 1][2];
                    }
                    else if(bag[a][i + j + 1][1] == bag[a][i][1] + bag[u][j][1] - graph[a].size() + bag[a][i][2]) temp_bag[i + j+ 1][2] = max(temp_bag[i + j+ 1][2],bag[a][i][2] + 1);
                }
            }
        }
        for (int i = 1; i <= size[a]; ++i) {
            bag[a][i][0] = temp_bag[i][0];
            bag[a][i][1] = temp_bag[i][1];
            bag[a][i][2] = temp_bag[i][2];
        }
    }
    for (int i = 1; i <= size[a]; ++i) {
      // cout<<i<<" "<<bag[a][i][0]<<endl;
        bag[a][i][0] = temp_bag[i][0];
        bag[a][i][1] = temp_bag[i][1];
        bag[a][i][2] = temp_bag[i][2];
    }
    if(a != 1)
    {
        for(int i = 1;i<=size[a];++i)
        {
            if(!ans_bag[i][0])
            {
                ans_bag[i][0] = 1;
                ans_bag[i][1] = bag[a][i][1] + 1;
            }
            else
            {
                ans_bag[i][1] = min(ans_bag[i][1],bag[a][i][1] + 1);
            }
        }
    }
    else
    {
        for(int i = 1;i<=size[a];++i)
        {
            if(!bag[a][i][0])continue;
            if(!ans_bag[i][0])
            {
                ans_bag[i][0] = 1;
                ans_bag[i][1] = bag[a][i][1];
            }
            else
            {
                ans_bag[i][1] = min(ans_bag[i][1],bag[a][i][1]);
            }
        }
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i< n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    get_size(1,-1);
    count_dp(1, -1);
    scanf("%d",&m);
     for(int i = 1;i<=n;++i)cout<<ans_bag[i][1]<<" ";
    for(int i = 1;i<=m;++i)
    {
        scanf("%d",&k);
        printf("%d\n",ans_bag[k][1]);
    }
}
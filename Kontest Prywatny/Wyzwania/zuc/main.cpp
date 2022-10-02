/*/
 * Filip Hoang
 * Zadanie Żuczki
 * Rozwanie Wzorcowe w złożoności O(n + m)
 */
#include <bits/stdc++.h>
using namespace std;
vector <int> graph[50001];
int n,m,a,b,k,wynik = 2137420;
bool if_impossible;
bitset<50000> beattle;
pair<int,int> beattle_distance[50001];
int dfs(int a,int b)
{
    if(beattle[a])
    {
        if(beattle_distance[a].first)
        {
            if(beattle_distance[a].first % 2 != 1)
            {
                if_impossible = true;
                return 0;
            }
            else if(!beattle_distance[a].second)beattle_distance[a].second = 1;
        }
        else beattle_distance[a].first = 1;
    }
    for(auto u : graph[a])
    {
        if(u==b)continue;
       int max_subtree = dfs(u,a);
       if(if_impossible)return 0;
       if(!max_subtree)continue;
       if((max_subtree % 2) != (beattle_distance[a].first %2)&&beattle_distance[a].first)
       {
           if_impossible = true;
           return 0;
       }
       if(max_subtree >= beattle_distance[a].first)
       {
           swap(beattle_distance[a].first,beattle_distance[a].second);
           beattle_distance[a].first = max_subtree;
       }
       else if(beattle_distance[a].second < max_subtree) beattle_distance[a].second = max_subtree;

    }
   //cout<<" S "<<a<<" "<<beattle_distance[a].first<<" "<<beattle_distance[a].second<<endl;
    if(beattle_distance[a].first)return beattle_distance[a].first + 1;
    else return 0;
}
void dfs_count(int a, int b,int subtree_max,int beyond_max)
{
    wynik = min(wynik,max(subtree_max,beyond_max));
    //cout<<a<<" "<<subtree_max<<" "<<beyond_max<<endl;
    for(auto u : graph[a])
    {
        if(u==b)continue;
        if(beattle_distance[u].first + 1 == beattle_distance[a].first&&(beyond_max|| beattle_distance[a].second))dfs_count(u,a,beattle_distance[u].first,max(beyond_max + 1,beattle_distance[a].second +1));
        else if(beattle_distance[u].first + 1 == beattle_distance[a].first)dfs_count(u,a,beattle_distance[u].first,0);
        else if(beyond_max||beattle_distance[a].first)dfs_count(u,a,beattle_distance[u].first,max(beyond_max + 1,beattle_distance[a].first +1));
       else dfs_count(u,a,beattle_distance[u].first,0);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i =1;i < n;++i)
    {
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    scanf("%d",&k);
    for(int i =0;i <k;++i)
    {
        scanf("%d",&a);
        beattle[a] = true;
    }
    dfs(1,-1);
    if(if_impossible)
    {
        printf("NIE");
        return 0;
    }
    dfs_count(1,-1,beattle_distance[1].first,0);
    printf("%d",wynik-1);

}
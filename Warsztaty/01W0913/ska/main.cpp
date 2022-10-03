#include <bits/stdc++.h>
using namespace std;

int n,a,value,number;
int graph[1000001];
int visited[1000001];

void dfs(int a)
{
    if(visited[a] >= number)
    {
        value++;
        return;
    }
    if(visited[a]) return;

    visited[a]=number;
    dfs(graph[a]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&a);
        graph[i]=a;
    }
    for(int i=1; i<=n; i++)
    {
        number++;
        dfs(i);
    }
    cout << value;
}

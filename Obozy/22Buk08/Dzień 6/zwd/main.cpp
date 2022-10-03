#include <bits/stdc++.h>
using namespace std;

int n,k,c,result[501][2];
vector <int> value;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k>>c;
    for(int i =1;i<=n;++i)cin>>result[i][0];
    for(int i =1;i<=n;++i)cin>>result[i][1];
    for(int i =1;i<=n;++i)
    {
        for(int j =i + 1;j <=n;++j)value.emplace_back(max(result[i][0],result[j][0]) + max(result[i][1],result[j][1]));
    }
    sort(value.begin(),value.end());
    cout<<value[ c - 1];
}
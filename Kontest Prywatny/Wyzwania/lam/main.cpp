#include <bits/stdc++.h>
using namespace std;
priority_queue<pair< long double,int>> pq;
int n,k,d,id;
long double l,last;
long double wynik,used[100001],gaps[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(7) << showpoint;
    cin>>n>>k>>d;
    cin>>last;
    for(int i =1;i < n;++i)
    {
        cin>>l;
        gaps[i] = (l-last)*(l-last);
        used[i] = 1;
        pq.push({(gaps[i]/used[i]-gaps[i]/(used[i]+1)),i});
        last = l;
    }
    while(k--)
    {
         id = pq.top().second;
        pq.pop();
        ++used[id];
        pq.push({(gaps[id]/used[id]-gaps[id]/(used[id]+1)),id});
    }
    for(int i =1;i < n;++i)wynik+= gaps[i]/used[i];
    cout<<wynik/4;
}
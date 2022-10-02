#include <bits/stdc++.h>
using namespace std;
priority_queue<pair< long double,long double>> pq;
long double n,k,d,id;
long double l,last;
long double wynik,used[100001],gaps[100001];
int main()
{
    cout.precision(10);
    cin>>n>>k>>d;
    cin>>last;
    for(long double i =1;i < n;++i)
    {
        cin>>l;
        gaps[int(i)] = (l-last)*(l-last);
        used[int(i)] = 1;
        pq.push({(gaps[int(i)]/used[int(i)]/(used[int(i)]+1)),i});
        last = l;
    }
    while(k--)
    {
        id = pq.top().second;
        pq.pop();
        ++used[int(id)];
        pq.push({(gaps[int(id)]/used[int(id)]/(used[int(id)]+1)),id});
    }
    for(int i =1;i < n;++i)wynik+= gaps[i]/used[i];
    cout<<setprecision(10)<<wynik/4;
}
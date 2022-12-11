#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,a,pot2 ;
vector<ll> v;

ll value, value2,sum,ans;
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a);
        v.emplace_back(a);
        sum+= a;
    }
    sort(v.begin(),v.end());
    cout<<v[2] - v[0];
}
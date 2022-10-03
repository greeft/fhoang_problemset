#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_SIZE = 151;
short p,q,r,t,dp[MAX_SIZE][MAX_SIZE][MAX_SIZE],dp_value[MAX_SIZE][MAX_SIZE][MAX_SIZE],value;
char tab[MAX_SIZE][MAX_SIZE][MAX_SIZE],pom[MAX_SIZE][MAX_SIZE][MAX_SIZE];
stack <pair<int,int>> s;
void calc() {
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= q; ++j) {
            for (int z = 1; z <= r; ++z) {
                dp[i][j][z] = 0;
                if (tab[i][j][z] == 'P')continue;
                dp[i][j][z] = min(dp[i - 1][j][z], min(dp[i][j][z - 1], dp[i - 1][j][z - 1])) + 1;
            }
        }
    }
    for (int i = 1; i <= p; ++i) {
            for (int z = 1; z <= r; ++z) {
                s.push({-2137, 0});
                for (int j = 1; j <= q; ++j) {
                    int t = dp[i][j][z];
                    while (t <= s.top().first)s.pop();
                    dp_value[i][j][z] = j - s.top().second - 1;
                    s.push({t, j});
                }
                while (!s.empty())s.pop();
            }
    }
        for (int i = 1; i <= p; ++i) {
            for (int z = 1; z <= r; ++z) {
                s.push({-2137, q + 1});
                for (int j = q; j; --j) {
                    t = dp[i][j][z];
                    while (t <= s.top().first)s.pop();
                    dp_value[i][j][z] += (s.top().second - j - 1);
                    if(value < (dp_value[i][j][z] + 1) * t)value = (dp_value[i][j][z] + 1) * t;
                    //cout<<4 * ((z - s.top().second) + dp_value[i][j][z]) * t<<endl;
                    s.push({t, j});
                }
                while (!s.empty())s.pop();
            }
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> p >> q >> r;
    for(int j =1; j<= q;++j)
        for(int i = 1; i<=p;++i)
            for(int z = 1; z<=r;++z)cin>>tab[i][j][z];
    calc();
    // dla r'a
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= q; ++j) {
            for (int z = 1; z <= r; ++z) {
                pom[i][z][j] = tab[i][j][z];
            }
        }
    }
    swap(q,r);
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= q; ++j) {
            for (int z = 1; z <= r; ++z) {
                tab[i][j][z] = pom[i][j][z];
            }
        }
    }
    calc();
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= q; ++j) {
            for (int z = 1; z <= r; ++z) {
                pom[j][i][z] = tab[i][j][z];
            }
        }
    }
    swap(p,q);
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= q; ++j) {
            for (int z = 1; z <= r; ++z) {
                tab[i][j][z] = pom[i][j][z];
            }
        }
    }
    calc();
    // dla j'ta
    cout<<value * 4<<endl;
}

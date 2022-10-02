/*/
 * Filip Hoang
 * Rozwiazanie Wzorcowe - Programowanie Dynamiczne
 * O(n^2*k)
 */

#include <bits/stdc++.h>
using namespace std;
int n,m,k,dp[501][501][2],school_time,day[501][2],cost,income,value,saved[501][501][2][2],lesson_number[501];
char lessons[501][501];
int main()
{
    cin>>n>>m>>k;
    for(int i =1; i <=n;++i)
    {
        for(int j =1; j <=m;++j)
        {
            cin>>lessons[i][j];
            if(!day[i][0]&&lessons[i][j] =='1')day[i][0] = j;
            if(lessons[i][j] =='1')day[i][1] = j;
        }
        school_time += day[i][1] -day[i][0] + 1;
        // cout<<i<<" "<<school_time<<endl;
    }
    for(int i =1; i <=n;++i)
    {
        cost =0;
        income = 0;
        for(int j =day[i][0]; j <=day[i][1];++j)
        {
            if(lessons[i][j]=='1')cost++;
            income++;
            if(income > saved[i][cost][0][0])
            {
                saved[i][cost][0][0] = income;
                saved[i][cost][0][1] = j;
            }

        }
        lesson_number[i] = cost;
    }
    for(int i =1; i <=n;++i) {
        cost = 0;
        income = 0;
        for (int j = day[i][1]; j >= day[i][0]; j--) {
            if (lessons[i][j] == '1')cost++;
            income++;
            if(income > saved[i][cost][1][0])
            {
                saved[i][cost][1][0] = income;
                saved[i][cost][1][1] = j;
            }
        }
    }
    for(int i = 1;i <=n;++i)
    {
        for(int j = 0; j <=lesson_number[i];++j)
        {
            for(int h = 0; h <=lesson_number[i];++h)
            {
                if(j + h >=lesson_number[i])
                {
                    dp[i][j + h][1] = max(dp[i][j + h][1],day[i][1] -day[i][0] + 1);
                    break;
                }
                else dp[i][j + h][1] = max(dp[i][j + h][1],saved[i][j][0][0] +saved[i][h][1][0]);
            }
        }
    }
    for(int i =1; i <=n;++i)
    {
        for(int j =0; j <=k;++j)
        {
            for(int g = j;g >= 0;--g)
            {
                //cout<<i<<" "<<j<<" "<<g<<" "<<j-g<<" "<<endl;
                //if(dp[i][g] + dp[i -1][j - g] dp[i][j) = max(dp[i][j],dp[i][g] + dp[i -1][j - g]);
                dp[i][j][0] = max(dp[i][j][0],dp[i-1][g][0] + dp[i][j -g][1]);
            }

        }
    }
    //  cout<<school_time<<endl;
    cout<<school_time -  dp[n][k][0];
}
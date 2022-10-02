#include <bits/stdc++.h>
using namespace std;

int n,last[10001][27],current = 25,pointer[10001],last_pointer[10001];
bool if_last,didnt_apeared;
string s[10001],ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i =1;i <= n;++i)
    {
        cin>>s[i];
        s[i] = "{" +s[i];
        for(int j =1; j < s[i].size();++j)
        {
            last[i][int(s[i][j] - 'a')] = j;
        }
    }
    while(current >=0)
    {
        for(int i = 1; i <=n;++i)
        {
            if(last[i][current] < pointer[i]||last[i][current] ==0)
            {
                didnt_apeared = true;
                break;
            }
        }
        if(didnt_apeared)
        {
            didnt_apeared = false;
            --current;
            continue;
        }
        for(int i =1;i <= n;++i)
        {
            //  pointer[i]++;
            for(int j = pointer[i];j <= last[i][current];j++)
            {
                pointer[i]++;
                //  cout<<" "<<" "<<i<<" "<<char(current + 'a')<<" "<<j<<" "<<endl;
                if(pointer[i]==last[i][current])
                {
                    // pointer[i]++;
                    if_last = true;
                    break;
                }
                if(s[i][pointer[i]]== char(current + 'a'))
                {
                    //pointer[i];
                    break;
                }
            }

        }
       if(if_last)
        {
            for(int i = 1;i <=n;++i)last_pointer[i] = pointer[i];
            if_last = false;
            ans +=char(current + 'a');
            --current;
        }
        else
        {
            for(int i = 1;i <=n;++i)last_pointer[i] = pointer[i];
            ans+=char(current + 'a');
        }
    }
    if("bitek" > ans)cout<<"bitek";
    else cout<<ans;
}
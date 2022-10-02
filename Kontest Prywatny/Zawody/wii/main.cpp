#include <bits/stdc++.h>
using namespace std;
const int h=31,mod=1000000009;
int n;
 long long m,ma;
string s;
priority_queue <pair<int,int> >pq;
int main()
{
    cin>>n;
    for(int i =0; i < n;i++)
    {
        cin>>s;
        m=0;
        for(int j =0;j < s.length();j++)
        {
            m*=h;
            m%=mod;
            m+=s[j]-'0';
            m%=mod;
        }
        //cout<<m<<endl;
        pq.push({-s.length(),m});
    }
    //cout<<"ok"<<endl;
    while(!pq.empty())
    {
         long long p=pq.top().second;
         long long d=-pq.top().first;
      //  cout<<pq.top().first<<" "<<pq.top().second<<endl;
        pq.pop();
        ma=max(ma,d);
        if(p==pq.top().second&&!pq.empty())
        {
            //cout<<"Ok"<<endl;
            for(int i =0; i < -pq.top().first;i++)
            {
                p*=h;
                p%=mod;

            }
            d+=-pq.top().first;
            p+=pq.top().second;
            p%=mod;
            pq.pop();
            pq.push({-d,p});
        }

    }
    cout<<ma<<endl;
}
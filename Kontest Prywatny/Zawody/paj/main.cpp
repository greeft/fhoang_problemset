#include <bits/stdc++.h>
using namespace std;

int d,n1,n2,a,b,stopien[20001],stopien2[20001];
bool if_impossible;
vector<int> web[20001];
vector<int> web2[20001];
int main()
{
    cin>>d;
    for(int h = 0; h < d;++h)
    {
        cin>>n1;
        for(int i = 1;i<=n1;++i)
        {
            web[i].clear();
            stopien[i] = 0;
        }
        cin>>a;
        for(int i =1; i < 2 * (2 * n1 -3);++i)
        {
            b =a;
            cin>>a;
            web[a].push_back(b);
            web[b].push_back(a);
        }
        cin>>n2;
        for(int i = 1;i<=n2;++i)
        {
            web2[i].clear();
            stopien2[i] = 0;
        }
        cin>>a;
        for(int i =1; i < 2 * (2 * n2 -3);++i)
        {
            //cout<<i<<endl;
            b =a;
            cin>>a;
            web2[a].push_back(b);
            web2[b].push_back(a);
        }
        if(n1!=n2)
        {
            cout<<"NIE"<<endl;
            continue;
        }
        for(int i =1; i<=n1;++i)stopien[web[i].size()]++;
        for(int i =1; i<=n2;++i)stopien2[web[i].size()]++;
        for(int i =1;i <=n1;++i)
        {
            if(stopien[i]!=stopien2[i])
            {
                cout<<"NIE"<<endl;
                if_impossible = true;
                break;
            }
        }
        if(if_impossible)
        {
            if_impossible = false;
            continue;
        }
        cout<<"TAK"<<endl;
    }
}
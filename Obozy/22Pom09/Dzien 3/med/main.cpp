#include <bits/stdc++.h>
using namespace std;
constexpr int MAX_N = 2 * 1e5 + 1;
#define ll long long
ll n,p,a_i,b_i,pocz,mid,kon,how_many,iter,pocz_l,kon_l,mid_l,essa;
vector <ll> ans,a,b;
int main() {
    cin>>n>>p;
    for(int i =1;i<=n;++i)
    {
        scanf("%lld",&a_i);
        a.emplace_back(a_i);
    }
    for(int i =1;i<=n;++i)
    {
        scanf("%lld",&b_i);
        b.emplace_back(b_i);
    }
    if(n  <= 1000)
    {
        for(int i = 0;i<n;++i)
            for(int j =0; j <n;++j)
                ans.emplace_back((a[i] * b[j]) % p);
        sort(ans.begin(),ans.end());
        cout<<ans[(ans.size()>>1)];
    }
    else if(p >= 1e15)
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        pocz = 0;
        kon = 1e15;
        mid = (pocz + kon) >> 1;
        while(pocz != mid&&mid != kon)
        {
            //cout<<pocz<<" "<<mid<<" "<<kon<<endl;
            iter = 0;
            how_many = 0;
            while(iter < a.size()&&a[iter] < mid)
            {
                if(a[iter] * b[0] > mid)break;
                pocz_l = 0;
                kon_l = b.size();
                mid_l = (pocz_l + kon_l) >>1;
                while(pocz_l != mid_l && mid_l != kon_l)
                {
                    //cout<<iter<< " "<<pocz_l<<" "<<kon_l<<endl;
                    //if(a[iter] * b[mid_l] == mid)essa =a[iter] * b[mid_l];
                    if(a[iter] * b[mid_l] > mid)
                    {

                        kon_l = mid_l;
                        mid_l = (pocz_l + kon_l) >>1;
                    }
                    else
                    {
                        pocz_l = mid_l;
                        mid_l = (pocz_l + kon_l) >>1;
                    }
                }
                how_many += mid_l + 1;
                ++iter;
            }
            //cout<<pocz<<" "<<mid<<" "<<kon<<" "<<how_many<<endl;
           // if(pocz + 1 == mid&&kon - 1== mid&&how_many == ((n * n) >> 1))break;
            if(how_many >= ((n * n) >> 1) + 1)
            {
               // if(how_many == (((n * n) >> 1) + 1)) essa = max(essa,mid);
                kon = mid;
                mid = (pocz + kon) >> 1;
            }
            else if(how_many < ((n * n) >> 1) + 1)
            {
                pocz = mid;
                mid = (pocz + kon) >> 1;
            }
        }
    cout<<mid + 1<<endl;
    return 0;
    }
}
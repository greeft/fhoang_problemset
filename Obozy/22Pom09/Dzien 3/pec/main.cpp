#include <bits/stdc++.h>
using namespace std;

int s,w,k,pom;
double dis,ans,water,dk,ds,skok;
int main()
{
    scanf("%d%d%d",&s,&w,&k);
    dk = k;
    ds = s;
    water = w;
    dis;
    if(w % k) {
        dis = (double(w % k) / double(w / k * 2.0 + 1.0));
        water -= w % k;
        if (dis >= s)
        {
            ans = w - (w / k * 2.0 + 1.0) * s;
            printf("%.3lf",ans);
            return 0;
        }
    }
             pom = (w / k) * 2.0 - 1.0;
            skok = (dk / double(pom));
            while(pom > 0&& dis + skok < ds)
            {
                water -= k;
                dis += skok;
                pom-= 2;
                skok = dk / double(pom);
            }
            ans = water - (ds - dis) * pom;
    printf("%.3lf",ans);
}
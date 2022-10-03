#include <bits/stdc++.h>
#include "roblib.h"
using namespace std;

inline void die(string msg, bool sendDie = true)
{
    cout << msg << '\n';
    exit(0);
}
namespace helper
{

    set<string> set_;
    bool wyslane = false;
    int n;
    vector<int> p;
    int z;
    int w;
}
bool check(const string &x)
{
    if ((int)x.length() != helper::n)
    {
        return false;
    }
    for (int i = 0; i < helper::n; i++)
    {
        if (x[i] != '0' && x[i] != '1')
        {
            return false;
        }
    }
    return true;
}

using namespace helper;
string groups;
void divide(int p,int k,int n)
{
    if(p == k)return;
    groups.clear();
   // cout<<p<<" "<<k<<endl;
    for(int i =0; i < p;++i)groups+='1';
    for(int i = p; i<=k;++i)groups+='0';
    for(int i = k + 1;i< n;++i)groups+='1';
    for(int i = p; i<=((p + k)>>1);++i)
    {
        groups[i] = '1';
     //   cout<<groups<<endl;
        zaprogramuj(groups);
        groups[i] = '0';
    }
    divide(p,((p + k)>>1),n);
    divide((((p+ k)>>1)+ 1),k,n);
}
vector<int> rob;
int tab[128];
void conquer(vector<int> v,int p,string mask,int n)
{
    //cout<<"C"<<" "<<p<<" "<<k<<" "<<v.size();
    if(v.size() == 1)
    {
        tab[p - n] = v[0];
        return;
    }
    string mask_l = mask;
    vector<int> v1;
    vector<int> v2;
    for(auto u : v)
    {
        mask_l[u] = '1';
        if(sprawdz(mask_l))
        {
            v1.emplace_back(u);
        }
        else
        {
            v2.emplace_back(u);
        }
        mask_l[u] = '0';
    }
   // cout<<" "<<v1.size()<<" "<<v2.size()<<endl;
    mask_l = mask;
    for(auto u : v2)
    {
        mask_l[u] = '1';
    }
    //p,(p + k)>>1,n)
    conquer(v1,p << 1,mask_l,n);
    mask_l = mask;
    for(auto u : v1)
    {
        mask_l[u] = '1';
    }
    conquer(v2,(p << 1) + 1,mask_l,n);

}
vector<int> rozpoznaj(int n, int w, int r)
{
    for(int i =0; i < n;++i)groups+='0';
   for(int i =0; i < (n >> 1);++i)
   {
       groups[i] = '1';
       //cout<<groups<<endl;
       zaprogramuj(groups);
       groups[i] = '0';
   }
   divide(0, (n>>1) - 1,n);
   divide((n >> 1),n - 1,n);
   wyslijRoboty();
   groups.clear();
   for(int i = 0;i < n;++i)
   {
       groups+='0';
        rob.emplace_back(i);
   }
    vector<int> v1;
    vector<int> v2;
    for(int i = 0;i < n;++i)
    {
        groups[i]='1';
       if(sprawdz(groups))
       {
           v1.emplace_back(i);
       }
       else
       {
           v2.emplace_back((i));
       }
        groups[i]='0';
    }
    //cout<<groups<<endl;
    string mask_l = groups;
    for(auto u : v2)
    {
        mask_l[u] = '1';
    }
   // cout<<v1.size()<<" "<<v2.size()<<endl;
    conquer(v1,2,mask_l,n);
    mask_l = groups;
    for(auto u : v1)
    {
        mask_l[u] = '1';
    }
   // cout<<mask_l<<endl;
    conquer(v2,3,mask_l,n);
    vector<int> ans;
    for(int i =0;i<n;++i)ans.emplace_back(0);
    for(int i = 0;i < n;++i)ans[i] = tab[i];
    //for(int i = 0;i < n;++i)cout<<ans[i]<<" ";
    return ans;
}
int main()
{
    cin >> n >> z >> w;
    p = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> answer = rozpoznaj(n, z, w);

    if ((int)answer.size() != n)
        die("Niepoprawny format");

    int ok = wyslane;
    for (int i = 0; i < n; i++)
    {
        if (answer[i] != p[i])
            ok = 0;
    }
    if (!ok)
        die("Zły wynik");
    die("OK.");
    return 0;
}

void zaprogramuj(string x)
{
    if (z == 0 || wyslane || !check(x))
        die("Nie można wykonać tego zapytania");
    z--;
    set_.insert(x);
}

bool sprawdz(string x)
{
    if (w == 0 || wyslane == 0 || !check(x))
        die("Nie można wykonać tego zapytania");
    w--;
    return set_.count(x);
}

void wyslijRoboty()
{
    if (wyslane)
        die("Nie można wysłać robotów");
    wyslane = true;
    set<string> compiledSet;
    string compiledElement = string(n, ' ');
    for (set<string>::iterator it = set_.begin(); it != set_.end(); it++)
    {
        string s = *it;
        for (int i = 0; i < n; i++)
        {
            compiledElement[p[i]] = s[i];
        }
       // cout<<"C "<<compiledElement<<endl;
        compiledSet.insert(compiledElement);
    }
    set_ = compiledSet;
}
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
string group;
int possitions[32];
vector<int> rozpoznaj(int n, int w, int r)
{
    for(int i =0; i < n - 1;++i)
    {
        group.clear();
        for(int j = 0; j <= i;++j)group+='0';
        for(int j = i + 1;j<n;++j)group+='1';
       // cout<<group<<endl;
        zaprogramuj(group);
    }
    group.clear();
    for(int j = 0; j <= n - 1;++j)group+='1';
    zaprogramuj(group);
    wyslijRoboty();
    group.clear();
    for(int j = 0; j< n;++j)
    {
       group +='0';
    }
    for(int i = n - 1;i;--i)
    {
        for(int j = 0; j < n;++j)
        {
            if(possitions[j])continue;
            group[j] = '1';
            if(sprawdz(group))
            {
                possitions[j] = i;
                break;
            }
            group[j] = '0';
        }
    }
    vector<int> ans;
    //cout<<"essa\n";
    for(int i =0;i < n;++i)ans.emplace_back(0);
    for(int i =0;i < n;++i)ans[possitions[i]] = i;
   // for(int i =0;i < n;++i)cout<<ans[i]<<" ";
   // assert(sprawdz("0001") == false);
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
        cout<<"C "<<compiledElement<<endl;
        compiledSet.insert(compiledElement);
    }
    set_ = compiledSet;
}
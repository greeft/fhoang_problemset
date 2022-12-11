//AMOGUS
#include <bits/stdc++.h>
using namespace std;
const int H = 31;
const int mod = 1e9 + 9;

int t,value,pointer_l,pointer_p,size;
int hash_l,hash_p,base_p;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    for(int h =0; h < t;++h)
    {
        cin>>s;
        pointer_l &=0;
        hash_l &= 0;
        base_p = 1;
        size = s.size();
        hash_p &= 0;
        pointer_p = size -1;
        value = 0;
        while(pointer_l < pointer_p)
        {
            hash_l *= H;
           if(hash_l >= mod) hash_l%= mod;
            hash_l+= s[pointer_l] - 'a';
            if(hash_l >= mod)  hash_l%= mod;
            hash_p +=((s[pointer_p] - 'a') * base_p);
            base_p *= H;
            if(base_p >= mod)base_p %= mod;
            //cout<<last_p<<" "<<pointer_p<<" "<<pointer_p - last_p - 1<<" "<<endl;
            if(hash_p >= mod) hash_p %= mod;
            //cout<<hash_l<<" "<<hash_p<<endl;
            //cout<<s[pointer_p]<<" "<<s[pointer_l]<<" "<<int(s[pointer_p] - 'a')<<" "<<int (s[pointer_l] - 'a')<<"  ";
            if(hash_l == hash_p)
            {
                base_p = 1;
                ++value;
                ++value;
                hash_l &= 0;
                hash_p &= 0;
            }
            pointer_l++;
            pointer_p--;
        }
        if(size%2)cout<<value + 1<<endl;
        else if(!hash_l&&!hash_p)cout<<value<<endl;
        else cout<<value + 1<<endl;
    }

}

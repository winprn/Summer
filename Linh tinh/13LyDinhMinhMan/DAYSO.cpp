#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

ll f[10]={9,189,2889,38889,488889,5888889,68888889,788888889,8888888889};
ll n;

ll get(ll x){
    if(x<10)return x;
    else{
        ll cur=10;
        int idx=-1;
        for(int i=1;i<=8;++i){
            if(cur*10>x){idx=i-1;break;}
            cur*=10;
        }
        if(idx==-1)idx=8;

        return f[idx]+(x-cur+1)*(idx+2);
    }

    //cout<<cur<<' '<<idx<<endl;
    return -1;
}

int main() {
    freopen("dayso.inp", "r", stdin);
    freopen("dayso.out", "w", stdout);

    while(cin>>n){
        ll l=1,r=3e9,ans=-1;
        while(l<r){
            ll m=l+(r-l+1)/2;
            if(get(m)>n)r=m-1;
            else l=m;
        }
        if(get(l)!=n)cout<<"-1"<<endl;
        else cout<<l<<endl;
    }
}
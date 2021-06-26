#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

int n;

map<ll,ll> factorize(ll x){
    map<ll,ll> kq;
    for(ll i=2;i*i<=x;++i){
        while(x%i==0){
            x/=i;
            kq[i]++;
        }
    }
    if(x>1)kq[x]++;
    return kq;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    vector<map<ll,ll>>facts;
    for(int i=0;i<n;++i){
        int x;cin>>x;
        facts.pb(factorize(x));
    }

    map<ll,ll>total;
    vector<ll>bad;
    for(auto i:facts){
        for(auto j:i)total[j.fi]+=j.se;
    }
    for(auto& i:total)i.se/=n;
    for(auto i:total){
        if(i.se==0)bad.pb(i.fi);
    }
    for(auto i:bad)total.erase(i);

    ll ans=1,need=0;
    for(auto i:total)ans*=pow(i.fi,i.se);
    for(auto i:facts){
        for(auto j:total){
            if(total[j.fi]>i[j.fi]){
                need+=(total[j.fi]-i[j.fi]);
            }
        }
    }
    cout<<ans<<' '<<need<<endl;
}
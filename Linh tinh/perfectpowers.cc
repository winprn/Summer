#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int MX=1e7+9;
vector<ll>primes;
bitset<(int)1e8>pr;
ll n;

void sieve(){
    pr.set();
    pr[0]=pr[1]=0;
    for(ll i=2;i<=MX;++i){
        if(pr[i]){
            primes.pb(i);
            for(ll j=i*i;j<=MX;j+=i)pr[j]=0;
        }
    }
}

vector<pair<ll,ll>> factorize(ll x){
    vector<pair<ll,ll>>kq;
    for(int i=0;i<(int)primes.size()&&primes[i]*primes[i]<=x;++i){
        int cur=primes[i],cnt=0;
        while(x%cur==0){
            x/=cur;
            ++cnt;
        }
        if(cnt)kq.pb({cur,cnt});
    }

    if(x>1)kq.pb({x,1});
    return kq;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while(cin>>n,n!=0){
        auto p=factorize(abs(n));
        ll g=0;
        for(auto i:p)g=__gcd(g,i.se);

        if(g&1||n>0)cout<<g<<endl;
        else {
            while(g%2==0)g/=2;
            cout<<g<<endl;
        }
    }
}
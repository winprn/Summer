#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int MX=1e8+3;
vector<ll>primes;
bitset<(int)1e8+5>pr;
ll n;

void sieve(){
    pr.set();
    pr[0] = pr[1] = 0;
    primes.pb(2);
    for(ll i=4;i<MX;i+=2)pr[i]=0;
    for(ll i=3;i*i<MX;i+=2){
        if(pr[i]){
            primes.pb(i);
            for(ll j=i;j<MX;j+=(i*2))pr[j]=0;
        }
    }
}

vector<pair<ll,ll>> factorize(ll x){
    vector<pair<ll,ll>>kq;
    for(int i=0;i<(int)primes.size()&&primes[i]*primes[i]<=x;++i){
        ll cur=primes[i],cnt=0;
        while(x%cur==0){
            x/=cur;
            ++cnt;
        }

        if(cnt)kq.pb({cur,cnt});
    }
    return kq;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    while(cin>>n){
        auto p=factorize(n);
        ll ans=1;
        for(auto i:p){
            ll cur=1;
            for(int j=0;j<i.fi;++j){
                cur*=i.se;    
            }
            ans*=cur;
        }
        cout<<n<<' '<<ans<<endl;
    }
}
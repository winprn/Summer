#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int MX=1e7+9;
vector<ll>primes;
bitset<(int)1e8>pr;
int p[(int)1e4+10],phi[(int)1e4+10];
int n,k,t;

void sieve(){
    pr.set();
    pr[0]=pr[1]=0;
    for (ll i=2;i<=MX;++i){
        if(pr[i]){
            primes.pb(i);
            for(ll j=i*i;j<=MX;j+=i)pr[j]=0;
        }
    }
}

int calc(int x){
    int ans=x;
    for (int i=0;i<(int)primes.size()&&primes[i]*primes[i]<=x;++i){
        if(x%primes[i]==0)ans-=ans/primes[i];
        while(x%primes[i]==0)x/=primes[i];
    }

    if(x!=1)ans-=ans/x;
    return ans;
}

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    memset(phi,-1,sizeof phi);
    memset(p,-1,sizeof p);
    cin>>t;
    while(t--){
        cin>>k>>n;
        for (int i=1;i<=n;++i){
            if(phi[i]==-1)phi[i]=calc(i);
        }

        p[1]=phi[1];
        if(p[n]==-1)for(int i=2;i<=n;++i)p[i]=p[i-1]+phi[i];
        cout<<k<<' '<<p[n]+1<<endl;
    }
}
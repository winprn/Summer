#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int MX=2e6;
vector<int>primes(MX+10);
bitset<(int)2e6+10>pr;
int ans[(int)2e6+10];
int n,q;

void sieve(){
    pr.set();
    pr[0]=pr[1]=0;
    for(ll i=2;i<=MX;++i){
        if(pr[i]){
            for(ll j=1;j<=MX;++j){
                if(i*j>MX)break;
                if(j>1)pr[i*j]=0;
                primes[i*j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    sieve();
    for(int n=2;n<=MX;++n){
        int total=0,tmp=n,lst=0,nd=1,pf=0;
        while(tmp>1){
            int now=primes[tmp];
            if(now!=lst){
                ++pf;
                nd*=(total+1);
                total=1;
            }else ++total;
            tmp/=now;
            lst=now;
        }
        nd*=(total+1);
        ans[n]=nd-pf;
    }

    cin>>q;
    while(q--){
        cin>>n;
        cout<<ans[n]<<'\n';
    }
}
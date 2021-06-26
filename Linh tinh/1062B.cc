#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x)*(x)
#define MOD 1000000007

typedef long long ll;

ll n;

ll get(ll n){
    for(ll i=1;i<=1000;++i){
        if(i*i>=n)return i;
    }

    return -1;
}

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;

    ll mn=1e9,num=0,cnt=0;
    while(1){
        bool ok=0;
        for(int i=1;i<n;++i){
            ll k=n*i;
            ll tmp=(ll)sqrt(k);
            if(sqr(tmp)==k){
                n=tmp;
                ++num;
                if(i!=1)++cnt;
                ok=1;
                break;
            }
        }
        if(!ok)break;
    }

    if(cnt)++num;
    cout<<n<<' '<<num;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (64 - __builtin_clzll(1ll*(x)) - 1)
#define numBit(x) (__builtin_popcountll(1ll*(x)))
#define getBit(x,i) (x>>i&1)
#define Pi acos(-1.0l)
#define sz(x) (int)x.size()
#define mt make_tuple
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define debug(x) cerr << #x << " = " << x << '\n';

int a[105];
int n;

int main() {
    fastIO;
#ifndef ONLINE_JUDGE
    freopen("i","r",stdin);
    freopen("ans","w",stdout);
#endif // ONLINE_JUDGE

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    ll ans=0;
    for(int i=1;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(a[i]*a[j]==i+j){
                //cout<<i<<' '<<j<<endl;
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

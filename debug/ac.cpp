#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef complex<ld> cp;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<cp> vcp;
typedef vector<ld> vld;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> vvii;

#define fastIO ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define forw(i,l,r) for( int i = (l) ; i < (r) ; i++ )
#define forb(i,r,l) for( int i = (r) ; i >= (l) ; i-- )
#define log2i(x) (32 - __builtin_clz((x)) - 1)
#define log2ll(x) (64 - __builtin_clzll((x)) - 1)
#define Pi 3.141592653589793
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

ll n,ans=0;
ll d[10];

int main() {
    fastIO;
    freopen("i","r",stdin);
    freopen("ans","w",stdout);

    for(ll pos=0,p=1;pos<10;pos++,p*=10) d[pos]=9*(pos+1)*p;
    cin >> n;
    if(n<=9) return cout << n, 0;
    ll m=10;
    int i;
    for(i=0;m<=n;i++,m*=10) ans+=d[i];
    m/=10;
    ans+=(n-m+1)*(i+1);
    cout << ans;
    return 0;
}

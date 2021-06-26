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

const int N = 41;
const int M = (1<<20)+1;
const int inf = 1e9+7;
int n;
int len[2],T[M];
ll k,ans=0;
pair<ll,ll> ar[2][N];
vll tmp;
vector<pair<int,ll> > ss[2];

void upd(int x, int val) {
    for(;x<=sz(tmp);x+=-x&x) T[x]+=val;
}

int gekt(int x) {
    int res=0;
    for(;x;x-=-x&x) res+=T[x];
    return res;
}

int main() {
    fastIO;
    freopen("sah.inp","r",stdin);
    freopen("sah.out","w",stdout);

    cin >> n >> k;
    len[0]=n/2; len[1]=n-len[0];
    forw(t,0,2) {
        forw(i,0,len[t]) cin >> ar[t][i].fi >> ar[t][i].se;
        forw(i,0,1<<len[t]) {
            ll sum=0,hei=0,st=inf;
            bool ok=true;
            forw(j,0,len[t]) if(i>>j&1) {
                sum+=ar[t][j].se;
                if(st==inf) st=ar[t][j].fi;
                if(hei<=ar[t][j].fi) hei=ar[t][j].fi;
                else {ok=false; break;}
            }
            if(ok) ss[t].pb(mp((t?st:hei),sum));
        }
        sort(all(ss[t]));
    }
    for(auto x:ss[0]) tmp.pb(x.se);
    sort(all(tmp)); tmp.resize(unique(all(tmp))-tmp.begin());
    int r=0;
    forw(i,0,sz(ss[1])) {
        int pos;
        while(r<sz(ss[0])&&ss[0][r].fi<=ss[1][i].fi) {
            pos=lower_bound(all(tmp),ss[0][r].se)-tmp.begin();
            upd(pos+1,1); r++;
        }
        pos=lower_bound(all(tmp),k-ss[1][i].se)-tmp.begin();
        ans+=r-gekt(pos);
    }
    cout << ans;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PI acos(-1.0)
#define FF first
#define SS second
#define eps 1e-9
// vector
#define pb push_back
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
// bit
#define CNTBIT(x) __builtin_popcount(x)
#define ODDBIT(x) __builtin_parity(x)
#define MASK(i) (1<<(i))
#define BIT(x, i) (((x)>>(i))&1)
#define SUBSET(big, small) (((big)&(small))==(small))
#define MINBIT(x) (x)&(-x)
// typedef
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, int> ii;
/* CODE BELOW */
const int N=1e6+7, M=5e5+7, K=18+1;
const int MOD=1e9+7;
const int oo=1e9+7;

int n, m, k, t;

int ti[N], cnt[N];
int mark[N];

int add(int a, int b, int mod) {
    return (a+b)%mod;
    //a+=b; if(a>=mod) a-=mod; return a;
}
int mul(int a, int b, int mod) {return (1LL*a*b)%mod;}

signed main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
    //fastIO;
    //A = 3, B = 12, C = 512, t[0] = 30
    ll n, m;
    scanf("%lld%lld", &n, &m);
    int a, b, c;
    scanf("%d%d%d%d", &a, &b, &c, &ti[0]);
    memset(cnt, 0, sizeof cnt);
    memset(mark, -1, sizeof mark);
    cnt[ti[0]]=1, mark[ti[0]]=0;
    int l=0, r=n;
    for(int i=1;i<n;i++) {
        ti[i]=add(mul(a, ti[i-1], c), b, c)+1;
        if(mark[ti[i]]!=-1) {
            l=mark[ti[i]], r=i-1; break;
        }
        mark[ti[i]]=i, cnt[ti[i]]=1;
    }

    ll penalty=0, ans=0, curtime=0;
    if(r==n) {
        sort(ti, ti+n);
        for(int i=0;i<n&&curtime+ti[i]<=m;i++) {
            curtime+=ti[i], ans++;
            penalty=add(penalty, curtime%MOD, MOD);
        }
        printf("%lld %lld\n", ans, penalty);
        return 0;
    }
    int len=r-l+1;
    ll mu=(n-l+1)/len-1, re=(n-l)%len;
    for(int i=0;i<l;i++) cnt[ti[i]]++;
    for(int i=0;i<len;i++) {
        cnt[ti[i+l]]+=mu;
        //printf("%d %d\n", i, ti[i+l]);
        if (i<re) cnt[ti[i+l]]++;
    }
    //printf("%d %lld %lld\n", len, mu, re);
    for(ll i=1;i<=c;i++) {
        if(!cnt[i]) continue;
        if(curtime+i>m||ans==n) break;
        ll cnti=min({1ll*cnt[i], (m-curtime)/i, n-ans});
        ll ad=mul(cnti, curtime%MOD, MOD);
        ll pen=mul(i, (1ll*cnti*(cnti+1)/2)%MOD, MOD);
        ad=add(ad, pen, MOD);
        ans+=cnti, penalty=add(penalty, ad, MOD);
        curtime+=i*cnti;
        //printf("%lld %lld | %lld %lld %lld\n", i, cnti, ans, curtime, penalty);
    }
    printf("%lld %lld", ans, penalty);
    return 0;
}

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
const int N=1e6+7, M=5e5+7, K=18+7;
const int MOD=1e9+7;
const int oo=1e9+7;

int n, m, k, t;

int ti[N];
int cnt[N];

signed main() {
    freopen("i", "r", stdin);
    freopen("ans", "w", stdout);
    //fastIO;
    ll n, m;
    scanf("%lld%lld", &n, &m);
    int a, b, c;
    scanf("%d%d%d%d", &a, &b, &c, &ti[0]);
    cnt[ti[0]]++;
    for(int i=1;i<n;i++) {
        ti[i]=(1LL*a*ti[i-1]+b)%c+1;
        cnt[ti[i]]++;
    }
    /*for(int i=1;i<=c;i++) {
        printf("%d %d\n", i, cnt[i]);
    }*/

    sort(ti, ti+n);
    ll curtime=0;
    int ans=0, penalty=0;
    for(int i=0;i<n&&curtime+ti[i]<=m;ans++, i++) {
        curtime+=ti[i];
        penalty=(penalty+curtime)%MOD;
        //printf("%d %d | %d %d\n", ti[i], i, curtime, penalty);
    }
    printf("%d %d\n", ans, penalty);
    return 0;
}

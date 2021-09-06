#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define PI acos(-1.0)
#define FF first
#define SS second
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
// typedef
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> i3;
/* CODE BELOW */
const int N=100+1, M=2000+1, K=4;
const int MOD=998244353+7;
const int oo=1e9+7;

int n, m, k, t;

bool _dp[N][N*M];
int a[N];

signed main() {
    freopen("i", "r", stdin);
    freopen("ans", "w", stdout);
    //fastIO;
    scanf("%d", &n);
    memset(_dp, 0, sizeof _dp);
    _dp[0][0]=1;
    int sum=0;
    for(int i=1;i<=n;i++) {
        scanf("%d", &a[i]);
        sum+=a[i];
        for(int j=0;j<i*M;j++) {
            _dp[i][j]=_dp[i-1][j];
            if(j>=a[i]) _dp[i][j]|=_dp[i-1][j-a[i]];
        }
    }
    if((sum&1)||!_dp[n][sum/2]) {
        printf("0"); return 0;
    }
    printf("1\n");
    for(int i=1;i<=n;i++) {
        if(a[i]&1) {printf("%d", i); return 0;}
        if(!_dp[n][sum/2-a[i]/2]) {
            printf("%d", i); return 0;
        }
    }
    return 0;
}

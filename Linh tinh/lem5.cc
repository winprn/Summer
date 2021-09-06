///* ldmm is n00b */
//#include <bits/stdc++.h>
//using namespace std;
//
//#define fi first
//#define se second
//
//const int N=1e5+10;
//pair<int,int> b[N];
//int a[N],dp[105][N];
//int n;
//
//bool cmp(pair<int,int> a,pair<int,int> b){
//    if(a.fi==b.fi)return a.se<b.se;
//
//    return a.fi<b.fi;
//}
//
//int bs(int i,int x){
//    int l=0,r=n-1,kq=-1;
//    for(int j=0;j<32;++j){
//        int m=(l+r)/2;
//        if(b[m].fi==a[i]-x&&b[m].se<i)kq=b[m].se,l=m;
//        else if(b[m].fi>a[i]-x||(b[m].fi==a[i]-x&&b[m].se>i))r=m;
//        else l=m;
//    }
//
//    return kq;
//}
//
//void solve2(){
//    cin>>n;
//    for(int i=0;i<n;++i)cin>>a[i],b[i]={a[i],i};
//    sort(b,b+n);
//
//    int ans=0;
//    for(int i=1;i<=100;++i){
//        for(int j=0;j<n;++j){
//            int k=bs(j,i);
//            //cout<<i<<' '<<j<<' '<<k<<endl;
//            if(k==-1)dp[i][j]=1;
//            else dp[i][j]=dp[i][k]+1;
//            ans=max(ans,dp[i][j]);
//        }
//    }
//    cout<<ans;
//}
//
//signed main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);
//
//    solve2();
//    //solve(b);
//}
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
typedef pair<ll, ll> ii;
typedef pair<int, ii> i3;
/* CODE BELOW */
const int N=1e5+7, M=1e2, K=8;
const int MOD=1e9+7;
const int oo=1e9+7;

int n, m, k, t;

ii a[N];
int _dp[N];

signed main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
    //fastIO;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) {
        scanf("%lld", &a[i].FF);
        a[i].SS=i;
    }
    sort(a+1, a+n+1);

    int ans=0;
    for(int j=0, k=1;k<=M;j=0, k++) for(int i=1;i<=n;i++) {
        _dp[i]=1;
        ii cmp=ii(a[i].FF-k, a[i].SS);
        while(j+1<n&&a[j+1]<=cmp) j++;
        if(cmp.FF==a[j].FF&&a[i].SS>a[j].SS) _dp[i]=_dp[j]+1;
        ans=max(ans, _dp[i]);
    }
    printf("%d", ans);
    return 0;
}
/* stuff you should look for
    - int overflow, array bounds
    - special/edge cases (n=1?)
    - do smth instead of nothing and stay organized
    - WRITE STUFF DOWN
    - DONT JUST STICK ON ONE APPROACH
*/

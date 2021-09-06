/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define fi first
#define se second
#define pb push_back

#ifdef RICARDO
    #define bug(x) cerr << #x << " = " << (x) << endl;
    #define block if(1)
#else
    #define bug(x) "IDINGO"
    #define block if(0)
#endif


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

const int N=4e3+10;
int a[N],dp[N][N];
int n;

void zip(){
    vector<int> tmp(a,a+n);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());

    for(int i=0;i<n;++i)a[i]=lower_bound(tmp.begin(),tmp.end(),a[i])-tmp.begin();
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    zip();
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)dp[i][j]=1;

    int ans=1;
    for(int i=0;i<n;++i){
        bool ok=0;
        for(int j=i-1;j>=0;--j){
            if(a[i]==a[j]){
                if(ok)continue;
                ok=1;
                dp[a[i]][a[j]]++;
            }else dp[a[i]][a[j]]=max(dp[a[i]][a[j]],1+dp[a[j]][a[i]]);
            ans=max(ans,dp[a[i]][a[j]]);
        }
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

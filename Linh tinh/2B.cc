/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define IN(a,b) ((a)&(1<<(b)))


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

const int N=1e3+10;
pii a[N][N];
int dp[2][N][N];
int n,si=-1,sj;

int get(int x,int i){
    int kq=0;
    while(x%i==0){
        x/=i;
        ++kq;
    }

    return kq;
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
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int x; cin>>x;
            if(x==0)si=i,sj=j,x=10;
            a[i][j]={get(x,2),get(x,5)};
        }
    }
    memset(dp,0x3f,sizeof(dp));
    dp[0][0][0]=a[0][0].fi,dp[1][0][0]=a[0][0].se;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i){
                mini(dp[0][i][j],dp[0][i-1][j]+a[i][j].fi);
                mini(dp[1][i][j],dp[1][i-1][j]+a[i][j].se);
            }
            if(j){
                mini(dp[0][i][j],dp[0][i][j-1]+a[i][j].fi);
                mini(dp[1][i][j],dp[1][i][j-1]+a[i][j].se);
            }
        }
    }
    int ans=min(dp[0][n-1][n-1],dp[1][n-1][n-1]);

    vector<char> path;
    if(si!=-1&&ans>1){
        ans=1;
        for(int i=0;i<si;++i)path.pb('D');
        for(int i=0;i<sj;++i)path.pb('R');
        for(int i=si+1;i<n;++i)path.pb('D');
        for(int i=sj+1;i<n;++i)path.pb('R');
    }else{
        //cout<<dp[0][n-1][n-1]<<' '<<dp[1][n-1][n-1]<<endl;
        if(ans==dp[0][n-1][n-1]){
            int i=n-1,j=n-1;
            while(i||j){
                if(i&&dp[0][i][j]-a[i][j].fi==dp[0][i-1][j]){
                    --i;
                    path.pb('D');
                }else if(j&&dp[0][i][j]-a[i][j].fi==dp[0][i][j-1]){
                    --j;
                    path.pb('R');
                }
            }
        }else{
            int i=n-1,j=n-1;
            while(i||j){
                if(i&&dp[1][i][j]-a[i][j].se==dp[1][i-1][j]){
                    --i;
                    path.pb('D');
                }else if(j&&dp[1][i][j]-a[i][j].se==dp[1][i][j-1]){
                    --j;
                    path.pb('R');
                }
            }
        }
        reverse(path.begin(),path.end());
    }
    assert(ans!=1e9);

    cout<<(ans<0?1:ans)<<endl;
    for(auto i:path)cout<<i;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
/*
wait, AC?
⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣾⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿
⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿
⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿
⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿
*/

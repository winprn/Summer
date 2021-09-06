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

const int MX=(1<<10);
vector<int> tmp,num;
int dp[20][2];
int n,k,t;

int dem(int x){
    int kq=0;
    while(x){
        kq+=(x%2);
        x/=2;
    }

    return kq;
}

void get(int x){
    num.clear();
    while(x){
        num.pb(x%10);
        x/=10;
    }
    reverse(num.begin(),num.end());
    n=(int)num.size();
}

ll converse(vector<int> a){
    ll kq=0;
    for(int i:a)kq=kq*10+i;

    return kq;
}

//bool ok(int i,int j){
//    if(i>n)return dp[i][j]=1;
//    int &ans=dp[i][j];
//    if(ans!=-1)return ans;
//    for(int l:tmp){
//        if(j&&l<num[i-1])continue;
//        ans=ok(i+1,j&(l==num[i-1]));
//        if(ans)return 1;
//    }
//
//    return ans=0;
//}

bool ok(int i, int j) {
    if(i>n) return dp[i][j]=1;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int v:tmp) {
        if(j&&v<num[i-1]) continue;
        dp[i][j]=ok(i+1,j&(v==num[i-1]));
        if(dp[i][j]==1) return 1;
    }
    return dp[i][j]=0;
}

ll solve(int cur){
    tmp.clear();
    for(int i=0;i<10;++i){
        if(cur&(1<<i))tmp.pb(i);
    }

    for(int i=0;i<=n;++i)dp[i][0]=dp[i][1]=-1;
    if(!ok(1,1))return 1e18;

    vector<int> kq;
    for(int t=1,i=1;i<=n;i++) {
        for(int j:tmp){
            if(t&&j<num[i-1]) continue;
            if(dp[i+1][t&(j==num[i-1])]) {
                kq.pb(j);
                t&=(j==num[i-1]);
                break;
            }
        }
    }

    return converse(kq);
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

    cin>>t;
    while(t--){
        cin>>n>>k;
        get(n);
        ll ans=1e18;
        for(int i=1;i<MX;++i){
            if(dem(i)<=k)mini(ans,solve(i));
        }
        cout<<ans<<endl;
    }

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

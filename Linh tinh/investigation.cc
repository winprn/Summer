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

vector<int> digs;
int dp[10][2][100][100];
int t,l,r,m,cases=0;

int _dp(int pos,bool smaller,int rem,int sum){
    if(pos==(int)digs.size()){
        return (rem%m==0&&sum%m==0);
    }
    int &ans=dp[pos][smaller][sum][rem];
    if(ans!=-1)return ans;
    ans=0;

    int lim=9;
    if(!smaller)lim=digs[pos];
    for(int i=0;i<=lim;++i){
        ans+=_dp(pos+1,smaller||i<lim,(rem*10+i)%m,sum+i);
    }
    return ans;
}

int solve(int x){
    digs.clear();
    while(x){
        digs.pb(x%10);
        x/=10;
    }
    reverse(digs.begin(),digs.end());
//    for(int i:digs)cout<<i<<' ';
//    cout<<endl;

    memset(dp,-1,sizeof(dp));
    return _dp(0,0,0,0);
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
        cin>>l>>r>>m;
        if(m>=100)cout<<"Case "<<++cases<<": "<<0<<endl;
        else cout<<"Case "<<++cases<<": "<<solve(r)-solve(l-1)<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

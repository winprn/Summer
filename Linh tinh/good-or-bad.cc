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

const int N=55;
string s;
int dp[N][N][N];
int t,cases=0;

bool vowel(char x){
    return (x=='A'||x=='E'||x=='I'||x=='O'||x=='U');
}

int _dp(int i,int v,int c){
    if(v>=3||c>=5)return 0;
    //cout<<i<<endl;
    if(i<0)return 1;
    int &ans=dp[i][v][c];
    if(ans!=-1)return ans;

    if(s[i]=='?'){
        int tmp=_dp(i-1,0,c+1),tmp2=_dp(i-1,v+1,0);
        if(tmp!=tmp2||tmp==2||tmp2==2)ans=2;
        else ans=tmp;
    }else{
        if(vowel(s[i]))ans=_dp(i-1,v+1,0);
        else ans=_dp(i-1,0,c+1);
    }

    return ans;
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
        cin>>s;

        memset(dp,-1,sizeof(dp));
        int n=(int)s.size();
        int ans=_dp(n-1,0,0);
        cout<<"Case "<<++cases<<": ";
        if(ans==1)cout<<"GOOD";
        else if(ans==2)cout<<"MIXED";
        else cout<<"BAD";
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

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

vector<int> a;
int n,m,cnt1,cnt2,ans=0;

void dfs(int mask,int cur){
    if(cur==cnt1+cnt2){
        int tmp=0,tmp2=0;
        for(int i=0;i<cnt1;++i)tmp=tmp*7+a[i];
        for(int i=0;i<cnt2;++i)tmp2=tmp2*7+a[i+cnt1];

        if(tmp<n&&tmp2<m)++ans;
        return ;
    }

    for(int i=0;i<7;++i){
        if(mask&(1<<i))continue;
        a.pb(i);
        dfs(mask^(1<<i),cur+1);
        a.pop_back();
    }
}

int get(int x){
    if(x==1)return 1;
    --x;
    int kq=0;
    while(x){
        x/=7;
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

    cin>>n>>m;
    cnt1=get(n),cnt2=get(m);

    if(cnt1+cnt2>7)cout<<0;
    else dfs(0,0),cout<<ans;

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

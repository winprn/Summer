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

const long long inf=1e18;
int n;

ll exp(ll a,ll b){
    ll kq=1;
    while(b){
        if(b&1)kq*=a;
        a=a*a;
        b>>=1;
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
    if(n<=0)cout<<"impossible";
    else{
        map<ll,ll> m[2];
        vector<pair<ll,ll>> ans;
        bool ok=1;
        for(int i=0;i<n;++i){
            ll x; cin>>x;
            if(x==0){ok=0;break;}
            ll cur=x;
            ans.clear();
            for(ll j=2;j*j<=cur;++j){
                if(cur%j==0){
                    int cnt=0;
                    while(cur%j==0)cur/=j,++cnt;
                    ans.pb({j,cnt});
                }
            }
            if(cur!=1)ans.pb({cur,1});

            for(auto j:ans){
                m[0][j.fi]+=j.se;
                m[1][j.fi]=max(m[1][j.fi],j.se);
            }
        }

        if(!ok)cout<<"impossible";
        else{
            ll res=1;
            for(auto i:m[0])res*=exp(i.fi,i.se-m[1][i.fi]);
            cout<<res;
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

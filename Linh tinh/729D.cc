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

string s;
int n,a,b,k;

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

    cin>>n>>a>>b>>k>>s;
    for(int i=n-1;i>=0;--i){
        if(s[i]=='0'){
            int j=i,cnt=1;
            while(j-1>=0&&s[j-1]=='0'&&cnt<b)++cnt,--j;

            //cout<<j<<' '<<cnt<<endl;
            if(cnt==b&&a){
                --a;
                for(int k=i;k>=j;--k)s[k]='2';
            }
            i=j;
        }
    }
    //cout<<s<<endl;

    vector<int> ans;
    int cur=0;
    bool ok=0;
    for(int i=0;i<n;++i){
        if(s[i]=='0'){
            if(cur==b-1)ans.pb(i),cur=0;
            else ++cur;
        }else cur=0;

        if(s[i]=='2'&&!ok)ans.pb(i),ok=1;
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i+1<<' ';

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

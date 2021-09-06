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

const int N=1e3+10;
int c[N][N];
int n,a,b;

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

    cin>>n>>a>>b;
    if(min(a,b)>1)cout<<"NO";
    else{
        if(n==2&&a==1&&b==1)cout<<"NO";
        else if(n==3&&a==b&&a==1)cout<<"NO";
        else{
            cout<<"YES"<<endl;
            bool ok=0;
            if(a==1){
                swap(a,b);
                ok=1;
            }

            for(int i=0;i<n-a;++i)c[i][i+1]=c[i+1][i]=1;
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j)cout<<(char)('0'+((ok^c[i][j])&&i!=j));
                cout<<endl;
            }
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

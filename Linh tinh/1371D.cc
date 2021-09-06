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

const int N=3e2+10;
int a[N][N];
int n,k,t;

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
        for(int i=0;i<n;++i)for(int j=0;j<n;++j)a[i][j]=0;
        cin>>n>>k;
        cout<<((k%n==0)?0:2)<<endl;

        int i=0,j=0;
        while(k--){
            a[i][j]=1;
            ++i,++j,i%=n;
            if(j==n){
                j=0,++i,i%=n;
            }
        }


        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)cout<<a[i][j];
            cout<<endl;
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

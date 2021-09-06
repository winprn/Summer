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
int bit[N][N];
bool mark[N][N];
int n,t;

void upd(int n,int m){
    while(n<=N){
        int j=m;
        while(j<=N){
            bit[n][j]++;
            j+=j&(-j);
        }
        n+=n&(-n);
    }
}

int get(int n,int m){
    int kq=0;
    while(n>0){
        int j=m;
        while(j>0){
            kq+=bit[n][j];
            j-=j&(-j);
        }
        n-=n&(-n);
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

    cin>>t;
    for(int c=1;c<=t;++c){
        cout<<"Case "<<c<<":"<<endl;
        cin>>n;
        memset(bit,0,sizeof(bit));
        memset(mark,0,sizeof(mark));
        while(n--){
            int d; cin>>d;
            if(d==0){
                int x,y; cin>>x>>y,++x,++y;
                if(mark[x][y])continue;
                upd(x,y);
                mark[x][y]=1;
            }else{
                int x1,x2,y1,y2;
                cin>>x1>>y1>>x2>>y2;
                ++x1,++x2,++y1,++y2;
                cout<<get(x2,y2)-get(x2,y1-1)-get(x1-1,y2)+get(x1-1,y1-1)<<endl;
            }
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

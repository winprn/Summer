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

const int N=1e5+10;
int a[N],bit[N];
int n,q,t;

void upd(int i,int val){
    for(;i<=n;i+=i&(-i))bit[i]+=val;
}

int get(int i){
    int kq=0;
    for(;i>0;i-=i&(-i))kq+=bit[i];

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
    for(int cases=1;cases<=t;++cases){
        cout<<"Case "<<cases<<":"<<endl;
        cin>>n>>q;
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;++i)cin>>a[i],upd(i,a[i]);

        while(q--){
            int c; cin>>c;
            if(c==1){
                int id; cin>>id,++id;
                upd(id,-a[id]);
                cout<<a[id]<<endl;
                a[id]=0;
            }else if(c==2){
                int id,v; cin>>id>>v,++id;
                upd(id,v);
                a[id]+=v;
            }else{
                int l,r; cin>>l>>r,++l,++r;
                cout<<get(r)-get(l-1)<<endl;
            }
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

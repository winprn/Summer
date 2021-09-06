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

const int N=2e5+10;
int ar[N],bit[N];
int n,cases=0;

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

    while(cin>>n){
        if(!n)break;
        if(cases)cout<<endl;
        cout<<"Case "<<++cases<<":"<<endl;
        memset(bit,0,sizeof(bit));
        for(int i=1;i<=n;++i){
            cin>>ar[i];
            upd(i,ar[i]);
        }

        string cmd;
        while(cin>>cmd&&cmd!="END"){
            int a,b; cin>>a>>b;
            //cout<<a<<' '<<b<<endl;
            if(cmd=="M")cout<<get(b)-get(a-1)<<endl;
            else upd(a,b-ar[a]),ar[a]=b;
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}

///* ldmm is n00b */
//#include <bits/stdc++.h>
//using namespace std;
//
//const int MOD=5000000;
//const int N=1e4+10;
//pair<int,int> a[N];
//int dp[N],b[N],bit[60][N];
//int n,k;
//
//bool cmp(pair<int,int> a,pair<int,int> b){
//    if(a.first==b.first)return a.second>b.second;
//
//    return a.first<b.first;
//}
//
//void upd(int id,int i,int v){
//    for(;i<=n;i+=i&(-i))bit[id][i]=(bit[id][i]+v)%MOD;
//}
//
//int get(int id,int i){
//    int kq=0;
//    for(;i>0;i-=i&(-i))kq=(kq+bit[id][i])%MOD;
//
//    return kq;
//}
//
//signed main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);
//
//    cin>>n>>k;
//    for(int i=1;i<=n;++i){
//        cin>>a[i].first;
//        a[i].second=i;
//        dp[i]=1;
//    }
//    sort(a+1,a+n+1,cmp);
//    for(int i=1;i<=n;++i)b[a[i].second]=i;
//
//    for(int j=2;j<=k;++j){
//        for(int i=1;i<=n;++i){
//            upd(j-1,b[i],dp[i]);
//            dp[i]=get(j-1,b[i]-1);
//        }
//    }
//
//    int ans=0;
//    for(int i=1;i<=n;++i)ans=(ans+dp[i])%MOD;
//    cout<<ans<<endl;
//}
#include <bits/stdc++.h>
#define up(i,a,b) for (int i = a; i <= b; i++)
using namespace std;

const int maxn = 100001;
const int maxk = 51;
const int MOD = 5000000;
int F[maxk][maxn];
int BIT[maxk][maxn];
int a[maxn];
int n,k;

void compress(){
    vector<int> V;
    V.assign(a+1, a+n+1);
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    up(i,1,n){
        a[i] = lower_bound(V.begin(), V.end(), a[i]) - V.begin() + 1;
    }
}

void add(int& a, int b){
    a = (a + b >= MOD ? a + b - MOD : a + b);
}

int get(int x, int le){
    int res = 0;
    while (x > 0){
        add(res, BIT[le][x]);
        x -= (x & (-x));
    }
    return res;
}

void update(int x, int le, int val){
    while (x <= n){
        add(BIT[le][x], val);
        x += (x & (-x));
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        freopen ("i", "r", stdin);
        freopen ("o", "w", stdout);

    cin >> n >> k;
    up(i,1,n){
        cin >> a[i];
        F[1][i] = 1;
    }
    compress();

    up(j,1,n){
        up(i,1,k){
            if (i > 1) F[i][j] = get(a[j]-1, i-1);
            update(a[j], i, F[i][j]);
        }
    }

    int sum = 0;
    up(i,1,n){
        add(sum, F[k][i]);
    }
    cout << sum;
    return 0;
}

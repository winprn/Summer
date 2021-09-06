#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e3+10;
ll c[N][N],cnt[N];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    c[0][0]=1;
    for(int i=1;i<=1000;++i){
        c[i][0]=1;
        for(int j=1;j<=i;++j){
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
        }
    }
    for(int i=1;i<=n;++i)cin>>cnt[i];
    ll kq=1,total=0;
    for(int i=1;i<=n;++i){
        kq=(kq*c[total+cnt[i]-1][cnt[i]-1])%MOD;
        total+=cnt[i];
    }
    cout<<kq;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
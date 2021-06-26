#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
ll a[N],b[N];
ll n,m,ans=0;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    for(int i=0;i<m;++i)cin>>b[i];
    sort(a,a+n),sort(b,b+m);

    for(int i=0;i<m;++i){
        auto it=lower_bound(a,a+n,b[i]);
        ans+=(*it-b[i]);
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
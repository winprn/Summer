#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
ll a[N],ans[N];
int n,m;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>a[i];
    sort(a,a+n);

    ll pref=0;
    for(int i=0;i<n;++i){
        pref+=a[i];
        ans[i]=pref;
        if(i>=m){
            ans[i]+=ans[i-m];
        }
        cout<<ans[i]<<' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
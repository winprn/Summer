#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
ll a[N];
int n,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        ll mn=1e10;
        int idx=-1;
        for(int i=0;i<n;++i){
            cin>>a[i];
            if(a[i]<mn&&i>0){
                mn=a[i];
                idx=i;
            }
        }

        ll ans=0;
        for(int i=1;i<n;++i){
            if(a[i]==mn)continue;
            ans+=-a[i];
        }
        cout<<ans<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

int cnt[(int)1e5+10];
int n,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        memset(cnt,0,sizeof cnt);
        cin>>n;
        map<int,int>m;
        for(int i=0;i<n;++i){
            int x; cin>>x;
            m[x]++;
        }

        for(auto i:m)cnt[i.se]++;

        int ans=0,bad=0;
        for(int c=1;c<=n;++c){
            ans=max(ans,c*((int)m.size()-bad));
            bad+=cnt[c];
        }
        cout<<n-ans<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
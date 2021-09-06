#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

pair<int,pair<int,int>> a[105];
int n,m,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;++i){
            cin>>a[i].fi>>a[i].se.fi>>a[i].se.se;
        }

        int mn=m,mx=m,lst=0;
        bool ok=1;
        for(int i=0;i<n;++i){
            int time=a[i].fi-lst;
            mn=mn-time,mx=mx+time;
            if(mn<=a[i].se.se&&mx>=a[i].se.fi){
                mn=max(mn,a[i].se.fi);
                mx=min(mx,a[i].se.se);
                lst=a[i].fi;
            }else {ok=0;break;}
        }
        cout<<(ok?"YES":"NO")<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
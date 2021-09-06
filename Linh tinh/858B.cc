#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

pair<int,int> a[105];
int n,m;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<m;++i)cin>>a[i].fi>>a[i].se;

    int ans=-1;
    for(int num=1;num<=100;++num){
        bool bad=0;
        for(int i=0;i<m;++i){
            int tmp=((a[i].fi+num-1)/num);
            if(tmp!=a[i].se){
                bad=1;
                break;
            }
        }
        if(!bad){
            if(ans==-1)ans=(n+num-1)/num;
            else if(ans!=(n+num-1)/num){
                ans=-1;
                break;
            }
        }
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
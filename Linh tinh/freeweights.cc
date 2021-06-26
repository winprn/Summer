#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e6+10;
int a[2][N];
int n,ans=-1;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[0][i];
    for(int i=0;i<n;++i)cin>>a[1][i];

    for(int i=0;i<2;++i){
        int mx=0,cur=0;
        for(int j=0;j<n;++j){
            if(cur==a[i][j])cur=0;
            else if(cur>a[i][j])mx=max(mx,a[i][j]);
            else {mx=max(mx,cur);cur=a[i][j];}
        }
        ans=max({ans,mx,cur});
    }
    cout<<ans;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
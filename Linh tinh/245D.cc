#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int a[105][105],ans[105];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cin>>a[i][j];
    }

    if(n==1)cout<<0;
    else{
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j)continue;
                ans[i]|=a[i][j];
            }
        }
        for(int i=0;i<n;++i)cout<<ans[i]<<' ';
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
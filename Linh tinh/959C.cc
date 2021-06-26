#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    if(n<6)cout<<"-1"<<endl;
    else{
        cout<<1<<' '<<2<<endl;
        for(int i=3;i<=n-2;++i)cout<<2<<' '<<i<<endl;
        cout<<3<<' '<<n-1<<endl;
        cout<<3<<' '<<n<<endl;
    }
    for(int i=1;i<n;++i)cout<<i<<' '<<i+1<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
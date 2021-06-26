#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
int a[N],p[N];
bool mark[N];
int n,q;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>q;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n;++i){
        p[i]=p[i-1];
        p[i]+=(a[i]>=a[i-1]&&a[i]>=a[i+1]);
    }

    while(q--){
        int l,r; cin>>l>>r;
        int num=p[r]-p[l-1];
        if(l==r)cout<<1;
        else if(num==0){
            if((a[l]<=a[l+1]&&a[r]>=a[r-1])||(a[l]>=a[l+1]&&a[r]<=a[r-1]))cout<<1;
            else cout<<0;
        }else if(num==1){
            if(a[l]>=a[l+1]||a[r]>=a[r-1])cout<<1;
            else if(a[l]<a[l+1]&&a[r]<a[r-1])cout<<1;
            else cout<<0;
        }else cout<<0;
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
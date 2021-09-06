#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
int a[N],pref[N],suf[N];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i];
    pref[0]=suf[n-1]=INT_MAX;
    for(int i=1;i<n;++i)pref[i]=pref[i-1]&(~a[i-1]);
    for(int i=n-2;i>=0;--i)suf[i]=suf[i+1]&(~a[i+1]);
    int mx=-1,idx=-1;
    for(int i=0;i<n;++i){
        int cur=pref[i]&a[i]&suf[i];
        if(cur>mx)mx=cur,idx=i;
    }

    cout<<a[idx];
    for(int i=0;i<n;++i)if(i!=idx)cout<<' '<<a[i];

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
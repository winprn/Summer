#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
int a[N],ans[N],l[N],r[N];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("gnlh.inp", "r", stdin);
    freopen("gnlh.out", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];

    stack<int> s,id;
    s.push(a[1]),id.push(1);
    for(int i=2;i<=n;++i){
        while(!s.empty()&&s.top()<=a[i])s.pop(),id.pop();
        if(s.empty())l[i]=1e9;
        else l[i]=id.top();

        s.push(a[i]),id.push(i);
    }

    while(!s.empty())s.pop(),id.pop();
    s.push(a[n]),id.push(n);
    for(int i=n-1;i>=1;--i){
        while(!s.empty()&&s.top()<=a[i])s.pop(),id.pop();
        if(s.empty())r[i]=1e9;
        else r[i]=id.top();

        s.push(a[i]),id.push(i);
    }

    ans[1]=(r[1]==1e9?1e9:a[r[1]]);
    for(int i=2;i<n;++i){
        if(i-l[i]==r[i]-i&&r[i]!=1e9)ans[i]=max(a[l[i]],a[r[i]]);
        else if(i-l[i]<r[i]-i&&l[i]!=1e9)ans[i]=a[l[i]];
        else if(r[i]!=1e9)ans[i]=a[r[i]];
        else ans[i]=1e9;
    }
    ans[n]=(l[n]==1e9?1e9:a[l[n]]);
    for(int i=1;i<=n;++i)if(ans[i]==1e9)cout<<"9999999 ";else cout<<ans[i]<<' ';

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
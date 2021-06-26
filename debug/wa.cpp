#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
int a[N];
int n,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    map<int,int>idx;
    for(int i=0;i<n;++i){
        cin>>a[i];
        idx[a[i]]=i+1;
    }

    ll ans=0;
    for(int i=0;i<n;++i){
        if(a[i]==1)continue;
        int cur=a[i];
        for(int j=2;cur<=2*n;++j){
            if(idx[cur/a[i]]+(i+1)==cur&&idx[cur/a[i]]!=i+1&&idx[cur/a[i]]!=0&&(idx[cur/a[i]]>i+1||cur/a[i]==1)){
                //cout<<i+1<<endl;
                ++ans;
            }
            cur=a[i]*j;
        }
    }
    cout<<ans<<endl;

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
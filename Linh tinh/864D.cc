#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
int a[N],cnt[N];
bool ok[N];
int n;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    memset(ok,false,sizeof ok);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int cur=1,ans=0;
    for(int i=0;i<n;++i){
        for(;cnt[cur]>0;++cur);
        if(cnt[a[i]]>1&&(cur<a[i]||ok[a[i]])){
            --cnt[a[i]];
            a[i]=cur;
            ++ans;
            ++cnt[a[i]];
        }else ok[a[i]]=1;
    }
    
    cout<<ans<<endl;
    for(int i=0;i<n;++i)cout<<a[i]<<' ';

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
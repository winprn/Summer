#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int a[2005];
int n,ans=1e9,cnt=0;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        cnt+=(a[i]==1);
    }
    
    if(cnt)cout<<n-cnt<<endl;
    else {
        for(int i=0;i<n;++i){
            int gcd=a[i],cur=0;
            for(int j=i;j<n;++j){
                gcd=__gcd(gcd,a[j]);
                if(gcd==1){cur=j-i;break;}
            }
            if(gcd==1)ans=min(ans,cur);
        }
        if(ans==1e9)cout<<"-1";
        else cout<<ans+n-1;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
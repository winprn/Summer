#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define MOD 1000000007

typedef long long ll;

int n,m,k,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        if(!m){
            if(n){
                for(int i=0;i<=n;++i)cout<<0;
                cout<<endl;
            }else {
                for(int i=0;i<=k;++i)cout<<1;
                cout<<endl;
            }
        }else{
            for(int i=0;i<n;++i)cout<<0;
            cout<<"01";
            for(int i=0;i<k;++i)cout<<1;
            
            --m;
            int cur=0;
            while(m){
                cout<<cur;
                --m,cur^=1;
            }
            cout<<endl;
        }
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
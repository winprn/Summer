#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

int a[105];
int n,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;++i)a[i]=i+1;
        if(n&1){
            for(int i=0;i<n-1;i+=2){
                swap(a[i],a[i+1]);
            }
            swap(a[n-2],a[n-1]);
        }else{
            for(int i=0;i<n-1;i+=2){
                swap(a[i],a[i+1]);
            }
        }

        for(int i=0;i<n;++i)cout<<a[i]<<' ';
        cout<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
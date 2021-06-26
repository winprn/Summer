#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
string s;
int p[3][N];
int n,k,t;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>t;
    while(t--){
        cin>>n>>k>>s;
        int zero=0,one=0;
        bool ok=1;
        for(int i=0;i<k;++i){
            int cur=-1;
            for(int j=i;j<n;j+=k){
                if(s[j]!='?'){
                    if(cur!=-1&&s[j]-'0'!=cur){
                        ok=0;
                        break;
                    }
                    
                cur=s[j]-'0';
                }
            }
            if(cur!=-1){
                ++(cur==0?zero:one);
            }
        }
        if(max(zero,one)>k/2)ok=0;
        cout<<(ok?"YES":"NO")<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
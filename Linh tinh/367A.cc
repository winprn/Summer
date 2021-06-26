#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=1e5+10;
string s;
int x[N],y[N],z[N];
int n,m;

int main() {
    cout.precision(10);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s;
    int n=(int)s.size();
    for(int i=0;i<n;++i){
        x[i+1]=x[i]+(s[i]=='x');
        y[i+1]=y[i]+(s[i]=='y');
        z[i+1]=z[i]+(s[i]=='z');
    }

    cin>>m;
    while(m--){
        int l,r; cin>>l>>r;
        int nx=x[r]-x[l-1],ny=y[r]-y[l-1],nz=z[r]-z[l-1];
        bool ok=1;
        if(nx-ny>1||nx-nz>1||ny-nz>1)ok=0;
        if(ny-nx>1||nz-nx>1||nz-ny>1)ok=0;
        if(nx+ny+nz<=2)ok=1;

        cout<<((ok)?"YES":"NO")<<endl;
    }

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
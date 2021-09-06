#include <bits/stdc++.h>

using namespace std;

#define sqr(x) (x)*(x)
#define MOD 1000000007

typedef long long ll;
typedef double ld;

ld x[1005],y[1005];
ld r;
int n;

ld calc(ld a,ld b,ld c){
    ld A=sqr(a-b);
    ld B=-2*c;
    ld C=sqr(2*r)-sqr(c)-A;
    ld delta=sqr(B)+4*C;

    if(a==43)cout<<a<<' '<<b<<' '<<c<<' '<<A<<' '<<B<<' '<<C<<' '<<delta<<endl;

    return max(-B+sqrt(delta),-B-sqrt(delta))/2.;
}

int main() {
    cout.precision(6);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>r;
    for(int i=0;i<n;++i)cin>>x[i];
    y[0]=r;

    for(int i=1;i<n;++i){
        int idx=-1;
        bool ok=0;
        for(int j=i-1;j>=0;--j){
            if(abs(x[i]-x[j])<=2*r){
                y[i]=max(y[i],calc(x[i],x[j],y[j]));
                ok=1;
                idx=j;
                //break;
            }
        }
        //if(i==25)cout<<idx<<endl;
        if(!ok)y[i]=r;
    }
    for(int i=0;i<n;++i)cout<<y[i]<<' ';

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
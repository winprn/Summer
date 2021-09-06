/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e4+10;
double a[N];
int n,k,cut=0;

int get(double x){
    int kq=0;
    cut=0;
    for(int i=0;i<n;++i){
        int cur=a[i]/x;
        kq+=cur;
        if(x==1&&a[i]-x>1e-8)++cut;
        else if(a[i]-cur*x<1e-7)cut+=(cur-1);
        else cut+=cur;
    }

    return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout.fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];

    double l=1,r=2e4,ans=0;
    for(int i=0;i<64;++i){
        double m=(l+r)/2.;
        //cout<<m<<endl;
        int tmp=get(m);
        if(tmp>=k)l=m;
        else r=m;
    }
    cout<<cut;
}

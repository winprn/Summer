/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

#define sqr(x) (x)*(x)

long double A,B,C;
long long x,y;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(9);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>x>>y;
    A=sqrt(2)*sqrt(x*(x+y))-x;
    B=y-A;
    C=sqrt(sqr(A)+sqr(B));
    cout<<min(A,B)<<' '<<max(A,B)<<' '<<C<<endl;
}

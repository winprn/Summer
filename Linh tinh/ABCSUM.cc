/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

int a,b,c;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("i", "r", stdin);
//    freopen("o", "w", stdout);

    cin>>a>>b>>c;
    cout<<(a+b==c||a+c==b||c+b==a);
}

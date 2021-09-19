/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

int n,s,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n>>s;
    int zero=(n+1)/2-1;
    if(n==1)cout<<s<<endl;
    else cout<<s/(n-zero)<<endl;
  }
}

/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

long long n,p,w,d,a,b=-1;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>p>>w>>d;
  for(a=0;a<w&&a*d<=p;++a){
    long long cur=d*a;
    if((p-cur)%w==0&&(p-cur)/w+a<=n){b=(p-cur)/w;break;}
  }

  if(b==-1)cout<<b;
  else cout<<b<<' '<<a<<' '<<n-a-b<<endl;
}

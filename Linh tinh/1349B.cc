/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int n,k,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n>>k;
    int cnt=0;
    memset(a,0,sizeof(a));
    for(int i=0;i<n;++i){
      cin>>a[i];
      if(a[i]<k)a[i]=0;
      else if(a[i]==k)a[i]=1,++cnt;
      else a[i]=2;
    }

    bool ok=(n==1);
    for(int i=0;i<n;++i){
      if(a[i]&&(a[i+1]||a[i+2])){ok=1;break;}
    }
    if(ok&&cnt)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
}

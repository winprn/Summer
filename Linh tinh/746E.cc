/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
map<int,int> cnt,cnt2;
map<int,bool> mark;
int a[N],b[N];
int n,m,ans=0;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>m;
  int od=0,ev=0;
  for(int i=0;i<n;++i)cin>>a[i],cnt[a[i]]++,b[i]=a[i],od+=(a[i]&1),ev+=!(a[i]&1);

  int odd=1,even=2;
  for(int i=0;i<n;++i){
    while(cnt2[odd]>1)odd+=2;
    while(cnt2[even]>1)even+=2;
    if(odd>m&&even>m)break;
    if(cnt[a[i]]>1){
      cnt[a[i]]--;
      if(a[i]&1)a[i]=even,cnt2[even]++,even+=2,--od,++ev;
      else a[i]=odd,cnt2[odd]++,odd+=2,++od,--ev;
    }
  }
//  for(int i=0;i<n;++i)cout<<a[i]<<' ';
//  cout<<endl;

  //for(int i=0;i<n;++i)od+=(a[i]&1),ev+=!(a[i]&1);
  if(ev>od){
    for(int i=0;i<n;++i){
      while(cnt2[odd])odd+=2;
      if(odd>m||od==ev)break;
      if(!(a[i]&1))cnt[a[i]]--,a[i]=odd,cnt[a[i]]++,cnt2[odd]++,--ev,++od;
    }
  }else if(od>ev){
    for(int i=0;i<n;++i){
      while(cnt2[even])even+=2;
      if(even>m||od==ev)break;
      if(a[i]&1)cnt[a[i]]--,a[i]=even,cnt[a[i]]++,cnt2[even]++,--od,++ev;
    }
  }
//  for(int i=0;i<n;++i)cout<<a[i]<<' ';
//  cout<<endl;

  bool ok=1;
  for(int i=0;i<n;++i){
    ans+=(a[i]!=b[i]);
    if(mark[a[i]]){ok=0;break;}
    mark[a[i]]=1;
  }
  if(!ok||od!=ev)cout<<"-1";
  else {
    cout<<ans<<endl;
    for(int i=0;i<n;++i)cout<<a[i]<<' ';
  }
}

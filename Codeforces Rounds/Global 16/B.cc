/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
string s;
int a[N];
int t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>s;
    int ans=0,cnt=0,idx=0;
    for(int i=0;i<(int)s.size();++i){
      int j=i;
      if(s[i]=='0'){
        while(s[i]=='0'&&j+1<s.size()&&s[j+1]=='0')++j;
        a[idx++]=0;
      }else if(s[i]=='1'){
        while(j+1<s.size()&&s[j+1]=='1')++j;
        a[idx++]=1;
      }else{
        while(j+1<s.size()&&s[j+1]=='2')++j;
        a[idx++]=2;
      }

      i=j;
    }

    int i=0;
    while(i<idx){
      //cout<<a[i]<<' ';
      if(a[i]==0){
        int j=i+1;
        while(j<idx&&a[j]!=a[j-1])++j;
        if(j-i>=3)ans+=2;
        else ++ans;
        i=j;
      }else ++i;
    }
    //cout<<endl;
    cout<<ans<<endl;
  }
}

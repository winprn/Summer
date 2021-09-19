/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[2][N];
int n,t;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n;
    for(int i=0;i<2;++i)for(int j=0;j<n;++j)a[i][j]=2;
    for(int i=0;i<2;++i){
      for(int j=0;j<n;++j){
        char c; cin>>c;
        a[i][j]=(c-'0');
      }
    }
//    for(int i=0;i<2;++i){
//      for(int j=0;j<n;++j)cout<<a[i][j]<<' ';
//      cout<<endl;
//    }

    int ans=0,i=0;
    while(i<n){
      if(a[0][i]==0&&a[1][i]==0){
        if(a[0][i+1]==1&&a[1][i+1]==1&&i+1<n){
          //cout<<i<<' ';
          ans+=2;
          i+=2;
        }else{
          ++ans;
          ++i;
        }
      }else if(a[0][i]==1&&a[1][i]==1){
        if((!a[0][i+1]||!a[1][i+1])&&i+1<n){
          //cout<<i<<'!';
          ans+=2;
          i+=2;
        }else ++i;
      }else ans+=2,++i;
    }
    //cout<<endl;
    cout<<ans<<endl;
  }
}

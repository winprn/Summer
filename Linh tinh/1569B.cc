/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=55;
string s;
char a[N][N];
bool b[N],ok[N],ok2[N];
int n,t;

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("i", "r", stdin);
  freopen("o", "w", stdout);

  cin>>t;
  while(t--){
    cin>>n>>s;
    for(int i=0;i<n;++i)for(int j=0;j<n;++j)a[i][j]='.',b[i]=(s[i]-'0'==1),ok[i]=b[i],ok2[i]=0;
    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        if(a[i][j]!='.')continue;
        if(i==j){a[i][j]=a[j][i]='X';continue;}
        if(b[i]&&b[j])a[i][j]=a[j][i]='=';
        else if(b[i]&&!b[j])a[i][j]='+',a[j][i]='-';
        else if(!b[i]&&b[j])a[i][j]='-',a[j][i]='+';
        else if(!ok2[i])a[i][j]='+',a[j][i]='-';
        else a[i][j]='-',a[j][i]='+';

        ok2[i]|=(a[i][j]=='+');
      }
    }

    for(int i=0;i<n;++i){
      for(int j=0;j<n;++j){
        if(b[i]&&a[i][j]=='-')ok[i]=0;
        if(!b[i]&&a[i][j]=='+')ok[i]=1;
      }
    }
//    for(int i=0;i<n;++i){
//      for(int j=0;j<n;++j)cout<<a[i][j];
//      cout<<endl;
//    }

    if(count(ok,ok+n,1)!=n)cout<<"NO"<<endl;
    else{
      cout<<"YES"<<endl;
      for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)cout<<a[i][j];
        cout<<endl;
      }
    }
  }
}

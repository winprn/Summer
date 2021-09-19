/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const long long MOD=1e15+37;
const int N=6e5+10;
unordered_set<long long> a;
long long h[N];
int n,m,base=1009;

long long getHash(string s){
  long long kq=0;
  for(int i=0;i<s.size();++i)kq=(kq+h[i]*int(s[i]))%MOD;

  return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

  cin>>n>>m;
  h[0]=1;
  for(int i=1;i<N;++i)h[i]=(h[i-1]*base)%MOD;
  for(int i=0;i<n;++i){
    string s; cin>>s;
    //cout<<getHash(s)<<' ';
    a.insert(getHash(s));
  }

  for(int i=0;i<m;++i){
    string s; cin>>s;
    long long cur=getHash(s);
    bool ok=0;
    for(int j=0;j<s.size();++j){
      //cout<<prf<<' '<<suf<<endl;
      for(char k='a';k<='c';++k){
        if(k==s[j])continue;
        long long tmp=cur+h[j]*(k-s[j]);
        while(tmp<0)tmp+=MOD;
        while(tmp>=MOD)tmp-=MOD;
        //cout<<tmp<<endl;
        if(a.count(tmp)){
          ok=1;
          break;
        }
      }
      if(ok)break;
    }

    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}

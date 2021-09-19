/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N];
int n,k;

void solve(int l,int r){
  if(k==1||l+1==r)return;
  k-=2;
  int m=(l+r)/2;
  swap(a[m-1],a[m]);
  solve(l,m);
  solve(m,r);
}

signed main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("i", "r", stdin);
  freopen("o", "w", stdout);

  cin>>n>>k;
  if(k%2==0)cout<<"-1";
  else{
    for(int i=0;i<n;++i)a[i]=i+1;
    solve(0,n);
    if(k>1)cout<<"-1";
    else for(int i=0;i<n;++i)cout<<a[i]<<' ';
  }
}

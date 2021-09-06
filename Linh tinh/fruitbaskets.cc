/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=45;
int a[N];
long long tot=0,sum=0;
int n;

void dfs(int i,int cur){
    if(cur>=200)return;
    if(i>n){sum+=cur;return;}
    dfs(i+1,cur+a[i]);
    dfs(i+1,cur);
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        tot+=(1LL*a[i]*(1LL<<(n-1))); //number of times an element contribute to a subset sum
    }

    // find sum of subset < 200
    dfs(1,0);
    //cout<<tot<<' '<<sum<<endl;
    cout<<tot-sum;
}

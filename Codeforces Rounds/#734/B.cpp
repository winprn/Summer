#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e5+10;
vector<int> idx[N],tmp;
int a[N],cnt[N],ans[N];
int n,k,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<=n;++i)idx[i].clear(),cnt[i]=ans[i]=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
			idx[a[i]].pb(i);
			cnt[a[i]]++;	
			if(cnt[a[i]]==k){
				for(int j=0;j<k;++j)ans[idx[a[i]][j]]=j+1;
			}
		}
		
		tmp.clear();
		for(int i=1;i<=n;++i){
			if((int)idx[i].size()<k)for(int j:idx[i])tmp.pb(j);
		}
		
		for(int j=0;j<(int)tmp.size()-((int)tmp.size()%k);++j)ans[tmp[j]]=j%k+1;
		for(int i=1;i<=n;++i)cout<<ans[i]<<' ';
		cout<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
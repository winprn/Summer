#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e4+10;
vector<pair<int,int>> ans;
int a[N],cnt[N],nxt[N][105],lst[N];
int n,k;

signed main(){
	cin>>n>>k;
	for(int i=0;i<n*k;++i){
		cin>>a[i];
		if(cnt[a[i]]){
			nxt[lst[a[i]]][a[i]]=i;
		}
		
		cnt[a[i]]++;
		lst[a[i]]=i;
	}
	
	int t=(n+k-2)/(k-1);
	//for(int i=0;i<n*k;++i)cout<<i<<' '<<nxt[i][a[i]]<<endl;
	for(int i=0;i<n*k;++i)cnt[i]=t;
	for(int i=0;i<n*k;++i){
		if(!cnt[i]||!nxt[i][a[i]])continue;
		if((int)ans.size()>=n)break;
		bool ok=0,bad=0;
		if((int)ans.size()==n-1)ok=1;
		for(int j=i+1;j<nxt[i][a[i]];++j){
			if(!ok){
				if(cnt[j]==1){bad=1;break;}
			}else{
				cnt[j]--;
			}
		}
		
		//cout<<i<<' '<<bad<<endl;
		if(!bad){
			ans.pb({i,nxt[i][a[i]]});
			for(int j=i;j<=nxt[i][a[i]];++j)cnt[j]--;
		}
	}
	
	// cout<<ans.size()<<endl;
	// assert((int)ans.size()==n);
	sort(ans.rbegin(),ans.rend());
	for(auto i:ans)cout<<i.fi+1<<' '<<i.se+1<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
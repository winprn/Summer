#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=2e5+10;
string s[N];
int n,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s[i];
		
		ll ans=0,tot=0,tot2=0;
		for(int j=0;j<5;++j){
			priority_queue<int> pq;
			tot=tot2=0;
			for(int i=0;i<n;++i){
				int cnt=0;
				for(int k=0;k<(int)s[i].size();++k){
					if(s[i][k]-'a'==j)++cnt;
				}
				//cout<<cnt<<endl;
				pq.push(cnt-(int)s[i].size()+cnt);
			}
			if(pq.empty())continue;
			
			tot+=pq.top();
			tot2+=(tot>0);
			pq.pop();
			while(tot&&!pq.empty()){
				tot+=pq.top();
				pq.pop();
				tot2+=(tot>0);
			}
			ans=max(ans,tot2);
		}
		cout<<ans<<endl;
	}	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
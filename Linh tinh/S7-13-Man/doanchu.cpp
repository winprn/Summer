#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

vector<string> dict[30];
int idx[30];
int n,m;

signed main(){
	freopen("doanchu.inp","r",stdin);
	freopen("doanchu.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;++i){
		string s; cin>>s;
		idx[s[0]-'a']=0;
		dict[s[0]-'a'].pb(s);
	}
	for(int i=0;i<=27;++i)sort(dict[i].begin(),dict[i].end());
	
	for(int i=0;i<m;++i){
		char x; cin>>x;
		cout<<dict[x-'a'][idx[x-'a']]<<endl;
		idx[x-'a']=(idx[x-'a']+1)%(int)(dict[x-'a'].size());
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
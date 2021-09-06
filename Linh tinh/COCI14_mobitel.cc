#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s;
int par[10];

signed main(){
	for(int i=1;i<=9;++i){
		int x; cin>>x;
		par[x]=i;
	}
	
	cin>>s;
	vector<pair<int,int>> ans;
	for(int i:s){
		if(i>='a'&&i<='c')ans.pb({2,i-'a'});
		else if(i>='d'&&i<='f')ans.pb({3,i-'d'});
		else if(i>='g'&&i<='i')ans.pb({4,i-'g'});
		else if(i>='g'&&i<='i')ans.pb({4,i-'g'});
		else if(i>='j'&&i<='l')ans.pb({5,i-'j'});
		else if(i>='m'&&i<='o')ans.pb({6,i-'m'});
		else if(i>='p'&&i<='s')ans.pb({7,i-'p'});
		else if(i>='t'&&i<='v')ans.pb({8,i-'t'});
		else if(i>='w'&&i<='z')ans.pb({9,i-'w'});
	}
	
	vector<char> kq;
	int lst=-1;
	for(auto i:ans){
		//cout<<i.fi<<' '<<i.se<<endl;
		if(i.fi==lst)kq.pb('#');
		for(int j=0;j<=i.se;++j)kq.pb((char)('0'+par[i.fi]));
		lst=i.fi;
	}
	for(auto i:kq)cout<<i;	
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
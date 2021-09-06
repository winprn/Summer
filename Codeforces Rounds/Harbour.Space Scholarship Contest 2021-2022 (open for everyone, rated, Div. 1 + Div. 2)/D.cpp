#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s,t;
int ts;

signed main(){
	cin>>ts;
	while(ts--){
		cin>>s>>t;
		int n=(int)s.size(),m=(int)t.size();
		int id=m-1;
		bool ok=0;
		for(int i=n-1;i>=0;--i){
			if(s[i]!=t[id])--i;
			else --id;
			ok=(ok||id<0);
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
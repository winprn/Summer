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
		
		bool ok=0;
		for(int i=0;i<n;++i){
			if(s[i]==t[0]){
				int j=i+1,id=1;
				while(j<n&&s[j]==t[id])++j,++id;
				
				j=j-1,id--;
				while(j>=0&&id<m&&s[j]==t[id])--j,++id;
				
				// /cout<<j<<' '<<id<<endl;
				ok=(ok||id==m);
			}
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
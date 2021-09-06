#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

int n,m,k,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int l=(n*m)/2-k;
		if((k%2==n%2&&l%2==m%2)||(k%2!=n%2&&l%2!=m%2))cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
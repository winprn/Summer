#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

int n;

signed main(){
	cin>>n;
	ll cur=1,tot=0;
	for(int i=0;i<n;++i){
		ll x; cin>>x;
		cout<<x*cur-tot<<' ';
		tot+=(x*cur-tot);cur++;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
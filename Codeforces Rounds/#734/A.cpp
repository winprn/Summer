#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

int n,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		int tmp=n/3;
		if(n%3==0)cout<<tmp<<' '<<tmp<<endl;
		else if(tmp+1+tmp*2==n)cout<<tmp+1<<' '<<tmp<<endl;
		else cout<<tmp<<' '<<tmp+1<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
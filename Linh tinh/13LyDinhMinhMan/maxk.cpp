#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
int a[N];
int n,k;

signed main(){
	freopen("maxk.inp","r",stdin);
	freopen("maxk.out","w",stdout);	

	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
		
	deque<int> dq;
	for(int i=1;i<=n;++i){
		while(!dq.empty()&&a[dq.back()]<=a[i])dq.pop_back();
		
		dq.pb(i);
		if(dq.front()+k<=i)dq.pop_front();
		if(i>=k)cout<<a[dq.front()]<<' ';
	}	
	cout<<endl;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e3+10;
ll a[N],h[N],num[N];
int n,m;

signed main(){
	cin>>n>>m;
	
	ll ans=0;
	a[0]=h[0]=num[0]=0;
	for(int i=1;i<=n;++i){
		stack<int> st;
		int lst=0;
		for(int j=1;j<=m;++j){
			int idx=-1,x; cin>>x;
			h[j]=(a[j]==x?h[j]:0)+1,a[j]=x;
			if(a[j]!=a[j-1]){
				lst=j-1;
				num[j-1]=0;
				while(!st.empty())st.pop();
			}
			
			while(!st.empty()&&h[st.top()]>=h[j])st.pop();
			if(idx==-1)idx=(st.empty()?lst:st.top());
			assert(idx!=-1);
			num[j]=num[idx]+(j-idx)*h[j];
			st.push(j);
			ans+=num[j];
		}
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
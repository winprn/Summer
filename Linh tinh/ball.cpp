#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define MOD 1000000007

typedef long long ll;

const int N=3e5+10;
int a[N],par[N],t[N],s[N];
int n,m;

int findP(int u){
	return((par[u]<0||par[u]==u)?u:par[u]=findP(par[u]));
}

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr),cout.tie(nullptr);
	freopen("ball.inp","r",stdin);
	freopen("ball.out","w",stdout);

	cin>>n;
	for(int i=0;i<n;++i)par[i]=-2;
	for(int i=0;i<n;++i){
		cin>>a[i];
		--a[i];
		if(a[i]<0)par[i]=-1;
	}

	cin>>m;
	for(int i=0;i<m;++i){
		cin>>t[i]>>s[i],--s[i];
		if(t[i]==2)par[s[i]]=-1;
	}

	for(int i=n-1;i>=0;--i){
		if(par[i]==-2)par[i]=findP(a[i]);
	}

	vector<int> ans;
	for(int i=m-1;i>=0;--i){
		if(t[i]==1){
			int u=findP(s[i]);
			ans.pb(par[u]==-1?u:-1);
		}else{
			par[s[i]]=findP(a[s[i]]);
		}
	}

	//cout<<id;
	reverse(ans.begin(),ans.end());
	for(int i:ans){
		if(i==-1)cout<<"LOOP";
		else cout<<i+1;
		cout<<endl;
	}

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}

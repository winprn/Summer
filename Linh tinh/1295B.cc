#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int N=1e5+10;
string s;
int p[N];
int n,t,x;

signed main(){
	cin>>t;
	while(t--){
		cin>>n>>x>>s;
		p[0]=(s[0]=='0'?1:-1);
		for(int i=1;i<n;++i)p[i]=p[i-1]+(s[i]=='0'?1:-1);
		
		int ans=(x==0?1:0),lst=abs(p[n-1]);
		bool ok=1;
		for(int i=0;i<n;++i){
			if(p[n-1]==0){
				if(p[i]==x){ok=0;break;}
			}else{
				int cur=(p[i]%lst+lst)%lst;
				int tmp=(x%lst+lst)%lst;
				if(tmp==cur){
					if((x==p[i])||(p[i]<x&&p[n-1]>0)||(p[i]>x&&p[n-1]<0))++ans;
				}
			}
		}
		
		cout<<(ok?ans:-1)<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
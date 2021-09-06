#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s;
ll ans[10][10];
int d[10][10];

signed main(){
	cin>>s;
	for(int x=0;x<10;++x){
		for(int y=0;y<10;++y){
			for(int i=0;i<10;++i)for(int j=0;j<10;++j)d[i][j]=1e9;
			for(int i=0;i<10;++i){
				d[i][(i+x)%10]=d[i][(i+y)%10]=1;
			}
			
			for(int k=0;k<10;++k)for(int i=0;i<10;++i){
				for(int j=0;j<10;++j)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
			
			for(int i=0;i<(int)s.size()-1;++i){
				ans[x][y]+=d[s[i]-'0'][s[i+1]-'0']-1;
				if(d[s[i]-'0'][s[i+1]-'0']>=1000000000LL){ans[x][y]=1000000000LL;break;}
			}
		}
	}
	
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j)cout<<(ans[i][j]<1e9?ans[i][j]:-1)<<' ';
		cout<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
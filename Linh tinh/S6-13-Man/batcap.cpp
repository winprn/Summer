#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define sqr(x) (x)*(x)
#define MOD 1000000007
 
typedef long long ll;

double dp[(1<<20)];
double x[20],y[20],dist[20][20];
int n,cases=0;

double _dist(double x1,double y1,double x2,double y2){
	return sqrt(sqr(x1-x2)+sqr(y1-y2));
}

double _dp(int mask){
	if(mask==(1<<2*n)-1)return 0;
	
	double &ans=dp[mask];
	if(ans!=0)return ans;
	
	ans=1e9;
	int a=-1,b=-1;
	for(a=0;a<2*n;++a){
		if(!(1&(mask>>a)))break;
	}
	
	for(b=a+1;b<2*n;++b){
		if(!(1&(mask>>b))){
			ans=min(ans,dist[a][b]+_dp(mask|(1<<a)|(1<<b)));
		}
	}
	return ans;
}

signed main(){
	freopen("batcap.inp","r",stdin);
	freopen("batcap.out","w",stdout);
	
	cout.precision(2);
	cout<<fixed;
	while(cin>>n,n){
		for(int i=0;i<2*n;++i){
			string s; cin>>s;
			cin>>x[i]>>y[i];
		}
		for(int i=0;i<2*n;++i){
			for(int j=i+1;j<2*n;++j){
				dist[i][j]=_dist(x[i],y[i],x[j],y[j]);
				dist[j][i]=dist[i][j];
			}
		}
		
		memset(dp,0,sizeof dp);
		cout<<"Case "<<++cases<<": "<<_dp(0)<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
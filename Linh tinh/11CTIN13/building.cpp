#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

const int td[4]={0,0,1,-1};
const int tc[4]={1,-1,0,0};
const int N=5e3+10;
vector<pair<int,pair<int,int>>> b;
int a[N][N];
bool vis[N][N];
int n,m,one,cnt;

bool ok(int i,int j){
	return(i>=0&&i<n&&j>=0&&j<m);
}

void bfs(int si,int sj){
	queue<pair<int,int>> q;
	q.push({si,sj});
	
	while(!q.empty()){
		int ui=q.front().fi;
		int uj=q.front().se;
		q.pop();
		
		for(int i=0;i<4;++i){
			int vi=ui+td[i];
			int vj=uj+tc[i];
			if(ok(vi,vj)&&!vis[vi][vj]&&a[vi][vj]<=a[ui][uj]){
				vis[vi][vj]=1;
				q.push({vi,vj});
			}
		}
	}
}

signed main(){
	freopen("building.inp","r",stdin);
	freopen("building.out","w",stdout);
	
	cin>>n>>m;
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)cin>>a[i][j],b.pb({a[i][j],{i,j}});
	sort(b.begin(),b.end());
	
	int ans=0;
	while(!b.empty()){
		int i=b.back().se.fi;
		int j=b.back().se.se;
		if(b.back().fi<=1){b.pop_back();continue;}
		b.pop_back();
		if(vis[i][j])continue;
		bfs(i,j);
		++ans;
	}
	cout<<ans;
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
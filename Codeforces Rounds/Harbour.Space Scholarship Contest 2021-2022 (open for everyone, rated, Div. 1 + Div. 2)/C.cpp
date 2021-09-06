#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s;
int cnt[2],lft[2];
int ts;

signed main(){
	cin>>ts;
	while(ts--){
		cin>>s;
		int n=(int)s.size();
		
		int ans=10;
		for(int i=0;i<=1;++i){
			cnt[0]=cnt[1]=0,lft[0]=lft[1]=5;
			for(int j=0;j<n;++j){
				if(s[j]=='1')cnt[j&1]++;
				if(s[j]=='?')cnt[j&1]+=((j&1)==i);
				lft[j&1]--;
				if(cnt[i]>cnt[1-i]+lft[1-i]){
					ans=min(ans,j+1);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
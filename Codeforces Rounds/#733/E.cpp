#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s;
int cnt[30];
int n,t;

signed main(){
	cin>>t;
	while(t--){
		cin>>s;
		int n=(int)s.size();
		for(int i=0;i<26;++i)cnt[i]=0;
		for(int i=0;i<n;++i){
			cnt[s[i]-'a']++;
			if(!i)continue;
			if(s[i]!=s[i-1])ok2=0;
		}
		if(ok2){cout<<s<<endl;continue;}
		
		int best=-1;
		for(int i=0;i<26;++i){
			if(cnt[i]==1){best=i;break;}
		}
		
		vector<int> ans;
		if(best!=-1){
			ans.pb(best);
			cnt[best]=0;
		}else{
			int a=-1,b=-1;
			for(int i=0;i<26;++i){
				if(cnt[i]>0){
					if(a>=0){b=i;break;}
					else a=i;
				}
			}
			
			if(a!=-1&&b!=-1){
				int total=0;
				for(int i=0;i<26;++i){
					if(i==a)continue;
					total+=cnt[i];
				}
				if(cnt[a]>cnt[b]+2){
					ans.pb(a);
					for(int i=0;i<cnt[b];++i)ans.pb(b);
					for(int i=0;i<cnt[a]-1;++i)ans.pb(a);
					cnt[a]=cnt[b]=0;
				}else{
					bool ok=1;
					ans.pb(a);cnt[a]--;
					if(cnt[a]>0)ans.pb(a),cnt[a]--;
					while(cnt[a]&&cnt[b]){
						if(ok){
							if(cnt[b]){
								ans.pb(b);cnt[b]--;
							}else{
								while(cnt[b]==0)++b;
								ans.pb(b);cnt[b]--;
							}
						}else ans.pb(a),cnt[a]--;
						
						ok=!ok;
					}
				}
			}
		}
		for(int i=0;i<26;++i){
			if(cnt[i]>0){
				for(int j=0;j<cnt[i];++j)ans.pb(i);
			}
		}
		
		for(int i:ans)cout<<(char)('a'+i);
		cout<<endl;
	}
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
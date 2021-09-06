#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

char ans[30];
int n;

signed main(){
	scanf("%d",&n);
	for(int i=0;i<n+n-1;++i){
		char s[30]; scanf("%s",&s);
		for(int j=0;j<strlen(s);++j)ans[j]^=s[j];
	}	
	printf("%s",ans);
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
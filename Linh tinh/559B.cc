#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define fi first
#define se second
#define MOD 1000000007
 
typedef long long ll;

string s,t;

string get(string x){
	if((int)x.size()&1)return x;
	string s1=get(x.substr(0,(int)x.size()/2));
	string s2=get(x.substr((int)x.size()/2,(int)x.size()));
	
	if(s1<s2)return s1+s2;
	return s2+s1;
}

signed main(){
	cin>>s>>t;
	if(get(s)==get(t))puts("YES");
	else puts("NO");
	
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.";
#endif
}
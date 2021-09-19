/// ldmm is n00b ///
#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int a[N],tmp[N];
int n,m;

struct Seg {
	int val[4*N];
	bool rev[4*N];
	void init( int id, int l, int r, int *b ) {
		rev[id]=0;
		if ( l==r ) {
			val[id]=b[l];
			return;
		}
		int m=(l+r)/2;
		init(id*2,l,m,b);
		init(id*2+1,m+1,r,b);
		val[id]=val[id*2]+val[id*2+1];
	}
	int get( int id, int l, int r ) {
		if ( !rev[id] ) return val[id];
		else return (r-l+1)-val[id];
	}
	void push( int id, int l, int r ) {
		if ( !rev[id] ) return;
		rev[id*2]^=1;
		rev[id*2+1]^=1;
		rev[id]=0;
	}
	void pull( int id, int l, int r ) {
		int m=(l+r)/2;
		val[id]=get(id*2,l,m)+get(id*2+1,m+1,r);
	}
	int get( int id, int l, int r, int ql, int qr ) {
		if ( qr<l || ql>r ) return 0;
		if ( ql<=l && r<=qr ) return get(id,l,r);
		push(id,l,r);
		int m=(l+r)/2,ret=0;
		ret+=get(id*2,l,m,ql,qr);
		ret+=get(id*2+1,m+1,r,ql,qr);
		pull(id,l,r);
		return ret;
	}
	void chg( int id, int l, int r, int ql, int qr ) {
		if ( qr<l || ql>r ) return;
		if ( ql<=l && r<=qr ) {
			rev[id]^=1;
			return;
		}
		push(id,l,r);
		int m=(l+r)/2;
		chg(id*2,l,m,ql,qr);
		chg(id*2+1,m+1,r,ql,qr);
		pull(id,l,r);
	}
}st[22];

signed main(){
    ios::sync_with_stdio(NULL);
    cin.tie(nullptr);
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=0;i<20;++i){
        for(int j=1;j<=n;++j)tmp[j]=((a[j]>>i)&1);
        st[i].init(1,1,n,tmp);
    }

    cin>>m;
    while(m--){
        int t,l,r,x;
        cin>>t>>l>>r;
        //cout<<t<<' '<<l<<' '<<r<<endl;
        if(t==2){
            cin>>x;
            for(int i=0;i<20;++i){
                if(x&(1<<i)){
                    st[i].chg(1,1,n,l,r);
                }
            }
        }else{
            long long ans=0;
            for(int i=0;i<20;++i)ans+=(1LL<<i)*st[i].get(1,1,n,l,r);
            cout<<ans<<endl;
        }
    }
}

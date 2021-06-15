#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

double l[(int)3e5+10];
string s;
int ans=0;

int to_int(string x){
    int kq=0,cur=1;
    for(int i=(int)x.size()-1;i>=0;--i){
        int tmp=x[i]-'0';
        kq+=(tmp*cur);
        cur*=10;
    }
    return kq;
}

int main() {
    cout.precision(4);
    cout<<fixed;
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>s;
    if((int)s.size()<7){
        int n=to_int(s),fact=1;
        for(int i=1;i<10;++i){
            fact*=i;
            if(fact==n){ans=i;break;}
        }
    }else{
        l[1]=log10(1);
        for(int i=1;1;++i){
            l[i+1]=l[i]+log10(i+1);
            if(floor(l[i+1])+1==(int)s.size()){ans=i+1;break;}
        }
    }
    cout<<ans;
}   
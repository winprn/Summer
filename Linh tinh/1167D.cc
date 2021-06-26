#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007

typedef long long ll;

const int N=2e5+10;
string s;
int mark[N];
int n;

int main() {
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>s;
    memset(mark,-1,sizeof mark);
    int l1=0,l2=0;
    for(int i=0;i<n;++i){
        if(s[i]=='('){
            if(l1>=l2)++l2,mark[i]=1;
            else ++l1,mark[i]=0;
        }else{
            if(l1>=l2)--l1,mark[i]=0;
            else --l2,mark[i]=1;
        }
    }
    assert(l1==0&&l2==0);

    for(int i=0;i<n;++i)cout<<mark[i];
}
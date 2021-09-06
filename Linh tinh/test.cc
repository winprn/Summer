//From L4A with love
#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first
#define kill(j) return cout << j , 0 ;
#define se second
using namespace std;
map<ll , map<ll , ll> >pos;
ll k ;
string s;
signed main()
{
    FASTER;
    freopen("i","r",stdin);
    freopen("o","w",stdout);

    ll x , y;
    cin >> x >> y;
    cin >> k >> s;
    pos[x][y]=1;
    pos[x][y - 1] = 1;
    pos[x][y + 1] = 1;
    pos[x - 1][y] = 1;
    pos[x + 1][y] = 1;
    pos[x + 1][y - 1] = 1;
    pos[x - 1][y - 1] = 1;
    pos[x - 1][y + 1] = 1;
    pos[x + 1][y + 1] = 1;
    bool check = false;
    ll l = 0 , r = 0;
    if(pos[0][0])check=1,cout<<0<<'\n';
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == 'D') r--;
        if(s[i] == 'L') l--;
        if(s[i] == 'R') l++;
        if(s[i] == 'U') r++;
        if(pos[l][r] == 1)
        {
            cout << i + 1 << '\n';
            check = true;
        }
    }
    if(check == false) cout << -1;
}

#include <bits/stdc++.h>
#define maxN 110
#define inf INT_MAX

using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> i3;
char a[maxN][maxN];
int n,m,k,t;
vector<int> order;
queue<i3> cmd;
ii s;

int cnt=0;

bool check(int x, int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m);
}

void execute(i3 u)
{
    int i=u.first.first,j=u.first.second;
    int x=u.second;

    if (order[x]==1)
    {
        while (i--&&(check(i,j)&&a[i][j]!='#'))
        {
            if (order[x+1]!=0)
                cmd.push(i3(ii(i,j),x+1));
            else a[i][j]='*';
        }
        return;
    }
    else if (order[x]==2)
    {
        while (j++&&(check(i,j)&&a[i][j]!='#'))
        {
            if (order[x+1]!=0)
                cmd.push(i3(ii(i,j),x+1));
            else a[i][j]='*';
        }

        return;
    }
    else if (order[x]==3)
    {
        while (i++&&(check(i,j)&&a[i][j]!='#'))
        {
            if (order[x+1]!=0)
                cmd.push(i3(ii(i,j),x+1));
            else a[i][j]='*';
        }
        return;
    }
    else if (order[x]==4)
    {
        while (j--&&(check(i,j)&&a[i][j]!='#'))
        {
            if (order[x+1]!=0)
                cmd.push(i3(ii(i,j),x+1));
            else a[i][j]='*';
        }
        return;
    }
}

int main()
{
    freopen("i","r",stdin);
    freopen("o","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
        {
            cin>>a[i][j];
            if (a[i][j]=='S') s=ii(i,j);
        }
    cin>>k;
    while (k--)
    {
        string tmp; cin>>tmp;
        if (tmp=="UP") order.push_back(1);
        else if (tmp=="RIGHT") order.push_back(2);
        else if (tmp=="DOWN") order.push_back(3);
        else order.push_back(4);
    }
    order.push_back(0);

    cmd.push(i3(s,0));
    while (!cmd.empty())
    {
        execute(cmd.front());
        cmd.pop();
    }

    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
            if(a[i][j]=='S')cout<<'.';
            else cout<<a[i][j];
        cout<<endl;
    }
}

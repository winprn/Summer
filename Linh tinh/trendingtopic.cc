/* ldmm is n00b */
#include <bits/stdc++.h>

using namespace std;

#define Cerr cerr << "\nTest: "
#define endl "\n"
#define fi first
#define se second
#define pb push_back
#define IN(a,b) ((a)&(1<<(b)))


template<class T> bool mini(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool maxi(T &a, T b) { return a < b ? (a = b, true) : false; }

typedef pair<int, int> pii;
typedef long long ll;
typedef double ld;

string s;
map<string,int> cnt[1005];

bool cmp(pair<int,string> a,pair<int,string> b){
    if(a.fi==b.fi)return a.se<b.se;
    return a.fi>b.fi;
}

int getNum(string s){
    int kq=0;
    for(int i=0;i<(int)s.size();++i){
        if(s[i]>='0'&&s[i]<='9')kq=kq*10+(s[i]-'0');
    }

    return kq;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);
#endif

    set<pair<int,string>> words[1005];
    set<string> tot;
    int i=-1;
    while(getline(cin,s)){
        //cout<<s<<endl;
        if(s=="")continue;
        if(s=="<text>"){
            ++i;
            getline(cin,s);
            set<string> cur;
            while(s!="</text>"){
                stringstream ss(s);
                string tmp;
                while(ss>>tmp){
                    //cout<<tmp<<endl;
                    if(tmp.size()<4)continue;
                    tot.insert(tmp);
                    cur.insert(tmp);
                    if(i==0)cnt[i][tmp]++;
                    if(i>0){
                        for(auto k:tot){
                            if(*cur.lower_bound(k)==k)cnt[i][k]=cnt[i-1][k]+1;
                            else cnt[i][k]=cnt[i-1][k];
                            if(i>=7)cnt[i][k]-=cnt[i-7][k];
                        }
                    }
                }
                getline(cin,s);
            }
            for(auto j:tot){
                cout<<j<<endl;
                //if(cnt[i][j]==0)continue;
                words[i].insert({cnt[i][j],j});
            }
        }else if(s[2]=='o'){
            cout<<i<<endl;
            for(auto it:words[i])cout<<it.fi<<' '<<it.se<<endl;
//            vector<pair<int,string>> ans;
//            int n=getNum(s),cur=0;
//            cout<<"<top "<<n<<'>'<<endl;
//            auto it=words[i].end();
//            --it;
//            for(;it!=words[i].begin()&&n--;--it){
//                ans.pb({it->fi,it->se});
//                //cout<<it->fi<<' '<<it->se<<endl;
//            }
//
//            auto lst=it;
//            ++lst;
//            while(it->fi==lst->fi){
//                ans.pb({it->fi,it->se});
//                lst=it;
//                --it;
//            }
////            for(auto it=words.end();it!=words.begin();--it){
////                auto tmp=it;
////                --tmp;
////                if(tmp->fi!=it->fi&&cur>=n)break;
////                cout<<it->fi<<' '<<it->se<<endl;
////                ++cur;
////            }
//
//            sort(ans.begin(),ans.end(),cmp);
//            for(auto i:ans)cout<<i.se<<' '<<i.fi<<endl;
//            cout<<"</top>"<<endl;
        }
    }

#ifdef LOCAL
    cerr << "\nTime elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}
/*
wait, AC?
⢀⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⣠⣤⣶⣶
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⢰⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⣀⣀⣾⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡏⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿
⣿⣿⣿⣿⣿⣿⠀⠀⠀⠈⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠉⠁⠀⣿
⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠙⠿⠿⠿⠻⠿⠿⠟⠿⠛⠉⠀⠀⠀⠀⠀⣸⣿
⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣴⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡟⠀⠀⢰⣹⡆⠀⠀⠀⠀⠀⠀⣭⣷⠀⠀⠀⠸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠈⠉⠀⠀⠤⠄⠀⠀⠀⠉⠁⠀⠀⠀⠀⢿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⢾⣿⣷⠀⠀⠀⠀⡠⠤⢄⠀⠀⠀⠠⣿⣿⣷⠀⢸⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⡀⠉⠀⠀⠀⠀⠀⢄⠀⢀⠀⠀⠀⠀⠉⠉⠁⠀⠀⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿
*/

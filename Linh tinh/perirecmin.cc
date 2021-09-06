/* ldmm is n00b */
#include <bits/stdc++.h>
using namespace std;

const int N=30;
int a[N][N];
int n,m;

int zero_matrix() {
//    int n = a.size();
//    int m = a[0].size();

    int ans = 0;
    vector<int> d(m+3, -1), d1(m+3), d2(m+3);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 1)
                d[j] = i;
        }

        for (int j = 0; j < m; ++j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d1[j] = st.empty() ? -1 : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = m - 1; j >= 0; --j) {
            while (!st.empty() && d[st.top()] <= d[j])
                st.pop();
            d2[j] = st.empty() ? m : st.top();
            st.push(j);
        }
        while (!st.empty())
            st.pop();

        for (int j = 0; j < m; ++j)
            ans = max(ans, (i - d[j]) + (d2[j] - d1[j] - 1));
    }
    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("i", "r", stdin);
    freopen("o", "w", stdout);

    cin>>n>>m;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j){char c; cin>>c;a[i][j]=c-'0';}
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)cout<<a[i][j];
        cout<<endl;
    }

    cout<<2*zero_matrix();
}

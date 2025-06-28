#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> b[i];
    multiset<int> st;
    int used = 0;
    for (int i = 0; i < n; ++i) {
        int res = 0;
        st.insert(a[i]+used);
        while (!st.empty() && *st.begin() < used){
            st.erase(st.begin());
        }
        while (!st.empty() && *st.begin() <= b[i]+used){
            res += (*st.begin()-used);
            st.erase(st.begin());
        }
        res += (int)st.size()*b[i];
        used += b[i];
        cout << res << " ";
    }
    cout << endl;
}


int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
     while (t--) {
        solve();
    }
    return 0;
}

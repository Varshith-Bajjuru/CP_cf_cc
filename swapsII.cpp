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

void solve(){
    int n;cin >> n;
    vi a(n),b(n);
    rep(i,0,n)cin >> a[i];
    rep(i,0,n)cin >> b[i];

    set<int> st;
    for (int i = 1; i <= 2*n; ++i) {
        st.insert(i);
    }
    vi memo(2*n+1);
    int idx = 0;
    while (!st.empty()){
        int ele = b[idx];
        vi toErase;
        for(int i : st){
            if (i > ele) break;
            memo[i] = idx;
            toErase.push_back(i);
        }
        for (int i : toErase) {
            st.erase(i);
        }
        idx++;
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        ans = min(ans,i+memo[a[i]]);
    }
    cout << ans << endl;
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

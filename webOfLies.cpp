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
    int n, m; cin >> n >> m;
    map<int, set<int>> mp;
    while (m--) {
        int u, v; cin >> u >> v;
        mp[u].insert(v);
        mp[v].insert(u);
    }

    int ans = 0;
    vector<bool> is(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        if (mp[i].lower_bound(i) == mp[i].end()) {
            ans++;
            is[i] = true;
        }
    }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;
        if (type == 3) {
            cout << ans << endl;
            continue;
        }

        int u, v; cin >> u >> v;
        if (is[u]) ans--;
        if (is[v]) ans--;

        if (type == 1) {
            mp[u].insert(v);
            mp[v].insert(u);
        } else {
            mp[u].erase(v);
            mp[v].erase(u);
        }

        is[u] = (mp[u].lower_bound(u) == mp[u].end());
        is[v] = (mp[v].lower_bound(v) == mp[v].end());

        if (is[u]) ans++;
        if (is[v]) ans++;
    }
}

int32_t main() {
    setIO();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

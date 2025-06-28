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

int ans = 0;

void dfs(int node, map<int, vi> &mp, vi &cats, int catss, int m, int prevNode) {
    if (cats[node]) catss++;
    else catss = 0;

    if (catss > m) return;

    bool isLeaf = true;
    for (int i : mp[node]) {
        if (i != prevNode) {
            isLeaf = false;
            dfs(i, mp, cats, catss, m, node);
        }
    }

    if (isLeaf) ans++;
}

void solve(){
    int n,m;cin >> n >> m;
    vi cats(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> cats[i];
    }
    map<int,vector<int>> mp;
    for (int i = 1; i < n; ++i) {
        int u,v;cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }

    dfs(1,mp,cats,0,m,0);

    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

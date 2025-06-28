#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 1e9+7;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int powerMod(int a,int b) {
    int res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

vi used;
int cnt = 0;

void dfs(int node,unordered_map<int,vi> &adj){
    used[node] = 1;
    cnt++;
    for (int i : adj[node]) {
        if (used[i] == 0){
            dfs(i,adj);
        }
    }
}

void solve(){
    int n,k;cin >> n >> k;
    used.resize(n+1,0);
    unordered_map<int,vector<int>> adj;
    for (int i = 0; i < n-1; ++i) {
        int u,v,x;cin >> u >> v >> x;
        if (x == 0){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int ans = powerMod(n,k);
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            cnt = 0;
            dfs(i, adj);
            int num = powerMod(cnt, k);
            ans = (ans - num + MOD) % MOD;
        }
    }

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

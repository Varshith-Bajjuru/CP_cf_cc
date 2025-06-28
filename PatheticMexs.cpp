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
    int x = 0;
    unordered_map<int,vi> adj;
    vector<pair<int,int>> given(n-1);
    map<pair<int,int>, int> edgeIndex;

    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        if (u > v) swap(u,v);
        adj[u].push_back(v);
        adj[v].push_back(u);
        given[i] = {u,v};
        edgeIndex[{u,v}] = i;
    }

    vi ans(n-1, -1);

    for(auto &p : adj){
        if (p.second.size() >= 3){
            for(auto i : p.second){
                int u = p.first, v = i;
                if (u > v) swap(u,v);
                ans[edgeIndex[{u,v}]] = x++;
            }
            break;
        }
    }

    for (int i = 0; i < n-1; ++i) {
        if (ans[i] == -1) ans[i] = x++;
    }

    for(int i : ans){
        cout << i << endl;
    }
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

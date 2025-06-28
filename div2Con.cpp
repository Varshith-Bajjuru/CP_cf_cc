#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void dfsOut(int node,int par,unordered_map<int,vi> &adj,bool out){
    for(int i : adj[node]){
        if (out) cout << node << " " << i << endl;
        if (par != i){
            dfsOut(i,node,adj,!out);
        }
    }
}

void solve(){
    int n;cin >> n;
    unordered_map<int,vi> adj;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int node = -1;
    for(auto &p : adj){
        if (p.second.size() == 2){
            node = p.first;
            break;
        }
    }
    if (node == -1){
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
    cout << node << " " << adj[node][0] << endl;
    dfsOut(adj[node][0],node,adj,false);
    dfsOut(adj[node][1],node,adj,true);
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

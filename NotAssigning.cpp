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
    map<int,vector<int>> tree;
    map<pair<int,int>,int> idxs;
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
        idxs[{u,v}] = i;
        idxs[{v,u}] = i;
    }
    if(n == 2){
        cout << 3 << endl;
        return;
    }
    for(auto p : tree){
        if (p.second.size() > 2){
            cout << -1 << endl;
            return;
        }
    }
    vi nodes;
    int nodeWithDeg1;
    for(auto p : tree){
        if (p.second.size() == 1){
            nodeWithDeg1 = p.first;
            break;
        }
    }
    nodes.push_back(nodeWithDeg1);
    int prevNode = nodeWithDeg1;
    vi currChilds = tree[prevNode];
    nodes.push_back(currChilds[0]);
    while (nodes.size() < n){
            prevNode = nodes[nodes.size()-1];
            currChilds = tree[prevNode];
            if (nodes[nodes.size()-2] != currChilds[0]){
                nodes.push_back(currChilds[0]);
            }else{
                nodes.push_back(currChilds[1]);
            }
    }
    vi ans(n-1);
    int weight = 2;
    for (int i = 0; i < n-1; ++i) {
        int u = nodes[i],v = nodes[i+1];
        ans[idxs[{u,v}]] = weight;
        if (weight == 2){
            weight = 3;
        }else{
            weight = 2;
        }
    }

    for(int i : ans) cout << i << " ";
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

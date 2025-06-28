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
    vector<int> a(n+1);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> adj(n+1,0);
    for (int i = 0; i < n-1; ++i) {
        int u,v;cin >> u >> v;
        adj[u]++;
        adj[v]++;
    }
    priority_queue<pair<int,int>> pq;
    for (int i = 1; i <= n; ++i) {
        adj[i]--;
        if (adj[i] > 0){
            pq.emplace(a[i],adj[i]);
        }
    }

    cout << sum << " ";
    for (int i = 2; i <= n-1; ++i) {
        pair<int,int> pair1 = pq.top();
        pq.pop();
        sum += pair1.first;
        pair1.second -= 1;
        if (pair1.second > 0) pq.push(pair1);
        cout << sum << " ";
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

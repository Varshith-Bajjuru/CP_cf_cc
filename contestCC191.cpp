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

    vi par(n),si(n,1);
    vector<bool> hasCycle(n,false);

    for (int i = 0; i < n; ++i) par[i] = i;
    auto find = [&](auto &&find,int v){
        if (par[v] == v) return v;
        else return (par[v] = find(find,par[v]));
    };

    auto join = [&](int a,int b){
        a = find(find,a);
        b = find(find,b);
        if (a == b){
            hasCycle[a] = true;
            return;
        }

        if (si[a] < si[b]) swap(a,b);

        if (hasCycle[b]) hasCycle[a] = true;
        si[a] += si[b];
        par[b] = a;
    };

    vector<bool> self(n,false);
    for (int i = 0; i < n; ++i) {
        int a,b;cin >> a >> b;
        a--,b--;
        if (a == b) self[a] = true;
        join(a,b);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (par[i] != i) continue;
        if (hasCycle[i]) ans += si[i];
        else ans += si[i] + 1;
    }
    cout << ans - accumulate(all(self),0) << endl;
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

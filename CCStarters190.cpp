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
    int n,m;cin >> n >> m;
    vector<vector<int>> v(n,vector<int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> v[i][j] ;
        }
    }

    int ele = v[0][0];
    vi curr(m);
    for (int i = 0; i < m; ++i) {
        curr[i] = ele++;
    }

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

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

int powermod(int a, int b) {
    long long res = 1;
    a %= MOD;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

void solve(){
    int n;cin >> n;
    vi a(n),b(n),d(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> d[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) {
            d[i] = a[i];
        }
    }
    unordered_map<int,int> idxs;
    for (int i = 0; i < n; ++i) {
        idxs[d[i]] = i+1;
    }
    idxs.erase(0);

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0){
            if (idxs[a[i]] == 0 && idxs[b[i]] != 0){
                d[i] = a[i];
                idxs[a[i]] = i+1;
            }
            else if (idxs[a[i]] != 0 && idxs[b[i]] == 0){
                d[i] = b[i];
                idxs[b[i]] = i+1;
            }
        }
    }

    vector<bool> visited(n+1,false);
    for(int i : d) visited[i] = true;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0){
            mp[a[i]] = b[i];
        }
    }
    int ans = 1;
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

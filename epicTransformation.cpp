#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    sort(all(a));
    int maxFreq = 0;
    int ele = a[n/2];
    for (int i = 0; i < n; ++i) {
        if (ele == a[i]) maxFreq++;
    }
    if (maxFreq == n){
        cout << n << '\n';
        return;
    }
    if (n % 2 == 0){
        if (maxFreq > n / 2){
            cout << 2 * (maxFreq - n / 2) << '\n';
            return;
        }
        cout << 0 << '\n';
    } else {
        if (maxFreq > n / 2){
            cout << 1 + 2 * (maxFreq - (n + 1) / 2) << '\n';
            return;
        }
        cout << 1 << '\n';
    }
}

int32_t main() {
    setIO();
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
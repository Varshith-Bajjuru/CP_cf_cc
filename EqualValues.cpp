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
    vi a(n+1);rep(i,1,n+1) cin >> a[i];

    int minCst = LLONG_MAX;
    bool allEqual = true;
    for (int i = 1; i <= n; ++i) {
        if (a[1] != a[i]){
            allEqual = false;
            break;
        }
    }
    if (allEqual){
        cout << 0 << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        int curr = a[i];
        int ele = 0;
        while (a[i] == curr && i <= n){
            i++;
            ele++;
        }
        minCst = min(minCst,(n-ele)*curr);
        i--;
    }

    cout << minCst << endl;
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

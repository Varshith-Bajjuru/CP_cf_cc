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
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int maxi = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i-1]){
            maxi = max(maxi,a[i-1] - a[i]);
            a[i] = a[i-1];
        }
    }

    int ans = 0;
    for (int i = 32; i >= 0; --i) {
        if (((maxi>>i)&1)){
            ans = i;
            break;
        }
    }
    if (maxi == 0){
        cout << 0 << endl;
        return;
    }
    cout << ans+1 << endl;
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

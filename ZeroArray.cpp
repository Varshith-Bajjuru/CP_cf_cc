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
    vi a(n);rep(i,0,n) cin >> a[i];
    int rst = a[0];
    for (int i = 1; i < n; ++i) {
        if (rst < 0){
            rst += a[i];
        }else{
            rst -= a[i];
        }
    }

    cout << (rst == 0 ? "Yes" : "No") << endl;
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

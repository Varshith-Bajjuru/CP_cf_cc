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
    int n,a,b;cin >> n >> a >> b;
    vi x(n); rep(i,0,n) cin >> x[i];
    if (n == 1){
        cout << b*x[0] << endl;
        return;
    }
    vi prefix(n);
    prefix[0] = x[0];

    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + x[i];
    }
    int ans = prefix[n-1]*b;
    for (int i = 0; i < n; ++i) {
        ans = min(ans,x[i]*(a+b)+((prefix[n-1] - prefix[i]) - (n-1-i)*x[i])*b);
    }
    cout << ans << endl;
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

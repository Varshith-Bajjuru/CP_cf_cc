#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 1000000007;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(vi &prefix){
    int a, b; cin >> a >> b;
    int ans = (prefix[b] - prefix[a-1])%MOD;
    if (ans < 0) ans += MOD;
    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    int k;
    cin >> t >> k;
    vi dp(1e5 + 1);
    for (int i = 1; i < k; ++i) {
        dp[i] = 1;
    }
    dp[k] = 2;
    for (int i = k + 1; i <= 1e5; ++i) {
        dp[i] = (dp[i - 1] + dp[i - k])%MOD;
    }
    vi prefix(1e5 + 1);
    prefix[0] = 0;
    prefix[1] = dp[1];
    for (int i = 2; i <= 1e5; ++i) {
        prefix[i] = (dp[i] + prefix[i - 1])%MOD;
    }
    while (t--) {
        solve(prefix);
    }
    return 0;
}


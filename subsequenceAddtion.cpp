#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define vi vector<int>

[[noreturn]] void solve() {
    int n;
    cin >> n;
    vi a(n);
    for(auto &x : a) cin >> x;
    if (n == 1){
        if(a[0] == 1)cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }if (n == 2){
        if(a[0] == 1 && a[1] == 1)cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }
    sort(a.begin(),a.end());
    vector<vector<bool>> dp(n,vector<bool> (2*10e5 + 1, false));
    dp[0][0] = true;
    dp[0][1] = a[0] == 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < 2*10e5 + 1; ++j) {
            dp[i][j] = dp[i-1][j] || (j-a[i] >= 0) && dp[i-1][j-a[i]];
        }
    }
    string ans = "YES";
    for (int i = 0; i < n-1; ++i) {
        if (!dp[i][a[i + 1]]){
            ans = "NO";
            break;
        }
    }
    cout << ans << endl;
}

signed main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

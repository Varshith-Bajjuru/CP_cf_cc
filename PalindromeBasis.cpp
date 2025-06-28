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

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x != 0 && x % 10 == 0) return false;
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    vi palindrome;
    for (int i = 1; i <= 40000; ++i) {
        if (isPalindrome(i)){
            palindrome.push_back(i);
        }
    }

    int n = (int)palindrome.size();
    int m = 40001;
    vector<vector<int>> dp(n+1,vector<int>(m,0));
    dp[0][0] = 1;
    for (int i = 0; i < n; ++i) dp[i][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (palindrome[i] > j) {
                dp[i][j] = (i == 0 ? 0 : dp[i-1][j]);
            } else {
                dp[i][j] = (i == 0 ? 0 : dp[i-1][j]) + dp[i][j - palindrome[i]];
            }
            dp[i][j] %= MOD;
        }
    }

    while (t--) {
        int num;cin >> num;
        cout << dp[n-1][num] << endl;
    }
    return 0;
}

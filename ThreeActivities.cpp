#include <bits/stdc++.h>
using namespace std;

#define int long long  // Define int as long long globally
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

const int MOD = 1e9+7;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(int n) {
    return to_string(n).size();  // More efficient way to count digits
}

int power(int a, int b) {
    if (b == 0) return 1;
    int x = power(a, b / 2);
    return (b % 2 == 0) ? x * x : x * x * a;
}

int powermod(int x, int y, int p) {
    int res = 1;
    x %= p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;
        x = (x * x) % p;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<pii> v1, v2, v3;

    rep(i, 1, n + 1) {
        int x;
        cin >> x;
        v1.emplace_back(x, i);
    }
    rep(i, 1, n + 1) {
        int x;
        cin >> x;
        v2.emplace_back(x, i);
    }
    rep(i, 1, n + 1) {
        int x;
        cin >> x;
        v3.emplace_back(x, i);
    }

    // Sort in descending order based on the first value
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    sort(v3.rbegin(), v3.rend());

    int ans = INT_MIN;

    // Try all top 3 elements from each list
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (v1[i].second != v2[j].second &&
                    v1[i].second != v3[k].second &&
                    v2[j].second != v3[k].second) {
                    ans = max(ans, v1[i].first + v2[j].first + v3[k].first);
                }
            }
        }
    }

    cout << ans << endl;
}

int32_t main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

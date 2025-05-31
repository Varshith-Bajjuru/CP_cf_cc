#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

[[noreturn]] void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<int> prefix(n), maxi(n);
    prefix[0] = a[0];
    maxi[0] = b[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
        maxi[i] = max(maxi[i - 1], b[i]);
    }
    int ans = 0;
    for (int i = 0; i < n && i < k; i++) {
        int remaining = k - (i + 1);
        int total_exp = prefix[i] + max(0, remaining) * maxi[i];
        ans = max(ans, total_exp);
    }
    cout << ans << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define vi vector<int>

[[noreturn]] void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);

    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    if (a == b) {
        cout << 1 << " " << n << endl;
        return;
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    }
    while (l > 0 && b[l - 1] <= b[l]) {
        --l;
    }
    while (r < n - 1 && b[r + 1] >= b[r]) {
        ++r;
    }

    cout << l + 1 << " " << r + 1 << endl;
}

signed main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

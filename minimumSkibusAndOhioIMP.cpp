#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
#define inf numeric_limits<ll>::max()

int findSmallestGreaterOrEqual(const vi &vec, ll x) {
    auto it = lower_bound(all(vec), x);
    return (it != vec.end()) ? *it : -1; // Return -1 if no such element exists
}

[[noreturn]] void solve() {
    ll n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;

    sort(all(b));
    ll prev = -inf;

    for (ll i = 0; i < n; i++) {
        ll val = findSmallestGreaterOrEqual(b, a[i] + prev);
        if (val != -1) {
            a[i] = (a[i] < prev) ? (val - a[i]) : min(a[i], val - a[i]);
        }
        if (a[i] < prev) {
            cout << "NO" << endl;
            return;
        }
        prev = a[i];
    }
    cout << "YES" << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

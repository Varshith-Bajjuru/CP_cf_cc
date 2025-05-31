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

[[noreturn]] void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    ll sum = 0;
    for (ll l = 0; l < n; ++l) sum += a[l];
    ll mini = inf;
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + a[i];
    }
    for (int i = 0; i <= k; ++i) {
        ll firstPart = (2 * i - 1 >= 0) ? prefix[2 * i - 1] : 0;
        ll secondPart = (n - (k - i) - 1 >= 0) ? prefix[n - 1] - prefix[n - (k - i) - 1] : 0;
        mini = min(firstPart + secondPart, mini);
    }
    cout << sum - mini << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define vi vector<ll>
#define all(x) (x).begin(), (x).end()
const ll MOD = 1e9 + 7;

[[noreturn]] void solve() {
    ll n;
    cin >> n;
    vi a(n), b(n);
    for (ll &x : a) cin >> x;
    for (ll &x : b) cin >> x;
    sort(all(a));
    sort(all(b));
    vi ans(n);
    for (ll i = 0; i < n; ++i) {
        ans[i] = n - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());
    }
    sort(all(ans));
    ll sum = 1;
    for (int i = 0; i < n; ++i) {
        sum = ((sum%MOD)*((ans[i]-i)%MOD))%MOD;
    }
    cout << sum << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

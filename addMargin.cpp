#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

ll check(vector<ll> &arr, ll w) {
    ll ans = 0;
    for (ll i = 0; i < arr.size(); ++i) {
        ll val = arr[i] + 2 * w;
        ans += (1LL * val * val);
        if (ans > 1e18) return ans;
    }
    return ans;
}

[[noreturn]] void solve() {
    ll n, c;
    cin >> n >> c;
    vector<ll> arr(n);
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll low = 0, high = 1e9, mid, ans = 0;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (check(arr, mid) <= c) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
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

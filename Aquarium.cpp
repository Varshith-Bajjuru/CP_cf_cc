#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

ll check(vector<ll> &arr, ll height) {
    ll required_water = 0;
    for (ll h : arr) {
        if (h < height) {
            required_water += (height - h);
        }
    }
    return required_water;
}

[[noreturn]] void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(all(arr));
    ll minHeight = arr[0];
    ll maxHeight = arr[n - 1] + x;
    ll ans = minHeight;

    while (minHeight <= maxHeight) {
        ll mid = minHeight + (maxHeight - minHeight) / 2;
        ll required = check(arr, mid);

        if (required <= x) {
            ans = mid;
            minHeight = mid + 1;
        } else {
            maxHeight = mid - 1;
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

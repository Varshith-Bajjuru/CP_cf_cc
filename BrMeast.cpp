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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    vector<ll> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + arr[i];
    }

    ll resmax = 0;

    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            vector<ll> diff;
            for (ll j = i - 1; j < n; j += i) {
                ll sum = (j == i - 1) ? prefix[j] : prefix[j] - prefix[j - i];
                diff.pb(sum);
            }
            sort(all(diff));
            resmax = max(resmax, diff.back() - diff.front());
        }
    }
    cout << resmax << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

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
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));
    vector<ll> prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i-1] + a[i];
    }

    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        ll score = a[i];
        int count = 0;
        int j = 0;

        while (j < n) {
            if (j != i && score >= a[j]) {
                score += a[j];
                count++;
            }
            j++;
        }
        ans[i] = count;
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

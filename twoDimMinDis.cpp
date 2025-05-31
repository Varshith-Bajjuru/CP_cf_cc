#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

ll distance(const pair<int, int> &a, const pair<int, int> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

[[noreturn]] void solve() {
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    --a; --b;  // Convert to 0-based index

    vector<pair<int, int>> pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> pos[i].first >> pos[i].second;
    }

    ll dis = distance(pos[a], pos[b]);  // Direct Manhattan distance

    // If there are no special stations, return the direct distance
    if (k == 0) {
        cout << dis << endl;
        return;
    }

    // Compute min distances to special stations
    ll minDis1 = 1e18, minDis2 = 1e18;

    for (int i = 0; i < k; ++i) {
        minDis1 = min(minDis1, distance(pos[a], pos[i]));
        minDis2 = min(minDis2, distance(pos[b], pos[i]));
    }

    ll ans = min(dis, minDis1 + minDis2);
    cout << ans << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll get_cost(const vector<int>& a, int start_parity) {
    vector<int> pos;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] % 2 == start_parity) {
            pos.push_back(i);
        }
    }
    ll cost = 0;
    for (int i = 0; i < pos.size(); ++i) {
        cost += abs(pos[i] - 2*i);
    }
    return cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int odds = 0, evens = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] % 2) odds++;
            else evens++;
        }

        if (abs(odds - evens) > 1) {
            cout << -1 << '\n';
            continue;
        }

        ll res = LLONG_MAX;
        if (odds == evens) {
            res = min(get_cost(a, 0), get_cost(a, 1));
        } else if (odds > evens) {
            res = get_cost(a, 1); // must start with odd
        } else {
            res = get_cost(a, 0); // must start with even
        }

        cout << res << '\n';
    }

    return 0;
}

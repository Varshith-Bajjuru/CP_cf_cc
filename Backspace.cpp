#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

int f(double a, double d, const vi &v) {
    int notequals = 0;
    const double EPS = 1e-6;
    for (int i = 0; i < v.size(); ++i) {
        double expected = a + d * i;
        if (abs((double)v[i] - expected) > EPS) notequals++;
    }
    return notequals;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) cin >> a[i];

    if (n <= 2) {
        cout << 0 << endl;
        return;
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double d = (double)(a[j] - a[i]) * 1.0 / (double)(j - i);
            double aa = (double)a[i] - (double)i * d;
            ans = min(ans, f(aa, d, a));
        }
    }

    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

[[noreturn]] void solve() {
    ll n,q;
    cin >> n >> q;
    vector<ll> a(n),x(q);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < q; ++i){
        cin >> x[i];
    }
    set<ll> hs;
    for (int i = 0; i < q; ++i) {
        if (hs.count(x[i]))continue;
        hs.insert(x[i]);
        ll power = pow(2, x[i]);
        for (int j = 0; j < n; ++j) {
            if (a[j] % power == 0) a[j] += power/2;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

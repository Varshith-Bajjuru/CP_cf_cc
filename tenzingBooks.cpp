#include <iostream>
#include <vector>
using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

[[noreturn]] void solve(){
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int i = 0; i < n; ++i) cin >> c[i];
    ll ans = 0;
    ll i = 0,j = 0,k = 0;



    if (ans == x) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}

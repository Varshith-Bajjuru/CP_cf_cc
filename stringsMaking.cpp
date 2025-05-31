#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

[[noreturn]] void solve() {
    int n ;
    cin >> n;
    string s;
    cin >> s ;
    ll ans = 0;
    vector<int> arr(26);
    for (ll i = 0; i < n; ++i) {
        if (!arr[s[i] - 'a']){
            ans += (n - i);
            arr[s[i] - 'a'] = 1;
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

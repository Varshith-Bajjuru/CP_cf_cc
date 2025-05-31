#include <bits/stdc++.h>
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int idx = 0;

    if(s[0] == s[1]){
        cout << s[0] << s[1] << endl;
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (s[i] - 'a' <= s[i-1] - 'a'){
            idx++;
        } else break;
    }
    string ans = "";
    for (int i = 0; i <= idx; ++i) {
        ans += s[i];
    }
    for (int i = idx; i >= 0 ; --i) {
        ans += s[i];
    }

    cout << ans << endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
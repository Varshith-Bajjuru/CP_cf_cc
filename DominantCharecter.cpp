#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vi a;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') a.push_back(i);
    }

    if (a.size() <= 1) {
        cout << -1 << endl;
        return;
    }

    int ans = INT_MAX;
    for (int i = 0; i < a.size() - 1; ++i) {
        int bs = 0, cs = 0;
        int idx1 = a[i], idx2 = a[i + 1];
        for (int j = idx1 + 1; j < idx2; ++j) {
            if (s[j] == 'b') bs++;
            else if (s[j] == 'c') cs++;
        }
        if (bs < 2 && cs < 2) {
            ans = min(ans,2+bs+cs);
        }
    }
    for (int i = 0; i < a.size()-2; ++i) {
        int bs = 0, cs = 0;
        int idx1 = a[i], idx2 = a[i + 2];
        for (int j = idx1 + 1; j < idx2; ++j) {
            if (s[j] == 'b') bs++;
            else if (s[j] == 'c') cs++;
        }
        if (bs < 3 && cs < 3) {
            ans = min(ans,3+bs+cs);
        }
    }
    if (ans != INT_MAX){
        cout << ans << endl;
        return;
    }
    cout << -1 << endl;
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

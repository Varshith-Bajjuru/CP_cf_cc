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
    vi a(n);
    vector<bool> used(n+1,false);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a),[](int a,int b){
        return a > b;
    });
    bool ok = true;

    for(auto &i : a){
        int x = i;
        while (x > n or used[x]) x  = x/2;
        if (x > 0) used[x] = true;
        else ok = false;
    }

    cout << (ok ? "YES" : "NO") << endl;
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
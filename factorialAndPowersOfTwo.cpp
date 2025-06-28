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

vector<pair<int,int>> a;
void computeVector(vi &v, int idx, int sum, int sz) {
    if (idx == v.size()) {
        a.emplace_back(sum, sz);
        return;
    }
    computeVector(v, idx + 1, sum + v[idx], sz + 1);
    computeVector(v, idx + 1, sum, sz);
}

void solve(vi &v) {
    int n;
    cin >> n;

    for (int i : v) {
        if (i == n) {
            cout << 1 << endl;
            return;
        }
    }

    for (int i = 0; i < 40; ++i) {
        if (n == (1LL << i)) {
            cout << 1 << endl;
            return;
        }
    }

    int ans = __builtin_popcountll(n);

    for (auto &p : a) {
        int ele = p.first;
        int sz = p.second;
        if (ele > n) continue;
        int rem = n-ele;
        ans = min(ans,sz+__builtin_popcountll(rem));
    }

    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t;
    cin >> t;
    set<int> st;
    int x = 1;
    for (int i = 1; i <= 15; ++i) {
        st.insert(x * i);
        x *= i;
    }
    vi v;
    for (int i : st) v.push_back(i);
    sort(all(v));
    computeVector(v, 0, 0, 0);
    while (t--) {
        solve(v);
    }

    return 0;
}
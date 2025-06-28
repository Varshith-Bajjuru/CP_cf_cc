#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO() {
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void solve() {
    int n;cin >> n;
    vi a(n);
    unordered_map<int,int> freq;
    rep(i, 0, n){
        cin >> a[i];
        freq[a[i]]++;
    }
    int currMex = 0;
    set<int> st;
    vi ans;
    for (int i = 0; i < n; ++i) {
        freq[a[i]]--;
        st.insert(a[i]);
        while (st.count(currMex)){
            currMex++;
        }
        if (freq[currMex] == 0){
            ans.push_back(currMex);
            currMex = 0;
            st.clear();
        }
    }

    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
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

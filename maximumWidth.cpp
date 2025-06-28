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

void solve(){
    int n,m;cin >> n >> m;
    string s,t;cin >> s >> t;
    unordered_map<char,vi> mp;
    for (int i = 0; i < n; ++i) {
        mp[s[i]].push_back(i);
    }

    vi mini(m),maxi(m);
    mini[0] = mp[t[0]][0];
    for (int i = 1; i < m; ++i) {
        mini[i] = *upper_bound(all(mp[t[i]]),mini[i-1]);
    }

    maxi[m-1] = *max_element(all(mp[t[m-1]]));
    for (int i = m-2; i >= 0; --i) {
        auto it = lower_bound(all(mp[t[i]]),maxi[i+1]);
        it--;
        maxi[i] = *it;
    }

    int ans = INT_MIN;
    for (int i = 0; i < m-1; ++i) {
        ans = max(ans,maxi[i+1] - mini[i]);
    }
    cout << ans << endl;
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

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
    int n;cin >> n;
    vector<string> s(n);
    vector<unordered_map<char,int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        unordered_map<char,int> mp;
        for(char j : s[i]){
            mp[j]++;
        }
        v[i] = mp;
    }

    int ans = INT_MIN;
    for(char c = 'a';c <= 'e';c++){
        vector<int> curr(n);
        for (int i = 0; i < n; ++i) {
            curr[i] = (int)s[i].size() - 2*v[i][c];
        }
        sort(all(curr));
        vi prefix(n);
        prefix[0] = curr[0];
        for (int i = 1; i < n; ++i) {
            prefix[i] = prefix[i-1] + curr[i];
        }
        int ele = 0;
        int ptr = 0;
        while (prefix[ptr] <= -1 && ptr < n) {
            ele++;
            ptr++;
        }
        ans = max(ans,ele);
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

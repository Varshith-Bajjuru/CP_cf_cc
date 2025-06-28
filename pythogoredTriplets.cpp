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

void solve(vi &ods){
    int n;cin >> n;
    int idx = lower_bound(all(ods),n) - ods.begin();
    if (ods[idx] != n){
        idx--;
    }
    cout << idx+1 << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    vi ods;
    for (int i = 3; i <= 1e5; ++i) {
        if (i&1)ods.push_back((i*i+1)/2);
    }
    while (t--) {
        solve(ods);
    }
    return 0;
}

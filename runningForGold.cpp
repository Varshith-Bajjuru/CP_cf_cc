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

bool isSuperior(vector<vector<int>> &v,int p1,int p2){
    int cnt = 0;
    for (int i = 0; i < 5; ++i) {
        if (v[p1][i] < v[p2][i]) cnt++;
    }

    return cnt >= 3;
}

void solve(){
    int n;cin >> n;
    vector<vector<int>> v(n,vector<int>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> v[i][j];
        }
    }
    if (n == 1){
        cout << 1 << endl;
        return;
    }

    int p1 = 0;
    for (int i = 1; i < n; ++i) {
        if (!isSuperior(v,p1,i)){
            p1 = i;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (!isSuperior(v,p1,i) && i != p1){
            cout << -1 << endl;
            return;
        }
    }

    cout << p1+1 << endl;
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

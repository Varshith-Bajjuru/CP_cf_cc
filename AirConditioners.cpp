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

void print(vi &v){
    for (int i = 1; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve(){
    int n,k;cin >> n >> k;
    vi a(k);rep(i,0,k)cin >> a[i];
    vi t(k);rep(i,0,k)cin >> t[i];
    vi ans(n+1,INT_MAX);
    for (int i = 0; i < k; ++i) {
        ans[a[i]] = t[i];
    }
    int idx = min_element(all(ans)) - ans.begin();
    int ptr1 = idx-1;
    int ptr2 = idx+1;
    int temp = ans[idx];

    while (ptr1 >= 1){
        ans[ptr1] = min(ans[ptr1],temp+1);
        temp = ans[ptr1];
        ptr1--;
    }
    temp = ans[idx];
    while (ptr2 <= n){
        ans[ptr2] = min(ans[ptr2],temp+1);
        temp = ans[ptr2];
        ptr2++;
    }
    temp = ans[n];
    int ptr = n-1;
    while (ptr >= 1){
        ans[ptr] = min(ans[ptr],temp+1);
        temp = ans[ptr];
        ptr--;
    }
    temp = ans[1];
    ptr = 2;
    while (ptr <= n){
        ans[ptr] = min(ans[ptr],temp+1);
        temp = ans[ptr];
        ptr++;
    }
    print(ans);
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

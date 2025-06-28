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
    int n,k;cin >> n >> k;
    if (n == 4 && k == 3){
        cout << -1 << endl;
        return;
    }
    if (k == n-1){

    }else{
        set<int> st;
        cout << k << " " << n-1 << endl;
        cout << n-1-n/2 << " " << 0 << endl;
        st.insert(k);
        st.insert(n-1);
        st.insert(n-1-k/2);
        st.insert(0);
        for (int i = 1; i < n; ++i) {
            if (st.count(i) == 0){
                cout << i << " " << i+n/2 << endl;
                st.insert(i);
                st.insert(i+n/2);
            }
        }
    }
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
